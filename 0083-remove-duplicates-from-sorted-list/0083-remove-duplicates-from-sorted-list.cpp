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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *myNode = head;
        while (myNode != nullptr && myNode->next != nullptr)
        {
            if (myNode->val == myNode->next->val)
            {
                ListNode* temp = myNode->next;
                myNode->next = myNode->next->next;
                delete temp;
            }
            else
                myNode = myNode->next;
        }
        return head;
    }
};
