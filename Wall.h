//Wall.h
// Header file for wall, which uses the doubly linked list template

#include <iostream>
#include "WallPost.h"
#include "dll.h"
#include "LinkedList.h"
using namespace std;
#ifndef WALL_H
#define WALL_H

class Wall{

 private:

  //dll<WallPost> timeline;
  LinkedList<WallPost> timeline;
  string username;

 public:
  
  //void addInput(WallPost& theInput);

  //void removeInput(WallPost& theInput);

  void addInput(const WallPost& post);

  void addComment(int i, WallPost& post);

  void removeInput(int pos);


  void setUsername(string theUsername){
    username = theUsername;
  }
  
  string getUsername(){
    return username;
  }
  
  string printWall();

  void readWall(string s);
  
  void clearWall();

  bool isEmpty();
};

#endif
