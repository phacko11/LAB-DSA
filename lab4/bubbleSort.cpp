template <class T>
void SLinkedList<T>::bubbleSort()
{
    if(this->count == 0 || this->count==1) return;
    
    bool swap;
    while(true){
        Node* temp = this->head;
        swap = true;
        while(temp->next!=NULL){
            if(temp->data > temp->next->data){
                T val = temp->data;
                temp->data = temp->next->data;
                temp->next->data = val;
                swap = false;
            }
            temp = temp->next;
        }
        if(!swap) printList();
        if(swap) break;
    }
}
