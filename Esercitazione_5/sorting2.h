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


// QUI DEVO SCRIVERE IL MERGE SORT E IL QUICK SORT

//PRIMA DI TUTTO DEVO DEFINIRE LA FUNZIONE MERGE

template<typename T>
void merge(std::vector<T>& A, int p,int q, int r) {
    int n1=q-p+1;
    int n2=r-q;
    std::vector<T> L(n1);
    std::vector<T> R(n2);
    for (int i=0; i<n1; i++) {
        L[i] = A[p+i];
    }
    for (int j=0; j<n2; j++) {
        R[j]=A[q+j+1];
    }
    int i=0;
    int j=0;
    
    for(int k=p; k<=r; k++) {
        if (i<n1 && (j>=n2 || L[i]<=R[j])) {
            A[k]=L[i];
            i++;
        }
        else {
            A[k]=R[j];
            j++;
        }
    }
}


template<typename T>
void merge_sort(std::vector<T>& A, int p, int r) {
    if (p<r) {
        int q=(p+r)/2;
        merge_sort(A, p, q);
        merge_sort(A, q+1, r);
        merge(A, p, q, r);
    }

}


// QUI DEVO SCRIVERE LA FUNZIONE PER IL QUICK SORT MA PRIMA DEVO SCRIVERE LA FUNZIONE PARTITION

template<typename T>
int partition(std::vector<T>& A, int p, int r) {
    T x=A[r];
    int i=p-1;
    for (int j=p; j<=r-1; j++) {
        if (A[j]<=x) {
            i++;
            std::swap(A[i], A[j]);
        }
    }
    std::swap(A[i+1], A[r]);
    return i+1;
}


template<typename T>
void quick_sort(std::vector<T>& A, int p, int r) {
    if (p<r) {
        int q=partition(A, p, r);
        quick_sort(A, p, q-1);
        quick_sort(A, q+1, r);
    }
}

template<typename T>                                                    // ora creiamo un quick sort modificato per cui, quando la lunghezza del vettore da ordinare è minore di una certa soglia (nel nostro caso 86) allora utilizza l'insertion sort e non il quick sort
void quick_sort_modificato(std::vector<T>& A, int p, int r) {
    if (p<r) {
        if (r-p+1 < 86) {                                                 
            insertion_sort(A);
        }
        else {
            int q=partition(A, p, r);
            quick_sort_modificato(A, p, q-1);
            quick_sort_modificato(A, q+1, r);
        }
    }
}