# include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, const char *argv[]) {
    std :: cout<<"Numero di parametri:"<< argc << "\n";
    if (argc!=2) {
        std:: cerr<< "Devi specificare il nome del file \n";
        return 1;
    }
    ifstream ifs(argv[1]);
    if (ifs.is_open()) {
        for (int i=1; i<=3; i=i+1) {
            string citta;
            double temp0;
            double temp6;
            double temp12;
            double temp18;
            ifs >> citta >> temp0 >> temp6 >> temp12 >> temp18;
            double media = (temp0+temp6+temp12+temp18)/4;
            cout << "La temperatura nella città di " << citta << " è di " << media << "\n";
        }
    
    }
    else {
        cout << "Non hai scritto bene il nome del file \n";
    }

}
    
