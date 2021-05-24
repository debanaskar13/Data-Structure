#include<iostream>

using namespace std;

int main(){

	node* head = NULL;
	append(head,1);
	append(head,2);
	append(head,3);
	append(head,4);
	append(head,5);
	append(head,6);
	print(head);
	return 0;
}