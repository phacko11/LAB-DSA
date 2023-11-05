vector<int> levelAlterTraverse(BSTNode* root) {
    vector<vector<int>> levels;
    queue<BSTNode*> q;
    bool leftToRight = true;

    if (root != nullptr) {
        q.push(root);
    }

    while (!q.empty()) {
        vector<int> currentLevel;

        int size = q.size();
        for (int i = 0; i < size; i++) {
            BSTNode* current = q.front();
            q.pop();

            if (leftToRight) {
                currentLevel.push_back(current->val);
            } else {
                currentLevel.insert(currentLevel.begin(), current->val);
            }

            if (current->left != nullptr) {
                q.push(current->left);
            }

            if (current->right != nullptr) {
                q.push(current->right);
            }
        }

        levels.push_back(currentLevel);
        leftToRight = !leftToRight;
    }

    vector<int> result;
    for (vector<int>& level : levels) {
        result.insert(result.end(), level.begin(), level.end());
    }

    return result;
}
