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
struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;   // min heap
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for(auto node: lists) {
            if(node) pq.push(node);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while(!pq.empty()) {
        ListNode* smallest = pq.top();
        pq.pop();

        curr->next = smallest;
        curr=smallest;


        if(smallest->next) pq.push(smallest->next);
        }
        return dummy->next;


    }
};