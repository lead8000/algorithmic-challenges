/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        int n = 1;
        ListNode *tail=new ListNode(head->val), *currNode = head->next;
        while (currNode != nullptr) {
            ListNode *newTail = new ListNode(currNode->val, tail);
            tail=newTail;
            currNode=currNode->next;
            n++;
        }

        int maxTwinSum = 2;
        currNode = head;
        for(int i=0; i<n/2; i++) {
            maxTwinSum = max(maxTwinSum, currNode->val + tail->val);
            currNode=currNode->next;
            tail = tail->next;
        }

        return maxTwinSum;
    }
};