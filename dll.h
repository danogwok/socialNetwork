// dll.h
// header file for doubly linked list (dll)

#include <iostream>
using namespace std;

#ifndef DLL_H
#define DLL_H

template <typename T>
class dll{
public:
  struct node
  {
    T info;
    struct node* next;
    struct node* prev;
    node(T i) : info(i), next(0), prev(0) {}
    T getData() { return info; }
  };

private:
  node* head; //first element of list
  node* tail; //last element of list
  int count;  //size of doubly linked list (number of elements)


 
 public:

  node* firstNode() { return head;}

  node* lastNode() { return tail; }


  dll(){
    head = NULL;
    tail = NULL;
    count = 0;
  }


  ~dll(){
    while(head != 0){
      node* temp = head;
      head = head->next;
      delete temp;
    }
  }

  node* addToEnd(T data){
    node* n = new node(data);
    if(head == NULL){            //if list is empty
      head = n;
      tail = head;
      head->prev = NULL;
      head->next = NULL;
      count++;
    }
    else{                             //if list is non empty
      tail->next = n;
      tail->next->prev = tail;
      tail = n;
      count++;
    }
    return n;
  }
  

  void remove(node* n){
    if(n == NULL)                  //if list is empty
      return;
    else if (n == head && n == tail) {
    	delete n;
	head = NULL;
	tail = NULL;
	return;
    }
    else if (n == head) {
	node* newHead = head->next;
	newHead->prev = NULL;
	head = newHead;
    }
    else if (n == tail) {
    	node* newTail = tail->prev;
	newTail->next = NULL;
	tail = newTail;
    }
    else {
	node* prevNode = n->prev;
	node* nextNode = n->next;
	prevNode->next = nextNode;
	nextNode->prev = prevNode;
    } 
    delete n;
    count--;
  }
  
  
  T getData(int index){
    node* temp = head;
    for(int i = 0; i < index; i++)
      temp = temp->next;
    cout << temp->info << endl;

  }
  

  int getSize(){
    int size = 0;
    node* temp = head;
    while(temp){
      size++;
      temp = temp->next;
    }
    cout << size << endl;
    return size;
  }
  

  bool isInList(T data){
    node* temp = head;
    while(temp){
      if(temp->info == data){
	cout << data << " is in list" << endl;
	return true;
      }
      else
	temp = temp->next;
    }
    cout << data << " is not in list" << endl;
    return false;
  }

  void setIterator(node* np){
    np = firstNode();
  }

   void getNext(node* np){
     if(np == NULL)
       return;
     else
       np = np->next;
  }
  

   void printAllNodes(){
    node* temp = head;
    while(temp){
      cout << temp->info << endl;
      temp = temp->next;
    }
   }

};

#endif

