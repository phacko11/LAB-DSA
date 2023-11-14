 void printInorderRec(Node* node) 
    { 
        if (node == NULL) 
            return; 
        printInorderRec(node->pLeft); 
        cout << node->data << " "; 
        printInorderRec(node->pRight); 
    } 

    bool findRec(Node* node, T i) {
        if (node == NULL) return false;
        else if (node->data == i) return true;
        else if (node->data > i) return findRec(node->pLeft, i);
        else return findRec(node->pRight, i);
    }

    void printInorder() {
        // TODO
        this->printInorderRec(this->root);
    }

    bool search(T value) {
        // TODO
        return this->findRec(this->root, value);
    }
