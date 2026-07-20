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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        else if(list2 == NULL) return list1;

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while(temp1 != NULL and temp2 != NULL){
            ListNode* curr = NULL;
            while(temp1 != NULL and temp2 != NULL and temp1->val <= temp2->val){
                curr = temp1;
                temp1 = temp1->next;
            }
            if(curr != NULL and curr->val <= temp2->val){
                curr->next = temp2;
            }

            curr = NULL;
            while(temp1 != NULL and temp2 != NULL and temp2->val <= temp1->val){
                curr = temp2;
                temp2 = temp2->next;
            }
            if(curr != NULL and curr->val <= temp1->val){
                curr->next = temp1;
            }
        }
        

        if(list1->val <= list2->val) return list1;
        return list2;
    }
};
