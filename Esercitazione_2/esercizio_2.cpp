# include <iostream>
# include <cmath>

int main(){

static const int N = 10;
double arr[N];

arr[0]=6.0;
arr[1]=21.0;
arr[2]=28.0;
arr[3]=30.0;
arr[4]=71.0;
arr[5]=23.0;
arr[6]=42.0;
arr[7]=69.0;
arr[8]=420.0;
arr[9]=3.14;

double somma=0;
for (int i=0; i<N; i++){
    somma+=arr[i];
}

double media=somma/N;
std::cout << "La media è: " << media << "\n";

double Massimo=arr[0];
for (int i=1; i<N; i++){
    if (arr[i]>Massimo){
        Massimo=arr[i];
    }
}
std::cout << "Il massimo è: " << Massimo << "\n";

double minimo=arr[0];
for (int i=1; i<N; i++){
    if (arr[i]<minimo){
        minimo=arr[i];
    }
}
std::cout << "Il minimo è: " << minimo << "\n";

double varianza=0;
for (int i=0; i<N; i++){
    varianza+=(arr[i]-media)*(arr[i]-media);
}
varianza/=N;
double deviazione=0;
deviazione=std::sqrt(varianza);
std::cout << "La deviazione standard è: " << deviazione << "\n";


// ora proviamo l'esercizio 2.1: bubble-sort
for (int i=0; i<N-1; i++){
    for (int j=0; j<N-1-i; j++){
        if (arr[j]>arr[j+1]){
            double temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
}
std::cout << "Array ordinato: ";
for (int i=0; i<N; i++){
    std::cout << arr[i] << " ";
}
std::cout << "\n";
return 0;
}