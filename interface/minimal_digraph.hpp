#ifndef MINIMAL_DIGRAPH_HPP
#define MINIMAL_DIGRAPH_HPP

#include <array>
#include <utility>

// This is a minimal digraph.  It's minimal, because it has no
// properties associated with a vertex, and with an edge.  We only
// know if an edge exists.  The graph is static: the number of
// vertexes doesn't grow.
//
// We store the graph information in a matrix with boolean values,
// because the graph can be dense, and because it's not a
// multidigraph.  The matrix is an array of arrays.

template <std::size_t N>
using vertex_data = std::array<bool, N>;

template <std::size_t N>
using minimal_digraph = std::array<vertex_data<N>, N>;

// -------------------------------------------------------------------
// Vertex implementation
// -------------------------------------------------------------------

// In this graph there is no object that describes a vertex, but we
// need something to represent a vertex: a vertex proxy.
//
// The vertex proxy should hold the information needed to use the
// vertex.  We want to be able to:
//
// * get the descriptor (index) of the vertex, and
//
// * iterate over the out edges of the vertex.

template <std::size_t N>
struct const_vertex_proxy
{
  typename minimal_digraph<N>::size_type m_index;
  const vertex_data<N> &m_data;

  const_vertex_proxy(typename minimal_digraph<N>::size_type index,
                     const vertex_data<N> &data):
    m_index(index), m_data(data)
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
struct const_vertex_iter
{
  typename minimal_digraph<N>::size_type m_index;
  typename minimal_digraph<N>::const_iterator m_iter;

  const_vertex_iter
  (typename minimal_digraph<N>::size_type index,
   typename minimal_digraph<N>::const_iterator iter):
    m_index(index), m_iter(iter)
  {
  }

  const_vertex_iter &
  operator++()
  {
    ++m_index;
    ++m_iter;
    return *this;
  }

  bool
  operator!=(const const_vertex_iter &i) const
  {
    return m_index != i.m_index;
  }

  const_vertex_proxy<N>
  operator*() const
  {
    return const_vertex_proxy<N>(m_index, *m_iter);
  }
};

// Const iterator range.

template <std::size_t N>
struct const_iter_range
{
  const_vertex_iter<N> m_begin;
  const_vertex_iter<N> m_end;

  const_iter_range(const_vertex_iter<N> begin,
                   const_vertex_iter<N> end):
    m_begin(begin), m_end(end)
  {
  };

  const_vertex_iter<N>
  begin() const
  {
    return m_begin;
  }

  const_vertex_iter<N>
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
    const_iter_range<N>(const_vertex_iter<N>(0, g.begin()),
                        const_vertex_iter<N>(N, g.end()));
}

template <std::size_t N>
auto
get_descriptor(const const_vertex_proxy<N> &i)
{
  return i.m_index;
}

// -------------------------------------------------------------------
// Edge implementation
// -------------------------------------------------------------------

// In this graph there is no object that describes an edge, but we
// need something to represent an edge: the edge proxy.
//
// The edge proxy should hold the information needed to use the edge.
// We want to be able to:
//
// * get the edge source and target.

template <std::size_t N>
struct const_edge_proxy
{
  typename minimal_digraph<N>::size_type m_source;
  typename minimal_digraph<N>::size_type m_target;

  const_vertex_proxy(typename minimal_digraph<N>::size_type source,
                     typename minimal_digraph<N>::size_type target):
    m_target(target), m_source(source)
  {
  }
};

// Const edge iterator stores:
//
// * the source index, which we put into the edge proxy, when
//   we dereference this iterator,
//
// * the target index we iterate with,
//
// * the const iterator to the vertex_data.

template <std::size_t N>
struct const_edge_iter
{
  // The source vertex: this 
  typename minimal_digraph<N>::size_type m_source;
  typename minimal_digraph<N>::size_type m_target;
  // Iterator to the vertex data of the source vertex.
  typename vertex_data<N>::const_iterator m_iter;

  const_edge_iter
  (typename minimal_digraph<N>::size_type source,
   typename minimal_digraph<N>::size_type target,
   typename minimal_digraph<N>::const_iterator iter):
    m_source(source), m_target(target), m_iter(iter)
  {
  }

  const_edge_iter &
  operator++()
  {
    ++m_index;
    ++m_iter;
    return *this;
  }

  bool
  operator!=(const const_edge_iter &i) const
  {
    return m_target != i.m_target && m_source != i.m_source;
  }

  const_edge_proxy<N>
  operator*() const
  {
    return const_edge_proxy<N>(m_source, m_target);
  }
};

// Const iterator range.

template <std::size_t N>
struct const_edge_iter_range
{
  const_edge_iter<N> m_begin;
  const_edge_iter<N> m_end;

  const_iter_range(const_edge_iter<N> begin,
                   const_edge_iter<N> end):
    m_begin(begin), m_end(end)
  {
  };

  const_edge_iter<N>
  begin() const
  {
    return m_begin;
  }

  const_edge_iter<N>
  end() const
  {
    return m_end;
  }
};

// Return a range of vertex iterators.

template <std::size_t N>
auto
edges(const vertex_proxy<N> &v)
{
  return
    const_edge_iter_range<N>(const_edge_iter<N>(v.m_source, 0,
                                                v.m_data.begin()),
                             const_edge_iter<N>(v.m_source, N,
                                                v.m_data.end()));
}

#endif /* MINIMAL_DIGRAPH_HPP */
