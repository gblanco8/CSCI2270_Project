#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Category;
struct Task;

struct Profile{
  string username;
  vector<Category> cat;
};

struct Category{
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
  void addTask(string taskName, float length, int time);
  void completeTopTask();
  void completeAnyTask(string taskname);
  void addProfile(string username);
  Task peek();
  bool isEmpty();
  void printList();
  void printProfiles();
  int search(string TaskName);
  double calculatePriority(float length, int time, int catweight); // (1/time til deadline) * (duration) * (importance)
private:
  void repairUpward(int nodeIndex);

  Task* TaskPriority;
  int currentQueueSize;
  int maxQueueSize = 100;
  vector<Profile> profs;
  int numProfs;
};
