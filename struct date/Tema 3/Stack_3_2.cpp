#include <iostream>

struct Nod {
    char val;
    Nod *next;

    Nod(char x) {
        val = x;
        next = nullptr;
    }

    // ~Nod(){
    //     delete next;
    // }
};

struct Stack{
    Nod *top;

    Stack() {
        top = nullptr;
    }

    ~Stack() {
        while (top != nullptr) {
            Nod *aux = top;
            top = top->next;
            delete aux;
        }
    }

    void push(char val) {
        Nod *nod = new Nod(val);
        nod->next = top;
        top = nod;
    }

    char pop() {
        char ch = top->val;
        if (top == nullptr) {
            std::cout << "Stiva este goala." << std::endl;
            
        }
        Nod *aux = top;
        top = top->next;
        delete aux;
        return ch;
    }

    void afisare() {
        Nod *aux = top;
        while (aux != nullptr) {
            std::cout << aux->val << " ";
            aux = aux->next;
        }
        std::cout << std::endl;
    }

    bool empty(){
        if (top == nullptr)
            return true;
        return false;
    }
};