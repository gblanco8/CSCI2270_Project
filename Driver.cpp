//Graham Blanco, Justin Buenviaje, Adam Bradshaw
//CSCI 2270 - Data Structures
//Final Project
//Driver file

#include <iostream>
#include <sstream>
#include <string>
#include "Project.cpp"

using namespace std;

///////////////////////Menu/////////////////////////
void menu(){
  cout << "=======Main Menu=======" << endl;
  cout << "1. Create a New Profile" << endl;
  cout << "2. Add a Task to an Existing Profile" << endl;
  cout << "3. Display Tasks in Order of Priority" << endl;
  cout << "4. Display Profiles" << endl;
  cout << "5. Complete a Task" << endl;
  cout << "6. Quit" << endl;
}

/////////////////////Main//////////////////////////
int main(int argc, char const* argv[]){
  ToDoList TQ;

//Input Variables
  int userInput;
  string username;
  string taskName;
  float length;
  int time;
  string deleteTaskName;

  while(userInput != 6){
    cout << endl;
    menu();
    cout << "Select an option: ";
    cin >> userInput;
    if(userInput == 1){
      //cin.ignore();
      cout << "Please enter a username: " << endl;
      cin >> username;
      TQ.addProfile(username);
    }else if(userInput == 2){
      cout << "Please enter name of task: " << endl;
      cin >> taskName;
      cout << "Please enter number of hours to complete task: " << endl;
      cin >> length;
      cout << "Please enter number of days until task is due: " << endl;
      cin >> time;
      TQ.addTask(taskName, length, time);
    }else if(userInput == 3){
      TQ.printList();
    }else if(userInput == 4){
      cout << "These are the current stored profiles:" << endl;
      TQ.printProfiles();
    }else if(userInput == 5){
      cout << "Please enter name of task you wish to delete: " << endl;
      getline(cin, deleteTaskName);
      if(TQ.peek().taskname == deleteTaskName){
        TQ.completeTopTask();
      }else{
        TQ.completeAnyTask(deleteTaskName);
      }
    }
  }
  cout << "Procrastination is the Death of Freedom!" << endl;
  return 0;
}
