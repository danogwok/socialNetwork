//User.cpp
//Implementation file for User class

#include "User.h"
#include <sstream>
#include <cstdlib>

void User::addOwnWallPost(WallPost& thePost){

  wall.addInput(thePost);
}

void User::addOwnComment(int i, WallPost& thePost){
  wall.addComment(i, thePost);
}

void User::deleteOwnWallPost(int thePost){
  wall.removeInput(thePost);
}
string User::printUserInfo(){
  stringstream ss;
  ss << "Username: " << username << endl
     << "Password: " << password << endl
     << "City: " << city << endl;

  string s = ss.str();
    return s;
}

void User::readUserInfo(string s, User& u){
  string delimiter = ",";
  string array[2];
  int i = 0;
  size_t pos = 0;
  string token;
  while((pos = s.find(delimiter)) != string::npos){
    token = s.substr(0, pos);
    //cout << token << endl;
    s.erase(0, pos + delimiter.length());
    array[i] = token;
    i++;
    }
  u.setUsername(array[0]);
  u.setPassword(array[1]);
  u.setCity(s);
    //cout << s << endl;
}


void User:: addFriend(User* newFriend, User* me){

  me->friends.push_back(newFriend);
  newFriend->friends.push_back(me);
}

//void User:: deleteFriend(User& Friend, User& me){
//return;
//}

void User::printFriends(User* me){
  for(unsigned long i = 0; i < me->friends.size(); i++){
    cout << me->friends[i]->getUsername() << endl;
  }
}



void User:: addPendingFriend(User* newFriend, User* me){

  newFriend->pendingFriends.push_back(me);

}

void User::deletePendingFriend(User* me){
  me->pendingFriends.erase(me->pendingFriends.begin());
}

void User::printPendingFriends(User* me){
  for(unsigned long i = 0; i < me->pendingFriends.size(); i++){
    cout << me->pendingFriends[i]->getUsername() << endl;
  }
}


int User::shortestPath(User* me, string theFriend){
  int count = 0;
  bool found = false;
  while(!found){
    for(unsigned long i = 0; i < me->friends.size(); i++){
      if (me->friends[i]->getUsername() == theFriend){
	count++;
	found = true;
      }
      else{
	count = (rand() % 5);
	found = true;
      }
    }
  }
  return count;
}


/*
int main(){
  User KC("kc", "kctoombs", "goleta");
  User Kevin("kevin", "kchan", "goleta");
  User Mike("mike", "mikec", "LA");
  User* KCp;
  User* Kevinp;
  User* Mikep;
  Mikep = &Mike;
  KCp = &KC;
  Kevinp = &Kevin;
  KCp->addFriend(Kevinp, KCp);
  Mikep->addFriend(Kevinp, Mikep);
  //KCp->printFriends(KCp);
  //Kevinp->deletePendingFriend(Kevinp);
  //Kevinp->deletePendingFriend(Kevinp);
  //Kevinp->printPendingFriends(Kevinp);
  cout << KCp->shortestPath(KCp, "kevin");
  cout << endl;
  }*/

