#include "minimal_digraph.hpp"

#include <iostream>

using namespace std;

/*

template <std::size_t N>
void
print(const minimal_digraph<N> &g)
{
  for(const auto &v: vertexes(g))
    for(const auto &e: edges(v))
      std::cout << source(e) << " -> " << target(e) << std::endl;
}
*/

int
main()
{
  minimal_digraph<2> g = {std::array<bool, 2>{true, false},
                          std::array<bool, 2>{true, false}};
}
