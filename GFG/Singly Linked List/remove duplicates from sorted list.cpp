//delete duplicates from a sorted linked list
void remove(Node *head){
	Node *temp;
	if(head==NULL){
		return;
	}
	
	if(head->next!=NULL){
		if(head->data == head->next->data){
			temp=head->next;
			head->next=head->next->next;
			delete(temp);
			remove(head);
		}
		else{
			remove(head->next);
		}
	}
}
