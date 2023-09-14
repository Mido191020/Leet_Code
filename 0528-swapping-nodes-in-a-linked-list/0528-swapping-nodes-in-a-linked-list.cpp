/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

class Solution {
public:
    ListNode* getNth(ListNode* head, int n) {
        int cnt = 0;
        for (ListNode* cur = head; cur; cur = cur->next) {
            if (++cnt == n) {
                return cur;
            }
        }
        return nullptr; // Node not found
    }

    ListNode* swapNodes(ListNode* head, int k) {
        int length = 0;
        for (ListNode* cur = head; cur; cur = cur->next) {
            length++;
        }

        int kth_back = length - k + 1;

        if (k == kth_back) {
            return head;
        }
        if (k > kth_back) {
            swap(k, kth_back);
        }

        ListNode* first = getNth(head, k);
        ListNode* last = getNth(head, kth_back);

        ListNode* first_prev = nullptr;
        ListNode* first_next = nullptr;
        ListNode* last_prev = nullptr;
        ListNode* last_next = nullptr;

        ListNode* prev = nullptr;
        for (ListNode* cur = head; cur; cur = cur->next) {
            if (cur->next == first) {
                first_prev = cur;
            }
            if (cur->next == last) {
                last_prev = cur;
            }
            prev = cur;
        }
        
        first_next = first->next;
        last_next = last->next;

        if (first_prev) {
            first_prev->next = last;
        } else {
            head = last;
        }

        if (last_prev) {
            last_prev->next = first;
        } else {
            head = first;
        }

        ListNode* temp = first->next;
        first->next = last->next;
        last->next = temp;

        return head;
    }
};
