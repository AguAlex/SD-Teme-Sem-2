#include <iostream>
#include <string>

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

void validare(std::string s) {
    bool ok;
    Stack stack;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[')
            stack.push(c);
        else {
            if (stack.empty() || 
                (c == ')' && stack.top->val != '(') || 
                (c == '}' && stack.top->val != '{') ||
                (c == ']' && stack.top->val != '[')) {
                ok = false;
                break;
            }
            stack.pop();
        }
    }

    //Varificare daca au ramas paranteze neinchise
    ok = stack.empty();
    if(ok == true)
        std::cout<<"Expresie corecta!"<<std::endl;
    else
        std::cout<<"Expresie gresita!"<<std::endl;
    return;
}

int main() {
    validare("([]{})");
    validare("{(})");
    validare("(");

    return 0;
}
