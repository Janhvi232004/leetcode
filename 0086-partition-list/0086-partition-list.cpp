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
    ListNode* partition(ListNode* head, int x) {
        ListNode* afterdum=new ListNode();
        ListNode* beforedum= new ListNode();
        ListNode* after=afterdum;
        ListNode* before=beforedum;
        while(head!=NULL){
            if(head->val < x){
                before->next=head;
                before=before->next;


            }
            else{
                after->next=head;
                after=after->next;
            }
            head=head->next;
        } 
        //attach after to null to termiate
        after->next=NULL;
        before->next=afterdum->next;
        return beforedum->next; 
    }
};