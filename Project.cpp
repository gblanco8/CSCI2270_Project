#include "Project.hpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

ToDoList::ToDoList(){
  TaskPriority = new Task[maxQueueSize];
  currentQueueSize = 0;
}
/////
ToDoList::~ToDoList(){
  delete [] TaskPriority;
}
/////
void ToDoList::addProfile(string username) //creates a new profile for the user
{
  Profile userProfile = new Profile;
  userProfile->username = username;

  string catName;
  int importance;
  bool catDone = false;

  while(!catDone) //how the user will stop the process of entering new categories
  {
    //Should clarify what we mean by category, so that it's more user-friendly
    cout<<"--Enter a new category name, or enter DONE if done entering categories--"<<endl;
    cin>>catName;
    if (catName == "DONE"){
      catDone = true;
    }
    else{
      Category newCat = new Category;
      newCat->categoryname = catName;
      cout<<"--Assign an 'importance' to this category--"<<endl;
      cout<<"--This should be a number between 1 and 10, with 10 being of highest importance--"<<endl;
      cin>>importance;
      newCat->categoryweight = importance;
      (userProfile->cat).push_back(cat);
      catDone = false;
    }
  }
}
/////
void ToDoList::addTask(){
  Task nT;
  float priority = 0;
  TaskPriority[currentQueueSize+1] = nT;
//Add fields the the new task
  nT->taskName = taskName;
  nT->length = length;
  nT->time = time;
//Calc priority and add it to the new task
  priority = calculatePriority(length, time);
  nT->priority = priority;
//Update queue
  TaskPriority[currentQueueSize] = *nT;
  repairUpward(currentQueueSize);
  currentQueueSize++;
}
/////
void ToDoList::completeTask(){
  if(!isEmpty()){
    TaskPriority[0] = TaskPriority[currentQueueSize-1];
    currentQueueSize--;
    repairUpward(currentQueueSize);
  }
  else{
    cout << "List empty, cannot complete task" << endl;
  }
}
/////
void ToDoList::completeAnyTask(string taskName) //depends on what search() returns (boolean or task*)
{
  int index = search(taskName);
  if(!isEmpty())
  {
    TaskPriority[index] = TaskPriority[currentQueueSize - 1];
    currentQueueSize--;
    repairUpward(currentQueueSize);
  }
  else{
    cout<<"List empty, cannot complete task"<<endl;
}
/////
Profile ToDoList::peek(){
  if(isEmpty()){
    cout << "To do list empty, nothing to see" << endl;
    return NULL;
  }else{
    return TaskPriority[0];
  }
}
/////
bool ToDoList::isEmpty(){
  if(currentQueueSize == 0){
    return true;
  }else{
    return false;
  }
}
/////
void ToDoList::printList(){
  for(int i=0; i<currentQueueSize; i++){
    cout << i+1 << ". " << TaskPriority[i]->taskName << endl;
  }
}
/////
int ToDoList::search(string TaskName){                               
  for(int i = 0; i < currentQueueSize; i++){
    if(TaskPriority[i].taskname == TaskName){
      return i;
    }
  }
}
/////
double ToDoList::calculatePriority(float length, int time){
  double priority;
  if(length > time){
    cout << "Sorry, you do not have enough time to complete this task" << endl;
    return -1;
  }else{
    priority = (length/time);
    return priority;
  }
}
/////
void swap(Task* a, Task* b){
  Task temp = a;
  a = b;
  b = temp;
}
//////
void ToDoList::repairUpward(int nodeIndex){
  int p = (nodeIndex-1)/2;

  if(TaskPriority[nodeIndex].priority >= TaskPriority[p].priority) return;
  else if(TaskPriority[nodeIndex].priority < TaskPriority[p].priority){
    swap(&TaskPriority[nodeIndex],&TaskPriority[p]);
    repairUpward(p);
  }
}
