#include "UserNetwork.h"
#include <string>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <stdio.h> 

void UserNetwork::addUser(User& u){
  dll<User>::node* n = network.addToEnd(u);
  u.setNP(n);
}

bool UserNetwork::doesUserExist(User& u){
  dll<User>::node* temp = network.firstNode();
  while(temp){
    if(temp->info.getUsername() == u.getUsername()){
      cout << "User already exists. Please create different username. \n";
      return true;
	}
    temp = temp->next;
  }
  return false;
}

dll<User>::node* UserNetwork::correctUser(string name, string password){
   dll<User>::node* temp = network.firstNode();
   while(temp){
     if((temp->info.getUsername() == name) && (temp->info.getPassword() == password)){
       return temp;
     }
     else{
       temp = temp->next;
     }
   }
   cout << "Username and password don't match. Please try again\n";
   return NULL;
}

void UserNetwork::printUserList(User* me){
  dll<User>::node* n = network.firstNode();
  while(n){
    if(n->info.getUsername() == me->getUsername()){
      n = n->next;
    }
    cout << n->info.getUsername() << endl;
    n = n->next;
  }
  return;
}

dll<User>::node* UserNetwork::findUser(string name){
  dll<User>::node* temp = network.firstNode();
  while(temp){
    if((temp->info.getUsername() == name)){
      return temp;
    }
    temp = temp->next;
  }
    return NULL;
}

void UserNetwork::deleteUser(User& u){
  dll<User>::node* temp = network.firstNode();

  while(temp){
    if(temp->info.getUsername() == u.getUsername())
      network.remove(u.getNP());
    temp = temp->next;
  }
}

void UserNetwork::writeUserList(){
  ofstream myfile;
  myfile.open("Users.txt");
  dll<User>::node* front = network.firstNode();
  if(network.firstNode() == NULL)
    return;
  while(front){
    myfile <<  (front->getData()).getUsername() << " " << (front->getData()).getPassword() << " " << (front->getData()).getCity() << endl;
    front = front->next;
  }
  myfile.close();
}

void UserNetwork::overwriteUserList(){
  remove("Users.txt");
  writeUserList();

  /*  FILE *fp;
  fp = fopen("Users.txt", "w");
  dll<User>::node* temp = network.firstNode();
  while(temp){
    fprintf(fp, (temp->getData()).getUsername().c_str());
    fprintf(fp, " ");
    fprintf(fp, (temp->getData()).getPassword().c_str());
    fprintf(fp, " ");
    fprintf(fp, (temp->getData()).getCity().c_str());
    fprintf(fp, "\n");
    temp = temp->next;
  }
  fclose(fp);*/
}

//clearUserList function?
//Once a users info is changed, must edit Users.txt

void UserNetwork::readUserList(){
  string line;
  ifstream infile;
  infile.open("Users.txt");
  while(getline(infile,line)){
    string username;
    string password;
    string city;
    istringstream iss(line);
    iss >> username;
    iss >> password;
    iss >> city;
    User u(username, password, city);
    addUser(u);
  }
}

/*int main(){
  UserNetwork u;
  User KC("kc","thebeast","Redding");
  User Kevin("kevin","kchaan","SF");
  u.addUser(KC);
  u.addUser(Kevin);
  u.writeUserList();
  u.readUserList();
  }*/


