#pragma once
#include <list>
#include <vector>
#include <set>
#include <map>
#include "unidirected_graph2.h"
#include "unidirected_edge2.h"
#include "fifo.h"
#include "lifo.h"

// qui dobbiamo implementare l'algoritmo di dijkstra per trovare il percorso più breve tra due nodi
// in input prendiamo la lista di adiacenza del grafo, il nodo sorgente, i pesi degli archi e il nodo di arrivo
// per questa implementazione assumiamo che tutti i pesi degli archi siano esattamente uguali a 1
// inoltre vogliamo implementare questo algoritmo utilizzando una struttura dati grafo dell'esercitazione precedente
// nonostante i pesi siano sempre 1, inizializzo una mappa che associa ad ogni arco il suo peso
// voglio restituire l'albero che rappresenta il cammino minimo

template<typename T>
unidirected_graph<T> dijkstra(const unidirected_graph<T>& grafo, const T& nodo_sorgente, const std::map<unidirected_edge<T>, int>& peso, const T& nodo_arrivo) {

    unidirected_graph<T> albero; // questo grafo conterrà l'albero risultante dalla visita
    std::map<T, T> nodi_predecessori; // questa mappa ha come chiave un nodo e come valore il suo predecessore
    std::map<T, int> distanza; // questa mappa contiene la distanza dal nodo sorgente ad ogni nodo visitato
    std::vector<T> coda_prioritaria; // questa coda prioritaria contiene i nodi da visitare ordinate in base alla distanza dal nodo sorgente

    // inizializzo la distanza di tutti i nodi che non sono il nodo sorgente ad un valore molto alto
    for (const auto& nodo:grafo.all_nodes()) {
        if (nodo == nodo_sorgente) {
            distanza[nodo]=0;
        }
        else {
            distanza[nodo]=100000;
        }
        coda_prioritaria.push_back(nodo); // inserisco tutti i nodi nella coda prioritaria
        }

    // ora inseriamo il nodo sorgente nella coda prioritaria
    coda_prioritaria.push_back(nodo_sorgente);

    // finchè la coda prioritaria non è vuota, prendo il nodo con la distanza dal nodo sorgente minore e lo visito
    while (coda_prioritaria.empty()==false) {
        
        // ora cerchiamo nel vettore l'indice del nodo che ha la distanza dal nodo sorgente minore
        int indice_nodo_corrente=0;
        for (int i=1; i<coda_prioritaria.size(); i++) {                  
            if (distanza[coda_prioritaria[i]] < distanza[coda_prioritaria[indice_nodo_corrente]]) {
                indice_nodo_corrente=i;
            }
        }

        // ora che abbiamo trovato il nodo con distanza minima salviamo in posizione nodo_corrente il nodo in questione 
        T nodo_corrente=coda_prioritaria[indice_nodo_corrente];
        int distanza_nodo_corrente=distanza[nodo_corrente];   // e salviamo la distanza del nodo corrente dal nodo sorgente

        // e ora lo togliamo dalla coda prioritaria in posizione indice nodo corrente 
        coda_prioritaria.erase(coda_prioritaria.begin()+indice_nodo_corrente);

        if (nodo_corrente==nodo_arrivo) {
            break; // cioè se il nodo corrente è il nodo di arrivo allora abbiamo trovato il cammino minimo
        }

        // ora esploriamo i vicini
        for (const T& vicino:grafo.neighbours(nodo_corrente)) {
            unidirected_edge<T> arco_corrente(nodo_corrente, vicino); // cioè creo un arco tra il nodo corrente e il vicino che esploro
            int peso_arco=1; // abbiamo assunto che il peso di ogni arco sia 1;

            // qui facciamo il rilassamento
            if (distanza[vicino]>distanza_nodo_corrente+peso_arco) {
                distanza[vicino]=distanza_nodo_corrente+peso_arco; // aggiorno la distanza del nodo vicino come la somma tra la distanza del nodo corrente e il peso dell'arco 
                nodi_predecessori[vicino]=nodo_corrente; // aggiorno il predecessore che ora è il nodo corrente
            }
        }
    }

    // ora dobbiamo ricosturire il cammino minimo a partire dal nodo di arrivo e risalendo i predecessori fino ad arrivare al nodo sorgente dato che come return un grafo
    T corrente = nodo_arrivo; // partiamo dal nodo di arrivo e andiamo a ritrovo

    while (corrente != nodo_sorgente) {
        T predecessore = nodi_predecessori[corrente]; // cioè diciamo che il predecessore del nodo corrente è il nodo che è stato salvato nella mappa dei predecessori
        albero.add_edge(predecessore, corrente); // aggiungo un arco tra il predecessore e il nodo corrente 
        corrente=predecessore; // aggiorno il nodo corrente che ora diventa il suo predecessore
    }

    return albero;

};


