#include "packetio/transmit_table.tcc"
#include "packetio/workers/dpdk/tx_source.hpp"

namespace openperf::packetio {

template class transmit_table<dpdk::tx_source>;

}
