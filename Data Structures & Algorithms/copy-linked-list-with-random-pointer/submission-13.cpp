class Solution {
   private:
    std::unordered_map<Node*, Node*> copies;

   public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        if (copies.count(head)) return copies[head];

        Node* copy = new Node(head->val);
        copies[head] = copy;

        copy->next = copyRandomList(head->next);
        copy->random = copies[head->random];

        return copy;
    }
};
