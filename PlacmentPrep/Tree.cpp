// Binary Tree : A tree in which each node has a maximum of 2 child Nodes

#include<iostream>
using namespace std;

struct Node
{
    char data; // member 
    // Every Node atmost will be connected to two other child nodes
    Node *left = NULL; // pointer variable for storing the address of the left child Node
    Node *right = NULL; // pointer variable for storing the address of the right child Node
};

// Every Tree Requires a ROOT node ==> Originating Node
Node *ROOT = NULL; // stores the address of the ROOT NODE 

Node* createNode(char value) // creates and returns the address of a node with the value stored in it 
{
    Node *newNode = new Node(); // allocate memory
    newNode->data = value; // update the value
    return newNode; // return the address of the Newly created node
}

void Inorder(Node* sample)
{
    Node* temp=ROOT;
    if(temp==NULL)
    {
        return;
    }    
    Inorder(temp->left);
    cout<<temp->data<<" ";
    Inorder(temp->right);
    cout<<temp->data<<" ";
}
int main()
{
    //      Arrange A,B,C,D,E as a Binary Tree
    //      consider A as the root Node
    ROOT = createNode('A'); // first Node is the ROOT Node
    ROOT->left = createNode('B');
    ROOT->right = createNode('C');
    ROOT->right->left = createNode('D');
    ROOT->right->right = createNode('E');
    Inorder(ROOT);
    
}