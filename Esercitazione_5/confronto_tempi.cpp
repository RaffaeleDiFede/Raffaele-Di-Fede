#include "sorting2.h"
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
    for (int i = 2; i <= 200; i++) {
        std::vector<std::vector<int>> vettore_prova(100, std::vector<int>(i));
        for (int n=0; n<100; n++) {
             rf.fill(vettore_prova[n], -1000, 1000);
        }

        auto vettore_bubble = vettore_prova;
        auto vettore_insertion = vettore_prova;
        auto vettore_selection = vettore_prova;
        auto vettore_std = vettore_prova;
        auto vettore_merge = vettore_prova;
        auto vettore_quick = vettore_prova;
        
        // TEST BUBBLE SORT
        tc.tic();
        for (int n=0; n<100; n++) {
            bubble_sort(vettore_bubble[n]);
        }
        double tempo_bubble=tc.toc()/100; // cioè qui calcolo la media 

        // TEST INSERTION SORT
        tc.tic();
        for (int n=0; n<100; n++) {
            insertion_sort(vettore_insertion[n]);
        }
        double tempo_insertion=tc.toc()/100;

        // TEST SELECTION SORT
        tc.tic();
        for (int n=0; n<100; n++) {
            selection_sort(vettore_selection[n]);
        }
        double tempo_selection=tc.toc()/100;

        // TEST CON IL SORT DELLA LIBRERIA STANDARD
        tc.tic();
        for (int n=0; n<100; n++) {
            std::sort(vettore_std[n].begin(), vettore_std[n].end());
        }
        double tempo_std=tc.toc()/100;

        // TEST MERGE SORT
        tc.tic();
        for (int n=0; n<100; n++) {
            merge_sort(vettore_merge[n], 0, i-1);
        }
        double tempo_merge=tc.toc()/100;

        // TEST QUICK SORT
        tc.tic();
        for (int n=0; n<100; n++) {
            quick_sort(vettore_quick[n], 0, i-1);
        }
        double tempo_quick=tc.toc()/100;


        // SCRITTURA DEI TEMPI SUL FILE 
        out << i << " " << tempo_bubble << " " << tempo_insertion << " " << tempo_selection << " " << tempo_std << " " << tempo_merge << " " << tempo_quick << "\n";
        std::cout<<"Ok ho completato la dimensione"<<i<<"\n";


        //stampiamo i tempi
        std::cout<<"tempo bubble sort: "<<tempo_bubble<<" secondi \n";
        std::cout<<"tempo insertion sort: "<<tempo_insertion<<" secondi \n";
        std::cout<<"tempo selection sort: "<<tempo_selection<<" secondi \n";
        std::cout<<"tempo sort della libreria standard: "<<tempo_std<<" secondi \n";
        std::cout<<"tempo merge sort: "<<tempo_merge<<" secondi \n";
        std::cout<<"tempo quick sort: "<<tempo_quick<<" secondi \n";
    }

    out.close(); 
    std::cout<<"I tempi sono stati scritti su tempi_matlab.txt \n";
    
    return 0;
}