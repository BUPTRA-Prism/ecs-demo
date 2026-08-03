#pragma once

#include "hash.h"
#include <atomic>
#include <cstddef>
#include <string_view>

namespace ecs {
    inline std::atomic<size_t> next_type_id = 0;

    template <typename T>
    size_t get_next_type_id() noexcept {
        static size_t id = next_type_id.fetch_add(1);
        return id;
    }

    template <typename T>
    constexpr std::string_view get_type_name() noexcept {
        #if defined(__clang__) || defined(__GNUC__)
            constexpr std::string_view func = __PRETTY_FUNCTION__;
            constexpr auto prefix = func.find("T = ");
            static_assert(prefix != std::string_view::npos, "Cannot parse type name (prefix)");
            constexpr auto suffix = func.find(']', prefix);
            static_assert(suffix != std::string_view::npos, "Cannot parse type name (suffix)");
            constexpr auto result = func.substr(prefix + 4, suffix - prefix - 4);
            static_assert(result.size() > 0, "Parsed type name is empty!");
            return result;

        #elif defined(_MSC_VER)
            constexpr std::string_view func = __FUNCSIG__;
            constexpr auto start = func.find('<');
            static_assert(start != std::string_view::npos, "Cannot parse type name (start)");
            constexpr auto end = func.find('>', start);
            static_assert(end != std::string_view::npos, "Cannot parse type name (end)");
            constexpr auto result = func.substr(start + 1, end - start - 1);
            static_assert(result.size() > 0, "Parsed type name is empty!");
            return result;

        #else
            #error "Unsupported compiler: cannot extract type name."

        #endif 
    }

    template <typename T>
    constexpr size_t get_type_hash() noexcept {
        return fnv1a_hash(get_type_name<T>());
    }
}