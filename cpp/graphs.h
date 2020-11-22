#ifndef GRAPHS_H
#define GRAPHS_H

#include <iostream>
using std::ostream;

namespace graphs {

struct Node {
    char label;
};

struct UndirectedEdge {
    Node *a;
    int weight;
    Node *b;
};

ostream & operator<<(ostream & s, UndirectedEdge & e) {
    s << e.a->label << "--(" << e.weight << ")--" << e.b->label;
    return s;
}

ostream & operator<<(ostream & s, Node & n) {
    s << n.label;
    return s;
}

}       // namespace graphs

#endif  // GRAPHS_H
