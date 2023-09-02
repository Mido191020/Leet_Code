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
     void reorderList(ListNode* head) {
        if (!head || !head->next) {
            return; // No need to reorder if the list is empty or has only one node.
        }

        // Step 1: Find the middle of the linked list.
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the linked list.
        ListNode* prev = nullptr;
        ListNode* current = slow->next;

        while (current) {
            ListNode* next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }
        slow->next = nullptr;

        // Step 3: Merge the first and reversed second halves alternatively.
        ListNode* current1 = head;
        ListNode* current2 = prev;

        while (current2) {
            ListNode* next_node1 = current1->next;
            ListNode* next_node2 = current2->next;

            current1->next = current2;
            current2->next = next_node1;

            current1 = next_node1;
            current2 = next_node2;
        }
    }
};