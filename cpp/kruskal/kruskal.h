#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../graphs.h"

using std::ostream;
using std::priority_queue;
using std::unordered_map;
using std::unordered_set;
using std::vector;

using graphs::UndirectedEdge;
using graphs::Node;

namespace kruskal {

bool IsCyclicImpl(unordered_map<Node *,
        vector<Node *>> * adj_map, Node * start, Node * parent,
        unordered_set<Node *> * visited) {

    visited->insert(start);

    for (auto i : adj_map->find(start)->second) {
        if (i == parent) continue;
        if (visited->find(i) != visited->end()) return true;
        if (IsCyclicImpl(adj_map, i, start, visited)) return true;
    }

    return false;
}

bool IsCyclic(vector<UndirectedEdge *> * e) {

    // Begin by creating an adjacency map.
    auto adj_map = new unordered_map<Node *, vector<Node *>>();
    for (auto e : *e) {
        if (adj_map->find(e->a) == adj_map->end()) {
            adj_map->emplace(e->a, vector<Node *>({e->b}));
        } else {
            adj_map->find(e->a)->second.push_back(e->b);
        }

        if (adj_map->find(e->b) == adj_map->end()) {
            adj_map->emplace(e->b, vector<Node *>({e->a}));
        } else {
            adj_map->find(e->b)->second.push_back(e->a);
        }
    }

    auto visited = new unordered_set<Node *>();
    bool is_cyclic = IsCyclicImpl(adj_map, (*e)[0]->a, nullptr, visited);

    delete visited;
    delete adj_map;
    return is_cyclic;
}

vector<UndirectedEdge *> *
CalcKruskalMst(vector<Node *> * v, vector<UndirectedEdge *> * e) {

    auto comparator = [](UndirectedEdge * a, UndirectedEdge * b) {
        return a->weight > b->weight;
    };

    auto mst_edges = new vector<UndirectedEdge *>();
    auto edges = new priority_queue<UndirectedEdge *,
         std::vector<UndirectedEdge *>, decltype(comparator)>(comparator);

    // enqueue all edges
    for (auto edge : *e) {
        edges->push(edge);
    }

    while (!edges->empty()) {
        mst_edges->push_back(edges->top());
        edges->pop();

        if (IsCyclic(mst_edges)) mst_edges->pop_back();
    }

    delete edges;
    return mst_edges;
}

}       // namespace kruskal

#endif  // KRUSKAL_H
