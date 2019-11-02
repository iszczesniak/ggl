#ifndef MINIMAL_DIGRAPH_HPP
#define MINIMAL_DIGRAPH_HPP

#include <array>
#include <utility>

// This is a minimal digraph.  It's minimal, because it has no
// properties associated with a vertex, and with an edge.  We only
// know if an edge exists.
//
// We store the graph information in a matrix with boolean values,
// because the graph can be dense, and because it's not a
// multidigraph.  The matrix is an array of arrays.  We can consider
// the nested array as the vertex object.
//
// In such a graph there is no object that describes a vertex, but we
// need something that uniquelly describes a vertex, i.e., the vertex
// descriptor.  An unsigned integer is the vertex descriptor.
//
// There is also no object that describes an edge, but we need
// something that uniquelly describes an edge, i.e., the edge
// descriptor.  A pair of vertex descriptors is the edge descriptor.

template <std::size_t N>
using minimal_digraph = std::array<std::array<bool, N>, N>;

// Const vertex iterator
template <std::size_t N>
using const_vertex_iterator =
  std::pair<minimal_digraph<N>::size_type,
            minimal_digraph<N>::const_iterator>;

// Return a range of vertex iterators.
template <std::size_t N>
auto
vertexes(minimal_digraph<N> &g)
{
  return make_iterator_range(cost_vertex_iterator<N>(0, g.begin());
}

template <typename N>
auto &
edges(const std::array<bool, N>> &v)
{
  return v;
}

#endif /* MINIMAL_DIGRAPH_HPP */
