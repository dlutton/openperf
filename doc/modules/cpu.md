# CPU Module

The **CPU** module is a part of OpenPerf, producing CPU load.

## CPU Generator

Functional unit of OpenPerf CPU module, providing an ability for CPU load generation. CPU generator configuration defines per core loading. Each core configuration has desired `utilization` and chain of `targets`. Utilization can be real value between 0 and 100, inclusive.

### CPU Generator API Model

```json
{
    "id": "",
    "running": false,
    "config": {
        "cores": [
            {
                "utilization": 22.5,
                "targets": [
                    {
                        "instruction_set": "scalar",
                        "data_type": "int32",
                        "weight": 5
                    }, {
                        "instruction_set": "scalar",
                        "data_type": "float64",
                        "weight": 10
                    }
                ]
            }
        ]
    }
}
```

* **id** - unique CPU generator identifier. If empty, then UUID identifier will be generated by module.
* **running** - current activity status of generator.
* **config** - configuration of CPU generator.
    * **cores** - array of per core configurations.
        * **utilization** - per core utilization value between 0 and 100.
        * **targets** - array of targets configurations.
            * **intruction_set** - set of instructions.
            * **data_type** - type of data for load.
            * **weight** - relative weight of task.

### Targets

Target is the algorithm used to generate load. Targets run sequentially in the order of definition. Weight of each target determines amount of use regard another targets in chain. Only one target instruction set `scalar` is available now. Additional instruction sets will be added in future. `data_type` depends on `instruction_set` value. `weight` is the relative execution time of current target regard other targets in same chain. For example, if one taraget has weight 10, and another has weight 50, then the CPU module will try to run targets in such a way that the second target has five times more CPU time than the first target.

List of available `data_type` values depends on selected `instruction_set` value:
* **scalar**
    * **int32** - integer numbers, 32-bit size.
    * **int64** - integer numbers, 64-bit size.
    * **float32** - floating point numbers, 32-bit size.
    * **float64** - floating point numbers, 64-bit size.

## CPU Generator Result

CPU generator result represents statistics of CPU I/O operations, unique for each CPU generator run. When a generator is started new generator result is created. Results are created in active state. When generator is stopped the result will go to inactive state and won't be changed anymore.

### CPU Generator Result API Model

```json
{
    "active": true,
    "id": "2c9d0e5d-a1be-49d2-759d-a2fcd99961ee",
    "generator_id": "e0a5d7c2-58a4-4864-5ee4-d850346f2917",
    "timestamp": "2020-05-18T13:16:47.804564Z",
    "stats": {
        "available": 7011826558,
        "error": 72788,
        "steal": 0,
        "system": 3996000,
        "user": 732173000,
        "utilization": 736169000,
        "cores": [
            {
                "available": 7011826558,
                "error": 72788,
                "steal": 0,
                "system": 3996000,
                "user": 732173000,
                "utilization": 736169000,
                "targets": [
                    {
                        "operations": 18279000
                    },
                    {
                        "operations": 39933000
                    },
                    {
                        "operations": 10503000
                    },
                    {
                        "operations": 4860000
                    }
                ]
            }
        ]
    }
}
```

* **id** - unique identifier of result.
* **active** - indicates whether the result updates periodically.
* **generator_id** - related generator identifier.
* **timestamp** - timestamp of the last update, in ISO 8601 format.
* **stats** - statistics.
    * **available** - available CPU time.
    * **error** - difference between wanted and actual utilization.
    * **steal** - time the hypervisor reported VM were blocked.
    * **system** - system time used, e.g. kernel or system calls.
    * **user** - user time used, e.g. generator load code.
    * **utilization** - CPU time used.
    * **cores** - per core statistics
        * **available** - same as above, but per core.
        * **error** - same as above, but per core.
        * **steal** - same as above, but per core.
        * **system** - same as above, but per core.
        * **user** - same as above, but per core.
        * **utilization** - same as above, but per core.
        * **targets**
            * **operations** - number of operations.


### Create CPU Generator

To create CPU Generator pass the valid API model. Field `id` should be unique. CPU module will generate new unique UUID, if `id` string is empty. Set `read_threads` or `write_threads` to `0` value to ignore read or write operations respectively.

### Start CPU Generator

Start CPU generator command returns CPU Generator Result, created for the particular start. Response `Location` header contains URI of created result.

### Getting CPU Generator Result

CPU generator statistics can be received by unique ID of statistics

## Commands flow

Further ```<OPENPERF>``` stands for OpenPerf location in format ```host[:port]```.

### Create CPU Generator

```bash
curl --verbose --location \
    --request POST 'http://<OPENPERF>/cpu-generators' \
    --header 'Content-Type: application/json' \
    --data-raw '{
        "id": "",
        "running": false,
        "config": {
            "cores": [
                {
                    "utilization": 22.5,
                    "targets": [
                        {
                            "instruction_set": "scalar",
                            "data_type": "int32",
                            "weight": 5
                        }, {
                            "instruction_set": "scalar",
                            "data_type": "float64",
                            "weight": 10
                        }
                    ]
                }
            ]
        }
    }'
```

