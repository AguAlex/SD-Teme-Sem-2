#include <iostream>
#include <vector>

using namespace std;

struct Nod {
    int val;
    Nod *next;

    Nod(int x) {
        val = x;
        next = nullptr;
    }
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

    void push(int val) {
        Nod *nod = new Nod(val);
        nod->next = top;
        top = nod;
    }

    int pop() {
        if (top == nullptr) {
            std::cout << "Stiva este goala." << std::endl;
            return -1; // Returnăm -1 pentru a indica o eroare
        }
        int ch = top->val;
        Nod *aux = top;
        top = top->next;
        delete aux;
        return ch;
    }

    int acces_top() {
        if (top == nullptr) {
            std::cout << "Stiva este goala." << std::endl;
            return -1;
        }
        return top->val;
    }

    bool empty() {
        return top == nullptr;
    }
};

std::vector<int> gasesteElemente(const std::vector<int>& v) {
    int n = v.size();
    std::vector<int> rez(n, -1); 
    Stack st;

    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && v[st.acces_top()] <= v[i]) {
            st.pop();
        }
        if (!st.empty()) {
            rez[i] = v[st.acces_top()];
        }
        st.push(i);
    }

    return rez;
}

vector<int> citire_input(){
    vector<int> aux;
    int nr, x;
    cout<<"\nLungime vector: ";
    cin>>nr;

    cout<<"\nIntroduce elementele vectorului: \n";

    for(int i=1; i<=nr; i++){
        cin>>x;
        aux.push_back(x);
    }
    
    return aux;

}

int main() {
    std::vector<int> v = citire_input();
    v = gasesteElemente(v);

    std::cout << "Elementele urmatoare mai mari sunt: \n";
    for (int val : v) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
