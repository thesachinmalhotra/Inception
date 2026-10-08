class Solution {
   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* kth = head;

        for (int i = 0; i < k; ++i) {
            if (!kth) return head;

            kth = kth->next;
        }

        ListNode* previous = kth;
        ListNode* current = head;

        while (current != kth) {
            ListNode* next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        head->next = reverseKGroup(kth, k);

        return previous;
    }
};
