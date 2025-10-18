// Last updated: 18/10/2025, 09:07:04
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <map>

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *curr = head;
        std::map<ListNode*, bool> visited;

        // Traverse the nodes
        while (curr) {
            // Node is already visited, indicating a cycle
            if (visited[curr]) {
                return true;
            }

            visited[curr] = true;
            curr = curr->next;
        }

        // No cycle detected
        return false;
    }
};
