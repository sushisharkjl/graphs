#ifndef PRIMS_H
#define PRIMS_H

#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

#include "../graphs.h"

using std::ostream;
using std::priority_queue;
using std::unordered_set;
using std::vector;

using graphs::UndirectedEdge;
using graphs::Node;

namespace prims {

vector<UndirectedEdge *> *
CalcPrimsMst(vector<Node *> * v, vector<UndirectedEdge *> * e, int begin=0) {

    auto comparator = [](UndirectedEdge * a, UndirectedEdge * b) {
        return a->weight > b->weight;
    };

    auto mst_edges = new vector<UndirectedEdge *>();
    auto visited_v = new unordered_set<Node *>();
    auto edges = new priority_queue<UndirectedEdge *,
         std::vector<UndirectedEdge *>, decltype(comparator)>(comparator);
    auto n_edges = v->size();
    visited_v->insert((*v)[begin]);

    // enqueue all edges
    for (auto edge : *e) {
        edges->push(edge);
    }

    // loop
    while (visited_v->size() != n_edges) {
        auto stack = vector<UndirectedEdge *>();
        auto edge = edges->top();
        edges->pop();
        while (!(( visited_v->find(edge->a) == visited_v->end() &&
                   visited_v->find(edge->b) != visited_v->end()) ||
                 ( visited_v->find(edge->a) != visited_v->end() &&
                   visited_v->find(edge->b) == visited_v->end()))) {
            stack.push_back(edge);
            edge = edges->top();
            edges->pop();
        }

        // Found edge.
        mst_edges->push_back(edge);
        if (visited_v->find(edge->a) == visited_v->end())
            visited_v->insert(edge->a);
        else visited_v->insert(edge->b);

        // Return the other edges.
        for (auto s : stack) edges->push(s);
    }

    delete visited_v;
    delete edges;
    return mst_edges;
}

}       // namespace prims

#endif  // PRIMS_H
