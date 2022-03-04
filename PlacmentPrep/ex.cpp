/* #include<iostream>
using namespace std;
// user defined dataType : structure struct
// * : dereference operator a.r.a value at
struct Node
{
    int data;
    // <dataType>* name;
      Node* next;
};
Node* HEAD = NULL; // Store the address of the first Node
Node* LAST = NULL; // Store the address of the last Node 

void append(int value) // data is inserted to the end of the linkedList
{
    Node* newNode = new  Node();
    if(HEAD==NULL) // LinkedList is empty
    {
        HEAD = newNode; // newly created node is the first node 
        LAST = newNode; // as well as the last Node
        newNode->data = value; // update the value
    }
    else
    {
        LAST->next = newNode; // last node to store the address of the newly created node
        LAST = newNode; // update the newly created node as the last node
        newNode->data = value; // update the value
    }
}
void printList()
{
    Node *temp = HEAD; // temp stores the address of the first node
    while(temp!=NULL) // stop when reaching the node who has the address stored as NULL
    {
        cout<<temp->data<<" ";
        temp = temp->next; // move temp to the next node
    }
    cout<<endl;
}
int main()
{
    int size,i=0;
    cin>>size;
    int arr[size];
    for(i=0;i<size;i++){
        cin>>arr[i];
        append(arr[i]);
    }
/*     append(10);
    append(20);
    append(30);
    append(40); 
    printList();
} */


#include<iostream>
using namespace std;

struct Node
{
    /* data */
    int data;
    Node* next;
};

Node* HEAD=NULL;
Node* LAST=NULL;

void append(int value)
{
    Node* newNode=new Node();
    if(HEAD==NULL)
    {
        HEAD=newNode;
        LAST=newNode;
        newNode->data=value;
    }
    else
    {
        LAST->next=newNode;
        LAST=newNode;
        newNode->data=value;
    }
}

void PrintList()
{
    Node* temp=HEAD;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void insertAt(int value,int position)
{
    Node* newNode=new Node();
    newNode->data=value;
    int count=1;
    Node* prevNode=HEAD;
    while(count<position-1)
    {
        prevNode=prevNode->next;
        if(prevNode==NULL)
        {
            cout<<"invalid inserting position"<<endl;
            return;
        }
        count++;
    }
    newNode->next=prevNode->next;
    prevNode->next=newNode;
}
/* void PrintRerverse(Node *visitingNode)
{
    if(visitingNode==NULL)
    return;
    PrintRerverse(visitingNode->next);
    cout<<visitingNode->data<<" ";
} */
void duplicates()
{
    Node* temp=HEAD;
    while(temp!=NULL)
    {
        
    }
    
}

void maxElement()
{
    Node* temp=HEAD;
    int max;
    max=temp->data;
    while(temp->next!=NULL)
    {
        if(temp->data<temp->next->data)
        {
            max=temp->next->data;
        }
        temp=temp->next;
    }
    cout<<"MAX ELEMENT IS:"<<max;

}
void deleteFromBegining()
{
    HEAD = HEAD->next;
}
void deleteValue(int value)
{
    Node *prevNode = NULL;
    Node *currNode = HEAD;
    if(currNode->data==value)// first node to be deleted
    {
        // special case 
        deleteFromBegining();
        return;
    }
    while(currNode->data!=value)
    {
        prevNode = currNode;
        currNode= currNode->next;
        if(currNode==NULL)
        {
          cout<<"Value not present"<<endl;
          return;
        }
    }
    prevNode->next = currNode->next; // prev node to store the address of the next node of the currNode
}
int main()
{
    append(10);
    append(15);
    append(20);
/*     PrintRerverse(HEAD);
 */    
/*     insertAt(6,2);
 */    PrintList();
 /*     maxElement(); */
    deleteValue(10);
    PrintList();
    

} 