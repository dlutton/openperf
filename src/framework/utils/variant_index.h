#ifndef _ICP_UTILS_VARIANT_INDEX_H_
#define _ICP_UTILS_VARIANT_INDEX_H_

#include <variant>

namespace icp::utils {

/*
 * Convenience template to extract the index of a specific type inside a
 * variant.
 *
 * Note: All variant types must be unique.
 */

template <typename VariantType, typename T, std::size_t index = 0>
constexpr size_t variant_index() {
    if constexpr (std::is_same_v<std::variant_alternative_t<index, VariantType>, T>) {
        return (index);
    } else {
        return (variant_index<VariantType, T, index + 1>());
    }
}

}

#endif /* _ICP_UTILS_VARIANT_INDEX_H_ */
