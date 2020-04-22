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


class TrafficLoadRate(object):
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
        'period': 'str',
        'value': 'int'
    }

    attribute_map = {
        'period': 'period',
        'value': 'value'
    }

    def __init__(self, period=None, value=None):  # noqa: E501
        """TrafficLoadRate - a model defined in Swagger"""  # noqa: E501

        self._period = None
        self._value = None
        self.discriminator = None

        self.period = period
        self.value = value

    @property
    def period(self):
        """Gets the period of this TrafficLoadRate.  # noqa: E501

        unit of time for the rate  # noqa: E501

        :return: The period of this TrafficLoadRate.  # noqa: E501
        :rtype: str
        """
        return self._period

    @period.setter
    def period(self, period):
        """Sets the period of this TrafficLoadRate.

        unit of time for the rate  # noqa: E501

        :param period: The period of this TrafficLoadRate.  # noqa: E501
        :type: str
        """
        self._period = period

    @property
    def value(self):
        """Gets the value of this TrafficLoadRate.  # noqa: E501

        number of packets per period  # noqa: E501

        :return: The value of this TrafficLoadRate.  # noqa: E501
        :rtype: int
        """
        return self._value

    @value.setter
    def value(self, value):
        """Sets the value of this TrafficLoadRate.

        number of packets per period  # noqa: E501

        :param value: The value of this TrafficLoadRate.  # noqa: E501
        :type: int
        """
        self._value = value

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
        if issubclass(TrafficLoadRate, dict):
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
        if not isinstance(other, TrafficLoadRate):
            return False

        return self.__dict__ == other.__dict__

    def __ne__(self, other):
        """Returns true if both objects are not equal"""
        return not self == other