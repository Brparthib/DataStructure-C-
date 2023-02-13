#include<bits/stdc++.h>
using namespace std;

class Queue
{
public:
    int *arr;
    int cap;
    int l,r;
    int sz;

    Queue()
    {
        arr=new int[1];
        cap=1;
        l=0;
        r=-1;
        sz=0;
    }

    void removeCircular()
    {
        if(l>r)
        {
            int *tmp = new int[cap];
            int idx=0;
            for(int i=l; i<cap; i++)
            {
                tmp[idx]=arr[i];
                idx++;
            }
            for(int i=0; i<=r; i++)
            {
                tmp[idx]=arr[i];
                idx++;
            }
            swap(arr,tmp);
            delete [] tmp;
            l=0;
            r=cap-1;
        }
    }

    void increaseSize()
    {
        removeCircular();
        //size increase
        int *tmp=new int[cap*2];
        for(int i=0; i<cap; i++)
        {
            tmp[i]=arr[i];
        }
        swap(arr,tmp);
        cap=cap*2;
        delete [] tmp;

    }

    //O(1)
    void enQueue(int value)
    {
        if(sz == cap)
        {
            increaseSize();
        }
        r++;
        if(r==cap)
        {
            r=0;
        }
        arr[r]=value;
        sz++;
    }

    //O(1)
    void deQueue()
    {
        if(sz==0)
        {
            cout<<"Queue is empty!";
            return;
        }
        l++;
        if(l==cap)
        {
            l=0;
        }
        sz--;
    }

    int front()
    {
        if(sz==0)
        {
            cout<<"Queue is empty!";
            return -1;
        }

        return arr[l];
    }

    void print()
    {
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

    int getSize()
    {
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

    q.deQueue();
    q.print();
    cout<<q.front() <<endl;
    cout<<"Q size : "<<q.getSize()<<"\n";
    q.enQueue(90);
    q.print();
    cout<<q.front() <<endl;
    cout<<"Q size : "<<q.getSize()<<"\n";

//    Queue q;
//    q.enQueue(5);
//    q.enQueue(6);
//    q.enQueue(7);
//
//    cout<<"Q size : "<<q.getSize()<<"\n";
//    cout<<q.front()<<"\n";
//    q.deQueue();
//    cout<<q.front()<<"\n";
//    q.deQueue();
//    cout<<q.front()<<"\n";
//    q.deQueue();
//
//    cout<<"Q size : "<<q.getSize()<<"\n";

    return 0;
}
