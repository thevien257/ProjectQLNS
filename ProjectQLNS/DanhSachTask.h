#pragma once
#include <iostream>
#include "Task.h"
#include <vector>

class DanhSachTask
{
private:
  vector<Task *> dsTask;

public:
  vector<Task *> getDSTask();
  void setDSTask(vector<Task *> dsTask);
};