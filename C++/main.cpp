#include<iostream>
#include "SinglyLinkedList.h"


int main(){
    node *head = NULL;

    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    print(head);
    insertAfter(head, 20, 50);
    print(head);
    cout << length(head);
    
}