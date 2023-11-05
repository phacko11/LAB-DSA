int kthSmallest(BSTNode* root, int k) {
    if (root == nullptr) {
        return -1;
    }

    int count = 0;
    stack<BSTNode*> st;

    BSTNode* current = root;
    while (current != nullptr || !st.empty()) {
        while (current != nullptr) {
            st.push(current);
            current = current->left;
        }

        current = st.top();
        st.pop();

        count++;
        if (count == k) {
            return current->val;
        }

        current = current->right;
    }

    return -1;
}
