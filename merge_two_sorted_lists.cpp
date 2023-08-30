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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1 == nullptr)
            return list2;

        if(list2 == nullptr)
            return list1;

        ListNode temp; //create a dummy node
        ListNode* curr = &temp; 

        while(list1 != nullptr && list2 != nullptr)
        {
            if(list1->val <= list2->val)
            {
                //link the current node to this list1
                curr->next = list1;
                list1 = list1->next;
            }
            else
            {
                curr->next = list2;
                list2 = list2->next;
            }

            curr = curr->next;
        }

        //if there are any more nodes left, link them to curr
        if(list1 != nullptr)
            curr->next = list1;

        if(list2 != nullptr)
            curr->next = list2;

        return temp.next; //skip the dummy node
    }
};
