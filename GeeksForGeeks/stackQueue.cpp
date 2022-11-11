//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

class StackQueue{
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int B);
    int pop();
};

int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        StackQueue *sq = new StackQueue();

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


/* The structure of the class is
class StackQueue{
private:   
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */

//Function to push an element in queue by using 2 stacks.
void StackQueue :: push(int x)
{
    s1.push(x);
}

void move_to(stack<int> *s1, stack<int> *s2){
    while (s1->size() > 0)
    {
        s2->push(s1->top());
        s1->pop();
    }
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
    if (s1.size() == 0)
        return -1;
    move_to(&s1, &s2);
    int tmp = s2.top();
    s2.pop();
    move_to(&s2, &s1);
    return tmp;
}
