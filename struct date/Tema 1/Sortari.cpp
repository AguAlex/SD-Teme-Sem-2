#include <iostream>
#include <vector>

void selectionSort(std::vector<int>& v) {
    int n = v.size();

    for (int i = 0; i < n - 1; i++) {
        
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[minIndex]) {
                minIndex = j;
            }
        }

        
        std::swap(v[i], v[minIndex]);
    }
}

void heapify(int v[], int len, int i){
    int maxim = i;
    int left = i*2+1;
    int right = i*2+2;

    if(left < len and v[maxim] < v[left]){
        maxim = left;
    }

    if(right < len and v[maxim] < v[right]){
        maxim = right;
    }

    if(maxim != i){
        std::swap(v[maxim], v[i]);
        heapify(v, len, maxim);
    }
}

void heapSort(int v[], int len){
    for(int i = len/2; i>=0; i--)
        heapify(v, len, i);

    for(int i = len-1; i>=1; i--){
        std::swap(v[0], v[i]);
        len--;
        
        heapify(v, len, 0);
    }

}

int main(){

    std::vector <int> v = {4, -4, 12, 8, -2};
    selectionSort(v);
    //heapSort(v, 5);

    for(int a : v){
        std::cout<<a<<" ";
    }
}