void LinkedList::partition(int k) {
    if (this->head==NULL) return;
    Node* head1 = nullptr;
    Node* cur1 = nullptr;
    Node* head2 = nullptr;
    Node* cur2 = nullptr;
    Node* cur3 = nullptr;
    Node* head3 = nullptr;

    Node* cur = head;
    while (cur != nullptr) {
        Node* curr = new Node;
        curr->value = cur->value;
        curr->next = NULL;
        if (curr->value < k) {
            if (head1 == nullptr) {
                head1 = curr;
                cur1 = curr;
            } else {
                cur1->next = curr;
            }
            cur1 = curr;
        } else if (curr->value == k) {
            if (head2 == nullptr) {
                head2 = curr;
                cur2 = curr;
            } else {
                cur2->next = curr;
            }
            cur2 = curr;
        } else {
            if (head3 == nullptr) {
                head3 = curr;
                cur3 = curr;
            } else {
                cur3->next = curr;
            }
            cur3 = curr;
        }
        cur = cur->next;
    }

    Node* newHead = nullptr;
    Node* newCur;
    if(head1 != NULL){ 
        newHead = head1;
        newCur = head1;
        while(newCur->next != nullptr) newCur = newCur->next;
        tail = newCur;
    }
    
    
    if (head2 != nullptr) {
        if(newHead==NULL) {
            newHead = head2;
            newCur = head2;
        }
        else newCur->next = head2;
        while(newCur->next != nullptr) newCur = newCur->next;
        tail = newCur;
    }
    
    if (head3 != nullptr) {
        if(newHead==NULL) {
            newHead = head3;
            newCur = head3;
        }
        else newCur->next = head3;
        while(newCur->next != nullptr) newCur = newCur->next;
        tail = newCur;
    }
    this->head = newHead;
}
