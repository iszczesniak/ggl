#ifndef MINIMAL_DIGRAPH_HPP
#define MINIMAL_DIGRAPH_HPP

#include <boost/range.hpp>

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
// proxy.  An unsigned integer will be the proxy.
//
// There is also no object that describes an edge, but we need
// something that uniquelly describes an edge, i.e., the edge proxy.
// A pair of unsigned integers will be the proxy.

template <std::size_t N>
using vertex_data = std::array<bool, N>;

template <std::size_t N>
using minimal_digraph = std::array<vertex_data<N>, N>;

template <std::size_t N>
using const_vertex_proxy = std::pair<minimal_digraph<N>::size_type,
                                     const vertex_data<N> &>;

// Const vertex iterator.  In the const iterator we have to store both
// the vertex index, and a const iterator.
//
// We need the vertex index, because we need to put it in the vertex
// proxy, when we dereference the iterator.
//
// We need the iterator, because we need to access the vertex_data.
template <std::size_t N>
using const_vertex_iterator =
  std::pair<minimal_digraph<N>::size_type,
            minimal_digraph<N>::const_iterator>;

// Return a range of vertex iterators.
template <std::size_t N>
auto
vertexes(const minimal_digraph<N> &g)
{
  return
    boost::make_iterator_range(const_vertex_iterator<N>(0, g.begin()),
                               const_vertex_iterator<N>(N, g.end()));
}

template <std::size_t N>
const_vertex_iterator &
operator++(const_vertex_iterator<N> &i)
{
  ++i.first;
  ++i.second;
  return i;
}

template <std::size_t N>
const_vertex_proxy
operator*(const const_vertex_iterator<N> &i)
{
  return const_vertex_proxy(i.first, *i.second);
}

template <std::size_t N>
minimal_digraph<N>::size_type
get_index(const const_vertex_iterator<N> &i)
{
  return i.first;
}

#endif /* MINIMAL_DIGRAPH_HPP */
