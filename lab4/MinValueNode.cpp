 Node* minValueNode(Node* node){
        Node* curr = node;
        while (curr && curr->pLeft != NULL){
            curr = curr->pLeft;
        }
        return curr;
    }
    Node* addNode(Node* root, T value){
        if(root == NULL) {
            Node* newNode = new Node(value);
            return newNode;
        }

        if(root->value > value){
            root->pLeft = addNode(root->pLeft, value);
        }

        if(root->value <= value){
            root->pRight = addNode(root->pRight, value);
        }
        return root;       
    }

    Node* delNode(Node* root, T value){
        if(root == NULL){
            return root;
        }

        if(root->value < value){
            root->pRight = delNode(root->pRight, value);
        }
        else if(root->value > value){
            root->pLeft = delNode(root->pLeft, value);
        }
        else if(root->value == value && root->pLeft == NULL){
            Node* temp = root->pRight;
            free(root);
            return temp;
        }
        else if(root->value == value && root->pRight == NULL){
            Node* temp = root->pLeft;
            free(root);
            return temp;
        }
        else if(root->value == value && root->pRight != NULL && root->pLeft != NULL){
            Node* temp = minValueNode(root->pRight);
            root->value = temp->value;
            root->pRight = delNode(root->pRight, temp->value);
        }
        return root;
    }
    void add(T value){
        root = addNode(root, value);
    }

    void deleteNode(T value) {
        //TODO
        root = delNode(root, value);
    }
