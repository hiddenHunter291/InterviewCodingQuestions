#include<iostream>
using namespace std;

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

int minRight(Tree* bst) {
    if(bst->left == NULL) return bst->data;
    return minRight(bst->left); 
}

Tree* deleteBST(int data, Tree* bst) {
    if(bst == NULL) return NULL;
    if(bst->data > data) {
        bst->left = deleteBST(data, bst->left);
    }
    if(bst->data < data) {
        bst->right = deleteBST(data, bst->right);
    }
    if(bst->data == data) {
        if(bst->right == NULL) {
            return bst->left;
        }
        if(bst->left == NULL) {
            return bst->right;
        }
        if(bst->left == NULL && bst->right == NULL) {
            return NULL;
        } 
        int replaceValue = minRight(bst->right);
        bst->data = replaceValue;
        bst->right = deleteBST(replaceValue, bst->right);
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
int main() {
    Tree* bst = NULL;
    int data, number;
    cin >> data;
    while(data != -1) {
        bst = insertBST(data, bst);
        cin >> data;
    }
    inorderTraversal(bst);
    cout << "\nEnter the number to delete\n" << endl;
    cin >> number;
    bst = deleteBST(number, bst);
    inorderTraversal(bst);
    return 0;
}