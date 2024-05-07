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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        ListNode* a = head;
        ListNode* reversed = reverse(a);

        ListNode* b = new ListNode(-1);
        ListNode* ans = b;
        
        ListNode* temp = reversed;
        int carry = 0;
        while(temp != NULL){
            int value = temp->val;
            int doubledValue = value*2;

            int digit = doubledValue%10 + carry;
            b->next = new ListNode(digit);
            b = b->next;

            temp = temp->next;
            carry = doubledValue/10;
        }

        if(carry != 0){
            b->next = new ListNode(carry);
            b = b->next;
        }


        ListNode* ans2 = reverse(ans->next);
        return ans2;
    }
};