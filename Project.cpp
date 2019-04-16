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

}
Profile ToDoList::peek(){

}
bool ToDoList::isEmpty(){

}
void ToDoList::printList(){

}
void ToDoList::search(){

}
void ToDoList::calculatePriority(){

}
void ToDoList::repairUpward(int nodeIndex){

}
