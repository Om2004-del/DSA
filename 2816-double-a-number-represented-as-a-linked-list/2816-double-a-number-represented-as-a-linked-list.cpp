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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);

        ListNode* curr = head;
        int carry = 0;

        while (curr != nullptr) {
            int sum = curr->val * 2 + carry;

            curr->val = sum % 10;
            carry = sum / 10;

            curr = curr->next;
        }

        head = reverse(head);

        if (carry > 0) {
            ListNode* newHead = new ListNode(carry);
            newHead->next = head;
            head = newHead;
        }

        return head;
    }
};
