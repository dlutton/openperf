#ifndef _LIB_PACKET_PROTOCOL_IPV6_HPP_
#define _LIB_PACKET_PROTOCOL_IPV6_HPP_

/**
 * IPv6 header for the packet header C++ Library
 *
 * This file is automatically generated by the library code generator.
 * Do not edit this file manually.
 **/

#include <type_traits>
#include "packet/type/endian.hpp"
#include "packet/type/ipv6_address.hpp"

namespace libpacket::protocol {

struct ipv6
{
    static constexpr size_t protocol_field_count = 8;
    static constexpr uint16_t protocol_length = 40;
    static constexpr std::string_view protocol_name = "ipv6";

    enum class field_name
    {
        none,
        version,
        traffic_class,
        flow_label,
        payload_length,
        next_header,
        hop_limit,
        source,
        destination,
    };

    type::endian::field<4> version_traffic_class_flow_label;
    type::endian::number<uint16_t> payload_length;
    type::endian::field<1> next_header;
    type::endian::number<uint8_t> hop_limit;
    type::ipv6_address source;
    type::ipv6_address destination;

    static enum ipv6::field_name get_field_name(std::string_view name) noexcept;
    static const std::type_info& get_field_type(field_name field) noexcept;

    template <typename Value>
    void set_field(enum field_name field, Value value) noexcept;
};

/**
 * IPv6 get functions
 **/

uint32_t get_ipv6_version(const ipv6& header) noexcept;
uint32_t get_ipv6_traffic_class(const ipv6& header) noexcept;
uint32_t get_ipv6_flow_label(const ipv6& header) noexcept;
uint16_t get_ipv6_payload_length(const ipv6& header) noexcept;
uint8_t get_ipv6_next_header(const ipv6& header) noexcept;
uint8_t get_ipv6_hop_limit(const ipv6& header) noexcept;
const type::ipv6_address& get_ipv6_source(const ipv6& header) noexcept;
const type::ipv6_address& get_ipv6_destination(const ipv6& header) noexcept;

/**
 * IPv6 set functions
 **/

void set_ipv6_defaults(ipv6& header) noexcept;
void set_ipv6_version(ipv6& header, uint32_t value) noexcept;
void set_ipv6_traffic_class(ipv6& header, uint32_t value) noexcept;
void set_ipv6_flow_label(ipv6& header, uint32_t value) noexcept;
void set_ipv6_payload_length(ipv6& header, uint16_t value) noexcept;
void set_ipv6_next_header(ipv6& header, uint8_t value) noexcept;
void set_ipv6_hop_limit(ipv6& header, uint8_t value) noexcept;
void set_ipv6_source(ipv6& header, const type::ipv6_address& value) noexcept;
void set_ipv6_source(ipv6& header, type::ipv6_address&& value) noexcept;
void set_ipv6_destination(ipv6& header, const type::ipv6_address& value) noexcept;
void set_ipv6_destination(ipv6& header, type::ipv6_address&& value) noexcept;

/**
 * IPv6 generic functions
 **/

template <typename Value>
void ipv6::set_field(enum ipv6::field_name field, Value value) noexcept
{
    switch (field) {
        case ipv6::field_name::version:
            if constexpr (std::is_convertible_v<Value, uint32_t>) {
                set_ipv6_version(*this, value);
            }
            break;
        case ipv6::field_name::traffic_class:
            if constexpr (std::is_convertible_v<Value, uint32_t>) {
                set_ipv6_traffic_class(*this, value);
            }
            break;
        case ipv6::field_name::flow_label:
            if constexpr (std::is_convertible_v<Value, uint32_t>) {
                set_ipv6_flow_label(*this, value);
            }
            break;
        case ipv6::field_name::payload_length:
            if constexpr (std::is_convertible_v<Value, uint16_t>) {
                set_ipv6_payload_length(*this, value);
            }
            break;
        case ipv6::field_name::next_header:
            if constexpr (std::is_convertible_v<Value, uint8_t>) {
                set_ipv6_next_header(*this, value);
            }
            break;
        case ipv6::field_name::hop_limit:
            if constexpr (std::is_convertible_v<Value, uint8_t>) {
                set_ipv6_hop_limit(*this, value);
            }
            break;
        case ipv6::field_name::source:
            if constexpr (std::is_convertible_v<Value, type::ipv6_address>) {
                set_ipv6_source(*this, value);
            }
            break;
        case ipv6::field_name::destination:
            if constexpr (std::is_convertible_v<Value, type::ipv6_address>) {
                set_ipv6_destination(*this, value);
            }
            break;
        default:
            break; /* no-op */
    }
}

}

#endif /* _LIB_PACKET_PROTOCOL_IPV6_HPP_ */
