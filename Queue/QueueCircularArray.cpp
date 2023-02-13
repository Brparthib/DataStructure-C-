#include<bits/stdc++.h>
using namespace std;
const int maxSize = 500;

class Queue{
public:
    int arr[maxSize];
    int l,r;
    int sz;

    Queue(){
        l=0;
        r=-1;
        sz=0;
    }

    //O(1)
    void enQueue(int value){
        if(r+1 >= maxSize)
        {
            cout<<"Queue is full!";
            return;
        }
        r++;
        if(r==maxSize)
        {
            r=0;
        }
        arr[r]=value;
        sz++;
    }

    //O(1)
    void deQueue(){
        if(sz==0)
        {
            cout<<"Queue is empty!";
            return;
        }
        l++;
        if(l==maxSize)
        {
            l=0;
        }
        sz--;
    }

    int front(){
        if(sz==0)
        {
            cout<<"Queue is empty!";
            return -1;
        }

        return arr[l];
    }

    void print(){
        if(sz==0)
        {
            cout<<"Queue is empty!";
            return;
        }

        for(int i=l; i<=r; i++)
        {
          cout<<arr[i] <<" ";
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

    q.deQueue();
    q.print();
    cout<<q.front() <<endl;

    q.enQueue(90);
    q.print();
    cout<<q.front() <<endl;

  return 0;
}
