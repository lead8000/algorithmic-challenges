//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
};



int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        MyQueue *sq = new MyQueue();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";

        }
        }
        cout<<endl;
    }
    }

// } Driver Code Ends

    // Function to push an element into the queue.
    void MyQueue::push(int x)
    {
        if (rear == NULL)
        {
            rear = new QueueNode(x);
            front = rear;
            return;
        }

        auto newNode = new QueueNode(x);
        rear->next = newNode;
        rear = newNode;
    }

    // Function to pop front element from the queue.
    int MyQueue::pop()
    {
        if (front == NULL)
            return -1;

        int tmp = front->data;
        auto newFront = front->next;
        delete front;
        front = newFront;

        if (front == NULL)
            rear = NULL;

        return tmp;
    }
