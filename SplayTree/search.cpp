Node* searchCur(Node* node, int val) {
        if (!node || node->val == val) {
            return node;
        }

        if (val < node->val) {
            return searchCur(node->pLeft, val);
        } else {
            return searchCur(node->pRight, val);
        }
    }

Node* findLast(Node* node, int val) {
        Node* last = nullptr;
        while (node) {
            last = node;

            if (val < node->val) {
                node = node->pLeft;
            } else {
                node = node->pRight;
            }
        }
        return last;
    }
    
 bool search(int val) {
        Node* foundNode = searchCur(this->root, val);
        if (foundNode) {
            splay(foundNode); 
            return true;
        } else {
            splay(findLast(this->root, val));
            return false;
        }
    }

    
    
