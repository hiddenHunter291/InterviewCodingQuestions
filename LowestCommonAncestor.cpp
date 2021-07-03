#include<bits/stdc++.h>
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

Tree* createTree() {            //can be used for BFS traversal
    int number;
    cout << "Enter the root: ";
    cin >> number;
    queue<Tree*> q;
    Tree* root = new Tree(number);
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        for(int i=0; i<size; ++i) {
            cout << "Enter the left child of " << q.front()->data << ": ";
            cin >> number;
            if(number != -1) {
                q.front()->left = new Tree(number);
                q.push(q.front()->left);
            }
            cout << "Enter the right child of " << q.front()->data << ": ";
            cin >> number;
            if(number != -1) {
                q.front()->right = new Tree(number);
                q.push(q.front()->right);
            }
            q.pop();
        }
    }
    return root;
}

Tree* lowestCommonAncestor(Tree* root, int val1, int val2) {
    if(root == NULL) return NULL;
    if(root->data == val1) return root;
    if(root->data == val2) return root;

    root->left = lowestCommonAncestor(root->left, val1, val2);
    root->right = lowestCommonAncestor(root->right, val1, val2);
    
    if(root->right != NULL && root->left != NULL) return root;
    if(root->right != NULL) return root->right;
    else return root->left;
}

void printTree(Tree* bst) {
    if(bst != NULL) {
        printTree(bst->left);
        cout << bst->data << " ";
        printTree(bst->right);
    }
}

int main() {
    Tree* root = createTree();
    Tree* answer = lowestCommonAncestor(root, 6, 4);
    cout << answer->data << endl;
    //printTree(root);
    return 0;
}