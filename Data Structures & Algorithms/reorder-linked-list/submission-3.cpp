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

    ListNode* mid (ListNode* head){
        ListNode* s = head;
        ListNode* f = head;

        while(f != NULL and f->next != NULL){
            s = s->next;
            f = f->next->next;
        }
        return s;
    }

    ListNode* reverse(ListNode* head){
        ListNode* temp = NULL;

        while(head != NULL)
        {
            ListNode* prev = head;
            head =  head->next;
            prev->next = temp;
            temp = prev;
        }

        return temp;
    }
    void reorderList(ListNode* head) {
        if(!head or head->next == NULL) return;
        
        ListNode* m = mid(head);
        ListNode* list2 = reverse(m);


        ListNode* list1 = head;

        while (list2){
            ListNode* tmp1 = list1->next;
            ListNode* tmp2 = list2->next;
            list1->next = list2;
            list2->next = tmp1;
            list1 = tmp1;
            list2 = tmp2;
        }
        if (list1) list1->next = nullptr;
        
    }
};
