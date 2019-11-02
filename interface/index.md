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

# Descriptor: standalone or dependent?

A descriptor of a vertex (or an edge) can be standalone or dependent.

Standalone: you can get a vertex (or an edge) object without using the
graph object.  For instance, a descriptor can be a pointer to a vertex
object, and so we don't need the graph object.

Dependent: you can get a vertex (or an edge) object, but you have to
know the graph object.  For instance, if a vertex descriptor is an
unsigned integer, than you need the graph object to locate the vertex
object.