class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* curr = dummyHead;
        curr->next = head;

        while (curr != NULL && curr->next != NULL && curr->next->next != NULL) {
            ListNode* first = curr->next;
            ListNode* second = curr->next->next;
            ListNode* thrid = curr->next->next->next;

            curr->next = second;
            second->next = first;
            first->next = thrid;
            curr = first;
        }

        return dummyHead->next;
    }
};
