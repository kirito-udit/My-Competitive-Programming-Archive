//swap nodes without swapping data
void swapNodes(Node *&head,int x,int y){
	if(x==y){
		return;
	}
	
	Node *prevX=NULL,*currX=head_ref;
	
	while(currX and currX->data!=x){
		prevX=currX;
		currX=currX->next;
	}
	
	Node *prevY=NULL,*currY=head_ref;
	
	while(currY and currY->data!=y){
		prevY=currY;
		currY=currY->next;
	}
	//one key doest not exist
	if(currY==NULL or currX==NULL){
		return;
	}
	
	if(prevX!=NULL){
		prevX->next=currY;
	}
	else{
		head_ref=currY;
	}
	
	if(prevY!=NULL){
		prevY->next=currX;
	}
	else{
		head_ref=currX;
	}
	
	Node *temp=currY->next;
	currY->next=currX->next;
	currX->next=temp;
}
