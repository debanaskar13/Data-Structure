#include<iostream>
#include "../SinglyLinkedList.h"

using namespace std;

void evenOddPosition(node* &head){
    node *oddptr = head;
    node *evenptr = head->next;
    node *evenStart = head->next;
    while(oddptr->next!=NULL and evenptr->next!=NULL){
        oddptr->next = evenptr->next;
        oddptr = oddptr->next;
        
        evenptr->next = oddptr->next;
        evenptr = evenptr->next;
    }
    oddptr->next = evenStart;
    if(oddptr->next == NULL){
        evenptr->next = NULL;
    }
}



int main(){
	// node *head = NULL;

    // append(head, 10);
    // append(head, 20);
    // append(head, 30);
    // append(head, 40);
    // append(head, 60);
    // append(head, 70);
    // print(head);
    // insertAfter(head, 40, 50);
    // print(head);
    // evenOddPosition(head);
    // print(head);
    cout << (0 << 2) << endl;
}