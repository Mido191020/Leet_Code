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
      ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head; // If the list has 0 or 1 node, no swapping is needed
        }
        
        ListNode* newHead = head->next; // New head after swapping
        ListNode* prev = nullptr;
        
        while (head && head->next) {
            ListNode* first = head;
            ListNode* second = head->next;
            
            // Swap nodes
            first->next = second->next;
            second->next = first;
            
            if (prev) {
                prev->next = second;
            }
            
            prev = first;
            head = first->next; // Move to the next pair
        }
        
        return newHead;
    }
};