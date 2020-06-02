//nth node from the end of the linked list
//two pointer method
int nthNode(Node *head,int n){
	Node *curr=head;
	Node *prev=head;
	
	for(int i=1;i<=n;i++){
		curr=curr->next;
		if(curr==NULL and i!=n){//for last node
			return -1;
		}
	}
	
	while(curr){
		curr=curr->next;
		prev=prev->next;
	}
	
	return prev->data;
}
