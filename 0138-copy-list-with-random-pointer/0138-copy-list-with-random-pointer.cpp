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
    //Time : O(N)
    //space : O(N)
    Node* copyRandomList(Node* head) {
        unordered_map<Node* , Node* > hash;
        Node dummy(-1);
        Node* dummyT = &dummy;
        Node* temp = head;
        hash[NULL] = NULL;
        while(temp){
            Node * newNode = new Node(temp->val);
            dummyT->next = newNode;
            hash[temp] = newNode;
            temp = temp->next;
            dummyT = dummyT->next; 
        }
        Node* newHead = dummy.next;
        for(auto &[l1,l2] : hash){
            if(l1==NULL)
                continue;
            l2->random = hash[l1->random];
        }
        return newHead;
    }
};