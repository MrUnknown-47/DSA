Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node* newHead = new Node(head->val);
        Node* oldTemp = head->next;
        Node* newTemp = newHead;

        unordered_map<Node*, Node*> mpp;
        mpp[head] = newHead;

        while(oldTemp != NULL){
            Node* copyNode = new Node(oldTemp->val);
            newTemp->next = copyNode;

            mpp[oldTemp] = copyNode;

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        oldTemp = head;
        newTemp = newHead;
        while(oldTemp != NULL){
            newTemp->random = mpp[oldTemp->random];
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }
        return newHead;
    }