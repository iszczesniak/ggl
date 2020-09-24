#ifndef SECOND_HPP
#define SECOND_HPP

#include <array>
#include <forward_list>
#include <utility>

// The graph defined at compile time.  The number of vertices cannot
// change, because their number is given at compile time.  The edges,
// however, can be added or removed, because they are stored in a
// forward_list.
template <typename T, int N>
using second = std::array<std::forward_list<std::pair<T, T>>, N>;

template <typename T>
auto
vertexes(const T &g)
{
  return g;
}

template <typename T>
auto
out_edges(const T &v)
{
  return v;
}

template <typename T>
T
source(const std::pair<T, T> &e)
{
  return e.second;
}

template <typename T>
T
target(const std::pair<T, T> &e)
{
  return e.second;
}

#endif // SECOND_HPP
