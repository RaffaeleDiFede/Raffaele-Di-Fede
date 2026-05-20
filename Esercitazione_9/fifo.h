#pragma once
#include <list>

template <typename T>
class fifo {
    private :
        std::list<T> coda;
    
    public :
        // costruttore di default
        fifo() = default;

        // metodo put per inserire un elemento nella coda
        void put(const T& elemento) {
            coda.push_front(elemento);
        }

        // metodo get per rimuovere un elemento dalla coda
        T get() {
            T elemento = coda.back();
            coda.pop_back();
            return elemento;
        }

        // metodo empty per controllare se la coda è vuota
        bool empty() const {
            return coda.empty();
        }
};