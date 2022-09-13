#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void printInorder(Node* root){
    if(root == NULL)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

Node* binarySearchTree(Node* root, int val){
    if(root == NULL)
        return new Node(val);

    else if(val < root->data)
        root->left = binarySearchTree(root->left, val);
    else 
        root->right = binarySearchTree(root->right, val);
}

int main(){
    Node* root = NULL;
    root = binarySearchTree(root, 5);
    binarySearchTree(root, 1);
    binarySearchTree(root, 3);
    binarySearchTree(root, 4);
    binarySearchTree(root, 2);
    binarySearchTree(root, 7);

    printInorder(root);
}