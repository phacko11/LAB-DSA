// You must use the nodes in the original list and must not modify ListNode's val attribute. 
// Hint: You should complete the function mergeLists first and validate it using our first testcase example

// Merge two sorted lists
ListNode* mergeLists(ListNode* a, ListNode* b) {
    if(a == NULL && b == NULL) return NULL;
    if(b == NULL) return a;
    if(a == NULL) return b;
    ListNode* newHead = nullptr;
    ListNode* cur = nullptr;
    if(a->val < b-> val){
        newHead = a;
        cur = a;
        a= a->next;
        cur->next = nullptr;
    }
    else{
        newHead = b;
        cur = b;
        b = b->next;
        cur->next = nullptr;
    }
    while(a != NULL && b!=NULL){
        if(a->val < b->val){
            cur->next = a;
            cur = a;
            a = a->next;
            cur->next = nullptr;
        }
        else{
            cur->next = b;
            cur = b;
            b= b->next;
            cur->next = nullptr;
        }
    
    }
    if(a!=NULL) cur->next = a;
    else if(b!=NULL) cur->next = b;
    return newHead;
}

// Sort and unsorted list given its head pointer
ListNode* mergeSortList(ListNode* head) {
    if(head==NULL) return nullptr;
    if(head->next == NULL) return head;
    int size = 0;
    ListNode* temp = head;
    while(temp!= NULL){
        temp = temp->next;
        size++;
    }
    ListNode* list1 = head;
    ListNode* list2 = head;
    int val = size/2-1;
    while(val--){
        list2 = list2->next;
    }
    temp = list2->next;
    list2->next = nullptr;
    list2 = temp;
    list1 = mergeSortList(list1);
    list2 = mergeSortList(list2);
    
    return mergeLists(list1,list2);
}
