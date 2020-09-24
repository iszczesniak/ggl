#include "second.hpp"

#include <iostream>

using namespace std;

template <typename T>
void
print_graph(const T &g)
{
  for(const auto &v: vertexes(g))
    for(const auto &e: out_edges(v))
      std::cout << source(e) << " -> " << target(e) << std::endl;
}

template <typename T>
void
test_int()
{
  second<T, 3> g = {{{{0, 1}},
                    {{1, 0}, {1, 2}},
                    {{2, 0}, {2, 1}, {2, 3}}}};

  print_graph(g);
}

template <typename T>
void
test_txt()
{
  second<T, 3> g = {{{{"a", "b"}},
                    {{"b", "a"}, {"b", "c"}},
                    {{"c", "a"}, {"c", "b"}, {"c", "c"}}}};

  print_graph(g);
}

int
main()
{
  test_int<int>();
  test_int<unsigned>();
  test_int<long>();
  test_txt<const char *>();
  test_txt<std::string>();
}
