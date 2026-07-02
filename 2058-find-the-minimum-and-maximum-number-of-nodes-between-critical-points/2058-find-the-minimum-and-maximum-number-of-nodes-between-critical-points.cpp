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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) return {-1, -1};

        int index = 1; // start from second node
        int firstCP = -1, lastCP = -1, minDist = INT_MAX;
        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr->next != nullptr) {
            int valPrev = prev->val;
            int valCurr = curr->val;
            int valNext = curr->next->val;

            if ((valCurr > valPrev && valCurr > valNext) ||
                (valCurr < valPrev && valCurr < valNext)) {
                if (firstCP == -1) firstCP = index;
                else {
                    minDist = min(minDist, index - lastCP);
                }
                lastCP = index;
            }

            prev = curr;
            curr = curr->next;
            index++;
        }

        if (firstCP == -1 || lastCP == firstCP) return {-1, -1};
        return {minDist, lastCP - firstCP};
    }
};

