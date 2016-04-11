//dll.cpp
//implementation file of dll.h

#include "dll.h"

/*template <typename T>
dll<T>::dll(){
  head = NULL;
  tail = NULL;
  count = 0;
}*/

/*template <typename T>
dll<T>::dll(T data){
  head = new node(data);  //ceate a new node with data in its info field
  tail = head;
  head->next = NULL;
  head->prev = NULL;
  count++;
  }*/
/*
template <typename T>
dll<T>::~dll(){
  while(head != 0){
    node* temp = head;
    head = head->next;
    delete temp;
  }
}

template <typename T>
void dll<T>::addToEnd(T data){
  if(head == NULL){            //if list is empty
    head = new node(data);
    tail = head;
    head->prev = NULL;
    head->next = NULL;
    count++;
     }
  else{                             //if list is non empty
    tail->next = new node(data);
    tail->next->prev = tail;
    tail = tail->next;
    count++;
  }
}

template <typename T>
void dll<T>::remove(T data){
  if(head == NULL)                  //if list is empty
    return;
  else if(head->info == data){     //if it is the first node
    node* temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
    count--;
  }
  else if(tail->info == data){     //if it is the last node
    node* temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete temp;
    count--;
  }
  else{                           //else node is somewhere in the middle
    node* temp = head;
    while(temp->info != data)
      temp = temp->next;       //move to the node that contains the data we want to delete
    temp->prev->next = temp->next;
    temp->next->prev = temp-> prev;
    delete temp;
    count--;
  }
}

template <typename T>
T dll<T>::getData(int index){
  node* temp = head;
  for(int i = 0; i < index; i++)
    temp = temp->next;
  cout << temp->info << endl;
    
}

template <typename T>
int dll<T>::getSize(){
  int size = 0;
  node* temp = head;
  while(temp){
    size++;
    temp = temp->next;
  }
  cout << size << endl;
  return size;
}

template <typename T>
bool dll<T>::isInList(T data){
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

template <typename T>
T dll<T>::printAllNodes(){
  node* temp = head;
  while(temp){
    cout << temp->info << endl;
    temp = temp->next;
  }
  }
*/
int main() {
	dll<int> d;
	d.addToEnd(5);
	d.addToEnd(12);
	d.addToEnd(20);
	d.addToEnd(25);
	d.printAllNodes();
	d.setIterator();
	cout << d.getNext()->info;
	
	}

