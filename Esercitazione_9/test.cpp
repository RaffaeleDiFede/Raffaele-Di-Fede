#include <iostream>
#include <map>
#include <vector>
#include "unidirected_graph2.h"
#include "unidirected_edge2.h"
#include "fifo.h"
#include "lifo.h"
#include "graph_visit.h"  
#include "dijkstra.h"   
#include "recursive_dfs.h"  

int main() {
    unidirected_graph<int> grafo;
    grafo.add_edge(1,2);
    grafo.add_edge(1,3);
    grafo.add_edge(1,4);
    grafo.add_edge(1,5);
    grafo.add_edge(2,3);
    grafo.add_edge(2,5);
    grafo.add_edge(3,4);
    grafo.add_edge(3,5);
    grafo.add_edge(4,5);

    // innanzitutto testiamo la visita in ampiezza
    std::cout << "visita in ampiezza con fifo:" << std::endl;
    fifo<int> coda; // creiamo il contenitore di politica fifo
    unidirected_graph<int> albero_bfs = graph_visit(grafo, 1, coda);
    
    std::cout << "archi dell'albero BFS:" << std::endl;
    for (const auto& arco : albero_bfs.all_edges()) {
        std::cout << "  " << arco << std::endl; 
    }


    // ora testiamo la visita in profondità 
    std::cout << "visità in profondità con lifo:" << std::endl;
    lifo<int> stack; // creiamo il contenitore di politica lifo
    unidirected_graph<int> albero_dfs_iter = graph_visit(grafo, 1, stack);
    
    std::cout << "Archi dell'albero DFS:" << std::endl;
    for (const auto& arco : albero_dfs_iter.all_edges()) {
        std::cout << "  " << arco << std::endl;
    }

    // ora testiamo la visita in profondità però ricorsiva
    std::cout << "visità in profondità ricorsiva:" << std::endl;
    unidirected_graph<int> albero_dfs_rec = recursive_dfs(grafo, 1);
    
    std::cout << "Archi dell'albero DFS ricorsivo:" << std::endl;
    for (const auto& arco : albero_dfs_rec.all_edges()) {
        std::cout << "  " << arco << std::endl;
    }

    // ora testiamo l'algoritmo di Dijkstra
    std::cout << "algoritmo di Dijkstra:" << std::endl;
    
    // Nonostante assumiamo peso 1 all'interno di dijkstra.h, la traccia 
    // richiede di passare comunque una mappa che associa ad ogni arco il suo peso
    std::map<unidirected_edge<int>, int> mappa_pesi;
    mappa_pesi[unidirected_edge<int>(1, 2)] = 1;
    mappa_pesi[unidirected_edge<int>(1, 3)] = 1;
    mappa_pesi[unidirected_edge<int>(2, 4)] = 1;
    mappa_pesi[unidirected_edge<int>(3, 4)] = 1;
    mappa_pesi[unidirected_edge<int>(4, 5)] = 1;
    mappa_pesi[unidirected_edge<int>(1, 4)] = 1;
    mappa_pesi[unidirected_edge<int>(2, 5)] = 1;
    mappa_pesi[unidirected_edge<int>(3, 5)] = 1; 


    // Calcoliamo il cammino minimo
    unidirected_graph<int> cammino_minimo = dijkstra(grafo, 1, mappa_pesi, 5);
    
    std::cout << "Archi che compongono il cammino minimo:" << std::endl;
    for (const auto& arco : cammino_minimo.all_edges()) {
        std::cout << "  " << arco << std::endl;
    }

}