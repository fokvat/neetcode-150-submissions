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
    void reorderList(ListNode* head) {
        if(!head or head->next == NULL) return;
        
        ListNode* s = head;
        ListNode* f = head->next;

        while(f != NULL and f->next != NULL){
            s = s->next;
            f = f->next->next;
        }
        
        ListNode* temp = s;
        s = s->next;
        temp->next = NULL;

        //reverse Second Part
        temp = NULL;

        while(s != NULL)
        {
            ListNode* cur = s;
            s = s->next;
            cur->next = temp;
            temp = cur;
        }

        s = head;

        // while(temp != NULL) {
        //     cout<<temp->val<<"->";
        //     temp = temp->next;
            
        // }
        
        // Merge Both
        while(s != NULL and temp != NULL){
            ListNode* cur = s;
            f = temp;
            s = s->next;
            cur->next = temp;
            temp = temp->next;
            f->next = s;
        }

        if(temp != NULL) f->next = temp;
        
    }
};
