void XuLy::xuLyMenuPhongBan()
{
  int choice = 1;            // default choice
  const int numChoices = 10; // total number of choices, including Exit

  _setmode(_fileno(stdin), _O_WTEXT); // switch console to unbuffered input mode

  while (true)
  {
    system("cls"); // clear the console before printing menu again

    // print the menu with highlighting for the current choice
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, 11);
    cout << "\t\t\t\t\t ___________________________________\n";
    cout << "\t\t\t\t\t| |\n";
    cout << "\t\t\t\t\t| Menu Quan ly phong ban 🏢\t\t|\n";
    cout << "\t\t\t\t\t| |\n";
    cout << "\t\t\t\t\t|___________________________________|\n";
    cout << endl;
    SetConsoleTextAttribute(color, 7);

    for (int i = 1; i <= numChoices; i++)
    {
      // print the menu item
      switch (i)
      {
      case 1:
        cout << "\t\t\t\t\t1. Them phong ban " << endl;
        break;
      case 2:
        cout << "\t\t\t\t\t2. Xuat phong ban" << endl;
        break;
      case 3:
        cout << "\t\t\t\t\t3. Phan bo nhan vien ve phong ban" << endl;
        break;
      case 4:
        cout << "\t\t\t\t\t4. Chi dinh truong phong ve phong ban" << endl;
        break;
      case 5:
        cout << "\t\t\t\t\t5. Xoa truong phong khoi phong ban" << endl;
        break;
      case 6:
        cout << "\t\t\t\t\t6. Xoa nhan vien khoi phong ban" << endl;
        break;
      case 7:
        cout << "\t\t\t\t\t7. Xoa phong ban" << endl;
        break;
      case 8:
        cout << "\t\t\t\t\t8. Sap xep so luong nhan su theo thu tu giam dan" << endl;
        break;
      case 9:
        cout << "\t\t\t\t\t9. Sap xep so luong nhan su theo thu tu tang dan" << endl;
        break;
      case 10:
        cout << "\t\t\t\t\t0. Thoat chuong trinh" << endl; // exit option
        break;
      default:
        break;
      }
    }

    // highlight the current choice
    if (choice >= 1 && choice <= numChoices)
    {
      SetConsoleTextAttribute(color, 10); // green highlight
      switch (choice)
      {
      case 1:
        cout << "\t\t\t\t\t1. Them phong ban " << endl;
        break;
      case 2:
        cout << "\t\t\t\t\t2. Xuat phong ban" << endl;
        break;
      case 3:
        cout << "\t\t\t\t\t3. Phan bo nhan vien ve phong ban" << endl;
        break;
      case 4:
        cout << "\t\t\t\t\t4. Chi dinh truong phong ve phong ban" << endl;
        break;
      case 5:
        cout << "\t\t\t\t\t5. Xoa truong phong khoi phong ban" << endl;
        break;
      case 6:
        cout << "\t\t\t\t\t6. Xoa nhan vien khoi phong ban" << endl;
        break;
      case 7:
        cout << "\t\t\t\t\t7. Xoa phong ban" << endl;
        break;
      case 8:
        cout << "\t\t\t\t\t8. Sap xep so luong nhan su theo thu tu giam dan" << endl;
        break;
      case 9:
        cout << "\t\t\t\t\t9. Sap xep so luong nhan su theo thu tu tang dan" << endl;
        break;
      case 10:
        cout << "\t\t\t\t\t0. Thoat chuong trinh" << endl; // exit option
        break;
      default:
        break;
      }
      SetConsoleTextAttribute(color, 7); // reset color to white for non-selected choices
    }

    // get user input using arrow keys
    char ch = _getch();
    if (ch == 224) // extended key code for arrow keys
    {
      ch = _getch(); // read the actual key code
      if (ch == 72)  // up arrow key
      {
        choice--;       // move selection up
        if (choice < 1) // wrap around to bottom of menu
        {
          choice = numChoices;
        }
      }
      else if (ch == 80) // down arrow key
      {
        choice++;                // move selection down
        if (choice > numChoices) // wrap around to top of menu
        {
          choice = 1;
        }
      }
    }
    else if (ch == 13) // enter key to select option
    {
      switch (choice)
      {
      case 1:
        dsPB.nhapPB();
        break;
      case 2:
        dsPB.xuatPB();
        break;
      case 3:
        phanBoNhanVienThuongVaoPhongBan();
        break;
      case 4:
        chiDinhTruongPhong();
        break;
      case 5:
        xoaTPkhoiPB();
        break;
      case 6:
        xoaNVkhoiPB();
        break;
      case 7:
        xoaPB();
        break;
      case 8:
        sapXepSoLuongNhanSuPBGD();
        break;
      case 9:
        sapXepSoLuongNhanSuPBTD();
        break;
      case 10:
        false;
        return;
      default:
        break;
      }
    }
  }
}