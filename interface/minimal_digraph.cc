#include "minimal_digraph.hpp"

#include <iostream>

using namespace std;

int
main()
{
  minimal_digraph<2> g = {std::array<bool, 2>{true, false},
                          std::array<bool, 2>{true, false}};

  for(const auto &v: vertexes(g))
    cout << "vertex index = " << get_index(v) << endl;
}
