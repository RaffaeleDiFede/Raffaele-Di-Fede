#include <vector>
#include <algorithm>  //questo serve per il std::swap

template<typename T>
bool is_sorted(const std::vector<T>& vec)
{
    if (vec.size()<2) {
        return true;   // i vettori di lunghezza zero o lunghezza uno sono già considerati ordinati
    }

    for (size_t i=1; i<vec.size(); i++) {
        if (vec[i]<vec[i-1]) {
            return false;     // cioè se controllando ogni elemento del vettore vediamo che l'elemento in posizione i-esima è minore di quello in posizione i-1 allora già possiamo constatare che il vettore non è ordinato
        }
    }

    return true;              // cioè se arriviamo alla fine del ciclo vuol dire che il vettore è ordinato
}


template<typename T>
void bubble_sort(std::vector<T>& A) {
    if (A.size()<2) {
        return;              // abbiamo detto che i vettori di lunghezza minore di 2 non vanno ordinati
    }

    for (size_t i=0; i<A.size()-1; i++) {       // fissiamo il primo elemento del vettore
        for (size_t j=A.size()-1; j>i; j--) {   // fissiamo il secondo elemento del vettore
            if (A[j]<A[j-1]) {                  // se il secondo elemento è minore del primo elemento allora li scambiamo
                std::swap(A[j], A[j-1]);        // qui avviene lo scambio
            }
        }
    }
}


template<typename T>
void insertion_sort(std::vector<T>& A) {
    if (A.size()<2) {
        return;      // come prima
    }

    for (size_t j=1; j<A.size(); j++) {      // fissiamo il secondo elemento del vettore
        T key = A[j];                          // dichiariamo il tipo T per la chiave
        int i=j-1;  
        while (i>=0 && A[i]>key) {           // finchè l'elemento in posizione i-esima è maggiore della chiave
            A[i+1] = A[i];                   // aggiorno l'elemento in posizione +1
            i--;
        }
        A[i+1] = key;
    }
}


template<typename T> 
void selection_sort(std::vector<T>& A) {
        if (A.size()<2) {
            return;
        }

        for (size_t i=0; i<A.size()-1; i++) {        // fisso il primo elemento del vettore
            size_t min=i;                            // assegno il minimo alla posizione i-esima del vettore
            for (size_t j=i+1; j<A.size(); j++) {    // fisso il secondo elemento del vettore
                if (A[j]<A[min]) {                   // se l'elemento in posizione j-esima è minore di quello in posizione "minima" allora aggiorno il minimo
                    min=j;
                }
            }
            std::swap(A[i], A[min]);                 // qui avvieni lo scambio tra i due elementi del vettore
        }
}