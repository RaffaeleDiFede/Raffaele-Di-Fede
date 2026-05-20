#pragma once
#include <iostream>
#include <Eigen/Dense>

Eigen::VectorXd gradiente_coniugato(const Eigen::MatrixXd& A, const Eigen::VectorXd& b, const Eigen::VectorXd& x0, int iter_max = 1000, double tol=1e-6) {
    
    // inizializzazione di x0
    Eigen::VectorXd x=x0;

    // inizializzazione del residuo
    Eigen::VectorXd r=b-A*x;

    // inizializzazione del passo
    Eigen::VectorXd p=r;

    // inzializzazione del contatore 
    int k=0;

    while (r.norm()>=tol && k<iter_max) {
        // calcolo del passo, qui uso la function transpose()
        double alpha=r.dot(r)/(p.dot(A*p));

        // aggiornamento di x
        x=x+alpha*p;

        // aggiornamento del residuo
        r=r-alpha*A*p;

        // calcolo di beta
        double beta=(p.dot(A*r))/(p.dot(A*p));

        //aggiornamento del passo
        p=r-beta*p;

        // aggiornamento del contatore
        k=k+1;
    }
            

    return x;
};
