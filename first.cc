#include "first.hpp"

#include <iostream>

using namespace std;

template <typename T>
void
print(const T &g)
{
  for(const auto &v: vertexes(g))
    for(const auto &e: edges(v))
      std::cout << source(e) << " -> " << target(e) << std::endl;
}

template <typename T>
void
test_int()
{
  first<T, 3> g = {{{0, 1}},
                   {{1, 0}, {1, 2}},
                   {{2, 0}, {2, 1}, {2, 3}}};

  print(g);
}

template <typename T>
void
test_txt()
{
  first<T, 3> g = {{{"a", "b"}},
                   {{"b", "a"}, {"b", "c"}},
                   {{"c", "a"}, {"c", "b"}, {"c", "c"}}};

  print(g);
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
