//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        stack<Node*> pilFst, pilScd;
        auto currentFst = first, currentScd = second;

        while (currentFst != nullptr || currentScd != nullptr)
        {
            if (currentFst != nullptr){
                pilFst.push(currentFst);
                currentFst = currentFst->next;
            }
            if (currentScd != nullptr){
                pilScd.push(currentScd);
                currentScd = currentScd->next;
            }
        }
        auto sumList = pilFst.size() >= pilScd.size()? first:second;
        int rest = 0;

        while (pilFst.size() && pilScd.size())
        {
            currentFst = pilFst.top();
            pilFst.pop();
            currentScd = pilScd.top();
            pilScd.pop();

            currentFst->data += currentScd->data + rest;
            rest = (int)(currentFst->data / 10);
            currentFst->data %= 10;
        }

        if (pilFst.size() == 0 && pilScd.size() > 0)
            pilScd.top()->next = first;
        
        while (pilFst.size())
        {
            currentFst = pilFst.top();
            pilFst.pop();

            currentFst->data += rest;
            rest = (int)(currentFst->data / 10);
            currentFst->data %= 10;
        }

        while (pilScd.size())
        {
            currentScd = pilScd.top();
            pilScd.pop();

            currentScd->data += rest;
            rest = (int)(currentScd->data / 10);
            currentScd->data %= 10;
        }

        if (rest){
            auto tmp = new Node(rest);
            tmp->next = sumList;
            sumList = tmp; 
        }

        return sumList;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends