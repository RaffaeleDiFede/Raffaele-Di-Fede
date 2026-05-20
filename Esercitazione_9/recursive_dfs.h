#pragma once
#include <list>
#include <set>
#include <map>
#include "unidirected_graph2.h"
#include "unidirected_edge2.h"
#include "fifo.h"
#include "lifo.h"


// ok ora implementiamo recursive dfs() che prende in input due parametri: un grafo da visitare e il nodo sorgente
// e restituisce un grafo contenente l'albero risultante dalla visita
// usando la versione ricorsiva della DFS per visitare il grafo

template<typename T>
void esplora_nodo(const T& nodo_corrente, const unidirected_graph<T>& grafo, std::set<T>& nodi_visitati, unidirected_graph<T>& albero) {
    nodi_visitati.insert(nodo_corrente); // aggiungo il nodo corrente ai nodi visitati

    for (const T& vicino:grafo.neighbours(nodo_corrente)) {
        if (nodi_visitati.find(vicino) == nodi_visitati.end()) {
            albero.add_edge(nodo_corrente, vicino); // cioè se il vicino non è stato visitato allora aggiungo un arco tra il nodo corrente e il vicino nell'albero

            // ora c'è la chiamata ricorsiva con la quale esploro il vicino
            esplora_nodo(vicino, grafo, nodi_visitati, albero);
        }
    }
};


template<typename T>
unidirected_graph<T> recursive_dfs(const unidirected_graph<T>& grafo, const T& nodo_sorgente) {
    unidirected_graph<T> albero; // questo grafo contiene l'albero risultante della visita
    std::set<T> nodi_visitati; // questo set contiene i nodi già visitati

    esplora_nodo(nodo_sorgente, grafo, nodi_visitati, albero); // qui faccio una chiamata ad una funzione di supporto che esplora un nodo e salva i suoi vicini
    return albero;
};


