#include <string>
#include <vector>
#include <utility>

struct vertex
{
  // The properties of a vertex.
  std::string name;

  // If a user wants, the cost of reaching that node can be stored
  // here.
  int weight;

  std::vector<edge> edges;
};

struct edge
{
  // The source node of the edge.
  vertex &src;
  // The destination node of the edge.
  vertex &trg;

  // The weight of an edge.
  int wgt;

  edge(vertex &src, vertex &dst, int wgt):
    src(src), dst(dst), wgt(wgt)
  {
  }
};

// A directed graph implemented with an adjacency list.
struct adjacency_list
{
  // The vector of vertexes.
  std::vector<vertex> vertexes;
};

add_vertex(adjacency_list &g)
{
  vertexes.push_back();
}

auto
vertexes(const adjacency_list &g)
{
  return std::make_pair(g.vertexes.begin(), g.vertexes.end());
}

auto
out_edges(const const adjacency_list &g,
          const adjacency_list::vertex_iterator v)
{
  auto const &l = 
    return std::make_pair(l.begin(), l.end());
}
