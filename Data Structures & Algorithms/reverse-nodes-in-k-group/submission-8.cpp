class Solution {
public:

    ListNode* getKth(ListNode* curr, int k){
        while(curr && k>0){
            curr = curr->next;
            k--;
        }
        return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* groupPrev = dummy;

        while(true){

            ListNode* kth = getKth(groupPrev , k);

            if(kth == NULL)
                break;

            ListNode* groupNext = kth->next;

            // reverse group
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while(curr != groupNext){
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // reconnect
            ListNode* temp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = temp;
        }

        return dummy->next;
    }
};