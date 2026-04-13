#include "sorting.h"
#include "randfiller.h"
#include "timecounter.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream> 

int main() {
    timecounter tc;
    randfiller rf;
    std::ofstream out("tempi_matlab.txt");          // qui apro il file per la scrittura dei tempi

    // preparo prima i vettori di lunghezza delle potenze di 2
    for (size_t i=4; i<=8192; i=i*2) {
        std::vector<int> vettore_prova(i);
        rf.fill(vettore_prova, -1000, 1000);

        // qui genero i 4 vettori da ordinare, sono tutti uguali per ora e poi verranno ordinati secondo uno dei metodi
        std::vector<int> vettore_bubble = vettore_prova;
        std::vector<int> vettore_insertion = vettore_prova;
        std::vector<int> vettore_selection = vettore_prova;
        std::vector<int> vettore_std = vettore_prova;
        
        // TEST BUBBLE SORT
        tc.tic();
        bubble_sort(vettore_bubble);
        double tempo_bubble=tc.toc();

        // TEST INSERTION SORT
        tc.tic();
        insertion_sort(vettore_insertion);
        double tempo_insertion=tc.toc();

        // TEST SELECTION SORT
        tc.tic();
        selection_sort(vettore_selection);
        double tempo_selection=tc.toc();

        // TEST CON IL SORT DELLA LIBRERIA STANDARD
        tc.tic();
        std::sort(vettore_std.begin(), vettore_std.end());
        double tempo_std=tc.toc();
        
        // SCRITTURA DEI TEMPI SUL FILE 
        out << i << " " << tempo_bubble << " " << tempo_insertion << " " << tempo_selection << " " << tempo_std << "\n";

        //stampiamo i tempi
        std::cout<<"tempo bubble sort: "<<tempo_bubble<<" secondi \n";
        std::cout<<"tempo insertion sort: "<<tempo_insertion<<" secondi \n";
        std::cout<<"tempo selection sort: "<<tempo_selection<<" secondi \n";
        std::cout<<"tempo sort della libreria standard: "<<tempo_std<<" secondi \n";
    }

    out.close(); 
    std::cout<<"I tempi sono stati scritti su tempi_matlab.txt \n";
    
    return 0;
}