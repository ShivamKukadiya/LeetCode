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
 class cmp{
    public:
    bool operator() (ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = nullptr;
        ListNode* teil = nullptr;
        priority_queue<ListNode*, vector<ListNode*>,cmp> mini;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                mini.push(lists[i]);
            }
        }

        while (!mini.empty()) {
            ListNode* tr = mini.top();
            if (head == nullptr) {
                head = tr;
                teil = tr;
            } else {
                teil->next = tr;
                teil = tr;
            }
            mini.pop();

            if (tr->next != nullptr){
                mini.push(tr->next);
            }
        }
        return head;
    }
};