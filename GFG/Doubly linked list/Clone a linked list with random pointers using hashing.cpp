//clone a linked list with arbitary pointers
//O(n) time O(n) space;
#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node *next,*random;
		Node(int d){
			this->data=d;
			this->next=this->random=NULL;
		}
};
class LinkedList{
	public:
		Node *head;
		LinkedList(Node *head){
			this->head=head;
		}
		//insert at first position
		void push(int data){
			Node *newnode = new Node(data);
			newnode->next=head;
			head=newnode;
		}
		
		//print the list
		void print(){
			Node *temp=head;
			while(temp){
				Node *random = temp->random;
				int random_data=(random!=NULL)? random->data:-1;
				
				cout<<"temp->data "<<temp->data<<" random data "<<random_data<<endl;
				temp=temp->next;
			}
		}
		
		LinkedList* clone(){
			Node *originalcurr = head;//pointer to original list
			Node *clonecurr = NULL;//pointer to the cloned list
			//making a hashtable
			unordered_map<Node*,Node*>mp;
			//first traverse and make a copy of each node
			while(originalcurr!=NULL){
				clonecurr=new Node(originalcurr->data);
				mp[originalcurr]=clonecurr;
				originalcurr=originalcurr->next;
			}
			
			
			//move original curr to head again 
			originalcurr=head;
			
			//agian traverse the list and connect random pointers
			
			while(originalcurr!=NULL){
				clonecurr=mp[originalcurr];
				clonecurr->next=mp[originalcurr->next];
				clonecurr->random=mp[originalcurr->random];
				originalcurr=originalcurr->next;
			}
			
			return new LinkedList(mp[head]);
		}
};
int main(){
	LinkedList *mylist = new LinkedList(new Node(5)); 
    mylist->push(4); 
    mylist->push(3); 
    mylist->push(2); 
    mylist->push(1); 
  
    // Setting up random references. 
    mylist->head->random = mylist->head->next->next; 
  
    mylist->head->next->random = 
        mylist->head->next->next->next; 
  
    mylist->head->next->next->random = 
        mylist->head->next->next->next->next; 
  
    mylist->head->next->next->next->random = 
        mylist->head->next->next->next->next->next; 
  
    mylist->head->next->next->next->next->random = 
        mylist->head->next; 
  
    // Making a clone of the original 
    // linked list. 
    LinkedList *clone = mylist->clone(); 
  
    // Print the original and cloned  
    // linked list. 
    cout << "Original linked list\n"; 
    mylist->print(); 
    cout << "\nCloned linked list\n"; 
    clone->print(); 
}
