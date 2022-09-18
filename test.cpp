//Build a binary search tree
#include <bits/stdc++.h>
using namespace std;
//1: Build a node first
struct Node{
    int data;
    Node* left;
    Node* right;
    //cosntructor
    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};
Node* inorderSucc(Node* root){
    Node* curr = root;
    while(curr && curr->left != NULL){
        curr = curr->left;
    }

    return curr;
}
//Delete from BST
Node* deleteFromBST(Node* root, int target){
    //search
    if(target > root->data)
        root->right = deleteFromBST(root->right, target);
    else if(target < root->data)
        root->left = deleteFromBST(root->left, target);
    else{
        if(root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        else if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else{
            Node* temp = inorderSucc(root->right);
            root->data = temp->data;
            root->right = deleteFromBST(root->right, temp->data);
        }
    }
    return root;
}

//search a key in BST in logn time
Node* searchInBST(Node* root, int key){
    if(root == NULL)
        return NULL;
    if(root->data == key)
        return root;
    else if(key > root->data)
        return searchInBST(root->right, key);
    else
        return searchInBST(root->left, key);
}

//2: Build tree

Node* buildBST(Node* root, int val){
    if(root == NULL)
        return new Node(val);
    else if(val < root->data)
        root->left = buildBST(root->left, val);
    else    
        root->right = buildBST(root->right, val);
}
//print inorder of BST
void printInorder(Node* root){
    if(root == NULL)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}


int main(){
    Node* root = NULL;
    root = buildBST(root, 11);
    buildBST(root, 1);
    buildBST(root, 12);
    buildBST(root, 4);
    buildBST(root, 7);
    buildBST(root, 8);
    buildBST(root, 9);
    printInorder(root);

    if(searchInBST(root, 15))
        cout << "Key exist";
    else
        cout << "Key doesn't exist";

    deleteFromBST(root, 7);
    cout << "\nAfter deletion:";
    printInorder(root);
}