# Interface

We want to have a minimal, simple, and intuitive graph intefrace that
will:

* represent any graph, regardless of the graph implementation,

* be sufficient for any algorithm.

We should be able to implement a graph in any way, and our
implementation is going to be useful as long as we stick to the
interface.

The basic functional requirements are:

* iterate over the graph vertexes,

* iterate over the out edges of a vertex.

Furthermore, we want to have a way of accessing data about vertexes,
and edges.

Some data we want to store in a graph, in a data structure that
represents a vertex or an edge.
