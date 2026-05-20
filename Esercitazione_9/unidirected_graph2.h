#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include "unidirected_edge2.h"


// ora devo implementare una classe unidirected_graph, conterrà una lista di nodi e una lista di archi 
template <typename T>
class unidirected_graph {
    private:
        // per ogni nodo consideriamo la sua lista di adiacenza cioè la lista dei suoi vicini
        // per rappresentarla utilizzo una mappa, la chiave è il nodo mentre il valore è un set che contiene i nodi adiacenti
        std::map<T, std::set<T>> lista_adiacenza_;

        // poi mi servirà un insieme di archi salvato come un set, preferisco i set così da eliminare i duplicati
        std::set<unidirected_edge<T>> archi_;

    public:
        // implemento il costruttore di default
        unidirected_graph()=default;

        // ora implemento un costruttore di copia
        unidirected_graph(const unidirected_graph<T>& other) 
            : lista_adiacenza_(other.lista_adiacenza_),          // copio la lista di adiacenza
            archi_(other.archi_)                                 // copio la lista di archi
            {}
            

        // ora implemento il metodo neighbours() che dato un nodo restituisce la lista dei suoi vicini
        // l'idea è quella di restituire un set che contiene i nodi adiacenti al nodo in questione
        std::set<T> neighbours(const T& nodo) const {
            auto iteratore = lista_adiacenza_.find(nodo);  // cioè cerco il nodo nella lista di adiacenza, il metodo find restituisce un iteratore: se il nodo è presente nella lista di adiacenza allora l'iteratore punta alla posizione del nodo, altrimento l'iteratore punterà alla fine della lista di adiacenza
            if (iteratore != lista_adiacenza_.end()) {
                return iteratore->second;
            }                                        // cioè se il nodo è presente nella lista di adiacenza allora restituisco sotto forma di set tutti i suoi vicini che sono contenuti nella parte "second" dell'iteratore 
            return std::set<T>();                    // se non trovo il nodo nella lista di adiacenza allora restuisco un set vuoto
        }
            

        // ora implemento il metodo add_edge() che dato un arco lo aggiunge al grafo
        // cioè praticamente chiamo due nodi e aggiungo l'uno alla lista di adiacenza dell'altro, infine aggiungo l'arco alla lista di tutti gli archi del grafo
        // avendo usato un set come struttura dati non mi devo nemmeno preoccupare di aver inseito più volte lo stesso arco
        void add_edge(T nodo1, T nodo2) {
            unidirected_edge<T> arco(nodo1, nodo2); // come prima cosa creo un arco tra i due nodi che prendo in input
            lista_adiacenza_[nodo1].insert(nodo2);  // aggiorno la lista di adiacenza del nodo 1
            lista_adiacenza_[nodo2].insert(nodo1);  // aggiorno la lista di adiacenza del nodo 2
            archi_.insert(arco);                    // come ultima cosa aggiungo l'arco appena creato al set di archi del grafo
        }


        // ora implemento il metodo all_edges() che restituisce la lista di tutti gli archi del grafo
        // l'idea è quella di restuire un vettore che contiene tutti gli archi del grafo
        std::vector<unidirected_edge<T>> all_edges() const {
            return std::vector<unidirected_edge<T>>(archi_.begin(), archi_.end()); // restituisco un vettore che contiene tutti gli archi del grafo, prendo tutti gli elementi del set di archi e li inserisco in un vettore
        }

        
        // ora implemento il metodo all_nodes() che resituisce la lista di tutti i nodi del grafo
        // itero sulla lista di adiacenza e prendo tutte le chiavi che rappresentano i nodi 
        // forse è meglio restiuire un set invece di un vettore così da evitare ripetizioni
        std::set<T> all_nodes() const {
            std::set<T> nodi_totali;                         // creo un set che conterrà tutti i nodi del grafo
            for (const auto& coppia : lista_adiacenza_) {
                nodi_totali.insert(coppia.first);            // inserisco in nodi_totali la prima parte della coppia nella lista di adiacenza
            }
            return nodi_totali;
        }


        // ora implemento il metodo edge_number() che dato un arco ne restiuisce la sua numerazione all'interno del grafo
        int edge_number(const unidirected_edge<T>& arco) const {
            int numero_arco=0;                                            // assegno il numero 0 al primo arco del grafo
            for (const auto& arco_corrente : archi_) {     // itero su titti gli archi del grafo 
                if (arco_corrente == arco) {
                    return numero_arco;         // se l'arco corrente è uguale all'arco che prendo in input allora restituisco il numero dell'arco corrente
                }
                numero_arco = numero_arco+1;                            // altrimenti vado avanti e incremento il numero dell'arco corrente
            }
            return -1;                                                    // se in input do un arco che non è presente nel grafo allora restituisco -1
        }


        // ora implemento il metodo edge_at() che dato un numero d'arco restituisce il corrispondente oggetto arco all'interno del grafo
        unidirected_edge<T> edge_at(int numero_arco) const{
            int numero_arco_corrente=0;                                   // assegno il numero 0 al primo arco del grafo
            for (const auto& arco_corrente : archi_) {     // itero su tutti gli archi del grafo}
                if (numero_arco_corrente == numero_arco)   {
                    return arco_corrente;              // se il numero dell'arco corrente è uguale al numero dell'arco che prendo in input allora restituisco l'arco corrente
                }
                numero_arco_corrente = numero_arco_corrente+1;
            }                           
        }

        
        // ora implementiamo l'opratore differenza operator-() che permette di calcolare la differenza tra due grafi
        // cioè dati due grafi G1 e G2 , la differenza G1-G2 è data da un nuovo grafo che contiene tutti i nodi di G1 e tutti gli archi
        // di G1 che però non sono presenti in G2
        unidirected_graph<T> operator-(const unidirected_graph<T>& other) const {
            unidirected_graph<T> grafo_differenza;            // creoo un nuovo grafo che sarà il grafo differenza

            // la prima cosa che faccio è che mi assicuro che tutti i nodi di G1 siano nel grafo differenza
            for (const auto& nodo : this->all_nodes()) {
                grafo_differenza.lista_adiacenza_[nodo];      // credo il nodo anche se è isolato
            }

            std::vector<unidirected_edge<T>> archi_differenza;     // creo un set che conterrà tutti gli archi di G1 che non sono presenti in G2
            std::set_difference(this->archi_.begin(), this->archi_.end(), other.archi_.begin(), other.archi_.end(), 
            std::back_inserter(archi_differenza));              // qui uso la set_difference per calcolare la differenza tra gli archi

            for (const auto& arco : archi_differenza) {
                grafo_differenza.add_edge(arco.from(), arco.to());    // aggiungo al grafo differenza gli archi presenti in G1 ma non in G2
            }

            return grafo_differenza; 
        }
};

