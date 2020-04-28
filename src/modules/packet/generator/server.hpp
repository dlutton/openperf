#ifndef _OP_PACKET_GENERATOR_SERVER_HPP_
#define _OP_PACKET_GENERATOR_SERVER_HPP_

#include <map>
#include <vector>

#include "core/op_core.h"
#include "packet/generator/api.hpp"
#include "packet/generator/source.hpp"
#include "packetio/internal_client.hpp"

namespace openperf::packet::generator::api {

class server
{
    core::event_loop& m_loop;
    packetio::internal::api::client m_client;
    std::unique_ptr<void, op_socket_deleter> m_socket;

    /*
     * Source's know their own id's, so we don't need to store
     * them in a map.  Just use a (sorted) vector so we don't
     * store id's twice.
     */
    using source_value_type = packetio::packets::generic_source;
    std::vector<source_value_type> m_sources;

    /*
     * Results don't know their id's, so we store them in an associative
     * container with the id as the key. Futhermore, we (the server)
     * own the results.  We just let the source borrow them for a while.
     */
    using result_value_type = source_result;
    using result_value_ptr = std::unique_ptr<result_value_type>;
    using result_map = std::map<core::uuid, result_value_ptr>;

    /* result id --> result */
    result_map m_results;

public:
    server(void* context, core::event_loop& loop);

    reply_msg handle_request(const request_list_generators&);
    reply_msg handle_request(const request_create_generator&);
    reply_msg handle_request(const request_delete_generators&);

    reply_msg handle_request(const request_get_generator&);
    reply_msg handle_request(const request_delete_generator&);

    reply_msg handle_request(const request_start_generator&);
    reply_msg handle_request(const request_stop_generator&);

    reply_msg handle_request(const request_list_generator_results&);
    reply_msg handle_request(const request_delete_generator_results&);
    reply_msg handle_request(const request_get_generator_result&);
    reply_msg handle_request(const request_delete_generator_result&);

    reply_msg handle_request(const request_list_tx_flows&);
    reply_msg handle_request(const request_get_tx_flow&);
};

}

#endif /* _OP_PACKET_GENERATOR_SERVER_HPP_ */