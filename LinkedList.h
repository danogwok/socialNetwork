//LinkedList.h

#include <stdlib.h>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "List.h"
using namespace std;

template <typename T>
class LinkedList: public List<T>{

 public:
  struct node{
    T info;
    struct node* next;
    node(T i) : info(i), next(0) {}
    T getData() {return info;}
  };
  
 private:
  node* head;
  node* tail;
  int size;

 public:

  LinkedList(){
    head = NULL;
    tail = NULL;
    size = 0;
  }

  node* firstNode(){
    return head;
  }

  node* lastNode(){
    return tail;
  }

  int sizeOf() const{
    int count = 0;
    if(head == NULL)
      return count;
    else{
      node* temp = head;
      while(temp){
	count++;
	temp = temp->next;
      }
    }
    return count;
  }

  void changeHeadtoNext( node* oldHead){
    head = oldHead->next;
  }

  void insert(int pos, const T& item){
    if(pos < 0 || pos > sizeOf()){
      cout << "Not a valid position\n";  //If pos is not between 0 and the current length of the list.
      return;
    }
    else{
      node* n = new node(item);
      if(head == NULL){             //If the list is empty.
	head = n;
	tail = n;
	n->next = NULL;
	size++;
	return;
      }
      else if(pos == 0){            //If it is to be inserted at the front.
	n->next = head;
	head = n;
	size++;
	return;
      }
      else if(pos == sizeOf()){     //If it is to be inserted at the back.
	tail->next = n;
	tail = n;
	n->next = NULL;
	size++;
	return;
      }
      else{                         //Else it is to be inserted somwehere in the middle.
	node* temp = head;
	node* trailer = head;
	for(int i = 0; i < pos; i++){
	  temp = temp->next;
	}
	for(int j = 0; j < (pos - 1); j++){
	  trailer = trailer->next;
	}
	trailer->next = n;
	n->next = temp;
	size++;
      }
    }
  }

  void remove(int pos){
    if(pos < 0 || pos > (sizeOf() - 1)){
      cout << "Not a valid position\n";  //If pos is not between 0 and the current length of the list.
      return;
    }
    
    else if(head == NULL){               //If the list is empty
      cout << "Nothing to delete.\n";             
      return;
    }
    
    else if(pos == 0){                  //If we are deleting the first node
      node* temp = head;
      head = head->next;
      delete temp;
      size--;
    }
    
    else if(pos == (sizeOf() - 1)){      //If we are deleting the last node
      node* temp = tail;
      tail = head;
      for(int i = 0; i < (sizeOf() - 2); i++)
	tail = tail->next;
      delete temp;
      tail->next = NULL;
      size--;
    }

    else{                               //Else it is somewhere in the middle
      node* temp = head;
      node* trailer = head;
      for(int i = 0; i < pos; i++){
	temp = temp->next;
      }
      for(int j = 0; j < (pos - 1); j++){
	trailer = trailer->next;
      }
      trailer->next = temp->next;
      delete temp;
      size--;
    }
  }

  void set(int pos, const T& item){
    if(pos < 0 || pos > (sizeOf() - 1)){
      cout << "Not a valid position\n";  //If pos is not between 0 and the current length of the list.
      return;
    }
    else{
      node* temp = head;
      for(int i = 0; i < pos; i++)
	temp = temp->next;
      temp->info = item;
    }
  }

  T const& get(int pos) const{
    if(pos < 0 || pos > (sizeOf() - 1)){
      cout << "Not a valid position\n";  //If pos is not between 0 and the current length of the list.
      exit(0);
      return;
    }
    else{
      node* temp = head;
      for(int i = 0; i < pos; i++){
	temp = temp->next;
      }
      return temp->info;
    }
  }




  void print(){                        //Prints all elements in the list 
    node* temp = head;
    while(temp){
      cout << temp->info << endl;
      temp = temp->next;
    }
  }
};

#endif
