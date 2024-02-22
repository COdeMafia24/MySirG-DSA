#include<iostream>
using namespace std;
class Node
{
    public:
        Node *left;
        int item;
        Node *right;
};
class BST
{
    private:
        Node *root;
    protected:
        void preorderrec(Node*);
        void inorderrec(Node*);
        void postorderrec(Node*);
        Node* deleteNode(Node*,int);
    public:
        BST();
        bool isEmpty();
        void insert(int);
        void preorder();
        void inorder();
        void postorder();
        void del(int);
        Node* search(int);
        ~BST();
};
BST::BST()
{
    root=nullptr;
}
bool BST::isEmpty()
{
    return root==nullptr;
}
void BST::insert(int data)
{
    Node *ptr;
    Node *n=new Node;
    n->left=nullptr;
    n->item=data;
    n->right=nullptr;
    if(isEmpty())
        root=n;
    else
    {
        ptr=root;
        while(n->item!=ptr->item)
        {
            if(n->item < ptr->item)
            { //Insert in Left Subtree
                if(ptr->left!=nullptr)
                    ptr=ptr->left;
                else
                {
                    ptr->left=n;
                    break;
                }
            }
            else
            { //Insert in Right Subtree
                if(ptr->right!=nullptr)
                    ptr=ptr->right;
                else
                {
                    ptr->right=n;
                    break;
                }
            }
        }
        if(ptr->item==n->item)
            delete n;
    } 
}
void BST::preorderrec(Node *ptr)
{
    if(ptr)
    {
        cout<<" "<<ptr->item;
        preorderrec(ptr->left);
        preorderrec(ptr->right);
    }
}
void BST::preorder()
{
    preorderrec(root);
}
void BST::inorderrec(Node *ptr)
{
    if(ptr)
    {
        inorderrec(ptr->left);
        cout<<" "<<ptr->item;
        inorderrec(ptr->right);
    }
}
void BST::inorder()
{
    inorderrec(root);
}
void BST::postorderrec(Node *ptr)
{
    if(ptr)
    {
        postorderrec(ptr->left);
        postorderrec(ptr->right);
        cout<<" "<<ptr->item;
    }
}
void BST::postorder()
{
    postorderrec(root);
}
Node* BST::deleteNode(Node *ptr,int data)
{
    if(isEmpty())
        return nullptr;
    if(data <ptr->item)
        ptr->left=deleteNode(ptr->left,data);
    else if(data >ptr->item)
        ptr->right=deleteNode(ptr->right,data);
    else
    {
        //No child
        if(ptr->left==nullptr && ptr->right==nullptr)
        {
            delete ptr;
            return nullptr;
        }
        //single child
        if(ptr->left==nullptr || ptr->right==nullptr)
        {
            Node *child = ptr->left?ptr->left:ptr->right;
            delete ptr;
            return child;
        }
        //two children
        Node *pred,*parpred;
        parpred=ptr;
        pred=ptr->left;
        while(pred->right!=nullptr)
        {
            parpred=pred;
            pred=pred->right;
        }
        ptr->item=pred->item;
        if(parpred->right==pred)
            parpred->right=deleteNode(pred,pred->item);
        else if(parpred->left==pred)
            parpred->left=deleteNode(pred,pred->item);
    }
    return ptr;
}
void BST::del(int data)
{
    root=deleteNode(root,data);
}
Node* BST::search(int data)
{
    Node *ptr=root;
    while(ptr)
    {
        if(ptr->item==data)
            return ptr;
        if(data < ptr->item)
            ptr=ptr->left;
        else
            ptr=ptr->right;
    }
    return ptr;
}
BST::~BST()
{
    while(root)
        del(root->item);
}