#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Profile{
  string username;
  vector<Categories> cat;
};

struct Categories{
  string categoryname;
  int categoryweight;
  vector<Task> tasks;
};

struct Task{
  string taskname;
  float length;
  int time;
  float priority;
};

class ToDoList{
public:
  ToDoList();
  ~ToDoList();
  void addTask();
  void completeTask();
  void addProfile(string username)
  Task peek();
  bool isEmpty();
  void printList();
  void search(string taskname);
  void calculatePriority(); // (1/time til deadline) * (duration) * (importance)
private:
  void repairUpward(int nodeIndex);

  Task* TaskPriority;
  int currentQueueSize;
  int maxQueueSize = 100;
};
