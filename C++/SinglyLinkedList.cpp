#include<stack>

using namespace std;

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
	/*
		Return The N'th Node From the Linked List Using Iterative Method.
	*/
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
	/*
		Return N'th Node from the Linked List Using Recursive Method
	*/
	if(pos>length(head)){
		node* notFind = NULL;
		append(notFind,-1);
		return notFind;
	}
	if(pos == 1 or pos == 0) return head;
	return returnNthNode(head->next, pos - 1);
}

node* nthNodeFromEnd(node* head,int pos){
	/*
		Return The N'th Node From END in the Linked List.
	*/
	node* newhead1 = reverse(head);
	head = reverse(newhead1);
	return getNthNode(newhead1, pos);
}

int middle(node* head){
	/*
		Return the Middle node Value of the Linked List
	*/
	int len = length(head);
	if(len%2!=0)
		len++;
	return getNthNode(head,len/2)->data;
}

int occurence(node* head,int key){
	/*
		Return The Position of the given Key in a Linked List
	*/
	node *temp = head;
	int counter = 0;

	while(temp!=NULL){
		if(temp->data == key)
			counter++;
		temp = temp->next;
	}
	return counter;
}

int occurenceRecursive(node* head,int key){
	/*
		Return The Position of the given Key in Linked List.
	*/
	if(head==NULL)
		return 0;
	if(key == head->data)
		return occurenceRecursive(head->next, key)+1;
	else
		return occurenceRecursive(head->next,key);
}

bool isPalindrome(node* head){
	/*
		Check The Linked List is Palindrome or Not Using Reverse Method
	*/
	node *temp = head;
	node* newhead = reverse(head);
	bool flag = true;
	while(temp!=NULL){
		if(temp->data != newhead->data)
			flag = false;
		temp = temp->next;
	}
	head = reverse(newhead);
	return flag;
}

bool checkPalindrome(node* head){
	/*
		Check The Linked List is Palindrome or not Using Stack.
	*/
	stack<int> s;
	node* temp = head;
	while(temp!=NULL){
		s.push(temp->data);
		temp = temp->next;
	}

	while(head!=NULL){
		int i = s.top();
		s.pop();
		if(head->data != i) return false;
		head = head->next;
	}
	return true;
}

void swapNodes(node* &head,int x,int y) {
	node *prevX = NULL;
	node* currX = head;
	node *prevY = NULL;
	node* currY = head;

	// search for x and track prev pointer
	while(currX != NULL && currX->data != x){
		prevX = currX;
		currX = currX->next;
	}

	// search for y and track prev pointer
	while(currY!=NULL && currY->data != y){
		prevY = currY;
		currY = currY->next;
	}

	// if x or y any one element not present then return
	if(currX == NULL || currY==NULL) return;

	// if x is not head of the linked list
	if(prevX != NULL){
		prevX->next = currY;
	}else{ // else make currY as a head of the Linked List
		head = currY;
	}

	// if y is not head of the Linked list
	if(prevY!=NULL){
		prevY->next = currX;
	}else{ // else make currX as a head of the Linked list
		head = currX;
	} 

	// swap next pointers
	node *temp = currX->next;
	currX->next = currY->next;
	currY->next = temp;

}

void makeCycle(node* &head,int pos){
	/*
		Make a cycle in a Linked List
	*/
	node *startNode;
	node* temp = head;
	int counter = 0;
	while(temp->next != NULL){
		if(counter == pos)
			startNode = temp;
		temp = temp->next;
		counter++;
	}
	temp->next = startNode;
}

bool detectCycle(node* &head){
	/*
		return True if cycle present in the Linked List
		Otherwise Return False
	*/
	node* slow = head;
	node* fast = head;
	while(fast!=NULL and fast->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast) return true;
	}
	return false;
}

int lengthOfLoop(node* head){
	/*
		return length of the loop in a Linked List
	*/
	node *slow = head;
	node *fast = head;
	node *startptr;

	while(fast!=NULL and fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast){
			startptr = slow;
			break;
		}
	}
	if(fast->next == NULL) return 0;
	int counter = 1;
	startptr = startptr ->next;
	while(startptr != fast){
		startptr = startptr->next;
		counter++;
	}
	return counter;
}

