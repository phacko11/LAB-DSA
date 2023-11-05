// STUDENT ANSWER BEGIN
    //HELPING FUNCTIONS
    T minRecur(Node* root){
        if(root->pLeft == NULL) return root->value;
        else return minRecur(root->pLeft);
        
    }

    T maxRecur(Node* root){
        if(root->pRight == NULL) return root->value;
        else return maxRecur(root->pRight);
        
    }
    //HELPING FUNCTIONS
    T getMax(){
        return maxRecur(this->root);
    }

    T getMin(){
        return minRecur(this->root);
    }
    // STUDENT ANSWER END
