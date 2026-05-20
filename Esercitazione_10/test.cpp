#include <iostream>
#include "gradiente_coniugato.h"
#include <Eigen/Dense>

int main() {
    // inizializzo la matrice A, il vettore b e il vettore di partenza x0
    // in particolare vogliamo che la matrice A sia simmetrica e definita positiva, altrimenti non potremmo garantire la convergenza del metodo del gradiente coniugato

    Eigen::MatrixXd A(3,3);
    A<< 4,1,2,
        1,3,0,
        2,0,5;

    Eigen::VectorXd b(3);
    b<< 7,5,8;

    Eigen::VectorXd x0 = Eigen::VectorXd::Ones(3);

    Eigen::VectorXd risultato = gradiente_coniugato(A, b, x0);

    std::cout<<"La matrice A è: "<<A<<std::endl;
    std::cout<<"Il vettore b è: "<<b<<std::endl;
    std::cout<<"Il vettore di partenza x0 è: "<<x0<<std::endl;
    std::cout<<"Il vettore finale è: "<<risultato<<std::endl;

}