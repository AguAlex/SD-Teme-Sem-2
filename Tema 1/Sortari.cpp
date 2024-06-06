#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void selectionSort(vector<int>& v) {
    int n = v.size();

    for (int i = 0; i < n - 1; i++) {
        
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[minIndex]) {
                minIndex = j;
            }
        }

        
        swap(v[i], v[minIndex]);
    }
}

void heapify(vector<int>& v, int len, int i) {
    int maxim = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < len && v[maxim] < v[left]) {
        maxim = left;
    }

    if (right < len && v[maxim] < v[right]) {
        maxim = right;
    }

    if (maxim != i) {
        swap(v[maxim], v[i]);
        heapify(v, len, maxim);
    }
}

void heapSort(vector<int>& v) {
    int len = v.size();

    // Construieste max-heapul (rearanjeaza vectorul)
    for (int i = len / 2 - 1; i >= 0; i--) {
        heapify(v, len, i);
    }

    // Extrage elementele unul cate unul din heap
    len -= 1;
    while (len > 0){
        // Muta radacina curenta la sfarsit
        swap(v[0], v[len]);

        // Apeleaza heapify pe heapul redus
        heapify(v, len, 0);

        len -= 1;
    }
        
    
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

int main(){

    vector <int> v = citire_input();
    //selectionSort(v);
    
    cout << "\nVector nesortat: ";
    for(int a : v){
        cout<<a<<" ";
    }

    cout<<"\nVector sortat: ";

    heapSort(v);
    for(int a : v){
        cout<<a<<" ";
    }

    
}