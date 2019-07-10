#include <cassert>
#include "lwip/sys.h"

#include "packetio/stack/tcpip.h"
#include "packetio/stack/dpdk/tcpip_mbox.h"

namespace icp::packetio::dpdk {

sys_mbox_t tcpip_mbox::init()
{
    m_mbox = std::make_unique<sys_mbox>();
    return (m_mbox.get());
}

void tcpip_mbox::fini()
{
    m_mbox.reset();
}

sys_mbox_t tcpip_mbox::get()
{
    return (m_mbox.get());
}

}

sys_mbox_t icp::packetio::tcpip::mbox()
{
    return (icp::packetio::dpdk::tcpip_mbox::instance().get());
}
