/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* ans = new Node(-1);
        Node* res = ans;
        Node* temp = head;
        unordered_map<Node*, Node*> mp;

        while(temp != NULL){
            res->next = new Node(temp->val);
            res = res->next;
            mp[temp] = res;
            temp = temp->next;
        }

        res = ans->next;

        while(head != NULL){
            if(head->random != nullptr) {
                // cout<<res->val<<" "<<head->random<<endl;
                res->random = mp[head->random];
            }
            res=res->next;
            head = head->next;
        }

        return ans->next;
    }
};
