int singleChild(BSTNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int count = 0;
    if (root->left == nullptr && root->right != nullptr) {
        count++;
    } else if (root->left != nullptr && root->right == nullptr) {
        count++;
    }

    count += singleChild(root->left);
    count += singleChild(root->right);

    return count;
}
