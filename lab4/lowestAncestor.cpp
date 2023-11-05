bool find(BTNode* cur, vector<int> &path, int p){
    if(cur == NULL) return false;
    path.push_back(cur->val);
    if(cur->val == p) return true;
    if((cur->left && find(cur->left,path,p)) || (cur->right && find(cur->right,path,p))) return true;
    path.pop_back();
    return false;
}
int lowestAncestor(BTNode* root, int a, int b) {
    vector<int> path1,path2;
    if(!find(root,path1,a) ||!find(root,path2,b)) return -1;
    unsigned i;
    for(i = 0;i<path1.size() && i<path2.size();i++) if(path1[i] != path2[i]) break;
    
    return path1[i-1];
    
}
