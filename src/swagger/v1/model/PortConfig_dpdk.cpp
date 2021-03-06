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


#include "PortConfig_dpdk.h"

namespace swagger {
namespace v1 {
namespace model {

PortConfig_dpdk::PortConfig_dpdk()
{
    m_Auto_negotiation = false;
    m_Speed = 0L;
    m_SpeedIsSet = false;
    m_Duplex = "";
    m_DuplexIsSet = false;
    
}

PortConfig_dpdk::~PortConfig_dpdk()
{
}

void PortConfig_dpdk::validate()
{
    // TODO: implement validation
}

nlohmann::json PortConfig_dpdk::toJson() const
{
    nlohmann::json val = nlohmann::json::object();

    val["auto_negotiation"] = m_Auto_negotiation;
    if(m_SpeedIsSet)
    {
        val["speed"] = m_Speed;
    }
    if(m_DuplexIsSet)
    {
        val["duplex"] = ModelBase::toJson(m_Duplex);
    }
    

    return val;
}

void PortConfig_dpdk::fromJson(nlohmann::json& val)
{
    setAutoNegotiation(val.at("auto_negotiation"));
    if(val.find("speed") != val.end())
    {
        setSpeed(val.at("speed"));
    }
    if(val.find("duplex") != val.end())
    {
        setDuplex(val.at("duplex"));
        
    }
    
}


bool PortConfig_dpdk::isAutoNegotiation() const
{
    return m_Auto_negotiation;
}
void PortConfig_dpdk::setAutoNegotiation(bool value)
{
    m_Auto_negotiation = value;
    
}
int64_t PortConfig_dpdk::getSpeed() const
{
    return m_Speed;
}
void PortConfig_dpdk::setSpeed(int64_t value)
{
    m_Speed = value;
    m_SpeedIsSet = true;
}
bool PortConfig_dpdk::speedIsSet() const
{
    return m_SpeedIsSet;
}
void PortConfig_dpdk::unsetSpeed()
{
    m_SpeedIsSet = false;
}
std::string PortConfig_dpdk::getDuplex() const
{
    return m_Duplex;
}
void PortConfig_dpdk::setDuplex(std::string value)
{
    m_Duplex = value;
    m_DuplexIsSet = true;
}
bool PortConfig_dpdk::duplexIsSet() const
{
    return m_DuplexIsSet;
}
void PortConfig_dpdk::unsetDuplex()
{
    m_DuplexIsSet = false;
}

}
}
}

