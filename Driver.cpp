//Graham Blanco, Justin Buenviaje, Adam Bradshaw
//CSCI 2270 - Data Structures
//Final Project
//Driver file

#include <iostream>
#include <string>
#includ "taskQueue.hpp"

using namespace std;

///////////////////////Menu/////////////////////////
void menu(){
  cout << "=======Main Menu=======" << endl;
  cout << "1. Create a New Profile" << endl;
  cout << "2. Add a Task to an Existing Profile" << endl;
  cout << "3. Display Tasks in Order of Priority" << endl;
  cout << "4. Complete a Task" << endl;
  cout << "5. Quit" << endl;
}

/////////////////////Main//////////////////////////
int main(int argc, char const* argv[]){
  TaskQueue TQ;

//Input Variables
  int userInput;
  string username;
  int age;
  string taskName;
  float length;
  float time;
  string deleteTaskName;

  while(userInput != 5){
    menu();
    cin >> userInput;
    if(userInput == 1){
      cin.ignore();
      cout << "Please enter a username: " << endl;
      getline(cin, username);
      cout << "Please enter your age: " << endl;
      getline(cin, age);
      TQ.createProfile(username, age);
    }else if(userInput == 2){
      cin.ignore();
      cout << "Please enter name of task: " << endl;
      getline(cin, taskName);
      cout << "Please enter number of hours to complete task: " << endl;
      getline(cin, length);
      cout << "Please enter number of days until task is due: " << endl;
      getline(cin, time);
      TQ.addTask(taskName, length, time);
    }else if(userInput == 3){
      TQ.displayInventory();
    }else if(userInput == 4){
      cin.ignore();
      cout << "Please enter name of task you wish to delete: " << endl;
      getline(cin, deleteTaskName);
      if(TQ.peek()->taskName == deleteTaskName){
        TQ.deleteTask();
      }
    }
  }
  cout << "Goodbye!" << endl;
  return 0;
}
