#include <iostream>
#include <vector>
#include <set>
#include "unidirected_edge.h"
#include "unidirected_graph.h"

int main() {
    // 1. Creazione del Grafo G1 (Foglia + Ciclo)
    unidirected_graph<int> g1;
    g1.add_edge(0, 1); 
    g1.add_edge(0, 2); 
    g1.add_edge(0, 3); 
    g1.add_edge(0, 4);
    g1.add_edge(2, 3);
    g1.add_edge(4, 5);
    g1.add_edge(5, 6);

    std::cout << "grafo 1" << std::endl;
    std::cout << "Numero archi: " << g1.all_edges().size();
    for (const auto& arco1 : g1.all_edges()) std::cout << arco1 << " ";
    std::cout << "\n" << std::endl;

    unidirected_graph<int> g2;
    g2.add_edge(2, 3);
    g2.add_edge(3, 4);
    g2.add_edge(4, 2);
    g2.add_edge(5, 5); 

    std::cout << "grafo 2" << std::endl;
    for (const auto& arco2 : g2.all_edges()) std::cout << arco2 << " ";
    std::cout << "\n" << std::endl;

    unidirected_graph<int> g3 = g1 - g2;

    std::cout << "g3=g1-g2" << std::endl;
    std::cout << "Archi rimasti: ";
    for (const auto& arco3 : g3.all_edges()) 
    std::cout << arco3 << " ";
    std::cout << "\n" << std::endl;

    if (g1.all_edges().size() > 0) {
        unidirected_edge<int> primo = g1.edge_at(0);
        int indice = g1.edge_number(primo);
        std::cout << "\nTest Indici: L'arco " << primo << " ha indice " << indice << std::endl;
    }

    return 0;
}