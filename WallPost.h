//WallPost.h
//Header file for WallPost class
#include <string>
#include <iostream>
#include <ctime>
#include "dll.h"
using namespace std;

#ifndef WALLPOST_H
#define WALLPOST_H

class WallPost{

 private:
  
  string author;
  string post;
  time_t timeOfPost;
  //    dll<WallPost>::node* parent;
  
 public:


  //constructor with parameter data
  WallPost(string thePost, string theAuthor){
    post = thePost;
    author = theAuthor;
    timeOfPost = time(0);
    //    parent = NULL;
  }


  //returns post of node
  string getPost() const{
    return post;
  }

  string getAuthor(){
    return author;
  }

 

  //sets post of node
  void setPost(string thePost){
    post = thePost;
  }


  //returns the entire wall post as a string
  string readWallPost();


  void operator = (WallPost& wp){
    post = wp.post;
    author = wp.author;
  }
  
  bool operator == (WallPost& wp){
    if (wp.post == getPost())
      return true;
    else
      return false;
   }
   
  bool operator != (WallPost& wp){
    if(wp.post != getPost())
      return true;
    else
      return false;
  }

};

#endif
