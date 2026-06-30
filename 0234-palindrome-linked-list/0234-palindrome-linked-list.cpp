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
    bool isPalindrome(ListNode* head) {
        // Base case: if list is empty OR has only one node → always palindrome
        if (head == nullptr || head->next == nullptr) return true;

        // Step 1: Find the middle of the list using slow & fast pointers
        // slow moves 1 step, fast moves 2 steps
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;          // move slow by 1
            fast = fast->next->next;    // move fast by 2
        }
        // At the end, slow points to the middle node

        // Step 2: Reverse the second half of the list (starting from slow->next)
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next; // save next node
            curr->next = prev;               // reverse the link
            prev = curr;                     // move prev forward
            curr = nextNode;                 // move curr forward
        }
        // Now 'prev' points to the head of the reversed second half

        // Step 3: Compare the first half and the reversed second half
        ListNode* first = head;   // start of first half
        ListNode* second = prev;  // start of reversed second half
        while (second != nullptr) {
            if (first->val != second->val) return false; // mismatch → not palindrome
            first = first->next;
            second = second->next;
        }

        // If all values matched, it's a palindrome
        return true;
    }
};
