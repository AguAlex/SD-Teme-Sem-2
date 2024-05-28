#include <iostream>

struct Nod{
    int val;
    Nod *next;
    Nod *prev;

    Nod(int x){
        val = x;
        next = nullptr;
        prev = nullptr;
    }

    ~Nod(){
        delete next;
        delete prev;
    }
};

struct lista_dublu{
    Nod *head;

    lista_dublu(){
        head = nullptr;
    }

    ~lista_dublu(){
        Nod *aux = head;
        while(aux != nullptr){
            Nod *next = aux->next;
            delete aux;
            aux = next;
        }
    }

    void adaugare_nod_final(int val){

        //Se creeaza nodul ce trebuie adaugat
        Nod *newNod = new Nod(val);
        if(head == nullptr){
            head = newNod;
        }
        else {
            Nod *aux = head;

            //Parcurgem lista pana la ultimul element
            while(aux->next != nullptr){
                aux = aux->next;
            }

            aux->next = newNod;
            newNod->prev = aux;
        }
    }

    void adaugare_nod_inceput(int val){
        Nod *newNod = new Nod(val);
        newNod->next = head;
        head = newNod;
    }

    void afisare(){
        Nod *aux = head;
        while(aux != nullptr){
            std::cout<<aux->val<<" ";
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
        delete aux;
        std::cout << "Elementul " << x << " nu este in lista." << std::endl;
    }

    void stergere(int x) {
        Nod *aux = head;
        while (aux != nullptr) {
            if (aux->val == x) {

                if (aux->prev != nullptr) {
                    aux->prev->next = aux->next;
                } else {
                    head = aux->next;
                }
                if (aux->next != nullptr) {
                    aux->next->prev = aux->prev;
                }
                
                return;
            }
            aux = aux->next;
        }
        delete aux;
        std::cout << "Elementul " << x << " nu a fost gasit in lista." << std::endl;
    }

};

int main(){
    lista_dublu lista;
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

}