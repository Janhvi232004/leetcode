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
    ListNode* mergeTwoLists(ListNode* a,ListNode* b)
    {
        ListNode* dummy=new ListNode();
        ListNode*tail=dummy;
        while(a!=NULL && b!=NULL){
            if(a->val<b->val){
                tail->next=a;
                a=a->next;
            }
            else{
                tail->next =b;
                b=b->next;

            }
            tail=tail->next;
        }
         if(a!=NULL) tail->next=a;
        else tail->next=b;
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        ListNode* result =lists[0];
        for(int i=1;i<lists.size();i++){
            result=mergeTwoLists(result,lists[i]);
        }
        return result;
        
        
    }
};