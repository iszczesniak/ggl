#ifndef MINIMAL_DIGRAPH2_HPP
#define MINIMAL_DIGRAPH2_HPP

#include <boost/range.hpp>

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
//
// This implementation differs from minimal_digraph in that
// vertex_data stores also the index of the vertex.

template <std::size_t N>
using vertex_data = std::pair<typename std::array<bool, N>::size_type,
                              std::array<bool, N>>;

template <std::size_t N>
using minimal_digraph2 = std::array<vertex_data<N>, N>;

// -------------------------------------------------------------------
// Vertex implementation
// -------------------------------------------------------------------

// Return a range of vertex iterators.

template <std::size_t N>
auto
vertexes(const minimal_digraph2<N> &g)
{
  return boost::make_iterator_range(g.begin(), g.end());
}

template <std::size_t N>
auto
get_descriptor(const vertex_data<N> &i)
{
  return i.first;
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
  typename minimal_digraph2<N>::size_type m_source;
  typename minimal_digraph2<N>::size_type m_target;

  const_edge_proxy(typename minimal_digraph2<N>::size_type source,
                   typename minimal_digraph2<N>::size_type target):
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
  typename minimal_digraph2<N>::size_type m_source;
  typename minimal_digraph2<N>::size_type m_target;
  // Iterator of the neighbor vector of the source vertex.
  typename vertex_data<N>::second_type::const_iterator m_iter;

  const_edge_iter
  (typename minimal_digraph2<N>::size_type source,
   typename minimal_digraph2<N>::size_type target,
   typename vertex_data<N>::second_type::const_iterator iter):
    m_source(source), m_target(target), m_iter(iter)
  {
  }

  const_edge_iter &
  operator++()
  {
    ++m_target;
    ++m_iter;
    adjust(*this);
    return *this;
  }

  bool
  operator!=(const const_edge_iter &i) const
  {
    return m_target != i.m_target || m_source != i.m_source;
  }

  const_edge_proxy<N>
  operator*() const
  {
    return const_edge_proxy<N>(m_source, m_target);
  }
};

template <std::size_t N>
void
adjust(const_edge_iter<N> &i)
{
  while(!*i.m_iter && i.m_target != N)
    ++i;
}

// Const iterator range.

template <std::size_t N>
struct const_edge_iter_range
{
  const_edge_iter<N> m_begin;
  const_edge_iter<N> m_end;

  const_edge_iter_range(const_edge_iter<N> begin,
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
edges(const vertex_data<N> &v)
{
  const_edge_iter<N> begin(v.first, 0, v.second.begin());
  adjust(begin);

  return
    const_edge_iter_range<N>(begin,
                             const_edge_iter<N>(v.first, N,
                                                v.second.end()));
}

template <std::size_t N>
auto
get_source(const const_edge_proxy<N> &e)
{
  return e.m_source;
}

template <std::size_t N>
auto
get_target(const const_edge_proxy<N> &e)
{
  return e.m_target;
}

#endif /* MINIMAL_DIGRAPH2_HPP */
