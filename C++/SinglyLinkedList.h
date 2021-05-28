#include "LinkedList.cpp"
#include "SinglyLinkedList.cpp"

void insertAtFirst(node* &head,int val);
void append(node* &head,int val);
void insertAfter(node* head,int prevVal,int val);
void pop(node* &head);
void deleteAtFirst(node* &head);
void deletion(node* &head,int val);
void deleteAt(node* &head,int pos);
bool search(node* head,int key);
bool find(node* head,int key);
void print(node* head);
node* reverse(node* &head);
node* reverseRecursive(node* &head);
void deleteLinedList(node* &head);
int length(node* head);
int size(node* head);
node* getNthNode(node* head,int pos);
node* returnNthNode(node* head,int pos);
node* nthNodeFromEnd(node* head,int pos);
int middle(node* head);
int occurence(node* head,int key);
int occurenceRecursive(node* head,int key);
bool isPalindrome(node* head);
bool checkPalindrome(node* head);
void swapNodes(node* &head,int x,int y);
void makeCycle(node* &head,int pos);
bool detectCycle(node* &head);
int lengthOfLoop(node* head);