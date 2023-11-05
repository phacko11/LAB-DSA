// STUDENT ANSWER BEGIN
// You can define other functions here to help you.

int Height(Node* root) {
        if (root == NULL)
            return 0;
        else
        {
            int l = Height(root->pLeft);
            int r = Height(root->pRight);
            return max(l,r) + 1;
        }
    }

int getHeight() {
        return Height(root);
}


void printInorder(Node* node) 
    { 
        if (node == NULL) 
            return; 
        printInorder(node->pLeft); 
        cout << node->value << " "; 
        printInorder(node->pRight); 
    } 

void printPreorder(Node* node) 
    { 
        if (node == NULL) 
            return; 
        cout << node->value << " "; 
        printPreorder(node->pLeft);  
        printPreorder(node->pRight); 
    }  

void printPostorder(Node* node) 
    { 
        if (node == NULL) 
            return; 
        printPostorder(node->pLeft); 
        printPostorder(node->pRight); 
        cout << node->value << " "; 
    } 

string preOrder() {
        printPreorder(root);
        return "";
    }

string inOrder() {
        printInorder(root);
        return "";
    }

string postOrder() {
        printPostorder(root);
        return "";
    }

// STUDENT ANSWER END
