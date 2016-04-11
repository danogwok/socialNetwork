//WallPost.cpp
//Implementation file of WallPost.cpp

#include "WallPost.h"
#include <sstream>


string WallPost::readWallPost(){
  stringstream ss;

  struct tm* t = localtime(&timeOfPost);
  
  ss  <<  "Author: " << getAuthor() << "\n" << getPost() << endl
      << "Time of post:" << " " <<  (t->tm_mon) + 1 << "/" << t->tm_mday << "/"
      << (t->tm_year) + 1900 << endl;
  
  string s = ss.str();
  return s;
}
/*
  
int main(){
    WallPost a("Hello Kevin");
    cout << a.readWallPost();
    }

*/
