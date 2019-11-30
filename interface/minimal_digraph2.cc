#include "minimal_digraph2.hpp"

#include <iostream>

using namespace std;

int
main()
{
  minimal_digraph2<2> g = {vertex_data<2>(0, std::array<bool, 2>{true, false}),
                           vertex_data<2>(1, std::array<bool, 2>{true, false})};

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
