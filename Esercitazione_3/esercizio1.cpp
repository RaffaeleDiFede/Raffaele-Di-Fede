#include "rational.hpp"
#include <iostream>

int main() {

    // Test della funzione di semplificazione
    rational<int> r1(3, 6);
    std::cout << "   Risultato: " << r1 << std::endl; 

    // Test Operazioni Aritmetiche
    rational<int> r2(1, 3);
    std::cout << "\n Test Operazioni: " << std::endl;
    
    auto somma = r1 + r2;
    std::cout << "   " << r1 << " + " << r2 << " = " << somma << std::endl;

    auto sottrazione = r1 - r2;
    std::cout << "   " << r1 << " - " << r2 << " = " << sottrazione << std::endl;

    auto prodotto = r1 * r2;
    std::cout << "   " << r1 << " * " << r2 << " = " << prodotto << std::endl;

    auto divisione = r1 / r2;
    std::cout << "   " << r1 << " / " << r2 << " = " << divisione << std::endl;

    // Test Casi Limite (Inf e NaN)
    
    rational<int> r_inf(5, 0);
    rational<int> r_nan(0, 0);
    std::cout << "   Costruttore (5, 0): " << r_inf << std::endl;
    std::cout << "   Costruttore (0, 0): " << r_nan << std::endl;

    // Operazione con Inf
    auto inf_piu_razionale = r_inf + r1;
    std::cout << "   Inf + 1/2 = " << inf_piu_razionale << std::endl;

    // Operazione che genera NaN (Inf * 0)
    rational<int> zero(0, 1);
    auto inf_per_zero = r_inf * zero;
    std::cout << "   Inf * 0 = " << inf_per_zero << std::endl;

    return 0;
}