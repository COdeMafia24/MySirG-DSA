#include <iostream>
using namespace std;
class Node
{
public:
    int item;
    Node *left;
    Node *right;
};
class BST
{
private:
    Node *root;

public:
    BST();
    bool isEmpty();
    void insertNode(int);
    void preorder(Node*);
    void inorder(Node*);
    void postorder(Node*);
    Node* deleteNode(Node*,int);
    ~BST();
};
// function definition
BST::~BST(){
    while(isEmpty()){
        deleteNode(root,root->item);
    }
}
Node* BST::deleteNode(Node* root,int data){
    if(isEmpty()){
        return NULL;
    }
    struct Node*ptr=root;
    if(data < ptr->item){
        ptr->left=deleteNode(ptr->left,data);
    }
    else if(data>ptr->item){
        ptr->right=deleteNode(ptr->right,data);
    }
    else{
        //no child
        if(ptr->left==NULL && ptr->right==NULL){
            delete(ptr);
            return NULL;
        }
        //one child
        else if(ptr->left==NULL || ptr->right==NULL){
            Node*child=ptr->left?ptr->left:ptr->right;
            delete(ptr);
            return child;
        }
        //two child
        else{
            Node*pred,*parpred;
            parpred=ptr;
            pred=ptr->left;
            while(pred->right!=NULL){
                parpred=pred;
                pred=pred->right;
            }
            ptr->item=pred->item;
            if(parpred->left==pred){
                parpred->left=deleteNode(parpred->left,pred->item);
            }
            else{
                parpred->right=deleteNode(parpred->right,pred->item);
            }
        }
    }
            return ptr;
}
void BST::preorder(Node *root){
    Node*temp=root;
    if(temp){
        cout<<temp->item<<" ";
        preorder(temp->left);
        preorder(temp->right);
    }
}
void BST::inorder(Node *root){
    Node*temp=root;
    if(temp){
        inorder(temp->left);
        cout<<temp->item<<" ";
        inorder(temp->right);
    }
}
void BST::postorder(Node *root){
    Node*temp=root;
    if(temp){
        postorder(temp->left);
        postorder(temp->right);
        cout<<temp->item<<" ";
    }
}

void BST::insertNode(int data)
{
    Node *nn = new Node;
    nn->item = data;
    nn->left = nullptr;
    nn->right = nullptr;
    if (isEmpty())
    {
        root = nn;
    }
    else
    {
        Node *temp = root, *prev = nullptr;
        // left insertion
        while (temp)
        {
            prev = temp;

            if (nn->item < temp->item)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        if (nn->item < prev->item)
        {
            prev->left = nn;
        }
        else
            prev->right = nn;
    }
}
bool BST::isEmpty()
{
    if (root == NULL)
        return 1;
    return 0;
}
BST::BST()
{
    root = NULL;
}