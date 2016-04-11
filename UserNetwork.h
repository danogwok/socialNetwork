//UserNetwork.h
//Header file for UserNetwork class

#ifndef USERNETWORK_H
#define USERNETWORK_H
#include "User.h"
#include <fstream>
#include <iostream>

class UserNetwork{
 private:
  dll<User> network;

 public:


  void addUser(User& u);

  void deleteUser(User& u);

  void writeUserList();

  void readUserList();

  bool doesUserExist(User& u);

  void overwriteUserList();

  void printUserList(User* me);

  dll<User>::node* findUser(string name);

  dll<User>::node* correctUser(string name, string password);

};

#endif

