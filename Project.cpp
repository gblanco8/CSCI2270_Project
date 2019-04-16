#include "Project.hpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

ToDoList::ToDoList(){
  TaskPriority = new Profile[maxQueueSize];
  currentQueueSize = 0;
}
ToDoList::~ToDoList(){
  delete [] TaskPriority;
}
void ToDoList::addProfile(){
  
}  
void ToDoList::addTask(){

}
void ToDoList::completeTask(){
  if(!isEmpty()){
    TaskPriority[0] = TaskPriority[currentQueueSize-1];
    currentQueueSize--;
    repairUpward(currentQueueSize);
  }
  else{
    cout << "List empty, cannot dequeue" << endl;
  }
}
Profile ToDoList::peek(){
  if(isEmpty()){
    cout << "To do list empty, nothing to see" << endl;
    return NULL;
  }else{
    return TaskPriority[0];
  }
}
bool ToDoList::isEmpty(){
  if(currentQueueSize == 0){
    return true;
  }else{
    return false;
  }
}
void ToDoList::printList(){
  for(int i=0; i<currentQueueSize; i++){
    cout << TaskPriority[i]->taskName
  }
}
void ToDoList::search(){

}
void ToDoList::calculatePriority(){

}
void ToDoList::repairUpward(int nodeIndex){

}
