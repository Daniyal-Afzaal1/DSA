#include <iostream>
using namespace std;

struct BST_NODE{
    int data;
    BST_NODE *left;
    BST_NODE *right;
};

BST_NODE *root = NULL;

string Search_Value(BST_NODE *root, int value){
    if(root == NULL){
        return "Not Found";
    }
    if(value == root->data){
        return "Found";
    }
    if(value>root->data){
        return Search_Value(root->right,value);
    }
    else{
        return Search_Value(root->left,value);
    }  
}

int Maximum(BST_NODE *root){
    while(root->right != NULL){
        root = root->right;
    }
    return root->data;
}

int Minimum(BST_NODE *root){
    while(root->left != NULL){
        root = root->left;
    }
    return root->data;
}

BST_NODE *CreateNode(int data){
    BST_NODE *temp = new BST_NODE;
    temp->data = data;
    temp->left=temp->right=NULL;
    return temp;
}

BST_NODE *Insertion(BST_NODE *root, int value){
    if(root == NULL){
        return CreateNode(value);
    }
    if(value < root->data){
        root->left = Insertion(root->left,value);
    }
    else{
        root->right = Insertion(root->right,value);
    }

    return root;
}

BST_NODE *Inoder_Successor(BST_NODE *root){
    while(root && root->left != NULL){
        root = root->left;
    }
    return root;
}

BST_NODE *Delete_Node(BST_NODE *root, int data){
    if(root == NULL){   
        return root;
    }

    if(data<root->data){
        root->left = Delete_Node(root->left, data);
    }
    else if(data>root->data){
        root->right = Delete_Node(root->right,data); //it stores the values that come from backtracking
    }
    else{
        if(root->left == NULL){
            BST_NODE *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            BST_NODE *temp = root->left;
            delete root;
            return temp;
        }

        BST_NODE *temp = Inoder_Successor(root->right);
        root->data = temp->data;
        
        root->right = Delete_Node(root->right,temp->data); //we use this b/c we want to also fix the previous node that point to invalid memory address we deleted
    }

    return root;
}

void preorder(BST_NODE *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(BST_NODE *root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void inorder(BST_NODE *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){

    root = Insertion(root,50);
    root = Insertion(root,30);
    root = Insertion(root,70);
    root = Insertion(root,20);
    root = Insertion(root,40);
    root = Insertion(root,60);
    root = Insertion(root,80);

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    cout << "Maximum: "
         << Maximum(root)
         << endl;

    cout << "Minimum: "
         << Minimum(root)
         << endl;

    cout << "Search 60: "
         << Search_Value(root,60)
         << endl;

    cout << "Search 100: "
         << Search_Value(root,100)
         << endl;

    cout << "\nDeleting 20 (Leaf Node)\n";
    root = Delete_Node(root,20);

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "\nDeleting 30 (One Child)\n";
    root = Delete_Node(root,30);

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "\nDeleting 50 (Two Children)\n";
    root = Delete_Node(root,50);

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    return 0;
}