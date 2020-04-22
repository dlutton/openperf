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
 * TrafficProtocol.h
 *
 * A traffic protocol definition for a traffic generator. At least one packet protocol must be set. 
 */

#ifndef TrafficProtocol_H_
#define TrafficProtocol_H_


#include "ModelBase.h"

#include "PacketProtocolIpv4.h"
#include "PacketProtocolMpls.h"
#include "PacketProtocolVlan.h"
#include "PacketProtocolEthernet.h"
#include "PacketProtocolUdp.h"
#include "PacketProtocolCustom.h"
#include "PacketProtocolIpv6.h"
#include "TrafficProtocol_modifiers.h"
#include "PacketProtocolTcp.h"

namespace swagger {
namespace v1 {
namespace model {

/// <summary>
/// A traffic protocol definition for a traffic generator. At least one packet protocol must be set. 
/// </summary>
class  TrafficProtocol
    : public ModelBase
{
public:
    TrafficProtocol();
    virtual ~TrafficProtocol();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    nlohmann::json toJson() const override;
    void fromJson(nlohmann::json& json) override;

    /////////////////////////////////////////////
    /// TrafficProtocol members

    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<TrafficProtocol_modifiers> getModifiers() const;
    void setModifiers(std::shared_ptr<TrafficProtocol_modifiers> value);
    bool modifiersIsSet() const;
    void unsetModifiers();
    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<PacketProtocolCustom> getCustom() const;
    void setCustom(std::shared_ptr<PacketProtocolCustom> value);
    bool customIsSet() const;
    void unsetCustom();
    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<PacketProtocolEthernet> getEthernet() const;
    void setEthernet(std::shared_ptr<PacketProtocolEthernet> value);
    bool ethernetIsSet() const;
    void unsetEthernet();
    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<PacketProtocolIpv4> getIpv4() const;
    void setIpv4(std::shared_ptr<PacketProtocolIpv4> value);
    bool ipv4IsSet() const;
    void unsetIpv4();
    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<PacketProtocolIpv6> getIpv6() const;
    void setIpv6(std::shared_ptr<PacketProtocolIpv6> value);
    bool ipv6IsSet() const;
    void unsetIpv6();
    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<PacketProtocolMpls> getMpls() const;
    void setMpls(std::shared_ptr<PacketProtocolMpls> value);
    bool mplsIsSet() const;
    void unsetMpls();
    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<PacketProtocolTcp> getTcp() const;
    void setTcp(std::shared_ptr<PacketProtocolTcp> value);
    bool tcpIsSet() const;
    void unsetTcp();
    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<PacketProtocolUdp> getUdp() const;
    void setUdp(std::shared_ptr<PacketProtocolUdp> value);
    bool udpIsSet() const;
    void unsetUdp();
    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<PacketProtocolVlan> getVlan() const;
    void setVlan(std::shared_ptr<PacketProtocolVlan> value);
    bool vlanIsSet() const;
    void unsetVlan();

protected:
    std::shared_ptr<TrafficProtocol_modifiers> m_Modifiers;
    bool m_ModifiersIsSet;
    std::shared_ptr<PacketProtocolCustom> m_Custom;
    bool m_CustomIsSet;
    std::shared_ptr<PacketProtocolEthernet> m_Ethernet;
    bool m_EthernetIsSet;
    std::shared_ptr<PacketProtocolIpv4> m_Ipv4;
    bool m_Ipv4IsSet;
    std::shared_ptr<PacketProtocolIpv6> m_Ipv6;
    bool m_Ipv6IsSet;
    std::shared_ptr<PacketProtocolMpls> m_Mpls;
    bool m_MplsIsSet;
    std::shared_ptr<PacketProtocolTcp> m_Tcp;
    bool m_TcpIsSet;
    std::shared_ptr<PacketProtocolUdp> m_Udp;
    bool m_UdpIsSet;
    std::shared_ptr<PacketProtocolVlan> m_Vlan;
    bool m_VlanIsSet;
};

}
}
}

#endif /* TrafficProtocol_H_ */
