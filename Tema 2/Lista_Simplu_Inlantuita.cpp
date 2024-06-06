#include <iostream>

struct Nod {
    int val;
    Nod *next;

    Nod(int x) {
        val = x;
        next = nullptr;
    }

    ~Nod() {
        
    }
};

struct lista {
    Nod *head;

    lista() {
        head = nullptr;
    }

    ~lista() {
        Nod *aux = head;
        while (aux != nullptr) {
            Nod *next = aux->next;
            delete aux;
            aux = next;
        }
    }

    void adaugare_nod_final(int val) {
        Nod *auxx = new Nod(val);
        if (head == nullptr) {
            head = auxx;
        } else {
            Nod *aux = head;

            // Parcurgem lista până la ultimul element
            while (aux->next != nullptr) {
                aux = aux->next;
            }

            aux->next = auxx;
        }
    }

    void adaugare_nod_inceput(int val) {
        Nod *auxx = new Nod(val);
        auxx->next = head;
        head = auxx;
    }

    void afisare() {
        Nod *aux = head;
        while (aux != nullptr) {
            std::cout << aux->val << " ";
            aux = aux->next;
        }
        std::cout << std::endl;
    }

    void cautare(int x) {
        Nod *aux = head;
        while (aux != nullptr) {
            if (aux->val == x) {
                std::cout << "Elementul " << x << " este in lista." << std::endl;
                return;
            }
            aux = aux->next;
        }
        std::cout << "Elementul " << x << " nu este in lista." << std::endl;
    }

    void stergere(int x) {
        Nod *aux = head;
        Nod *prev = nullptr;

        while (aux != nullptr) {
            if (aux->val == x) {
                if (prev != nullptr) {
                    prev->next = aux->next;
                } else {
                    head = aux->next;
                }
                delete aux;
                std::cout << "Elementul " << x << " a fost sters din lista." << std::endl;
                return;
            }
            prev = aux;
            aux = aux->next;
        }
        std::cout << "Elementul " << x << " nu a fost gasit in lista." << std::endl;
    }
};

int main() {

    lista l;
    int x = 1;
    std::cout << "Introduceti valoruile nodurilor: \n";
    while(x){
        std::cin >> x;
        l.adaugare_nod_final(x);
    }
    std::cout<<"\nLista inainte de stergere: ";
    l.afisare();
    l.stergere(l.head->val); //Se sterge primul element
    std::cout<<"Lista dupa stergere: ";
    l.afisare();
    return 0;
}
