ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp=head;
        if(!temp || !temp->next) return head;
        while(temp->next){
            if(temp->val == temp->next->val){
                temp->next=temp->next->next;
                continue;
            }
            temp=temp->next;
        }
        return head;
    }