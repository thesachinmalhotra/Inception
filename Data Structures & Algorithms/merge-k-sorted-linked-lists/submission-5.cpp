class Solution {
   public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        auto compare = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(compare)> heap(compare);

        for (ListNode* list : lists) {
            if (list) heap.push(list);
        }

        ListNode dummy;
        ListNode* tail = &dummy;

        while (!heap.empty()) {
            ListNode* node = heap.top();
            heap.pop();

            tail->next = node;
            tail = node;

            if (node->next) heap.push(node->next);
        }

        return dummy.next;
    }
};
