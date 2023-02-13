#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *nxt;
};

class Queue{
public:
    node *head;
    node *tail;
    int sz;

    Queue(){
        head=NULL;
        tail=NULL;
        sz=0;
    }

    node *CreateNewNode(int value){
        node *newnode = new node;
        newnode->data = value;
        newnode->nxt = NULL;
        return newnode;
    }

    void enQueue(int value){
        sz++;
        node *a = CreateNewNode(value);
        if(head==NULL)
        {
            head=a;
            tail=a;
            return;
        }
        tail->nxt=a;
        tail=a;
    }

    void deQueue(){
        if(sz==0)
        {
            cout<<"Queue is empty!\n";
            return;
        }
        if(sz==1)
        {
            delete head;
            head=NULL;
            tail=NULL;
            sz--;
            return;
        }
        node *a = head;
        head = head->nxt;
        sz--;
        delete a;
    }

    int front(){
        if(sz==0)
        {
            cout<<"Queue is empty\n";
            return -1;
        }
        return head->data;
    }

    void print(){
        if(sz==0)
        {
            cout<<"Queue is empty\n";
            return;
        }
        node *a = head;
        while(a!=NULL)
        {
            cout<<a->data <<" ";
            a = a->nxt;
        }
        cout<<"\n";
    }

    int getSize(){
        return sz;
    }
};

int main()
{
    Queue q;

    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    q.enQueue(60);
    q.print();
    cout<<q.front() <<endl;
    cout<<q.getSize() <<endl;

    q.deQueue();
    q.print();
    cout<<q.front() <<endl;
    cout<<q.getSize() <<endl;

    return 0;
}
