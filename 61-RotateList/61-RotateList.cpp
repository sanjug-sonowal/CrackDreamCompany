// Last updated: 18/10/2025, 09:07:32
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
    ListNode* rotateRight(ListNode* head, int k) {
        //step count of the linked list
   
if(head == NULL || head->next == NULL)
return head;
        int count = 0;
        ListNode *temp = head;
        while(temp)
        {
            count++;
            temp = temp->next;
        }

        k = k % count;
        if(k == 0)
        return head;

        count -= k;

        ListNode *curr = head;
        ListNode *prev = NULL;

        while(count--)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = NULL;
        ListNode *Tail = curr;

        //second list ko tail ko null hone tk travcerse kro
        while(Tail->next != NULL)
        {
            Tail = Tail->next;
        }

        Tail->next = head;
        return curr;
    }
};