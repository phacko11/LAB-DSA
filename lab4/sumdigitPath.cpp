void dfs(BTNode* root, int path_sum, int& sum) {
  path_sum = (path_sum * 10 + root->val) % 27022001;
  
  if (root->left == NULL && root->right == NULL) {
    sum += path_sum;
    return;
  }

  if (root->left) dfs(root->left, path_sum, sum);
  
  if (root->right) dfs(root->right, path_sum, sum);
  
}

int sumDigitPath(BTNode* root) {
  if (root == NULL) return 0;

  int sum = 0;
  int path_sum = 0;
  dfs(root, path_sum, sum);
  return sum % 27022001;
}
