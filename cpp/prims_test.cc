#include "prims.h"

using prims::Node;
using prims::UndirectedEdge;
using prims::calc_prims_mst;

int main() {

    // Create nodes
    auto a = new Node{'A'};
    auto b = new Node{'B'};
    auto c = new Node{'C'};
    auto d = new Node{'D'};
    auto e = new Node{'E'};
    auto f = new Node{'F'};
    auto g = new Node{'G'};
    
    auto nodes = new vector<Node *>();
    nodes->push_back(a);
    nodes->push_back(b);
    nodes->push_back(c);
    nodes->push_back(d);
    nodes->push_back(e);
    nodes->push_back(f);
    nodes->push_back(g);

    // Edges
    auto e_a = new UndirectedEdge{a, 4, b};
    auto e_b = new UndirectedEdge{a, 8, c};
    auto e_c = new UndirectedEdge{c, 9, b};
    auto e_d = new UndirectedEdge{b, 8, d};
    auto e_e = new UndirectedEdge{c, 2, d};
    auto e_f = new UndirectedEdge{b, 10, e};
    auto e_g = new UndirectedEdge{e, 7, d};
    auto e_h = new UndirectedEdge{d, 9, f};
    auto e_i = new UndirectedEdge{f, 1, c};
    auto e_j = new UndirectedEdge{e, 5, f};
    auto e_k = new UndirectedEdge{e, 6, g};
    auto e_l = new UndirectedEdge{g, 2, f};

    auto edges = new vector<UndirectedEdge *>();
    edges->push_back(e_a);
    edges->push_back(e_b);
    edges->push_back(e_c);
    edges->push_back(e_d);
    edges->push_back(e_e);
    edges->push_back(e_f);
    edges->push_back(e_g);
    edges->push_back(e_h);
    edges->push_back(e_i);
    edges->push_back(e_j);
    edges->push_back(e_k);
    edges->push_back(e_l);

    auto mst = calc_prims_mst(nodes, edges);

    for (auto edge : *mst) {
        std::cout << *edge << std::endl;
    }

    while (!edges->empty()) {
        delete edges->back();
        edges->pop_back();
    } 
    while (!nodes->empty()) {
        delete nodes->back();
        nodes->pop_back();
    }

    return 0;
}
