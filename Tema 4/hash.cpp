#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

std::map<char, std::vector<std::string>> citire_cuvinte() {
    std::map<char, std::vector<std::string>> h;
    std::string cuvant;
    int nr;

    std::cout<<"Introduce numarul de cuvinte: ";
    std::cin>>nr;
    std::cout<<"Introduce cuvintele: ";
    for(int i=1; i<=nr; i++){
        std::cin>>cuvant;
        char prima_litera = std::tolower(cuvant[0]);
        h[prima_litera].push_back(cuvant);
    }
    
    for (auto& pair : h) {
        std::sort(pair.second.begin(), pair.second.end());
    }

    return h;
}

void afisare_dictionar(const std::map<char, std::vector<std::string>>& h) {
    for (auto pair : h) {
        std::cout << pair.first << ": ";
        for (auto cuvant : pair.second) {
            std::cout << cuvant << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::map<char, std::vector<std::string>> h = citire_cuvinte();

    afisare_dictionar(h);

    return 0;
}
