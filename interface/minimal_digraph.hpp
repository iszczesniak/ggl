#ifndef MINIMAL_DIGRAPH_HPP
#define MINIMAL_DIGRAPH_HPP

#include <array>

// This is a minimal digraph.  It's minimal, because it has no
// properties associated with a vertex, and with an edge.  We only
// know if an edge exists.
//
// We store the graph information in a matrix with boolean values,
// because the graph can be dense.
//
// In such a graph we need a way to refer to a vertex, and it's going
// to be an unsigned integer.

template <std::size_t N>
using minimal_digraph = std::array<std::array<bool, N>, N>;


template <std::size_t N>
// We need the "auto &" return type (and not "auto") to prevent the
// array decay into a pointer.
auto &
vertexes(const minimal_digraph<N> &g)
{
  return g;
}

template <typename N>
auto &
edges(const std::array<bool, N>> &v)
{
  return v;
}
*/

#endif /* MINIMAL_DIGRAPH_HPP */
