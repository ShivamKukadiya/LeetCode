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
    ListNode* swapPairs(ListNode* head) {
        if(head && head -> next){
            ListNode* t1 = head;
            ListNode* t2 = head->next;
            ListNode* t3 = head->next->next;
            t2->next=t1;
            t1->next=swapPairs(t3);
            head = t2;
        }
        return head;

    }
};