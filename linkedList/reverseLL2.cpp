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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head->next || left == right) return head;
        
        ListNode *dummy = new ListNode(0, head);
        ListNode *beforeGrp= dummy;

        for(int i=0; i<left-1; i++){
            beforeGrp=beforeGrp->next;
        }
        ListNode* grpFirst=beforeGrp->next;

        ListNode* prev= beforeGrp;
        ListNode* curr= grpFirst;

        for(int i=0; i< right-left+1; i++){
            ListNode* next= curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        beforeGrp->next=prev;
        grpFirst->next=curr;
        return dummy->next;
    }
};