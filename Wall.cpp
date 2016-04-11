//Wall.cpp
//Implementation file of Wall.h

#include "Wall.h"
#include "LinkedList.h"
#include "dll.h"
#include <sstream>


void Wall::addInput(const WallPost& post){
  timeline.insert(0, post);
}

void Wall::addComment(int i, WallPost& post){
  timeline.insert(i, post);
}

void Wall::removeInput(int pos){
  timeline.remove(pos);
}


string Wall::printWall(){
  ostringstream oss;
  oss << "Wall:\n";
  LinkedList<WallPost>::node* temp = timeline.firstNode();
  while(temp){
    oss << (temp->getData()).readWallPost() << endl;
    temp = temp->next;
  }
  string s = oss.str();
  return s;
}


void Wall::clearWall(){
  LinkedList<WallPost>::node* temp = timeline.firstNode();
  while(temp){
    timeline.changeHeadtoNext(timeline.firstNode());
    delete temp;
    temp = timeline.firstNode();
  }
  
}

/*void Wall::readWall(string s){
  clearWall();
  string delimiter = "***";
  size_t pos = 0;
  string token;
  while((pos = s.find(delimiter)) != string::npos){
    token = s.substr(0, pos);
    // cout << token << std::endl;
    WallPost p(token, username);
    timeline.addToEnd(p);
    s.erase(0, pos + delimiter.length());
      }
  WallPost w(s, username);
  timeline.addToEnd(w);
  //cout << s << endl;
  }*/


bool Wall::isEmpty(){
  LinkedList<WallPost>::node* temp = timeline.firstNode();
  if(temp == NULL)
    return true;
  else
    return false;
    }

/*int main(){
  Wall w;
  w.addInput("Hello");
  w.addInput("Hello again");
  w.addInput("Hi");
  cout << w.printWall() << endl << endl;
  w.clearWall();
  cout << endl<< endl << w.printWall();
  return 0;
  }*/

