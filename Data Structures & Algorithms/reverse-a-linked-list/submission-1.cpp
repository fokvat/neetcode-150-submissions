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


//  #include <bits/stdc++.h>
// using namespace std;

// class Node{
//     public:
//     int data;
//     Node* next;
    
    
//     Node(int d){
//         data = d;
//         next = NULL;
//     }
    
//     ~Node(){
//         next = NULL;
//         data = 0;
//     }
// };

// class LinkedList {
//     public:
//     Node* head;
//     Node* tail;
    
//     LinkedList (){
//         head = NULL;
//         tail = NULL;
//     }
    
//     void add(int data){
//         if(head == NULL){
//             head = new Node(data);
//             tail = head;
//             return;
//         }
        
//         Node* temp = new Node(data);
//         tail->next = temp;
//         tail = temp;
//         return;
//     }
    
//     void print(){
//         Node* temp = head;
//         while(temp != NULL){
//             cout<<temp->data<<"->";
//             temp = temp->next;
//         }
//     }
// };



// int main() {
// 	// your code goes here
	
//     // Node* head = new Node(10);
//     // Node* tail = head;
//     // cout<< head->data<<endl;
//     // cout<<head<<endl;
//     // cout<<head->next<<endl;
    
//      int arr[4] = {1, 2, 3, 4};
    
//     // for(int i=0;i<4;i++){
//     //     Node* temp = new Node(arr[i]);
//     //     tail->next = temp;
//     //     tail = temp;
//     // }
    
//     // Node* temp = head;
//     // while(temp != NULL){
//     //     cout<<temp->data<<"->";
//     //     temp = temp->next;
//     // }
    
//     LinkedList* l = new LinkedList();
//     l->add(10);
    
//     // cout<<l->head->data<<endl;
//     // cout<<l->head<<endl;
//     // cout<<l->head->next<<endl;
    
//     for(int i=0;i<4;i++){
//         l->add(arr[i]);
//     }
    
//     (*l).print();
// }



class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr){
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        while(curr != nullptr){
            next = curr;
            curr = curr->next;
            next->next= prev;

            prev=next;
        }

        return prev;
    }
};
