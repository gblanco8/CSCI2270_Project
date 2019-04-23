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
  if(indatabase.is_open()){
    string line;
    while(getline(indatabase,line)){
      stringstream ss(line);
      string data[5];
      int index = 0;
      while(getline(ss,data[index])){
       index++;
      }
      TQ.addTask(data[2],stof(data[3]),stoi(data[4]));
    }
  }
  indatabase.close();

//Input Variables
  int userInput;
  string username;
  string taskName;
  string catname;
  float length;
  int time;
  string deleteTaskName;
  string output;

  ofstream outdatabase("Database.txt");
  if(outdatabase.is_open()){
    while(userInput != 7){
      cout << endl;
      menu();
      cout << "Select an option: ";
      cin >> userInput;
      if(userInput == 1){
        cout << "Please enter a username: " << endl;
        cin >> username;
        TQ.addProfile(username);
      }else if(userInput == 2){
        TQ.printProfiles();
        cout << "Choose a profile" << endl;
        cin >> username;
      }else if(userInput == 3){
        cout << "Please enter the category it is for:" << endl;
        cin >> catname;
        cout << "Please enter name of task: " << endl;
        cin >> taskName;
        cout << "Please enter number of hours to complete task: " << endl;
        cin >> length;
        cout << "Please enter number of days until task is due: " << endl;
        cin >> time;
        TQ.addTask(taskName, length, time);
        output = username + "," + catname + "," + taskName + "," + to_string(length) + "," + to_string(time) + "\n";
        outdatabase << output;
      }else if(userInput == 4){
        cout << "These are the current stored profiles:" << endl;
        TQ.printList();
      }else if(userInput == 5){
        return 0;
        //TQ.printProfiles();
      }else if(userInput == 6){
        cout << "Please enter name of task you wish to delete: " << endl;
        TQ.printList();
        cin >> deleteTaskName;
        if(TQ.peek().taskname == deleteTaskName){
          TQ.completeTopTask();
        }else{
          TQ.completeAnyTask(deleteTaskName);
        }
      }
        outdatabase.close();
    }
  }


  cout << "Procrastination is the Death of Freedom!" << endl;
  return 0;
}
