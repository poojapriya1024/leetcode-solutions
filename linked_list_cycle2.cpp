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

    // initialoze slow and fast pointers
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != nullptr && fast->next != nullptr)
    {
        //move the slow pointer by 1
        slow = slow->next;
        //move the fast pointer by 2
        fast = fast->next->next;

        // at any point of time, if they meet each other
        if (slow == fast)
            return true;
    }

    //if no cycle is detected
    return false;
    }
};
