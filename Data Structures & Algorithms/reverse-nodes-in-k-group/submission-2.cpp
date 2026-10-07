class Solution {
   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy;
        dummy.next = head;

        ListNode* groupPrevious = &dummy;

        while (true) {
            ListNode* kth = groupPrevious;

            for (int i = 0; i < k; ++i) {
                kth = kth->next;

                if (!kth) return dummy.next;
            }

            ListNode* groupNext = kth->next;

            ListNode* previous = groupNext;
            ListNode* current = groupPrevious->next;

            while (current != groupNext) {
                ListNode* next = current->next;
                current->next = previous;
                previous = current;
                current = next;
            }

            ListNode* oldFirst = groupPrevious->next;
            groupPrevious->next = kth;
            groupPrevious = oldFirst;
        }
    }
};
