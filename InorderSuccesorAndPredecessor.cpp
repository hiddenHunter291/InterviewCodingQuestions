#include<iostream>
using namespace std;

int previous = -1, answer = -1;

class Tree {
public:
    int data;
    Tree* right;
    Tree* left;

    Tree(int data) {
        this->data = data;
        right = NULL;
        left = NULL;
    } 
};


Tree* insertBST(int data, Tree* bst) {
    if(bst == NULL) return new Tree(data);
    if(bst->data > data) {
        bst->left = insertBST(data, bst->left);
    }
    if(bst->data < data) {
        bst->right = insertBST(data, bst->right);
    }
    return bst;
}

void inorderTraversal(Tree* bst) {
    if(bst != NULL) {
        inorderTraversal(bst->left);
        cout << bst->data << " ";
        inorderTraversal(bst->right);
    }
}

void inorderSuccessor(Tree* root, int target) {
    if(root) {
        inorderSuccessor(root->left, target);
        if(root->data == target) {
            answer = previous;
        } else {
            previous = root->data;
        }
        inorderSuccessor(root->right, target);
    }
}

void inorderPredecessor(Tree* root, int target) {
    if(root) {
        inorderPredecessor(root->left, target);
        if(previous == target) {
            answer = root->data;
            previous = -1;
        } else {
            previous = root->data;
        }
        inorderPredecessor(root->right, target);
    }
}

int main() {
    Tree* bst = NULL;
    int data, number;
    cin >> data;
    while(data != -1) {
        bst = insertBST(data, bst);
        cin >> data;
    }
    inorderTraversal(bst);
    cout << "\nEnter the number: " << endl;
    cin >> number;
    inorderSuccessor(bst, number);
    cout << "InorderSuccesor    : " << answer << endl;
    previous = -1, answer = -1;
    inorderPredecessor(bst, number);
    cout << "InorderPredecessor : " << answer << endl;
    
    return 0;
}