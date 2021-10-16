#### Representation Alternatives

##### 1-adjacency matrix

This representation need huge space cost and don't allow parallel edges. 

##### 2-only edges

Implement `adj()` would involve examining all the edges.

##### 3-adjacency lists

Space-O(V+E), `add_edge`-O(1), `adj()`-O(1).

##### 4-adjacency sets

Use `set` instead of bag and support `delete_edge` and `contain_edge`.

The hashset will have a high performance and BinaryTree have a lower space cost.

##### 5-Named Vertex

Use `ST` instead of array and support `add_vertex` and `delete_vertex` with name.
