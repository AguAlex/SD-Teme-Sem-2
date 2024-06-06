#include <iostream>
#include <vector>

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int x) : value(x), left(nullptr), right(nullptr) {}
};

void preorderBst(Node* root, std::vector<int>& v) {

    if (root == nullptr) {
        return;
    }
    v.push_back(root->value);
    preorderBst(root->left, v);
    preorderBst(root->right, v);
}

void preorderPrintBst(Node* root){

    if (root == nullptr) {
        return;
    }
    std::cout << root->value << " ";
    preorderPrintBst(root->left);
    preorderPrintBst(root->right);
}

std::vector<int> mergeArrays(std::vector<int> v1, std::vector<int> v2) {
    std::vector<int> rez;
    int i = 0, j = 0;
    while (i < v1.size() && j < v2.size()) {
        if (v1[i] < v2[j]) {
            rez.push_back(v1[i]);
            i++;
        } else {
            rez.push_back(v2[j]);
            j++;
        }
    }
    while (i < v1.size()) {
        rez.push_back(v1[i]);
        i++;
    }
    while (j < v2.size()) {
        rez.push_back(v2[j]);
        j++;
    }
    return rez;
}

Node* sortedArrayToBST(std::vector<int> v, int left, int right)
{
    if (left > right)
        return nullptr;
 
    int mid = (left + right) / 2;

    Node* root = new Node(v[mid]);
   
    root->left = sortedArrayToBST(v, left, mid - 1);
    
    root->right = sortedArrayToBST(v, mid + 1, right);
 
    return root;
}

Node* mergeTwoBSTs(Node* root1, Node* root2) {

    std::vector<int> v1, v2;

    preorderBst(root1, v1);
    preorderBst(root2, v2);
    
    std::vector<int> mergedVector = mergeArrays(v1, v2);
    
    return sortedArrayToBST(mergedVector, 0, mergedVector.size()-1);
}

void deleteTree(Node* node) {
    if (node == nullptr)
        return;

    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

int main() {
    
    Node* root1 = new Node(1);
    root1->left = new Node(0);
    root1->right = new Node(2);

    Node* root2 = new Node(4);
    root2->left = new Node(3);
    root2->right = new Node(5);

    Node* merged = mergeTwoBSTs(root1, root2);

    preorderPrintBst(merged);

    delete root1->left;
    delete root1->right;
    delete root1;
    delete root2->left;
    delete root2->right;
    delete root2;

    deleteTree(merged);

    return 0;
}