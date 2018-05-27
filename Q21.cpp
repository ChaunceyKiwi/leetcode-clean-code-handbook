class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr = new ListNode(-1);
        ListNode* dummyHead = curr;
        int carry = 0;

        while (l1 != NULL || l2 != NULL) {
            int digit = 0;
            if (l1 == NULL) {
                digit = l2->val + carry;
                l2 = l2 ->next;
            } else if (l2 == NULL) {
                digit = l1->val + carry;
                l1 = l1 ->next;
            } else {
                digit = l1->val + l2->val + carry;
                l1 = l1 ->next;
                l2 = l2 ->next;
            }

            carry = 0;
            if (digit >= 10) {
                digit -= 10;
                carry = 1;
            }

            curr->next = new ListNode(digit);
            curr = curr->next;
        }

        if (carry == 1) {
            curr->next = new ListNode(1);
            curr = curr->next;
        }

        return dummyHead->next;
    }
};
