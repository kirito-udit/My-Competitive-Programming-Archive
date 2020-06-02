//finding middle element of the linked list 
//use slow and fast pointers
int middle(Node *head){
	Node *fast=head,*slow=head;
	if(head==NULL){
		return -1;
	}
	while(fast and fast->next){
		fast=fast->next->next;
		slow=slow->next;
	}
	return slow->data;
}
