#pragma once
#include <list>

template<typename T>
class lifo {
    private :
        std::list<T> stack;
    
    public :
        // costruttore di default
        lifo() = default;

        // metodo put per aggiungere un elemento nello stack
        void put(const T& elemento) {
            stack.push_back(elemento);
        }

        // metodo get per rimuovere un elemento dallo stack
        T get() {
            T elemento = stack.back();
            stack.pop_back();
            return elemento;
        }

        // metodo empty per determinare se lo stack è vuoto
        bool empty() const {
            return stack.empty();
        }
};