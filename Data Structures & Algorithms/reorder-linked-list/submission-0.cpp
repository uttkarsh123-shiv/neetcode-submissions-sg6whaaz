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
    void reorderList(ListNode* head) {
        vector<ListNode*> v;

        ListNode* temp = head;
        while(temp!=nullptr) {
            v.push_back(temp);
            temp=temp->next;
        }

        int l=0;
        int r=v.size()-1;

        while(l<r) {
            v[l]->next=v[r];
            l++;

            if(l==r) break;

            v[r]->next=v[l];
            r--;
        }
    v[l]->next=nullptr;
    }
};
