#include<bits/stdc++.h>
using namespace std;
const int maxSize = 500;

class Queue{
public:
    int arr[maxSize];
    int l,r;

    Queue(){
        l=0;
        r=-1;
    }

    //O(1)
    void enQueue(int value){
        if(r+1 >= maxSize)
        {
            cout<<"Queue is full!";
            return;
        }
        r++;
        arr[r]=value;
    }

    //O(1)
    void deQueue(){
        if(l>r)
        {
            cout<<"Queue is empty!";
            return;
        }
        l++;
    }

    int front(){
        if(l>r)
        {
            cout<<"Queue is empty!";
            return -1;
        }

        return arr[l];
    }

    void print(){
        if(l>r)
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
        return r-l+1;
    }

};

int main()
{
    Queue q;

    q.enQueue(10);
    q.enQueue(30);
    q.enQueue(20);
    q.enQueue(30);
    q.print(); 

    q.deQueue();
    q.print();
  
  return 0;
}