#include<iostream>
#include<vector>

using namespace std;

class node{

	public:
		int data;
		node* next;

	node(int val){
		data = val;
		next = NULL;
	}
};

void insertAtFirst(node* &head,int val){
	/*
		insert value at first of the Linked List
	*/
	node* n =new node(val);
	n->next = head;
	head = n;
}

void append(node* &head,int val){
	/*
		insert value at last of the Linked List
	*/
	node* n = new node(val);
	
	if(head==NULL){
		head = n;
		return;
	}
	

	node* temp = head;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp ->next = n;
}

void insertAfter(node* head,int prevVal,int val){
	/*
		insert a value after a specific value in a Linked List
	*/
	if(head==NULL){
		return;
	}

	node* n = new node(val);
	
	node* temp = head;
	while(temp->data != prevVal){
		temp = temp->next;
	}
	n->next = temp->next;
	temp->next = n;
}

void pop(node* &head){
	/*
		delete value at last of the Linked List
	*/
	node* temp = head;

	while(temp->next->next!=NULL){
		temp = temp->next;
	}
	node* toDelete = temp->next;
	temp ->next = NULL;
	delete toDelete;
}

void deleteAtFirst(node* &head){
	/*
		delate value at first of the Linked List
	*/
	if(head == NULL){
		return;
	}

	node* toDelete = head;
	head = head->next;
	delete toDelete;
}

void deletion(node* &head,int val){
	/*
		delete specific value from the Linked List
	*/
	if(head == NULL){
		return;
	}

	if(head->next==NULL){
		deleteAtFirst(head);
		return;
	}


	node* temp = head;

	while(temp->next->next!=NULL){
		if(temp->next->data == val){
			node* toDelete = temp->next;
			temp->next = temp->next->next;
			delete toDelete;
			return;
		}
		temp = temp->next;
	}

}

bool search(node* head,int key){
	/*
		search a value in Linked List
		if value present in the Linked List then return 1 otherwise return 0
	*/
	while(head!=NULL){
		if(head->data==key)
			return 1;
		head = head->next; 
	}
	return 0;
}

void print(node* head){
	/*
		Display all value in Linked List
	*/
	node* temp = head;

	while(temp!=NULL){
		cout<<temp->data<<" -> ";
		temp = temp->next;
	}cout<<"NULL"<<endl;
}

void reverse(node* &head){
	node* prevptr = NULL;
	node* currptr = head;
	node* nextptr;
	while(currptr!=NULL){
		nextptr = currptr->next;
		currptr->next = prevptr;
		prevptr = currptr;
		currptr = nextptr;
	}
	head = prevptr;
}

node* reverseRecursive(node* &head){
	
	if(head==NULL || head->next==NULL){
		return head;
	}

	node* newhead = reverseRecursive(head->next);
	head->next->next = head;
	head->next = NULL;

	return newhead;

}


int main(){
	
	node* head = NULL;
	append(head,1);
	append(head,2);
	append(head,3);
	append(head,4);

	print(head);
	insertAtFirst(head,5);
	insertAtFirst(head,6);
	insertAtFirst(head,7);

	print(head);
	// pop(head);
	// print(head);
	// deletion(head,1);
	// print(head);
	// deleteAtFirst(head);
	// print(head);
	insertAfter(head,5,10);
	print(head);

	cout<<search(head,10)<<endl;
	node* newhead = reverseRecursive(head);
	print(newhead);
	reverse(newhead);
	print(newhead);


	return 0;
}