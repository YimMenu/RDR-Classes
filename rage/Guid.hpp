#pragma once
#include <cstdint>

template <typename size_t Len>
class Guid {
public:
  static_assert(Len > 0);

  inline constexpr size_t size() const { return Len; }

  template <typename T> 
  inline constexpr T &At(size_t i) {
    static_assert(sizeof(T) <= sizeof(uint64_t));
    assert(i < Len);
    return *reinterpret_cast<T *>(&m_Buffer[i]);
  }

  inline constexpr uint32_t &operator[](size_t i) { return At<uint32_t>(i); }

  inline constexpr Guid() {
    for (size_t i = 0; i < size(); i++)
      m_Buffer[i] = 0;
  }

  template <typename size_t Len2>
  inline constexpr Guid<Len> &operator=(Guid<Len2> g) {
    for (size_t i = 0; i < std::min(size(), g.size()); i++)
      m_Buffer[i] = g[i];
    return *this;
  }

  template <typename size_t Len2> 
  inline constexpr Guid(Guid<Len2> g) {
    *this = g;
  }

  inline constexpr void *get() { return reinterpret_cast<void*>(&m_Buffer); }

private:
  alignas(8) uint64_t m_Buffer[Len];
};
static_assert(sizeof(Guid<5>) == sizeof(uint64_t) * 5);