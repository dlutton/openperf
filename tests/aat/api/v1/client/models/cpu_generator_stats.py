# coding: utf-8

"""
    OpenPerf API

    REST API interface for OpenPerf  # noqa: E501

    OpenAPI spec version: 1
    Contact: support@spirent.com
    Generated by: https://github.com/swagger-api/swagger-codegen.git
"""


import pprint
import re  # noqa: F401

import six


class CpuGeneratorStats(object):
    """NOTE: This class is auto generated by the swagger code generator program.

    Do not edit the class manually.
    """

    """
    Attributes:
      swagger_types (dict): The key is attribute name
                            and the value is attribute type.
      attribute_map (dict): The key is attribute name
                            and the value is json key in definition.
    """
    swagger_types = {
        'available': 'int',
        'utilization': 'int',
        'system': 'int',
        'user': 'int',
        'steal': 'int',
        'error': 'int',
        'cores': 'list[CpuGeneratorCoreStats]'
    }

    attribute_map = {
        'available': 'available',
        'utilization': 'utilization',
        'system': 'system',
        'user': 'user',
        'steal': 'steal',
        'error': 'error',
        'cores': 'cores'
    }

    def __init__(self, available=None, utilization=None, system=None, user=None, steal=None, error=None, cores=None):  # noqa: E501
        """CpuGeneratorStats - a model defined in Swagger"""  # noqa: E501

        self._available = None
        self._utilization = None
        self._system = None
        self._user = None
        self._steal = None
        self._error = None
        self._cores = None
        self.discriminator = None

        self.available = available
        self.utilization = utilization
        self.system = system
        self.user = user
        if steal is not None:
            self.steal = steal
        self.error = error
        self.cores = cores

    @property
    def available(self):
        """Gets the available of this CpuGeneratorStats.  # noqa: E501

        The total amount of CPU time available  # noqa: E501

        :return: The available of this CpuGeneratorStats.  # noqa: E501
        :rtype: int
        """
        return self._available

    @available.setter
    def available(self, available):
        """Sets the available of this CpuGeneratorStats.

        The total amount of CPU time available  # noqa: E501

        :param available: The available of this CpuGeneratorStats.  # noqa: E501
        :type: int
        """
        self._available = available

    @property
    def utilization(self):
        """Gets the utilization of this CpuGeneratorStats.  # noqa: E501

        The amount of CPU time used  # noqa: E501

        :return: The utilization of this CpuGeneratorStats.  # noqa: E501
        :rtype: int
        """
        return self._utilization

    @utilization.setter
    def utilization(self, utilization):
        """Sets the utilization of this CpuGeneratorStats.

        The amount of CPU time used  # noqa: E501

        :param utilization: The utilization of this CpuGeneratorStats.  # noqa: E501
        :type: int
        """
        self._utilization = utilization

    @property
    def system(self):
        """Gets the system of this CpuGeneratorStats.  # noqa: E501

        The amount of system time used, e.g. kernel or system calls  # noqa: E501

        :return: The system of this CpuGeneratorStats.  # noqa: E501
        :rtype: int
        """
        return self._system

    @system.setter
    def system(self, system):
        """Sets the system of this CpuGeneratorStats.

        The amount of system time used, e.g. kernel or system calls  # noqa: E501

        :param system: The system of this CpuGeneratorStats.  # noqa: E501
        :type: int
        """
        self._system = system

    @property
    def user(self):
        """Gets the user of this CpuGeneratorStats.  # noqa: E501

        The amount of user time used, e.g. openperf code  # noqa: E501

        :return: The user of this CpuGeneratorStats.  # noqa: E501
        :rtype: int
        """
        return self._user

    @user.setter
    def user(self, user):
        """Sets the user of this CpuGeneratorStats.

        The amount of user time used, e.g. openperf code  # noqa: E501

        :param user: The user of this CpuGeneratorStats.  # noqa: E501
        :type: int
        """
        self._user = user

    @property
    def steal(self):
        """Gets the steal of this CpuGeneratorStats.  # noqa: E501

        The amount of time the hypervisor reported our virtual cores were blocked  # noqa: E501

        :return: The steal of this CpuGeneratorStats.  # noqa: E501
        :rtype: int
        """
        return self._steal

    @steal.setter
    def steal(self, steal):
        """Sets the steal of this CpuGeneratorStats.

        The amount of time the hypervisor reported our virtual cores were blocked  # noqa: E501

        :param steal: The steal of this CpuGeneratorStats.  # noqa: E501
        :type: int
        """
        self._steal = steal

    @property
    def error(self):
        """Gets the error of this CpuGeneratorStats.  # noqa: E501

        The difference between intended and actual CPU utilization  # noqa: E501

        :return: The error of this CpuGeneratorStats.  # noqa: E501
        :rtype: int
        """
        return self._error

    @error.setter
    def error(self, error):
        """Sets the error of this CpuGeneratorStats.

        The difference between intended and actual CPU utilization  # noqa: E501

        :param error: The error of this CpuGeneratorStats.  # noqa: E501
        :type: int
        """
        self._error = error

    @property
    def cores(self):
        """Gets the cores of this CpuGeneratorStats.  # noqa: E501

        Statistics of the CPU cores (in the order they were specified in generator configuration)  # noqa: E501

        :return: The cores of this CpuGeneratorStats.  # noqa: E501
        :rtype: list[CpuGeneratorCoreStats]
        """
        return self._cores

    @cores.setter
    def cores(self, cores):
        """Sets the cores of this CpuGeneratorStats.

        Statistics of the CPU cores (in the order they were specified in generator configuration)  # noqa: E501

        :param cores: The cores of this CpuGeneratorStats.  # noqa: E501
        :type: list[CpuGeneratorCoreStats]
        """
        self._cores = cores

    def to_dict(self):
        """Returns the model properties as a dict"""
        result = {}

        for attr, _ in six.iteritems(self.swagger_types):
            value = getattr(self, attr)
            if isinstance(value, list):
                result[attr] = list(map(
                    lambda x: x.to_dict() if hasattr(x, "to_dict") else x,
                    value
                ))
            elif hasattr(value, "to_dict"):
                result[attr] = value.to_dict()
            elif isinstance(value, dict):
                result[attr] = dict(map(
                    lambda item: (item[0], item[1].to_dict())
                    if hasattr(item[1], "to_dict") else item,
                    value.items()
                ))
            else:
                result[attr] = value
        if issubclass(CpuGeneratorStats, dict):
            for key, value in self.items():
                result[key] = value

        return result

    def to_str(self):
        """Returns the string representation of the model"""
        return pprint.pformat(self.to_dict())

    def __repr__(self):
        """For `print` and `pprint`"""
        return self.to_str()

    def __eq__(self, other):
        """Returns true if both objects are equal"""
        if not isinstance(other, CpuGeneratorStats):
            return False

        return self.__dict__ == other.__dict__

    def __ne__(self, other):
        """Returns true if both objects are not equal"""
        return not self == other
