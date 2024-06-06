#include <iostream>
#include <vector>

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int x) : value(x), left(nullptr), right(nullptr) {}
};

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

void preOrderTraversal(Node* node) {
    if (node == nullptr) {
        return;
    }
    std::cout << node->value << " ";
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

void deleteTree(Node* node) {
    if (node == nullptr)
        return;

    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

int main() {
    std::vector<int> sortedArray = {1, 2, 3, 4, 5, 6, 7};

    int n = sortedArray.size();

    if (n == 0)
        std::cout<<"Vector invalid.";
    else{

        Node* root = sortedArrayToBST(sortedArray, 0, n-1);
        std::cout << "Arborele in pre-ordine: " << std::endl;
        preOrderTraversal(root);
        std::cout << std::endl;
        deleteTree(root);
    }
        
    

    return 0;
}
