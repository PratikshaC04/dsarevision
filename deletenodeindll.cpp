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
    void deleteNode(ListNode* node) {
 

        if (node == nullptr || node->next == nullptr) return; // Safety check

        ListNode* temp = node->next; // Store next node
        node->val = temp->val;       // Copy next node's value into current node
        node->next = temp->next;     // Skip next node

        delete temp; // Free memory
    



    }
};
