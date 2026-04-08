/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr) return nullptr;
        // Node* newNode = new Node(curr->val);
        Node* curr = head;

        // Insert Copy nodes
        while(curr) {
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr=newNode->next;
        }


        // assign random pointer
        curr = head;
        while(curr) {
            if(curr->random) {
                curr->next->random = curr->random->next;
            }
            curr=curr->next->next;
        }
        
        curr=head;
        Node* copyHead = head->next;
        Node* copy = copyHead;

        while(curr) {
            curr->next=curr->next->next;

            if(copy->next) {
                copy->next=copy->next->next;
            } 

            curr=curr->next;
            copy=copy->next;
        }
    return copyHead;
    }
};
