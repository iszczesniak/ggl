# Interface

There are many graph types, ways of implementing them, and storing and
processing associated data.  Therefore, there is no single and easy
way of implementing a graph.

We want to have a minimal, simple, and intuitive graph intefrace that
will allow to work with any graph implementation, and be sufficient
for any algorithm.

We should be able to implement a graph in any way, and our
implementation is going to be useful for any algorithm as long as we
stick to the interface.

The basic functional requirements are:

* iterate over the graph vertexes,

* iterate over the out edges of a vertex.

Furthermore, we want to have a way of accessing data about vertexes,
and edges.  Some data we want to store in a graph, in a data structure
that represents a vertex or an edge.

A programmer wants to understand what's going on.  Ideally, we would
like to provide a type that defines a vertex, and a type that defines
an edge.  But that might not be necessary, since we a vertex or an
edge might not store any data.

Here are a few things to consider:

* should the graph be directed or not?

* should a graph be static or dynamic?  Is it implemented with
  data structures which size doesn't change?

* should it be a graph or a multigraph?

* should it be a sparse or dense graph?

Usually, a vertex or an edge has properties, such as cost, or
capacity.  Here we have such choices:

* should the properties be built into a graph?

* should the properties be built into a vertex or an edge?

* should the properties be stored in a vertex or an edge object?

# Examples of graph implementations

Here we study a few interesting graph models, and their
implementations.  Before we start abstracting, let's have a look at
some use cases.

## A minimal digraph implementation

A vertex and an edge store no information.  We only have a set of
vertexes, and a set of directed edges.  We want to be able to find out
the neighbors of a vertex, i.e., the vertex reachable from a vertex
with out edges.

We want to model a graph, not a multigraph, i.e., there is only one
edge allowed between two vertexes.

## A minimal graph implementation

A vertex and an edge store no information.  We have a set of vertexes
and undirected edges.

# Plan

Let's work out a minimal interface that will be enough for the graph
implementations above, and be enough for the Dijkstra algorithm.

We might not have an object for a vertex or an edge, yet we need to
refer to such a vertex or an edge somehow.  Therefore we need a
*descriptor*.  The descriptor should allow us access properties of a
vertex.

# Iterator must be standalone

The vertex (or an edge) iterator must be standalone, so that we can
use it loops like that:

for (const auto &v: vertexes(g))
  // Do sth with v, which is a vertex object or a vertex proxy

This implies that an iterator must be dereferenceable, i.e., when you
apply the * operator, you must get a vertex (or an edge) object or
proxy.

# Vertex and edge descriptor

We might want to be able to uniquelly identify a vertex or an edge,
and for this we need a descriptor, which we could use to:

* address elements in a container which stores some property of an
  edge or a vertex,

* get the vertex or edge object in a graph.

Descriptors, however, and not required for every graph.

# Allow for const properties.

Some properties (like a weight of an edge or vertex) should be const
(only initialized).  For instance, once a network is loaded, we should
not modify the weight of an edge.
