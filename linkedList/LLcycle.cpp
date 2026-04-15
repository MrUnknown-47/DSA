bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        ListNode *s=head, *f=head;
        while(f && f->next){
            s=s->next;
            f=f->next->next;
            if(s==f) return true;
        }
        return false;
    }