#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *prv;
    node *nxt;
};

class Deque
{
public:
    node *head;
    node *tail;
    int sz;

    Deque()
    {
        head=NULL;
        tail=NULL;
        sz=0;
    }

    node *CreateNewNode(int value)
    {
        node *newnode = new node;
        newnode->data = value;
        newnode->nxt = NULL;
        return newnode;
    }

    void pushBack(int value)
    {
        node *newnode = CreateNewNode(value);
        if(sz==0)
        {
            head=newnode;
            tail=newnode;
            sz++;
            return;
        }
        tail->nxt=newnode;
        newnode->prv=tail;
        tail=newnode;
        sz++;
    }

    void pushFront(int value)
    {
        node *newnode = CreateNewNode(value);
        if(sz==0)
        {
            head=newnode;
            tail=newnode;
            sz++;
            return;
        }
        head->prv=newnode;
        newnode->nxt=head;
        head=newnode;
        sz++;
    }

    void popBack()
    {
        if(sz==0)
        {
            cout<<"Deque is empty!\n";
            return;
        }
        if(sz==1)
        {
            delete tail;
            sz--;
        }
        node *newnode = tail;
        tail = newnode->prv;
        tail->nxt = NULL;
        delete newnode;
        sz--;

    }

    void popFront()
    {
        if(sz==0)
        {
            cout<<"Deque is empty!\n";
            return;
        }
        if(sz==1)
        {
            delete head;
            sz--;
        }
        node *newnode = head;
        head = newnode->nxt;
        head->prv = NULL;
        delete newnode;
        sz--;
    }

    int Front()
    {
        if(sz==0)
        {
            cout<<"Deque is empty!\n";
            return -1;
        }
        return head->data;
    }

    int Back()
    {
        if(sz==0)
        {
            cout<<"Deque is empty!\n";
            return -1;
        }
        return tail->data;
    }

    void print()
    {
        if(sz==0)
        {
            cout<<"Deque is empty\n";
            return;
        }
        node *newnode=head;
        while(newnode!=NULL)
        {
            cout<<newnode->data <<" ";
            newnode = newnode->nxt;
        }
        cout<<"\n";
    }

    void reversePrint()
    {
        if(sz==0)
        {
            cout<<"Deque is empty\n";
            return;
        }
        node *newnode=tail;
        while(newnode!=NULL)
        {
            cout<<newnode->data <<" ";
            newnode = newnode->prv;
        }
        cout<<"\n";
    }

    void reverseDeque()
    {
        if(sz==0)
        {
            cout<<"Deque is empty!\n";
            return;
        }
        if(sz==1)
        {
            cout<<head->data <<"\n";
            return;
        }
        node *a = head;
        node *b = tail;
        while(b!=NULL)
        {
            swap(b->prv,b->nxt);
            b = b->nxt;
        }
        head=tail;
        tail=a;
    }

    int Size()
    {
        return sz;
    }
};

int main()
{
    Deque d;

    d.pushBack(10);
    d.pushBack(20);
    d.pushBack(30);
    d.pushBack(40);
    d.pushBack(50);
    d.pushBack(60);
    cout<<d.Front() <<endl;
    cout<<d.Back() <<endl;
    cout<<d.Size() <<endl;

    d.pushFront(5);
    d.pushFront(0);
    cout<<d.Front() <<endl;
    cout<<d.Back() <<endl;
    cout<<d.Size() <<endl;

    d.popFront();
    d.popBack();
    cout<<d.Front() <<endl;
    cout<<d.Back() <<endl;
    cout<<d.Size() <<endl;

    cout<<"\n";
    d.print();
//    d.reversePrint();

    d.reverseDeque();
    d.print();
    cout<<d.Front() <<endl;
    cout<<d.Back() <<endl;
    cout<<d.Size() <<endl;


    return 0;
}
