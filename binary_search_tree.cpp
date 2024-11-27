#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* GetNewNode(int data){
    BSTNode* newNode = new BSTNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* Insert(BSTNode* root, int data) {
    if (root == NULL) {
        root = GetNewNode(data);
    }
    else if (data <= root->data) {
        root->left = Insert(root->left, data);
    }
    else {
        root->right = Insert(root->right, data);
    }
    return root;
}

bool Search(BSTNode* root, int data){
    if (root == NULL) return false;
    if (root->data == data) return true;    
    if (data <= root->data) return Search(root->left, data);
    else return Search(root->right, data);
}

void Remove(BSTNode* root, int data) {
    
}
int main() {
    cin.tie(0)->sync_with_stdio(false);

    BSTNode* rootPtr;
    rootPtr = NULL;

    rootPtr = Insert(rootPtr, 15);
    rootPtr = Insert(rootPtr, 20);
    rootPtr = Insert(rootPtr, 10);
    rootPtr = Insert(rootPtr, 8);
    rootPtr = Insert(rootPtr, 11);

    cout << Search(rootPtr, 12) << '\n';
    cout << Search(rootPtr, 15) << '\n';

    rootPtr = Insert(rootPtr, 25);
    cout << Search(rootPtr, 8) << '\n';
    cout << Search(rootPtr, 13) << '\n';
    cout << Search(rootPtr, 25) << '\n';

    Remove(rootPtr, 25);
    Remove(rootPtr, 15);

    return 0;
}