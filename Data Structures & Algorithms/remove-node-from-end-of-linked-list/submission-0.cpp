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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* temp = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        int i = 0;
        while (i < n){
            fast = fast->next;
            i++;
        }

        while(fast != NULL){
            if(prev == NULL) prev = temp;
            else prev = prev->next;
            temp = temp->next;
            fast = fast->next;
        }
        
        if(prev == NULL) return temp->next;
        prev->next = temp->next;
        temp->next = NULL;
        return head;
    }
};
