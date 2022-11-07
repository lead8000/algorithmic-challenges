//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    void swapNode(Node *prevFst, Node *prevScd, Node *fst, Node *scd){
        if (prevFst != nullptr)
            prevFst->next = scd;
        if (prevScd != nullptr)
            prevScd->next = fst;
        auto tmp = fst->next;
        fst->next = scd->next;
        scd->next = tmp;
    }
    vector<Node*> sortFirstXs(Node *head, int x, Node *previousFirst = nullptr){
        auto first = head, current = head, newHead = head;
        Node *previous = nullptr;
        int count = 0;

        while (current != nullptr)
        {
            if (current->data == x){
                if (count == 0){
                    newHead = current;
                    count++;
                }
                swapNode(previous, previousFirst, current, first);
                previousFirst = current;
                first = current->next;
            }
            previous = current;
            current = current->next;
        }
        return vector<Node*>{ newHead, first, previousFirst };
    }
    void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}
// WRONG !!!!!!!
// 5
// 2 2 1 2 1
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        // sort 0s at first
        auto result = sortFirstXs(head, 0);
        auto newHead = result[0];
        printList(newHead);
        cout<<head<<endl<<result[1]<<endl;
        // sort 1s at end
        head = result[1];
        sortFirstXs(head, 1);
        return newHead;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends