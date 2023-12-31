Node* rightRotate(Node* y)
    {
        Node* x = y->pLeft;
        y->pLeft = x->pRight;
        x->pRight = y;
        return x;
    }
    Node* leftRotate(Node* x)
    {
        Node* y = x->pRight;
        x->pRight = y->pLeft;
        y->pLeft = x;
        return y;
    }
    int getBalance(Node* N)
    {
        if (N == NULL)
            return 0;
        return getHeightRec(N->pLeft) - getHeightRec(N->pRight);
    }
    Node* insert(Node* node, T key)
    {
        if (node == NULL)
            return(new Node(key));

        if (key < node->data)
            node->pLeft = insert(node->pLeft, key);
        else if (key >= node->data)
            node->pRight = insert(node->pRight, key);
        
        int balance = getBalance(node);
        // Left Left Case  
        if (balance > 1 && key < node->pLeft->data)
            return rightRotate(node);

        // Right Right Case  
        if (balance < -1 && key >= node->pRight->data)
            return leftRotate(node);

        // Left Right Case  
        if (balance > 1 && key >= node->pLeft->data)
        {
            node->pLeft = leftRotate(node->pLeft);
            return rightRotate(node);
        }
        // Right Left Case  
        if (balance < -1 && key < node->pRight->data)
        {
            node->pRight = rightRotate(node->pRight);
            return leftRotate(node);
        }
        return node;
    }
    void insert(const T& value)
    {
        // TODO
        this->root = insert(this->root, value);
    }
