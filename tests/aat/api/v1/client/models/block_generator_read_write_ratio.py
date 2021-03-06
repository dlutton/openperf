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


class BlockGeneratorReadWriteRatio(object):
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
        'writes': 'int',
        'reads': 'int'
    }

    attribute_map = {
        'writes': 'writes',
        'reads': 'reads'
    }

    def __init__(self, writes=None, reads=None):  # noqa: E501
        """BlockGeneratorReadWriteRatio - a model defined in Swagger"""  # noqa: E501

        self._writes = None
        self._reads = None
        self.discriminator = None

        if writes is not None:
            self.writes = writes
        if reads is not None:
            self.reads = reads

    @property
    def writes(self):
        """Gets the writes of this BlockGeneratorReadWriteRatio.  # noqa: E501


        :return: The writes of this BlockGeneratorReadWriteRatio.  # noqa: E501
        :rtype: int
        """
        return self._writes

    @writes.setter
    def writes(self, writes):
        """Sets the writes of this BlockGeneratorReadWriteRatio.


        :param writes: The writes of this BlockGeneratorReadWriteRatio.  # noqa: E501
        :type: int
        """
        self._writes = writes

    @property
    def reads(self):
        """Gets the reads of this BlockGeneratorReadWriteRatio.  # noqa: E501


        :return: The reads of this BlockGeneratorReadWriteRatio.  # noqa: E501
        :rtype: int
        """
        return self._reads

    @reads.setter
    def reads(self, reads):
        """Sets the reads of this BlockGeneratorReadWriteRatio.


        :param reads: The reads of this BlockGeneratorReadWriteRatio.  # noqa: E501
        :type: int
        """
        self._reads = reads

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
        if issubclass(BlockGeneratorReadWriteRatio, dict):
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
        if not isinstance(other, BlockGeneratorReadWriteRatio):
            return False

        return self.__dict__ == other.__dict__

    def __ne__(self, other):
        """Returns true if both objects are not equal"""
        return not self == other
