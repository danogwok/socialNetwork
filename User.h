//User.h
//Header file for User class

#ifndef USER_H
#define USER_H
#include "Wall.h"
#include <vector>
#include <iostream>
using namespace std;

class User{

 private:
  Wall wall;
  string username;
  string password;
  string city;
  vector<User*> friends;
  vector<User*> pendingFriends;
  dll<User>::node* np;


 public:

  User(string theUsername, string thePassword, string theCity){
    username = theUsername;
    password = thePassword;
    city = theCity;
    np = NULL;
  }

   User() {
    username = "";
    password = "";
    city = "";
    np = NULL;
    }

  /* ~User(){
    wall.clearWall();
    username = "";
    password = "";
    city = "";
    }*/

  void setNP(dll<User>::node* p) {np = p;}

  dll<User>::node* getNP() {return np;}

  void setUsername(string theUsername){
    username = theUsername;
  }

  string getUsername(){
    return username;
  }

  void setPassword(string thePassword){
    password = thePassword;
  }

  string getPassword(){
    return password;
  }

  void setCity(string theCity){
    city = theCity;
  }

  string getCity(){
    return city;
  }

  string printUserWall(){
    return  wall.printWall();
  }

  bool userWallEmpty(){
    return wall.isEmpty();
  }

  void addOwnWallPost(WallPost& thePost);

  void addOwnComment(int i, WallPost& thePost);

  void deleteOwnWallPost(int thePost);

  string printUserInfo();

  void readUserInfo(string s, User& u);

  void addFriend(User* newFriend, User* me);

  //void deleteFriend (User* Friend, User* me);

  void addPendingFriend(User* newFriend, User* me);

  void deletePendingFriend(User* me);

  void printPendingFriends(User* me);

  void printFriends(User* me);

  int getPendingFriendSize(User* me){
    return me->pendingFriends.size();
  }

  string printPendingFriend(int i, User* me){
    return me->pendingFriends[i]->getUsername();
  }

  void postOnFriendsWall(User* theFriend, WallPost& thePost){
    theFriend->wall.addInput(thePost);
  }

  int shortestPath(User* me, string theFriend);
  
};

#endif
