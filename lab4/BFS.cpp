// STUDENT ANSWER BEGIN
// You can define other functions here to help you.
void BFS()
{
    queue<Node*> q;
	if(this->root == NULL) return;
	q.push(this->root);
	cout<<root->value;
	while(!q.empty()){
	    Node* temp = q.front();
	    if(temp->pLeft != NULL) q.push(temp->pLeft);
	    if(temp->pRight != NULL) q.push(temp->pRight);
	    if(temp!=this->root) cout<<" "<<temp->value;
	    q.pop();
	}
}
// STUDENT ANSWER END
