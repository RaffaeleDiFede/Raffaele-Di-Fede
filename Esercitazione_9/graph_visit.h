#pragma once
#include <list>
#include <set>
#include <map>
#include "unidirected_graph2.h"
#include "unidirected_edge2.h"
#include "fifo.h"
#include "lifo.h"


// implemento una funzione template graph_visit che 
// 1) prende in input due parametri che sono il grafo da visitare e il nodo sorgente 
// 2) prende un parametro template che specifica il tipo del contenitore da usare per effettuare la visita
// 3) restituisce un oggetto di tipo grafo contenente l'albero risultante dalla visita

template <typename T, typename container>
unidirected_graph<T> graph_visit(const unidirected_graph<T>& grafo, const T& nodo_sorgente, container& contenitore) {
    
    // ora, in base al contenitore passato come parametro, effettuo una visita in ampiezza o una visita in profondità
    // cioè l'idea è quella che se il contenitore è di tipo fifo allora effettuo una visita in ampiezza, mentre se è un contenitore di tipo lifo effettuo una visita in profondità
    // inoltre non specificheremo mai se il contenitore è di tipo fifo o lifo, ma sarà semplicemente un parametro contenitore che ha tre attributi
    
    unidirected_graph<T> albero; // questo grafo contienel'albero risultante della visita
    std::set<T> nodi_visitati; // questo set (così evitiamo ripetizioni) contiene i nodi già visitati 
    std::map<T, T> nodi_predecessori; // questa mappa contiene i nodi predecessori di ogni nodo visitato

    // inserisco il nodo sorgente nel contenitore
    contenitore.put(nodo_sorgente);

    while (contenitore.empty() == false) {
        // prendo il prossimo nodo dal contenitore
        T nodo_corrente=contenitore.get();
        if (nodi_visitati.find(nodo_corrente) != nodi_visitati.end()) {
            continue;                                                   // se il nodo corrente è già dentro l'insieme dei nodi visitati allora passiamo al prossimo

        }

        nodi_visitati.insert(nodo_corrente); // cio+ se non è già stato visitato mettilo tra i nodi visitati

        if (nodo_corrente != nodo_sorgente) {
            albero.add_edge(nodi_predecessori[nodo_corrente], nodo_corrente); // se il nodo corrente non è il nodo sorgente allora aggiungo un arco tra il nodo predecessore del nodo corrente e il nodo corrente
        }

        // ora prendi tutti i vicini del nodo corrente, se non sono ancora stati visitati allora salvo il nodo corrente come predecessore del vicino e inserisco il vicino nel contenitore
        for (const T& vicino:grafo.neighbours(nodo_corrente)) {
            if (nodi_visitati.find(vicino) == nodi_visitati.end() ) {
                nodi_predecessori[vicino] = nodo_corrente;
                contenitore.put(vicino);
            }
        }
        
    }
    return albero;

};

