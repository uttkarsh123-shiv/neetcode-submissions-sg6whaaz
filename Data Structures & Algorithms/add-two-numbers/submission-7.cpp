class Solution {
public:
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* prev = nullptr;

    //     while(head) {
    //         ListNode* next = head->next;
    //         head->next = prev;
    //         prev = head;
    //         head = next;
    //     }
    //     return prev;
    // }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1 = reverseList(l1);
        // l2 = reverseList(l2);

        int carry = 0;

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while(l1 || l2 || carry) {
            int sum = carry;

            if(l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
             curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }

        // ListNode* result = reverseList(dummy->next);
        // delete dummy;
        return dummy->next;
    }
};