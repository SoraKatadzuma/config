#ifndef SK_TYPES_HPP
#define SK_TYPES_HPP
#include <cstdint>
#include <cwchar>
#include <memory>

namespace sk {


template<typename TData> using owner  = std::unique_ptr<TData>;
template<typename TData> using shared = std::unique_ptr<TData>;
template<typename TData> using mutptr = TData*;
template<typename TData> using immptr = const TData*;

using int8    = std::int8_t;
using int16   = std::int16_t;
using int32   = std::int32_t;
using int64   = std::int64_t;
using uint8   = std::uint8_t;
using uint16  = std::uint16_t;
using uint32  = std::uint32_t;
using uint64  = std::uint64_t;
using float32 = float;
using float64 = double;
using cstring = immptr<char>;
using wstring = immptr<wchar_t>;
using rawptr  = mutptr<void>;


} // namespace sk

#endif // SK_TYPES_HPP