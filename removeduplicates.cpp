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
        if (!head || !head->next) return head;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;  // Last node before duplicate sequence
        
        while (head) {
            bool isDuplicate = false;
            
            // Skip duplicates
            while (head->next && head->val == head->next->val) {
                isDuplicate = true;
                head = head->next;
            }
            
            if (isDuplicate) {
                // Remove the entire duplicate block
                prev->next = head->next;
            } else {
                prev = prev->next; // No duplicates, move prev forward
            }
            
            head = head->next; // Always move head forward
        }
        
        return dummy.next;
    }
};
