#pragma once

#include <cstddef>
#include <cstring>
#include <type_traits>

#include <clean-core/move.hh>
#include <clean-core/new.hh>

namespace cc::detail
{
template <class T, class SizeT = std::size_t>
void container_move_range(T* src, SizeT num, T* dest)
{
    if constexpr (std::is_trivially_move_constructible_v<T> && std::is_trivially_copyable_v<T>)
    {
        if (num > 0)
            std::memcpy(dest, src, sizeof(T) * num);
    }
    else
    {
        for (SizeT i = 0; i < num; ++i)
            new (placement_new, &dest[i]) T(cc::move(src[i]));
    }
}

template <class T, class SizeT = std::size_t>
void container_copy_range(T const* src, SizeT num, T* dest)
{
    if constexpr (std::is_trivially_copyable_v<T>)
    {
        if (num > 0)
            std::memcpy(dest, src, sizeof(T) * num);
    }
    else
    {
        for (SizeT i = 0; i < num; ++i)
            new (placement_new, &dest[i]) T(src[i]);
    }
}

template <class T, class SizeT = std::size_t>
void container_destroy_reverse(T* data, SizeT size, SizeT to_index = 0)
{
    if constexpr (!std::is_trivially_destructible_v<T>)
    {
        for (SizeT i = size; i > to_index; --i)
            data[i - 1].~T();
    }
}
}
