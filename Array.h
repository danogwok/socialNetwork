//Array.h

#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include "List.h"
using namespace std;

template <typename T>

class Array: public List<T>{
 public:
  int ARRAY_SIZE;
  T *array;
  
 private:
  int size;

 public:

  Array(){
    size = 0;
    ARRAY_SIZE = 10000;
    array = new T[ARRAY_SIZE];
  }

  ~Array(){
    delete [] array;
  }

  T& operator[](size_t index){
    return array[index];
  }

  int getSize(){
    return size;
  }


  void resize(){
    T* temp = new T[ARRAY_SIZE * 2];
    for(int i = 0; i < (ARRAY_SIZE - 1); i++){
      temp[i] = array[i];
    }
    delete [] array;
    array = temp;
    ARRAY_SIZE = ARRAY_SIZE * 2;
  }

  void insert (int pos, const T & item){
    if(pos < 0 || pos > size){
      cout << "Not a valid position\n";  //If pos is not between 0 and the current length of the list.
      return;
    }

    /*else if(array[ARRAY_SIZE -1]){                //If the array is full
      resize();
      for(int i = size; i > pos; i--){
	array[i+1] = array[i];
      }
      array[pos] = item;
      size++;
      return;
      }*/
    
    else{
      for(int i = size; i > pos; i--){
	array[i] = array[i-1];                 //move all elements after the inserted element down one spot.
      }
      array[pos] = item;
      size++;
    }
  }

  void remove (int pos){
    if(pos < 0 || pos > (size - 1)){
      cout << "Not a valid position\n";  //If pos is not between 0 and the current length of the list.
      return;
    }

    else{
      for(int i = pos; i < (size-1); i++)
	array[i] = array[i+1];
      array[size-1] = NULL;
      size--;
      return;
    }
    
  }

  void set (int pos, const T & item){
    if(pos < 0 || pos > (size - 1)){
      cout << "Not a valid position\n";  //If pos is not between 0 and the current length of the list.
      return;
    }
    else
      array[pos] = item;
  }
    
  T const & get (int pos) const{
    if(pos < 0 || pos > (size - 1)){
      cout << "Not a valid position\n";  //If pos is not between 0 and the current length of the list.
      return;
    }
    else
      return array[pos];
  }

  int findPos(string s){
    for (int i = 0; i< getSize(); i++){
      if (array[i] == s)
	return i;
    }

  }
};
  
#endif