Response:
```
< HTTP/1.1 201 Created
< Content-Type: application/json
< Connection: Close
< Location: /cpu-generators/0a565dac-5a7f-447b-40ec-5fa1f30fa4d0
< Content-Length: 238
<
{
    "id": "0a565dac-5a7f-447b-40ec-5fa1f30fa4d0",
    "running": false,
    "config": {
        "cores": [
            {
                "utilization": 22.5,
                "targets": [
                    {
                        "data_type": "int32",
                        "instruction_set": "scalar",
                        "weight": 5
                    },{
                        "data_type": "float64",
                        "instruction_set": "scalar",
                        "weight": 10
                    }
                ]
            }
        ]
    }
}
```

### Start CPU Generator

```bash
curl --verbose --location --request POST \
  'http://<OPENPERF>/cpu-generators/0a565dac-5a7f-447b-40ec-5fa1f30fa4d0/start'
```

Response:
```
< HTTP/1.1 201 Created
< Content-Type: application/json
< Connection: Close
< Location: /cpu-generator-results/7286bd27-fa5d-4fea-51f0-4f6f92285321
< Content-Length: 332
<
{
    "active": true,
    "id": "7286bd27-fa5d-4fea-51f0-4f6f92285321",
    "generator_id": "0a565dac-5a7f-447b-40ec-5fa1f30fa4d0",
    "timestamp": "2020-05-18T13:51:25.891662Z",
    "stats": {
        "available": 0,
        "error": 0,
        "steal": 0,
        "system": 0,
        "user": 0,
        "utilization": 0,
        "cores": [
            {
                "available": 0,
                "error": 0,
                "steal": 0,
                "system": 0,
                "targets": null,
                "user": 0,
                "utilization": 0
            }
        ]
    }
}
```

### Stop CPU Generator

```bash
curl --verbose --location --request POST \
    'http://<OPENPERF>/cpu-generators/0a565dac-5a7f-447b-40ec-5fa1f30fa4d0/stop'
```

Response:
```
< HTTP/1.1 204 No Content
< Connection: Close
< Content-Length: 0
<
```

### Get CPU Generator Statistics

```bash
curl --verbose --location --request GET \
    'http://<OPENPERF>/cpu-generator-results/7286bd27-fa5d-4fea-51f0-4f6f92285321'
```

```
< HTTP/1.1 200 OK
< Content-Type: application/json
< Connection: Close
< Content-Length: 461
<
{
    "active": false,
    "id": "7286bd27-fa5d-4fea-51f0-4f6f92285321",
    "generator_id": "0a565dac-5a7f-447b-40ec-5fa1f30fa4d0",
    "timestamp": "2020-05-18T13:56:54.540224Z",
    "stats": {
        "available": 328629204375,
        "error": 262984,
        "steal": 0,
        "system": 353555000,
        "user": 73587753000,
        "utilization": 73941308000,
        "cores": [
            {
                "available": 328629204375,
                "error": 262984,
                "steal": 0,
                "system": 353555000,
                "user": 73587753000,
                "utilization": 73941308000,
                "targets": [
                    {
                        "operations": 2367792000
                    }, {
                        "operations": 4501467000
                    }
                ]
            }
        ]
    }
}
```

### Delete CPU Generator

Active CPU Generator can be deleted. Active statistic of deleted generator goes to inactive state.

```bash
curl --verbose --location --request DELETE \
    'http://<OPENPERF>/cpu-generators/0a565dac-5a7f-447b-40ec-5fa1f30fa4d0'
```

Response:
```
< HTTP/1.1 204 No Content
< Connection: Close
< Content-Length: 0
<
```

### Delete CPU Generator Result

Active CPU Generator Results cannot be deleted.

```bash
curl --verbose --location --request DELETE \
    'http://<OPENPERF>/cpu-generator-results/7286bd27-fa5d-4fea-51f0-4f6f92285321'
```

Response:
```
< HTTP/1.1 204 No Content
< Connection: Close
< Content-Length: 0
<
```

### Get CPU Info

```bash
curl --verbose --location --request GET \
    'http://<OPENPERF>/cpu-info'
```

Response:
```
< HTTP/1.1 200 OK
< Content-Type: application/json
< Connection: Close
< Content-Length: 56
<
{
    "architecture": "x86_64",
    "cache_line_size": 64,
    "cores": 4
}
```

## Dynamic Results field names

### Common statistics:
* **available** - available CPU time.
* **error** - difference between wanted and actual utilization.
* **steal** - time the hypervisor reported VM were blocked.
* **system** - system time used, e.g. kernel or system calls.
* **user** - user time used, e.g. generator load code.
* **utilization** - CPU time used.

### Per *core* statistics:

To access to the particular statitics of a configured core, use an appropriate core number instead of *N* below. The core number is the integer value from 0 to number core configuration blocks in the generator configuration minus 1. The order of cores are preserved. The core number refer to core number of system.

* **cores[*N*].available** - available CPU time.
* **cores[*N*].error** - difference between wanted and actual utilization.
* **cores[*N*].steal** - time the hypervisor reported VM were blocked.
* **cores[*N*].system** - system time used, e.g. kernel or system calls.
* **cores[*N*].user** - user time used, e.g. generator load code.
* **cores[*N*].utilization** - CPU time used.

### Per *target* statistics:

By analogy with *cores* use appropriate *target* number, instead of *T* below.

* **cores[*N*].targets[*T*].operations** - number of operations.
