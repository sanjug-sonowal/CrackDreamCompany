// Last updated: 18/10/2025, 09:08:04
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode *temp = head;

        //count the total number of the linked list
        while(temp)
        {
            count++;
            temp = temp->next;
        }

        //update the count
        count -= n;

        ListNode *curr = head;
        ListNode *prev = NULL;

        //check for first node to be deleted edge case
        if(count == 0)
        {
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        while(count--)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        delete curr;
        return head;
    }
};