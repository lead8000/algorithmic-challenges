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
    ListNode* deleteMiddle(ListNode* head) {
        int n = 1;
        ListNode* curr = head;
        while(curr->next != nullptr) {
            curr = curr->next;
            n++;
        }
        int middle = n/2;

        ListNode* prevNode = nullptr;
        curr = head;
        for (int i = 0; i<middle; i++) {
            prevNode = curr;
            curr = curr->next;
        }

        if (prevNode != nullptr) {
            prevNode->next = curr->next;
        }
        else {
            delete curr;
            return nullptr;
        }

        delete curr;
        return head;
    }
};