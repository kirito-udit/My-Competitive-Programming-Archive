Node * removeDuplicates( Node *head) 
{
 // your code goes here
    Node *root=head;
    unordered_set<int>st;
    st.insert(head->data);
    while(head->next!=NULL){
        if(st.find(head->next->data)==st.end()){
            head=head->next;
            st.insert(head->data);
        }
        else{
            Node *temp=head;
            head->next=head->next->next;
            // delete(temp);
        }
    }
    return root;
 
}
