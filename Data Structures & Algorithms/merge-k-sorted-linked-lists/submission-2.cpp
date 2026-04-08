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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> result;

        for(int i=0;i<lists.size();i++) {
            ListNode* temp = lists[i];

            while(temp!=nullptr) {
                result.push_back(temp->val);
                temp=temp->next;
            }
        }

         sort(result.begin(), result.end());
    
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        for(int i=0;i<result.size();i++) {
            curr->next = new ListNode(result[i]);
            curr=curr->next;
        }
        return dummy->next;
    }
};
