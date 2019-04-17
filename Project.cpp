#include "Project.hpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

ToDoList::ToDoList(){
  TaskPriority = new Task[maxQueueSize];
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
int ToDoList::search(string TaskName){                               
  for(int i = 0; i < currentQueueSize; i++){
    if(TaskPriority[i].taskname == TaskName){
      return i;
    }
  }
}
void ToDoList::calculatePriority(){

}
void swap(Task* a, Task* b){
  Task temp = a;
  a = b;
  b = temp;
}
void ToDoList::repairUpward(int nodeIndex){
  int p = (nodeIndex-1)/2;

  if(TaskPriority[nodeIndex].priority >= TaskPriority[p].priority) return;
  else if(TaskPriority[nodeIndex].priority < TaskPriority[p].priority){
    swap(&TaskPriority[nodeIndex],&TaskPriority[p]);
    repairUpward(p);
  }
}
