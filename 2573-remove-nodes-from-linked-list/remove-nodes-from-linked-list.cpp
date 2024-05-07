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
    ListNode* GetPoint(ListNode* n, int v){
        while(n->next->val >= v) n = n->next;
        return n;
    }
    ListNode* removeNodes(ListNode* head) {
        ListNode* curr = head->next;
        int max = head->val, prev = head->val;
        while(curr){
            if(curr->val > max){
                //Move head to here
                max = curr->val;
                head = curr;
            } else if(curr->val > prev) {
                ListNode* ch = GetPoint(head, curr->val);
                ch->next = curr;
            }
            prev = curr->val;
            curr = curr->next;
        }
        return head;
    }
};