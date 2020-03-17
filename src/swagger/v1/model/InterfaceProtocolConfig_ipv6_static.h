/**
* OpenPerf API
* REST API interface for OpenPerf
*
* OpenAPI spec version: 1
* Contact: support@spirent.com
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/swagger-api/swagger-codegen.git
* Do not edit the class manually.
*/
/*
 * InterfaceProtocolConfig_ipv6_static.h
 *
 * Static configuration parameters
 */

#ifndef InterfaceProtocolConfig_ipv6_static_H_
#define InterfaceProtocolConfig_ipv6_static_H_


#include "ModelBase.h"

#include <string>

namespace swagger {
namespace v1 {
namespace model {

/// <summary>
/// Static configuration parameters
/// </summary>
class  InterfaceProtocolConfig_ipv6_static
    : public ModelBase
{
public:
    InterfaceProtocolConfig_ipv6_static();
    virtual ~InterfaceProtocolConfig_ipv6_static();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    nlohmann::json toJson() const override;
    void fromJson(nlohmann::json& json) override;

    /////////////////////////////////////////////
    /// InterfaceProtocolConfig_ipv6_static members

    /// <summary>
    /// IPv6 address
    /// </summary>
    std::string getAddress() const;
    void setAddress(std::string value);
        /// <summary>
    /// Prefix length
    /// </summary>
    int32_t getPrefixLength() const;
    void setPrefixLength(int32_t value);
        /// <summary>
    /// Default gateway
    /// </summary>
    std::string getGateway() const;
    void setGateway(std::string value);
    bool gatewayIsSet() const;
    void unsetGateway();

protected:
    std::string m_Address;

    int32_t m_Prefix_length;

    std::string m_Gateway;
    bool m_GatewayIsSet;
};

}
}
}

#endif /* InterfaceProtocolConfig_ipv6_static_H_ */
