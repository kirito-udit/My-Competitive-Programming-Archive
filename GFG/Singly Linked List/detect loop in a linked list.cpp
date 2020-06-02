//detect loop in a linkes list 
//using slow and fast pointer
bool loop(Node *head){
	Node *fast=head,*slow=head;
	while(slow and fast and fast->next){
		slow=slow->next;
		fast=fast->next->next;
		if(fast==slow){
			return true;
		}
	}
	return false;
}
