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

// class Node{
//     public:
//     ListNode* node;
//     int row;

//     Node(ListNode* node, int row){
//         this->node = node;
//         this->row = row;
//     }
// };

class cmp{
    public:
    bool operator() (ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);

        ListNode* head = NULL;
        ListNode* tail = NULL;
        priority_queue<ListNode*, vector<ListNode*>, cmp> mini;

        for(int i=0; i<lists.size(); i++){
            if(lists[i] != NULL)
                mini.push(lists[i]);
        }

        while(!mini.empty()){
            ListNode* minNode = mini.top();
            
            //add miniNode to ans List
            if(head == NULL){
                head = minNode;
                tail = minNode;
            }

            else{
                tail -> next = minNode;
                tail = minNode;
            }

            mini.pop();
        
            if(minNode->next != NULL){
                //insert next node of minNode List
                mini.push(minNode->next);
            }
        }
        
        return head;
    }
};