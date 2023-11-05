int rangeCount(BTNode* root, int lo, int hi) {
    if (root == nullptr) {
        return 0;
    }

    if (root->val < lo) {
        return rangeCount(root->right, lo, hi);
    } else if (root->val > hi) {
        return rangeCount(root->left, lo, hi);
    } else {
        return 1 + rangeCount(root->left, lo, hi) + rangeCount(root->right, lo, hi);
    }
}
