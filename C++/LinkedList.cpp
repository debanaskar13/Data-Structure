#include<iostream>
#include<cmath>

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

void deleteAt(node* &head,int pos){
	/*
		delete a value from specific position of the Linked List
	*/
	int counter = 0;
	node* temp = head;
	node* toDelete;
	if(pos == 0){
		deleteAtFirst(head);
		return;
	}
	counter++;
	while(temp != NULL){
		if(counter == pos){
			toDelete = temp;
			temp->next = temp->next->next;
			delete toDelete;
			return;
		}
		temp = temp->next;
		counter++;
	}
	return;
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

bool find(node* head,int key){
	/*
		search a value in Linked List
		if value present in the Linked List then return 1 otherwise return 0
	*/
	if(head==NULL) return false;
	if(head->data == key) return true;
	return find(head->next, key);

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

node* reverse(node* &head){
	/*
		This function Reversed the Linked List
	*/
	node* prevptr = NULL;
	node* currptr = head;
	node* nextptr;
	while(currptr!=NULL){
		nextptr = currptr->next;
		currptr->next = prevptr;
		prevptr = currptr;
		currptr = nextptr;
	}
	return prevptr;
}

node* reverseRecursive(node* &head){
	/*
		This function Reversed the Linked List
	*/
	
	if(head==NULL || head->next==NULL) return head;
	node* newhead = reverseRecursive(head->next);
	head->next->next = head;
	head->next = NULL;

	return newhead;

}

void deleteLinedList(node* &head){
	/*
		Delete the Linked List
	*/
	node* toDelete;
	while(head!=NULL){
		toDelete = head;
		head = head->next;
		delete toDelete;
	}
}

int length(node* head){
	/*
		return length of Linked List
	*/
	node *temp = head;
	int len = 0;
	while(temp!=NULL){
		len++;
		temp = temp->next;
	}
	return len;
}

int size(node* head){
	/*
		return length of Linked List
	*/
	if(head==NULL) return 0;
	return size(head->next) + 1;
}

node* getNthNode(node* head,int pos){
	node *temp = head;
	int counter = 1;
	if(counter == 0) return head;

	while(temp!=NULL){
		if(counter == pos) return temp;
		temp = temp->next;
		counter++;
	}
	node* notFind = NULL;
	append(notFind,-1);
	return notFind;
}

node* returnNthNode(node* head,int pos){
	if(pos>length(head)){
		node* notFind = NULL;
		append(notFind,-1);
		return notFind;
	}
	if(pos == 1 or pos == 0) return head;
	return returnNthNode(head->next, pos - 1);
}

node* nthNodeFromEnd(node* head,int pos){
	node* newhead1 = reverse(head);
	head = reverse(newhead1);
	return getNthNode(newhead1, pos);
}

int middle(node* head){
	int len = length(head);
	if(len%2!=0)
		len++;
	return getNthNode(head,len/2)->data;
}


int main(){
	
	node* head = NULL;
	append(head,1);
	append(head,2);
	append(head,3);
	append(head,4);
	// print(head);

	insertAtFirst(head,5);
	insertAtFirst(head,6);
	insertAtFirst(head,7);
	// print(head);

	// pop(head);
	// print(head);

	// deletion(head,1);
	// print(head);

	// deleteAtFirst(head);
	// print(head);

	insertAfter(head,5,10);
	print(head);

	// cout<<search(head,10)<<endl;
	// cout<<find(head, 1)<<endl;

	// node* newhead = reverse(head);
	// print(newhead);

	// node* newhead1 = reverseRecursive(head);
	// print(newhead1);

	// deleteLinedList(newhead1);
	// print(newhead1);

	// deleteAt(newhead1,4);
	// print(newhead1);

	// cout << length(newhead1) << endl;
	// cout << size(newhead1) << endl;
	// cout << getNthNode(newhead1,2)->data<<endl;
	// cout << returnNthNode(newhead,15)->data<<endl;

	// cout << nthNodeFromEnd(head, 12)->data << endl;
	// print(head);

	// cout << middle(head) << endl;

	
	

	return 0;
}