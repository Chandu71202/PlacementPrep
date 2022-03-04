// Binary Search Tree : A Binary Tree in which  : LeftChild < Parent < rightChild 

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


int getHeight(Node *visitingNode)
{
    if(visitingNode==NULL)
    {
        return 0;
    }

    int leftHeight = getHeight(visitingNode->left); // height of left sub-tree
    int rightHeight = getHeight(visitingNode->right);// height of right sub-tree
    if(leftHeight>rightHeight)
    {
        return leftHeight+1;
    }
    else
    {
        return rightHeight+1;
    }
}



void Preorder(Node *temp)
{
    // print left right 
    if(temp==NULL)
    {
        return; // to previously visited Node 
    }
    cout<<temp->data<<" : "<<getHeight(temp)<<endl; // ==> print
    Preorder(temp->left); // ==> left
    Preorder(temp->right); // ==> right
    return; // to previously visited Node
}



void Postorder(Node *temp)
{
    // left right print 
    if(temp==NULL)
    {
        return; // to previously visited Node 
    }
    Postorder(temp->left); // ==> left
    Postorder(temp->right); // ==> right
    cout<<temp->data<<" : height : "<<getHeight(temp)<<endl; // ==> print
    return; // to previously visited Node
}


void Inorder(Node *temp)
{
    // prints sorted order for BST 
    // left print right 
    if(temp==NULL)
    {
        return; // to previously visited Node 
    }
    Inorder(temp->left); // ==> left
    cout<<temp->data<<" "/*<<getHeight(temp)<<endl*/; // ==> print
    Inorder(temp->right); // ==> right
    return; // to previously visited Node
}


void printNodesinLevel(Node *vistingNode,int level)
{
    if(vistingNode==NULL)
    {
        return;
    }
    if(level==1)
    {
        cout<<vistingNode->data<<" ";
    }
    else
    {
        printNodesinLevel(vistingNode->left,level-1);
        printNodesinLevel(vistingNode->right,level-1);
    }
}


void BFS()
{
    int h = getHeight(ROOT); // height of the Tree : Height of the ROOT node
    for(int i=1;i<=h;i++) 
    {
        printNodesinLevel(ROOT,i);
    }
}

int diameter(Node *vistingNode)
{
    if(vistingNode==NULL)
    {
        return 0;
    }
    int ldiameter = diameter(vistingNode->left);
    int rdiameter = diameter(vistingNode->right);
    int lheight = getHeight(vistingNode->left);
    int rheight = getHeight(vistingNode->right);


    if(ldiameter>rdiameter)
    {
        // diameter of Left sub-tree is larger 
        if(ldiameter>(lheight+rheight+1))
        {
            return ldiameter;
        }
        else
        {
            return (lheight+rheight+1);
        }
    }
    else
    {
        if(rdiameter>(lheight+rheight+1))
        {
            return rdiameter;
        }
        else
        {
            return (lheight+rheight+1);
        }
    }
    
}

void kThSmallestElement(Node *vistingNode, int *k)
{
    // what if K is greater than number of elements in the Tree
    if(vistingNode==NULL)
    {
        return; // to previously visited Node 
    }
    kThSmallestElement(vistingNode->left,k); // ==> left
    
    if(*k!=1)
    {
        *k = *k-1;
    }
    else
    {
        cout<<vistingNode->data<<" "/*<<getHeight(temp)<<endl*/; // ==> print
        *k = *k-1;
    }  
    kThSmallestElement(vistingNode->right,k); // ==> right
    return; // to previously visited Node
}

int main()
{
   // Input : B,A,D,C,E
   // Start the insert Node operation from the ROOT node

    ROOT = insertNode(ROOT,12);
    ROOT = insertNode(ROOT,7);
    ROOT = insertNode(ROOT,13);
    ROOT = insertNode(ROOT,4);
    ROOT = insertNode(ROOT,9);
    ROOT = insertNode(ROOT,5);
    ROOT = insertNode(ROOT,10);
    ROOT = insertNode(ROOT,1);
    ROOT = insertNode(ROOT,3);
    ROOT = insertNode(ROOT,11);
   
    cout<<"DFS : InOrder : "<<endl;
    Inorder(ROOT); // Inorder always will give sorted order of values 
    cout<<"\nHeight of the Tree : "<<getHeight(ROOT);   
    cout<<"\nBFS : ";
    BFS();
    cout<<"\nDiameter of the Tree : "<<diameter(ROOT);
    cout<<"\n2nd Smallest Element : ";
    int K = 2;
    kThSmallestElement(ROOT,&K);
}