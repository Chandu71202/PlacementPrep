#include<iostream>
using namespace std;

void func()
{
    struct Node{
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

    void printReverse(Node *visitingNode)
    {
    if(visitingNode==NULL)
    return;
    printReverse(visitingNode->next);
    cout<<visitingNode->data;
    }
}

int main()
{
  int T;
  cin>>T;
  while(T>0)
  {
    int a;
    cin>>a;
    for(int i=1;i<=a;i++)
    {
      cin>>i;
      append(i);
    }
    printReverse(HEAD);
    T=T-1;
  }
}