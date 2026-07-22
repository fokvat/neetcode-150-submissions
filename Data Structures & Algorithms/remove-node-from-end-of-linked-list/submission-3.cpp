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

        int i = 0;
        while (i < n){
            fast = fast->next;
            i++;
        }

        if(fast == NULL) return head->next;

        while(fast->next != NULL){
            temp = temp->next;
            fast = fast->next;
        }
        
        temp->next = temp->next->next;
        return head;
    }
};
