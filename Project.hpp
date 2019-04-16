#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Profile{
  string username;
  int age;
  vector<Categories> cat;
};

struct Categories{
  string categoryname;
  int categoryweight;
};

struct Task{
  string taskname;
  float length;
  float time;
  double classweight;
  float priority;
};

class ToDoList{
public:
  ToDoList();
  ~ToDoList();
  void addTask();
  void completeTask();
  Profile peek();
  bool isEmpty();
  void printList();
  void search(string taskname);
  void calculatePriority();
private:
  void repairUpward(int nodeIndex);

  Profile* TaskPriority;
  int currentQueueSize;
  int maxQueueSize = 100;
};
