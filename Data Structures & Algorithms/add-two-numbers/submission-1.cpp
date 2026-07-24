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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(-1);
        ListNode* resT = res;
        int borrow = 0;
        int sum = 0;

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        while(temp1 != NULL and temp2 != NULL){
            sum = temp1->val + temp2->val + borrow;
            borrow = sum > 9 ;
            sum = sum % 10;
            resT->next = new ListNode(sum);
            resT = resT->next;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        while(temp1 != NULL){
            sum = temp1->val + borrow;
            borrow = sum > 9 ;
            sum = sum % 10;
            resT->next = new ListNode(sum);
            resT = resT->next;
            temp1 = temp1->next;
        }

        while(temp2 != NULL){
            sum = temp2->val + borrow;
            borrow = sum > 9 ;
            sum = sum % 10;
            resT->next = new ListNode(sum);
            resT = resT->next;
            temp2 = temp2->next;
        }

        if(borrow) resT->next = new ListNode(borrow);
        return res->next;
    }
};
