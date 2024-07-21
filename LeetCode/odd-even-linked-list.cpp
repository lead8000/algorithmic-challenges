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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) 
            return head;
        
        ListNode *oddIdx  = head, *currOddIdx = head;
        ListNode *evenIdx = head->next, *currEvenIdx = head->next;
    
        while (currOddIdx != nullptr && currEvenIdx != nullptr) {
            currOddIdx->next = currOddIdx->next->next;            
            if (currOddIdx->next != nullptr)
                currOddIdx  = currOddIdx->next;
            if (currEvenIdx->next != nullptr) {
                currEvenIdx->next = currEvenIdx->next->next;
                currEvenIdx = currEvenIdx->next;
            }
            else {
                currEvenIdx = nullptr;
            }
        }

        currOddIdx->next = evenIdx;
        return oddIdx;
    }
};