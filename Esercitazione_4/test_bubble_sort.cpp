#include "sorting.h"
#include "randfiller.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> 

int main() {
    randfiller rf; // come nell'esempio

    for (int i=0; i<100; i++) {               // qui genero i 100 vettori di dimensione casuale
        std::vector<int> vettore_interi;
        size_t dimensione = rand() % 1000 +1; // qui genero una dimensione casuale tra 1 e 1000
        vettore_interi.resize(dimensione);               // qui assegno la dimensione generata casualmente al vettore
        rf.fill(vettore_interi, -1000, 1000);            // qui riempio il vettore con numeri casuali positivi e negativi

        bubble_sort(vettore_interi);                     // qui vado ad ordinare il vettore con il metodo bubble_sort

        if (is_sorted(vettore_interi)==false) {          // dopo averlo ordinato vado a controllare che sia effettivamente ordinato
            std::cout<<"Il vettore non è ordinato, test:"<<i<<"\n";
            return EXIT_FAILURE;
        }
    }

    std::vector<std::string> vettore_stringhe={"termosifone", "giuseppe", "griglia", "lombalgia", "scapola", "pelo", "alluce", "farcito", "pasta e fagioli", "pastiera"};

    bubble_sort(vettore_stringhe);

    if (is_sorted(vettore_stringhe)==false) {
        std::cout<<"Il vettore di stringhe non è ordinato \n";
        return EXIT_FAILURE;
    }

    std::cout<<"Tutti i test per il Bubble Sort sono passati \n";
    return EXIT_SUCCESS;
}
