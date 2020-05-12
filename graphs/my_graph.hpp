/* my implementation of a graph structure
 * there are 2 ways to represent graphs
 * 1) edge list representation (for relativly sparse problems)
 * 2) conectivity matrix    (for dense graphs)
 * */

#include "my_list.hpp"

class my_graph
{
public:
    void add_vertex();
    void remove_vertex();
};

class my_vertex
{
public:
    my_vertex(int indentifcator) : id(indentifcator)
    {}

private:

    int id;
    my_list edge_list;
};


int test_graph(void)
{
    return 0;
}
