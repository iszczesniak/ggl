#ifndef FIRST_HPP
#define FIRST_HPP

#include <cstddef>
#include <forward_list>
// We need to include iterator for the std::begin and std::end
// functions, which a user will need in their foreach loops.
#include <iterator>
#include <utility>

// The graph is defined as a C-style array.  The template parameters
// are the type of the edge weight, and the number of nodes.
//
// The number of vertices cannot change, because their number is
// determined at compile time.  The edges, however, can be added or
// removed, because they are stored in a forward_list.
template <typename T, std::size_t N>
using first = std::forward_list<std::pair<T, T>>[N];

template <typename T, std::size_t N>
// We need the "auto &" return type (and not "auto") to prevent the
// array decay into a pointer.
auto &
vertexes(const first<T, N> &g)
{
  return g;
}

template <typename T, std::size_t N>
// We need the "auto &" return type (and not "auto") to prevent the
// array decay into a pointer.
auto &
vertexes(first<T, N> &g)
{
  return g;
}

template <typename T>
auto &
edges(const std::forward_list<std::pair<T, T>> &v)
{
  return v;
}

template <typename T>
auto &
edges(std::forward_list<std::pair<T, T>> &v)
{
  return v;
}

template <typename T>
auto &
source(const std::pair<T, T> &e)
{
  return e.first;
}

template <typename T>
auto &
source(std::pair<T, T> &e)
{
  return e.first;
}

template <typename T>
auto &
target(const std::pair<T, T> &e)
{
  return e.second;
}

template <typename T>
auto &
target(std::pair<T, T> &e)
{
  return e.second;
}

#endif // FIRST_HPP
