#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;

    //enqueue O(1)
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    //size O(1)
    cout<<"Queue size: " <<q.size() <<"\n";

    //empty O(1)
    cout<<q.empty() <<"\n";

    //front O(1)
    cout<<q.front() <<"\n";

    //dequeue O(1)
    q.pop();

    cout<<q.front() <<"\n";
    q.pop();

    cout<<q.front() <<"\n";
    q.pop();
    q.pop();
    q.pop();
    cout<<q.front() <<"\n";
    q.pop();
    cout<<q.empty() <<"\n";

    return 0;
}
