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
    ListNode* reverse(ListNode* newhead) {
        ListNode *heada = newhead, *temp, *nextnode;
        while (heada) {
            nextnode = heada->next;
            heada->next = temp;
            temp = heada;
            heada = nextnode;
        }
        return temp;
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *temp, *current;
        if (head == NULL || head->next == NULL)
            return head;
        int count = 1;
        temp = head;
        while (temp) {
            if (count == left)
                break;
            count++;
            current = temp;
            temp = temp->next;
        }
        ListNode* newhead = temp;
        while (temp) {
            if (count == right)
                break;
            count++;
            temp = temp->next;
        }
        ListNode* last = temp->next;
        temp->next = NULL;
        ListNode* nhead = reverse(newhead);
        newhead->next = last;
        if (left == 1)
            return nhead;
        current->next = nhead;
        return head;
    }
};