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

void printInOrder(Node* root){
    if(root == NULL)
        return;
    printInOrder(root->left);
    cout<< root->data << " ";
    printInOrder(root->right);
}
Node* binarySearchTree(Node* root, int val){
    if(root == NULL)
        return new Node(val);
    if(val > root->data)
        root->right = binarySearchTree(root->right, val);
    else
        root->left = binarySearchTree(root->left, val);

}
Node* searchInBst(Node* root, int target){
    if(root == NULL)
        return NULL;
    if(target == root->data)
        return root;
    else if(target > root->data)
        return searchInBst(root->right, target);
    else
        return searchInBst(root->left, target);
}
Node* inorderSucccessor(Node* root){
    Node* curr = root;
    while(curr && curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}
Node* deleteFromBST(Node* root, int key){
    //searching
    if(key > root->data)
        root->right = deleteFromBST(root->right, key);
    else if(key < root->data)
        root->left = deleteFromBST(root->left, key); 
    else{
        //first case
        if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        //second case
        else if(root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        //third case: node with two childs
        else {
            Node* temp = inorderSucccessor(root->right);
            root->data = temp->data;
            root->right = deleteFromBST(root->right, temp->data);
        }

        return root;
    }
}
// Node* deleteFromBST(Node* root, int key){
//     //searching
//     if(key < root->data)
//         root->left = deleteFromBST(root->left, key);
//     else if(key > root->data)
//         root->right = deleteFromBST(root->right, key);
//     else{
//         // 1st case when no sucessors
//         if(root->left == NULL)
//         {
//             //store the right data and remove left then
//             Node* temp = root->right;
//             free(root);
//             return temp;
//         } 
//         else if(root->right == NULL){
//             //store left data
//             Node* temp = root->left;
//             free(root);
//             return temp;
//         }
//         else{
//             //Third case: when target node have successors.
//             Node* temp = inorderSucccessor(root->right);
//             root->data = temp->data;
//             root->right = deleteFromBST(root->right, temp->data);
//         }
//     }

//     return root;
// }
int main(){
    Node* root = NULL;
    root = binarySearchTree(root, 5);
    binarySearchTree(root, 1);
    binarySearchTree(root, 3);
    binarySearchTree(root, 4);
    binarySearchTree(root, 2);
    binarySearchTree(root, 7);
    printInOrder(root);

   if(searchInBst(root, 2) != NULL)
        cout<< "Target found" << endl;
    else
        cout << "Target not found" << endl;

    deleteFromBST(root, 2);
    
    cout << "after deletion: ";
    printInOrder(root);
}