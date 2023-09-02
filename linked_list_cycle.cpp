/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

    if(head == nullptr || head->next == nullptr)
        return false;

    
    ListNode* curr = head;
    set<ListNode*> mySet;

    bool flag = true;
    while(curr != nullptr && flag)
    {   
        flag = mySet.find(curr) == mySet.end();
        if(flag)
        {    mySet.insert(curr);
             curr = curr->next;
        }
        else
            return true;    
    }
        
    return (curr == nullptr)? false:true;
    }
};
