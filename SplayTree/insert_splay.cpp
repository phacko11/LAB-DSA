void rotateRight(Node* x) {
        Node* y = x->pLeft;
        x->pLeft = y->pRight;
        if (y->pRight) {
            y->pRight->pParent = x;
        }
        y->pParent = x->pParent;
        if (!x->pParent) {
            root = y;
        } else if (x == x->pParent->pLeft) {
            x->pParent->pLeft = y;
        } else {
            x->pParent->pRight = y;
        }
        y->pRight = x;
        x->pParent = y;
}

void rotateLeft(Node* x) {
        Node* y = x->pRight;
        x->pRight = y->pLeft;
        if (y->pLeft) {
            y->pLeft->pParent = x;
        }
        y->pParent = x->pParent;
        if (!x->pParent) {
            root = y;
        } else if (x == x->pParent->pLeft) {
            x->pParent->pLeft = y;
        } else {
            x->pParent->pRight = y;
        }
        y->pLeft = x;
        x->pParent = y;
}

 void splay(Node* p) {
        while (p->pParent) {
            Node* parent = p->pParent;
            Node* grandparent = parent->pParent;

            if (!grandparent) {
                // Zig case
                if (p == parent->pLeft) {
                    rotateRight(parent);
                } else {
                    rotateLeft(parent);
                }
            } else {
                if (p == parent->pLeft && parent == grandparent->pLeft) {
                    // Zig-zig case
                    rotateRight(grandparent);
                    rotateRight(parent);
                } else if (p == parent->pRight && parent == grandparent->pRight) {
                    // Zig-zig case
                    rotateLeft(grandparent);
                    rotateLeft(parent);
                } else {
                    // Zig-zag case
                    if (p == parent->pLeft) {
                        rotateRight(parent);
                        rotateLeft(grandparent);
                    } else {
                        rotateLeft(parent);
                        rotateRight(grandparent);
                    }
                }
            }
        }
        root = p; 
    }

void insert(int val) {
        if (!root) {
            root = new Node(val);
            return;
        }

        Node* current = root;
        Node* parent = nullptr;

        while (current) {
            parent = current;
            if (val < current->val) {
                current = current->pLeft;
            } else {
                current = current->pRight;
            }
        }

        current = new Node(val, nullptr, nullptr, parent);

        if (val < parent->val) {
            parent->pLeft = current;
        } else {
            parent->pRight = current;
        }

        splay(current); // Splay the newly inserted node to the root
}

    
