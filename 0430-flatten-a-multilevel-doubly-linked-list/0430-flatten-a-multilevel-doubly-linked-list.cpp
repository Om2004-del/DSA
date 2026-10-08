/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {

        if (head == NULL)
            return head;

        Node* curr = head;

        while (curr != NULL) {

            if (curr->child != NULL) {

                // Save original next
                Node* next = curr->next;

                // Child ko next banao
                curr->next = curr->child;
                curr->child->prev = curr;

                // Child pointer remove
                curr->child = NULL;

                // Child list ke last node tak jao
                Node* temp = curr->next;

                while (temp->next != NULL) {
                    temp = temp->next;
                }

                // Child list ko original next se connect karo
                temp->next = next;

                if (next != NULL) {
                    next->prev = temp;
                }
            }

            curr = curr->next;
        }

        return head;
    }
};