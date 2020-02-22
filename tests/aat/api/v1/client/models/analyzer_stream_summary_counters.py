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


class AnalyzerStreamSummaryCounters(object):
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
        'min': 'int',
        'max': 'int',
        'total': 'int',
        'std_dev': 'int'
    }

    attribute_map = {
        'min': 'min',
        'max': 'max',
        'total': 'total',
        'std_dev': 'std_dev'
    }

    def __init__(self, min=None, max=None, total=None, std_dev=None):  # noqa: E501
        """AnalyzerStreamSummaryCounters - a model defined in Swagger"""  # noqa: E501

        self._min = None
        self._max = None
        self._total = None
        self._std_dev = None
        self.discriminator = None

        if min is not None:
            self.min = min
        if max is not None:
            self.max = max
        self.total = total
        if std_dev is not None:
            self.std_dev = std_dev

    @property
    def min(self):
        """Gets the min of this AnalyzerStreamSummaryCounters.  # noqa: E501

        Minimum value  # noqa: E501

        :return: The min of this AnalyzerStreamSummaryCounters.  # noqa: E501
        :rtype: int
        """
        return self._min

    @min.setter
    def min(self, min):
        """Sets the min of this AnalyzerStreamSummaryCounters.

        Minimum value  # noqa: E501

        :param min: The min of this AnalyzerStreamSummaryCounters.  # noqa: E501
        :type: int
        """
        self._min = min

    @property
    def max(self):
        """Gets the max of this AnalyzerStreamSummaryCounters.  # noqa: E501

        Maximum value  # noqa: E501

        :return: The max of this AnalyzerStreamSummaryCounters.  # noqa: E501
        :rtype: int
        """
        return self._max

    @max.setter
    def max(self, max):
        """Sets the max of this AnalyzerStreamSummaryCounters.

        Maximum value  # noqa: E501

        :param max: The max of this AnalyzerStreamSummaryCounters.  # noqa: E501
        :type: int
        """
        self._max = max

    @property
    def total(self):
        """Gets the total of this AnalyzerStreamSummaryCounters.  # noqa: E501

        Sum of all received values  # noqa: E501

        :return: The total of this AnalyzerStreamSummaryCounters.  # noqa: E501
        :rtype: int
        """
        return self._total

    @total.setter
    def total(self, total):
        """Sets the total of this AnalyzerStreamSummaryCounters.

        Sum of all received values  # noqa: E501

        :param total: The total of this AnalyzerStreamSummaryCounters.  # noqa: E501
        :type: int
        """
        self._total = total

    @property
    def std_dev(self):
        """Gets the std_dev of this AnalyzerStreamSummaryCounters.  # noqa: E501

        Standard deviation of received values  # noqa: E501

        :return: The std_dev of this AnalyzerStreamSummaryCounters.  # noqa: E501
        :rtype: int
        """
        return self._std_dev

    @std_dev.setter
    def std_dev(self, std_dev):
        """Sets the std_dev of this AnalyzerStreamSummaryCounters.

        Standard deviation of received values  # noqa: E501

        :param std_dev: The std_dev of this AnalyzerStreamSummaryCounters.  # noqa: E501
        :type: int
        """
        self._std_dev = std_dev

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

        return result

    def to_str(self):
        """Returns the string representation of the model"""
        return pprint.pformat(self.to_dict())

    def __repr__(self):
        """For `print` and `pprint`"""
        return self.to_str()

    def __eq__(self, other):
        """Returns true if both objects are equal"""
        if not isinstance(other, AnalyzerStreamSummaryCounters):
            return False

        return self.__dict__ == other.__dict__

    def __ne__(self, other):
        """Returns true if both objects are not equal"""
        return not self == other
