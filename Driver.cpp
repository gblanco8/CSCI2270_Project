//Graham Blanco, Justin Buenviaje, Adam Bradshaw
//CSCI 2270 - Data Structures
//Final Project
//Driver file

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "Project.cpp"

using namespace std;

///////////////////////Menu/////////////////////////
void menu(){
  cout << "=======Main Menu=======" << endl;
  cout << "1. Create a New Profile" << endl;
  cout << "2. Choose Existing Profile" << endl;
  cout << "3. Add a Task to an Existing Profile" << endl;
  cout << "4. Display Tasks in Order of Priority" << endl;
  cout << "5. Display Profiles" << endl;
  cout << "6. Complete a Task" << endl;
  cout << "7. Quit" << endl;
}

/////////////////////Main//////////////////////////
int main(int argc, char const* argv[]){
  ToDoList TQ;
  
  ifstream indatabase("Database.txt");
  string line;
  string data[5];
  if(indatabase.is_open()){
    while(getline(indatabase,line)){
      stringstream ss << line;
      while(getline(ss,data[i],",")){
       i++; 
      }
      TQ.addProfile(data[0]);
      TQ.addTask(data[1],stof(data[2]),stoi(data[3]));
    }
  }
  indatabase.close();
  
//Input Variables
  int userInput;
  string username;
  string taskName;
  float length;
  int time;
  string deleteTaskName;

  ofstream outdatabase("Database.txt");
  if(outdatabase.is_open()){
    
  while(userInput != 7){
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
      QT.printProfiles();
    }else if(userInput == 3){
      cout << "Please enter name of task: " << endl;
      cin >> taskName;
      cout << "Please enter number of hours to complete task: " << endl;
      cin >> length;
      cout << "Please enter number of days until task is due: " << endl;
      cin >> time;
      TQ.addTask(taskName, length, time);
    }else if(userInput == 4){
      TQ.printList();
    }else if(userInput == 5){
      return 0;
      //TQ.printProfiles();
    }else if(userInput == 6){
      cout << "Please enter name of task you wish to delete: " << endl;
      getline(cin, deleteTaskName);
      if(TQ.peek().taskname == deleteTaskName){
        TQ.completeTopTask();
      }else{
        TQ.completeAnyTask(deleteTaskName);
      }
    }
  }
    outdatabase.close();
  }
  
  cout << "Procrastination is the Death of Freedom!" << endl;
  return 0;
}
