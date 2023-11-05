//Helping functions
int count(Node* node) {   
        if (node == NULL) return 0;
        else if (node->pLeft == NULL && node->pRight == NULL) return node->value + count(node->pLeft) + count(node->pRight) ;
        else return count(node->pLeft) + count(node->pRight);
}

int sumOfLeafs() {
        return count(root);
}
