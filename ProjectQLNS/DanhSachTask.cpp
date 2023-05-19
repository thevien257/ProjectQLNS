#include "DanhSachTask.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
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
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  if (dsTask.size() == 0)
  {
    cout << endl;
    SetConsoleTextAttribute(color, 12);
    cout << "\t\t\t\tChua co task nao trong cong ty ❌" << endl;
    SetConsoleTextAttribute(color, 7);
  }
  else
  {
<<<<<<< HEAD
    int cyan = 11;
    int brightYellow = 14;
    int darkWhite = 7;
    cout << "\t\t                      ╔═════════════════════════════════╗\n";
    cout << "\t\t                      ║ ";
    SetConsoleTextAttribute(color, cyan);
||||||| c82f458
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "\t\t\t\t    ╔═══════════════════════════════════╗\n";
    cout << "\t\t\t\t╔═══║ ";
    SetConsoleTextAttribute(color, 11);
=======
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    int cyan = 11;
    int brightYellow = 14;
    int darkWhite = 7;
    cout << "\t\t                      ╔═════════════════════════════════╗\n";
    cout << "\t\t                      ║ ";
    SetConsoleTextAttribute(color, cyan);
>>>>>>> e7d433c80b750568709153137ba315da9d482b0f
    cout << "       Thong tin Task  📂    ";
    SetConsoleTextAttribute(color, 7);
    cout << "   ║                \n";
    cout << "\t\t╔═══════════╦═════════╬══════════════════╦══════════════╬════════════════════╦═════════════════════╗\n";
    cout << "\t\t║ ";
    SetConsoleTextAttribute(color, cyan);
    cout << "So thu tu ";
    SetConsoleTextAttribute(color, darkWhite);
    cout << "║ ";
    SetConsoleTextAttribute(color, cyan);
    cout << "Ma task ";
    SetConsoleTextAttribute(color, darkWhite);
    cout << "║    ";
    SetConsoleTextAttribute(color, cyan);
    cout << "Ten task      ";
    SetConsoleTextAttribute(color, darkWhite);
    cout << "║   ";
    SetConsoleTextAttribute(color, cyan);
    cout << "Deadline   ";
    SetConsoleTextAttribute(color, darkWhite);
    cout << "║    ";
    SetConsoleTextAttribute(color, cyan);
    cout << "Ma nhan vien    ";
    SetConsoleTextAttribute(color, darkWhite);
    cout << "║   ";
    SetConsoleTextAttribute(color, cyan);
    cout << "Trang thai task   ";
    SetConsoleTextAttribute(color, darkWhite);
    cout << "║\n";
    cout << "\t\t╠═══════════╬═════════╬══════════════════╬══════════════╬════════════════════╬═════════════════════╣\n";

    Task *lastTask = dsTask.back();
    int j = 1;
    for (int i = 0; i < dsTask.size(); i++)
    {
      cout << "\t\t║ " << std::setw(5) << std::setfill(' ');
      SetConsoleTextAttribute(color, cyan);
      cout << j;
      SetConsoleTextAttribute(color, darkWhite);
      cout << std::setw(4) << std::setfill(' ') << ""
           << " ║";
      dsTask[i]->xuatTask();
      cout << endl;
      if (dsTask[i] != lastTask)
      {
        cout << "\t\t╠═══════════╬═════════╬══════════════════╬══════════════╬════════════════════╬═════════════════════╣\n";
        j++;
      }
      else
      {
        cout << "\t\t╚═══════════╩═════════╩══════════════════╩══════════════╩════════════════════╩═════════════════════╝\n";
      }
    }
  }
}

void DanhSachTask::nhapTask()
{
  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  int n;
  cout << endl;
  cout << "\t\t\t\tNhap so luong task: ";
  cin >> n;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // add this line
  for (int i = 0; i < n; i++)
  {
    cout << endl;
    SetConsoleTextAttribute(color, 11);
    cout << "\t\t\t\tNhap task thu " << i + 1 << " ✍️" << endl;
    SetConsoleTextAttribute(color, 7);
    Task *task = new Task();
    task->nhapTask();
    dsTask.push_back(task);
  }
}

void DanhSachTask::docFileTask(string fileName)
{
  ifstream file(fileName);
  if (file.is_open())
  {
    while (file.good())
    {
      Task *task = new Task();
      file >> *task;
      dsTask.push_back(task);
    }
    file.close();
  }
  else
  {
    cout << "Khong the mo file" << endl;
  }
}

DanhSachTask::DanhSachTask()
{
  docFileTask("Task.txt");
}