#include <iostream>

struct Nod {
    int val;
    Nod *next;

    Nod(int x) {
        val = x;
        next = nullptr;
    }
};

struct lista {
    Nod *head;

    lista() {
        head = nullptr;
    }

    ~lista() {
        if (head != nullptr) {
            Nod *aux = head;
            Nod *primul = head;
            do {
                Nod *next = aux->next;
                delete aux;
                aux = next;
            } while (aux != primul);
        }
    }

    void adaugare_nod_final(int val) {
        Nod *nod = new Nod(val);
        if (head == nullptr) {
            head = nod;
            nod->next = head;
        } else {
            Nod *aux = head;
            while (aux->next != head) {
                aux = aux->next;
            }
            aux->next = nod;
            nod->next = head;
        }
    }

    void adaugare_nod_inceput(int val) {
        Nod *nod = new Nod(val);
        if (head == nullptr) {
            head = nod;
            nod->next = head;
        } else {
            Nod *aux = head;
            while (aux->next != head) {
                aux = aux->next;
            }
            nod->next = head;
            head = nod;
            aux->next = head;
        }
    }

    void afisare() {
        if (head != nullptr) {
            Nod *aux = head;
            do {
                std::cout << aux->val << " ";
                aux = aux->next;
            } while (aux != head);
            std::cout << std::endl;
        }
    }

    void cautare(int x) {
        if (head != nullptr) {
            Nod *aux = head;
            do {
                if (aux->val == x) {
                    std::cout << "Elementul " << x << " este in lista." << std::endl;
                    return;
                }
                aux = aux->next;
            } while (aux != head);
        }
        std::cout << "Elementul " << x << " nu este in lista." << std::endl;
    }

    void stergere(int x) {
        if (head == nullptr) {
            std::cout << "Elementul " << x << " nu a fost gasit in lista." << std::endl;
            return;
        }

        Nod *aux = head;
        Nod *prev = nullptr;

        // gasim nodul de sters
        do {
            if (aux->val == x) {
                if (prev != nullptr) {
                    prev->next = aux->next;
                } else {
                    Nod *last = head;
                    while (last->next != head) {
                        last = last->next;
                    }
                    head = aux->next;
                    last->next = head;
                }

                if (aux == head && aux->next == head) {
                    // Lista are un singur element care trebuie șters
                    head = nullptr;
                }
                delete aux;
                std::cout << "Elementul " << x << " a fost sters din lista." << std::endl;
                return;
            }
            prev = aux;
            aux = aux->next;
        } while (aux != head);

        std::cout << "Elementul " << x << " nu a fost gasit in lista." << std::endl;
    }
};

int main() {
    lista lista;
    lista.adaugare_nod_final(4);
    lista.adaugare_nod_final(22);
    lista.adaugare_nod_final(14);
    lista.afisare();
    lista.adaugare_nod_inceput(3);
    lista.afisare();

    lista.cautare(4);
    lista.cautare(11);

    lista.stergere(22);
    lista.afisare();

    return 0;
}
