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
//
// There is also no object that describes an edge, but we need
// something that uniquelly describes an edge, i.e., the edge proxy.
// A pair of unsigned integers will be the proxy.

template <std::size_t N>
using vertex_data = std::array<bool, N>;

template <std::size_t N>
using minimal_digraph = std::array<vertex_data<N>, N>;

// In this graph there is no object that describes a vertex, but we
// need something that uniquelly describes a vertex, i.e., the vertex
// proxy.  An unsigned integer will be the proxy.

template <std::size_t N>
struct const_vertex_proxy
{
  typename minimal_digraph<N>::size_type m_index;
  const vertex_data<N> &m_vertex_data;

  const_vertex_proxy(typename minimal_digraph<N>::size_type index,
                     const vertex_data<N> &vertex_data):
    m_index(index), m_vertex_data(vertex_data)
  {
  }
};

// Const vertex iterator.  In the const iterator we have to store both
// the vertex index, and a const iterator.
//
// We need the vertex index, because we need to put it in the vertex
// proxy, when we dereference the iterator.
//
// We need the iterator, because we need to access the vertex_data.
template <std::size_t N>
struct const_vertex_iterator
{
  typename minimal_digraph<N>::size_type m_index;
  typename minimal_digraph<N>::const_iterator m_iterator;

  const_vertex_iterator
  (typename minimal_digraph<N>::size_type index,
   typename minimal_digraph<N>::const_iterator iterator)
  {
  }

  const_vertex_iterator &
  operator++()
  {
    ++m_index;
    ++m_iterator;
    return *this;
  }

  bool
  operator!=(const const_vertex_iterator &i) const
  {
    return m_index != i.m_index;
  }

  const_vertex_proxy<N>
  operator*() const
  {
    return const_vertex_proxy<N>(m_index, *m_iterator);
  }
};

// Const iterator range.
template <std::size_t N>
struct const_iterator_range
{
  const_vertex_iterator<N> m_begin;
  const_vertex_iterator<N> m_end;

  const_iterator_range(const_vertex_iterator<N> begin,
                       const_vertex_iterator<N> end):
    m_begin(begin), m_end(end)
  {
  };

  const_vertex_iterator<N>
  begin() const
  {
    return m_begin;
  }

  const_vertex_iterator<N>
  end() const
  {
    return m_end;
  }
};

// Return a range of vertex iterators.
template <std::size_t N>
auto
vertexes(const minimal_digraph<N> &g)
{
  return
    const_iterator_range<N>(const_vertex_iterator<N>(0, g.begin()),
                            const_vertex_iterator<N>(N, g.end()));
}

template <std::size_t N>
auto
get_index(const const_vertex_proxy<N> &i)
{
  return i.m_index;
}

#endif /* MINIMAL_DIGRAPH_HPP */
