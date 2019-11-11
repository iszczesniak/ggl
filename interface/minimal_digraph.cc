#include "minimal_digraph.hpp"

#include <iostream>

using namespace std;

int
main()
{
  minimal_digraph<2> g = {std::array<bool, 2>{true, false},
                          std::array<bool, 2>{true, false}};

  for(const auto &v: vertexes(g))
    {
      cout << "vertex descriptor = " << get_descriptor(v) << endl;

      for(const auto &e: edges(v))
        {
          cout << "edge source = " << get_source(e) << endl;
          cout << "edge target = " << get_target(e) << endl;
        }
    }
}
