#include "packetio/generic_workers.h"
#include "packetio/workers/dpdk/worker_controller.h"

namespace icp::packetio::workers {

std::unique_ptr<generic_workers> make(void* context, driver::generic_driver& driver)
{
    return (std::make_unique<generic_workers>(dpdk::worker_controller(context, driver)));
}

}
