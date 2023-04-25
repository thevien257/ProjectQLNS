#include "DanhSachTask.h"
#include <iostream>
#include <fstream>
using namespace std;

vector<Task *> &DanhSachTask::getDSTask()
{
  return dsTask;
}

void DanhSachTask::setDSTask(vector<Task *> task)
{
  this->dsTask = task;
}

void DanhSachTask::xuatTask()
{
  if (dsTask.size() == 0)
  {
    cout << "\t\t\tChua co task nao" << endl;
  }
  else
  {
    for (int i = 0; i < dsTask.size(); i++)
    {
      cout << "\t\tTask thu " << i + 1 << endl;
      dsTask[i]->xuatTask();
      cout << endl;
    }
  }
}

void DanhSachTask::nhapTask()
{
  int n;
  cout << endl;
  cout << "\t\t\tNhap so task: ";
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    Task *task = new Task();
    task->nhapTask();
    dsTask.push_back(task);
  }
}

void DanhSachTask::docFileTask(string fileName)
{
  ifstream fileIn;
  fileIn.open(fileName, ios::in);
  if (fileIn.fail())
  {
    cout << "Khong mo duoc file" << endl;
  }
  else
  {
    while (!fileIn.good())
    {
      Task *task = new Task();
      fileIn >> *task;
      dsTask.push_back(task);
    }
  }
  fileIn.close();
}

DanhSachTask::DanhSachTask()
{
  docFileTask("Task.txt");
}