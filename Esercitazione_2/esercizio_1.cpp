#include <iostream>

int main() {
    double ad[4] = {0.0, 1.1, 2.2, 3.3};
    float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    int ai[3] = {0, 1, 2};

    int x = 1;
    float y = 1.1;

    std::cout << "Indirizzo di x:   " << &x << "\n";
    std::cout << "Indirizzo di y: " << &y << "\n";
    
    // qui stampo il primo e l'ultimo elemento per vedere quanto spazio occupano
    std::cout << "ad[0]: " << &ad[0] << " | ad[3]: " << &ad[3] << " (8 byte per elemento)\n";
    std::cout << "af[0]: " << &af[0] << " | af[7]: " << &af[7] << " (4 byte per elemento)\n";
    std::cout << "ai[0]: " << &ai[0] << " | ai[2]: " << &ai[2] << " (4 byte per elemento)\n";

    (&y)[1] = 0; 

    std::cout << "Valore di x nuovo: " << x << "\n";
    
    if (x == 0) {
        std::cout << "Spiegazione: x e' stato sovrascritto perche' si trova subito dopo y in memoria.\n";
    } else {
        std::cout << "Spiegazione: x e' rimasto 1. Il compilatore ha messo x e y distanti o in ordine diverso.\n";
    }

    return 0;
}
