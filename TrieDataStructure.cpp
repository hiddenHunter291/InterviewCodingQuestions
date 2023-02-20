#include<bits/stdc++.h>
using namespace std;
class Trie {
public:
    Trie* children[26];
    bool isEnd;
    
    Trie() {
        for(Trie* a : this->children)
            a = NULL;
        isEnd = false;
    }
};

void insertString(Trie* root, string s) {
    Trie* temp = root;
    for(char ch : s) {
        int index = ch - 'a';
        if(temp->children[index] == NULL) {
            temp->children[index] = new Trie();
        }
        temp = temp->children[index];
    }
    temp->isEnd = true;
}

bool isLeaf(Trie* root) {
    for(Trie* a : root->children) {
        if(a != NULL) return false;
    }
    return true;
}

Trie* deleteString(Trie* root, int current_index, string s) {
    if(root == NULL) return NULL;
    if(current_index == s.length()) {
        if(root->isEnd) {
            root->isEnd = false;
        }
        if(isLeaf(root)) {
            delete (root);
            return NULL;
        }
        return root;
    }
    int index = s[current_index] - 'a';
    root->children[index] = deleteString(root->children[index], current_index + 1, s);
    if(isLeaf(root) && root->isEnd) {
        delete (root);
        root = NULL;
    }
    return root;    
}

bool search(Trie* root, string s) {
    Trie* temp = root;
    for(char ch : s) {
        int index = ch - 'a';
        if(temp->children[index] == NULL) return false;
        temp = temp->children[index];
    }
    return temp->isEnd;
}

int main() {
    Trie* trie = new Trie();
    insertString(trie, "abc");
    insertString(trie, "abd");
    deleteString(trie, 0, "abd");
    cout << search(trie, "ab") << endl;
    return 0;
}