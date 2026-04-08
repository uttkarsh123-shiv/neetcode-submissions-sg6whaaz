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
    ListNode* findmid(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next && fast->next->next) {
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
    }

    ListNode* reverseSecondHalf(ListNode* curr) {
        ListNode* prev = nullptr;

        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    void mergeBothHalves(ListNode* first, ListNode* second){
        
        while(second) {
            ListNode* temp1=first->next;
            ListNode* temp2=second->next;

            first->next = second;
            second->next=temp1;

            first=temp1;
            second=temp2;
        }
    }
    void reorderList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return;
    

    //find mid
    ListNode* mid = findmid(head);
    
    //reverse second half
    ListNode* second = mid->next;
    mid->next=nullptr;
    second = reverseSecondHalf(second);

    //merge
    mergeBothHalves(head, second);
}
};
