/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode* next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k, nullptr);

        // Step 1: Count total nodes
        int length = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            length++;
            temp = temp->next;
        }

        // Step 2: Find base size and extra nodes
        int baseSize = length / k;   // minimum nodes per part
        int extra = length % k;      // leftover nodes to distribute

        // Step 3: Split into k parts
        ListNode* curr = head;
        for (int i = 0; i < k; i++) {
            ans[i] = curr;  // start of this part

            int partSize = baseSize;          // every part gets baseSize nodes
            if (i < extra) partSize += 1;     // first 'extra' parts get one extra node

            // move curr to the end of this part
            for (int j = 0; j < partSize - 1 && curr != NULL; j++) {
                curr = curr->next;
            }

            // cut the list
            if (curr != NULL) {
                ListNode* nextPart = curr->next;
                curr->next = NULL;
                curr = nextPart;
            }
        }

        return ans;
    }
};
