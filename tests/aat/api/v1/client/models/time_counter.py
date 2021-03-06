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


class TimeCounter(object):
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
        'id': 'str',
        'name': 'str',
        'frequency': 'int',
        'priority': 'int'
    }

    attribute_map = {
        'id': 'id',
        'name': 'name',
        'frequency': 'frequency',
        'priority': 'priority'
    }

    def __init__(self, id=None, name=None, frequency=None, priority=None):  # noqa: E501
        """TimeCounter - a model defined in Swagger"""  # noqa: E501

        self._id = None
        self._name = None
        self._frequency = None
        self._priority = None
        self.discriminator = None

        self.id = id
        self.name = name
        self.frequency = frequency
        self.priority = priority

    @property
    def id(self):
        """Gets the id of this TimeCounter.  # noqa: E501

        Unique time counter identifier  # noqa: E501

        :return: The id of this TimeCounter.  # noqa: E501
        :rtype: str
        """
        return self._id

    @id.setter
    def id(self, id):
        """Sets the id of this TimeCounter.

        Unique time counter identifier  # noqa: E501

        :param id: The id of this TimeCounter.  # noqa: E501
        :type: str
        """
        self._id = id

    @property
    def name(self):
        """Gets the name of this TimeCounter.  # noqa: E501

        Time counter name  # noqa: E501

        :return: The name of this TimeCounter.  # noqa: E501
        :rtype: str
        """
        return self._name

    @name.setter
    def name(self, name):
        """Sets the name of this TimeCounter.

        Time counter name  # noqa: E501

        :param name: The name of this TimeCounter.  # noqa: E501
        :type: str
        """
        self._name = name

    @property
    def frequency(self):
        """Gets the frequency of this TimeCounter.  # noqa: E501

        Tick rate of the counter, in Hz.  # noqa: E501

        :return: The frequency of this TimeCounter.  # noqa: E501
        :rtype: int
        """
        return self._frequency

    @frequency.setter
    def frequency(self, frequency):
        """Sets the frequency of this TimeCounter.

        Tick rate of the counter, in Hz.  # noqa: E501

        :param frequency: The frequency of this TimeCounter.  # noqa: E501
        :type: int
        """
        self._frequency = frequency

    @property
    def priority(self):
        """Gets the priority of this TimeCounter.  # noqa: E501

        Priority determines which counter to use in situations where there are multiple counters available (higher number = higher priority). Priority is always positive.   # noqa: E501

        :return: The priority of this TimeCounter.  # noqa: E501
        :rtype: int
        """
        return self._priority

    @priority.setter
    def priority(self, priority):
        """Sets the priority of this TimeCounter.

        Priority determines which counter to use in situations where there are multiple counters available (higher number = higher priority). Priority is always positive.   # noqa: E501

        :param priority: The priority of this TimeCounter.  # noqa: E501
        :type: int
        """
        self._priority = priority

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
        if issubclass(TimeCounter, dict):
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
        if not isinstance(other, TimeCounter):
            return False

        return self.__dict__ == other.__dict__

    def __ne__(self, other):
        """Returns true if both objects are not equal"""
        return not self == other
