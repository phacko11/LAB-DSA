int maxLevel(BTNode* cur){
    if(cur==NULL ) return 0;
    
    int left = maxLevel(cur->left);
    int right = maxLevel(cur->right);
    
    return max(left,right) + 1;
    
}
int max(BTNode* cur,int level){
    
    if(cur==NULL && level == 0 ) return 0;
    else if(cur==NULL) return INT8_MIN;
    int left = max(cur->left,level - 1);
    int right = max(cur->right,level - 1);
    return max(left,right) + cur->val;
    
}
int longestPathSum(BTNode* root) {
    if(root == NULL) return 0;
    
    int level = maxLevel(root);
    
    int maxPath = 0;
    
    stack<BTNode*> s;
    s.push(root);
    while (!s.empty()) {
        BTNode* cur = s.top();
        s.pop();
        int curPath = max(cur,level);
        maxPath = max(maxPath, curPath);
        
        if (cur->left != NULL) s.push(cur->left);
        
        if (cur->right != NULL) s.push(cur->right);
        
    }

    return maxPath;
}
