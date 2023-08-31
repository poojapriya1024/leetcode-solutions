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

private:
ListNode* reverse(ListNode* head)
{
    ListNode* curr = head;
    ListNode* prev = nullptr;
    ListNode* next = head;

    while(curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}
public:
    
    void reorderList(ListNode* head)  {    
    
    // if there is only one node in the list
    if(head->next == nullptr)
        return;
    
    //initialize slow and fast pointers
    ListNode* slow = head;
    ListNode* fast = head->next;

    // at the end of this loop, slow pointer reaches the mid node
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    ListNode* prev = slow->next; // this is the new head for right list
    slow->next = nullptr; //break the link

    // prev is the head of the reversed linked list
    prev = reverse(prev);
    ListNode* temp = head;

    // add alternatively starting from temp
    while(temp != nullptr && prev != nullptr)
    {
        ListNode* temp_next = temp->next;
        ListNode* prev_next = prev->next;

        temp->next = prev;
        prev->next = temp_next;

        temp = temp_next;
        prev = prev_next;
    }
}
};
