#pragma once

#include <cstddef>
#include <string_view>

constexpr size_t FNV_BASIS = 0xcbf29ce484222325ULL;
constexpr size_t FNV_PRIME = 0x100000001b3ULL;

constexpr size_t fnv1a_hash(const char* str, size_t len) noexcept {
    size_t hash = FNV_BASIS;
    for (size_t i = 0; i < len; ++i) {
        hash ^= size_t(str[i]);
        hash *= FNV_PRIME;
    }
    return hash;
}

constexpr size_t fnv1a_hash(std::string_view str) noexcept {
    return fnv1a_hash(str.data(), str.size());
}

class hashed_string {
private:
    std::string_view m_str;
    size_t m_hash;
    
public:
    template <size_t N>
    constexpr hashed_string(const char (&str)[N]) : m_str(str, N - 1), m_hash(fnv1a_hash(m_str)) {}
    constexpr hashed_string(std::string_view str) : m_str(str), m_hash(fnv1a_hash(str)) {}
    
    constexpr std::string_view getStr() const noexcept { return m_str; }
    constexpr size_t getHash() const noexcept { return m_hash; }

    constexpr bool operator==(const hashed_string& other) const noexcept {
        return m_hash == other.m_hash;
    }
    constexpr bool operator!=(const hashed_string& other) const noexcept {
        return m_hash != other.m_hash;
    }
};
