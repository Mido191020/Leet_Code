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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    int len = 0;
    for (ListNode* cur = head; cur; cur = cur->next) {
        len++;
    }

    if (len == 1) {
        return nullptr;
    } else {
        int x = len - n;
        ListNode* res = head;
        ListNode* prev = nullptr; // To keep track of the previous node

        int ct = 0;
        for (ListNode* cur = head; cur; cur = cur->next) {
            if (ct == x) {
                if (prev == nullptr) {
                    // If the node to be removed is the head node
                    ListNode* temp = head;
                    head = head->next;
                    delete temp;
                } else {
                    // If the node to be removed is not the head node
                    prev->next = cur->next;
                    delete cur;
                }
                break;
            }
            prev = cur;
            ct++;
        }
        return head;
    }
}
};