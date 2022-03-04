#include<iostream>
using namespace std;

struct Node
{
    int data; // member 
    // Every Node atmost will be connected to two other child nodes
    Node *left = NULL; // pointer variable for storing the address of the left child Node
    Node *right = NULL; // pointer variable for storing the address of the right child Node
};

// Every Tree Requires a ROOT node ==> Originating Node
Node *ROOT = NULL; // stores the address of the ROOT NODE 

Node* createNode(int value) // creates and returns the address of a node with the value stored in it 
{
    Node *newNode = new Node(); // allocate memory
    newNode->data = value; // update the value
    return newNode; // return the address of the Newly created node
}


// visitingNode : CurrentNode that is being visited
// value : Value to be inserted 
Node* insertNode(Node *vistingNode,int value) // return the address of the child Node to the parent Node
{
    if(vistingNode==NULL)
    {
        //1. Create a newNode
        Node *newNode = createNode(value);
        //2. return the address of the newNode to parent Node
        return newNode;
    }
    else
    {
        if(vistingNode->data < value) // (Value of the current Node) < (Value to be inserted)
        {
            // visit the right side
            vistingNode->right = insertNode(vistingNode->right,value);
            // ParentNode's right child address  = insertNode(righChild,value)
        }
        else
        {
            // visit the left side
            vistingNode->left = insertNode(vistingNode->left,value);
            // ParentNode's left child address  = insertNode(leftChild,value)
        }
        return vistingNode;
    }
}

void Inorder(Node *temp)
{
    // left print right 
    if(temp==NULL)
    {
        return; // to previously visited Node 
    }
    Inorder(temp->left); // ==> left
    cout<<temp->data<<" "; // ==> print
    Inorder(temp->right); // ==> right
    return; // to previously visited Node
}
void Preorder(Node* temp)
{
    if(temp==NULL)
    {
        return;
    }    
    
    cout<<temp->data<<" ";
    Preorder(temp->left);
    Preorder(temp->right);
    return;
}
void Postorder(Node* temp)
{
    if(temp==NULL)
    {
        return;
    }    
    Postorder(temp->left);
    Postorder(temp->right);
    cout<<temp->data<<" ";

    return;
}
int main()
{
   // Input : B,A,D,C,E
   // Start the insert Node operation from the ROOT node

    ROOT = insertNode(ROOT,4);
    ROOT = insertNode(ROOT,2);
    ROOT = insertNode(ROOT,6);
    ROOT = insertNode(ROOT,1);
    ROOT = insertNode(ROOT,3);
    ROOT = insertNode(ROOT,5);
    ROOT = insertNode(ROOT,7);
   

    Inorder(ROOT); 
    cout<<endl;// Inorder always will give sorted order of values 
    Preorder(ROOT);
    cout<<endl;
    Postorder(ROOT);
}
