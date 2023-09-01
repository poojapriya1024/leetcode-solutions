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
        
        if(head == nullptr)
            return nullptr;
        
        unordered_map<Node*,Node*> myMap;
        Node* curr = head;

        while(curr != nullptr)
        {
            myMap[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // assign the pointers
        curr = head;
        while(curr != nullptr)
        {   
            Node* temp = myMap[curr];
            temp->next = myMap[curr->next];
            temp->random = myMap[curr->random];
            curr = curr->next;
        }

        return myMap[head];
    }
};
