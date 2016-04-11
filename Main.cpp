#include "UserNetwork.h"
#include "dll.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
  while(1 == 1){
  int account;
  UserNetwork un;
  un.readUserList(); //Read in the file "Users.txt" which contains all users in the network

  welcomeScreen: 
  cout << "Welcome!" << endl
       << "If you would like to create a new account, press 1 and hit enter." << endl
       << "If you would like to sign in, press 2 and hit enter." << endl;

  cin >> account;

  
  if(account == 1){
    string name;
    string password;
    string city;
    string username;
    Wall w;


  signUp:
    cout << "Thank you for signing up!" << endl
	 << endl << "Please create a username:" << endl;
    cin >> name;

    User tempUser(name, "dummyPassword", "dummyCity");
    if(un.doesUserExist(tempUser)){         //If the user exists, ask to create a different username
	goto signUp;
      }
    cout << endl << "Please create a strong password:" << endl;
    cin >> password;
    
    cout << endl << "Please enter your city of residence:" << endl;
    cin.ignore();
    getline(cin, city);
    
    cout << endl;

    User u(name, password, city);
    
    un.addUser(u);
    u.setUsername(name);          //set the username
    u.setPassword(password);      //set the password
    u.setCity(city);              //set the city
    un.writeUserList();           //add the user the the user list "Users.txt"

    string post;
    cout << "Create your first post. Then hit enter.\n";
    getline(cin, post);
    WallPost P(post, u.getUsername());  //create the WallPost object with the given input.
    w.addInput(P);              //add the wall post to the wall.
    u.addOwnWallPost(P);        //add the wall post the the user's wall.
    
  mainScreen:
    
    cout << "\nIf you would like to view your wall, press 1 then hit enter\n"
	 << "If you would like to make another post, press 2 then hit enter\n"
	 << "If you would like to view your personal information, press 3 then hit enter\n"
	 << "If you would like to log out, press 4 then hit enter\n"
	 << "If you would like to exit the program, press 5\n";
    int decision;
    cin >> decision;
    if(decision == 1){
      cout << w.printWall();  //1 means view wall
      goto mainScreen;
    }
    
    else if(decision == 2){
      string post2;
      cout << "Write your next post, then hit enter.\n";
      cin.ignore();
      getline(cin, post2);
      WallPost P2(post2, u.getUsername());   //2 means write another post
      w.addInput(P2);
      u.addOwnWallPost(P2);
      goto mainScreen;
      }
      
    else if(decision == 3){
      cout << u.printUserInfo();      //3 means view personal information
      goto mainScreen;
    }
    else if(decision == 4){
      cout << "Thank you! Please return soon.\n\n";     //4 means log out
      goto welcomeScreen;
    }
    else if(decision == 5){
      return 1;
    }
    else{
      cout << "Not a valid input. Please enter 1, 2, 3, or 4.\n";
      goto mainScreen;
    }

  }
  

  if(account == 2){
    
  signIn:
    string password;
    string user;
 
    cout << "\nPlease enter your username, then hit enter\n";
    cin >> user;
    cout << "\nPlease enter your password, then hit enter\n";
    cin >> password;

    if(un.correctUser(user, password)){
      cout << "Welcome " << user << "!\n\n";
    }
    else{
      goto signIn;
    }
    dll<User>::node* x = un.correctUser(user,password);
    User* xp;
    xp = &(x->info);
    if(x->info.getPendingFriendSize(xp)){
      cout << "You have freind requests!\n\n"
	   << "Pending friends:\n";
      x->info.printPendingFriends(xp);
      while(x->info.getPendingFriendSize(xp) > 0){
	for(int i = 0; i < x->info.getPendingFriendSize(xp); i++){
	Friend_Request:
	  cout << "Would you like to accept or decline " << x->info.printPendingFriend(i,xp)
	       << "'s request? Hit 1 to accept, or 2 to decline. Then press enter\n";
	  int decision;
	  cin >> decision;
	  if(decision == 1){
	    dll<User>::node* theFriend = un.findUser(x->info.printPendingFriend(i,xp));
	    User* Friendp = &(theFriend->info); 
	    x->info.addFriend(Friendp, xp);
	    cout << "Added " <<  x->info.printPendingFriend(i,xp) << "!\n";
	  }
	    else if(decision != 1 || decision != 2){
	      cout << "Not a valid input. Enter a 1 or a 2\n\n";
	      goto Friend_Request;
	    }
	    x->info.deletePendingFriend(xp);
	}
      }
    }
  prompt:

 
    cout << "\nWhat would you like to do?\n"
      	 << "Press 0 and hit enter to logout\n"
	 << "Press 1 and hit enter to view your wall\n"
	 << "Press 2 and hit enter to create a post\n"
	 << "Press 3 and hit enter to delete a post\n"
	 << "Press 4 and hit enter to reply to a post on your Wall\n"
	 << "Press 5 and hit enter to view your personal information\n"
	 << "Press 6 and hit enter to change your personal information\n"
	 << "Press 7 and hit enter to view your friends\n"
	 << "Press 8 and hit enter to send a friend request\n"
	 << "Press 9 and hit enter to post on a friend's wall\n"
	 << "Press 10 and hit enter to delete your post on a friend's wall\n"
	 << "Press 11 and hit enter to find your degree of separation from another user\n"
	 << "Press 12 and hit enter to delete your profile\n"
	 << "Press 13 and hit enter to exit the program\n";
    


    int decision;
    cin >> decision;
    if(decision == 1){
      if(x->info.userWallEmpty()){
	cout << "Your wall is empty. Go create a post!\n";
      }
      else
	cout << x->info.printUserWall();         //1 means view wall
      goto prompt;
    }
    
    else if(decision == 2){
      string post2;
      cout << "\nWrite your next post, then hit enter.\n";
      cin.ignore();
      getline(cin, post2);
      WallPost P2(post2, x->info.getUsername());   //2 means write another post
      x->info.addOwnWallPost(P2);
      goto prompt;
      }

    else if(decision == 3){
      cout << "\nType the number of the post you would like to delete. Your first post (the top post) is represented by the number 0, the next post is represented by the number 1, and so on. Then hit enter\n\n";
      cout << x->info.printUserWall();
      int postToDelete;
      cin >> postToDelete;
      x->info.deleteOwnWallPost(postToDelete);
      cout << "\n\nHere is your updated wall\n";            //3 means delete post
      cout << x->info.printUserWall();
      cout << "\n\n";
      goto prompt;
      
    }
      
    else if(decision == 4){
      cout << "Type the number of the post you would like to reply to. The first post (the top post) is represented by the number 0, the next post is represented by the number 1, and so on. Then hit enter.\n\n";
      cout << x->info.printUserWall() << endl;
      int commentPost;
      cin >> commentPost;
      cout << "\n\nType your reply:\n";
      string reply;
      cin.ignore();
      getline(cin, reply);
      WallPost P(reply, x->info.getUsername());
      x->info.addOwnComment((commentPost + 1), P);
      cout << "Your reply has been posted!\n\n";
      goto prompt;
    }

    else if(decision == 5){
      cout << x->info.printUserInfo();      //5 means view personal information
      goto prompt;
    }

    else if(decision == 6){
    change_info:
      cout << "Press 1 and hit enter to change your password\n"
	   << "Press 2 and hit enter to change your city of residence\n";
      int choice;
      cin >> choice;
      cout << endl;
      
      if(choice == 1){
	cout << "Enter your new password\n";
	string newPassword;
	cin >> newPassword;
	cout << "Your password was changed to " << newPassword << endl;
	x->info.setPassword(newPassword);
	un.overwriteUserList();
	goto prompt;
      }
      else if(choice == 2){
	cout << "Enter your new city of residence\n";
	string newCity;
	cin >> newCity;
	cout << "Your city of residence was changed to " << newCity << endl;
	x->info.setCity(newCity);
	un.overwriteUserList();
	goto prompt;
      }
      else{
	cout << "Not a valid input, please enter a 1 or a 2.\n";
	goto change_info;
      }
    }

    else if(decision == 7){
      x->info.printFriends(xp);
      cout << "\n";
      goto prompt;
    }

    else if(decision == 8){
      string myFriend;
      cout << "Type the username of the user you'd like to send a request to\n";
      un.printUserList(xp);
      cin >> myFriend;
      dll<User>::node* theFriend = un.findUser(myFriend);
      User* Friendp;
      Friendp = &(theFriend->info);
      x->info.addPendingFriend((Friendp), (xp));
      cout<< "Friend request sent!" << endl;
      goto prompt;
      
    }

    else if(decision == 9){
      x->info.printFriends(xp);
      cout << "\n\nWhich friend's wall would you like to write a post on?\n";
      string myFriend;
      string post;
      cin >> myFriend;
      cout << "\nWrite your post, then hit enter\n";
      cin.ignore();
      getline(cin,post);
      WallPost P(post, x->info.getUsername());
      dll<User>::node* theFriend = un.findUser(myFriend);
      User* Friendp = &(theFriend->info);
      x->info.postOnFriendsWall(Friendp, P);
      cout << "Your post has been posted to " << myFriend << "'s wall!\n";
      goto prompt;
    }
    
    else if(decision == 0){
      cout << "Thank you! Please return soon.\n\n";     //0 means log out
      goto welcomeScreen;
    }

    else if(decision == 10){
      cout << "Type the username of the user whos wall you would like to delete your post from.\n";
      string name;
      cin >> name;
      dll<User>::node* theUser = un.findUser(name);
      cout << "Type the number of the post you would like to delete. The first post (the top post) is represented by the number, the next post is represented by the number 1, and so on. Then hit enter\n";
      int post;
      cout << theUser->info.printUserWall() << endl;
      cin >> post;
      theUser->info.deleteOwnWallPost(post);
      cout << "Your post has been deleted from " << name << "'s wall.\n\n";
      goto prompt;
    }

    else if(decision == 11){
      string user;
      cout << "Which user would you like to see your degree of separation from?\n\n";
      un.printUserList(xp);
      cout << endl;
      cin.ignore();
      getline(cin, user);
      cout << x->info.shortestPath(xp, user) << endl;
      goto prompt;
    }

    else if(decision == 12){
      cout << "Are you sure you want to delete your profile? Press 1 to confirm. Press 2 to cancel\n";
      int deleteConfirm;
      cin >> deleteConfirm;
      if(deleteConfirm == 1){
	un.deleteUser(x->info);
	un.overwriteUserList();
	goto welcomeScreen;
      }
      else if(deleteConfirm == 2){
	goto prompt;
      }
     
      else{
	cout << "Not a valid input. Please enter 1 or 2.\n";
	goto prompt;
      }
    }

    else if(decision == 13){
      return 1;
    }
    
    else{
      cout << "Not a valid input. Please enter 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, or 13.\n";
      goto prompt;
    }

  }

  
  else{
    cout << "\n Not a valid input. Please enter a 1 or 2.\n";
    goto welcomeScreen;
  }

  }
}
