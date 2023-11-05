// STUDENT ANSWER BEGIN
bool findRecur(Node* root, T data){
        if(root == NULL) return false;

        if(root->value == data) return true;
        else if(root->value > data){
            return findRecur(root->pLeft, data);
        }
        else if(root->value < data){
            return findRecur(root->pRight, data);
        }
        return false;
    }

    T sumRecur(Node* root, T left, T right){
        if(root == NULL) return 0;

        if(root->value < left){
            return sumRecur(root->pRight, left, right);
        }  
        else if(root->value > right){
            return sumRecur(root->pLeft, left, right);
        }   
        else{
            return root->value + sumRecur(root->pRight, left, right) + sumRecur(root->pLeft, left, right);
        }   
    }
    //HELPING FUCNTION
    bool find(T i) {
        // TODO: return true if value i is in the tree; otherwise, return false.
        return findRecur(this->root, i);
    }

    T sum(T l, T r) {
        // TODO: return the sum of all element in the tree has value in range [l,r].
        return sumRecur(this->root, l, r);
    }
// STUDENT ANSWER END
