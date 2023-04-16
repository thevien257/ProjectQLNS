#include "DanhSachTask.h"
#include <iostream>
using namespace std;

vector<Task *> DanhSachTask::getDSTask()
{
  return dsTask;
}

void DanhSachTask::setDSTask(vector<Task *> task)
{
  this->dsTask = task;
}