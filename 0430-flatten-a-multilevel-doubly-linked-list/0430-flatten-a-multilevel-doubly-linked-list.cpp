/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    // time : O(N)
    // space : O(N)
    
    Node* flatten(Node* head) {
        if(!head)
            return NULL;
        if(head->child)
        {
            Node* tempNext = head->next;
            Node* recurChild = flatten(head->child);
            head->next = recurChild;
            if(recurChild)
                recurChild->prev = head;
            Node* tail = head;
            while(tail->next)
                tail=tail->next;
            Node* recurNext = flatten(tempNext);
            tail->next = recurNext;
            if(recurNext)
                recurNext->prev = tail;
            head->child = NULL;
        }
        else{
            Node* recurNext = flatten(head->next);
            head->next = recurNext;
            if(recurNext)
                recurNext->prev = head;
        }
        return head;
    }
};