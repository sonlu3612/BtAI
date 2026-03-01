#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "bestfirst.h"

// ===== include file thuat toan =====
// #include "bfs.h"
// #include "bestfirst.h"
// #include "astar.h"

using namespace std;

void clear()
{
    system("cls");
}

void drawMenu(int selected)
{
    vector<string> menu =
    {
        "BFS",
        "Best First Search",
        "A*",
        "Thoat"
    };

    cout << "+--------------------------------------+\n";
    cout << "|        MENU THUAT TOAN TIM KIEM      |\n";
    cout << "+--------------------------------------+\n";

    for(int i=0;i<menu.size();i++)
    {
        cout << "| ";

        if(i == selected)
        {
            SetConsoleTextAttribute(
                GetStdHandle(STD_OUTPUT_HANDLE),
                240);

            cout << "> " << menu[i];

            cout << string(31-menu[i].length(),' ');

            cout << " <";

            SetConsoleTextAttribute(
                GetStdHandle(STD_OUTPUT_HANDLE),
                7);
        }
        else
        {
            cout << "  " << menu[i] << string(33-menu[i].length(),' ');
        }

        cout << "  |\n";
    }

    cout << "+--------------------------------------+\n";

    cout << "\nDung mui ten va ENTER de dieu khien\n";
}

int inputMenu()
{
    vector<string> menu =
    {
        "Nhap tu ban phim",
        "Nhap tu file"
    };

    int selected=0;

    while(true)
    {
        clear();

        cout << "+--------------------------------------+\n";
        cout << "|              CHON INPUT              |\n";
        cout << "+--------------------------------------+\n";

        for(int i=0;i<menu.size();i++)
        {
            cout << "| ";

            if(i == selected)
            {
                SetConsoleTextAttribute(
                    GetStdHandle(STD_OUTPUT_HANDLE),
                    240);

                cout << "> " << menu[i];

                cout << string(30-menu[i].length(),' ');

                cout << "<";

                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            }
            else
            {
                cout << "  " << menu[i] << string(32-menu[i].length(),' ');
            }

            cout << "|\n";
        }

        cout << "+--------------------------------------+\n";

        int key=_getch();

        if(key == 224)
        {
            key=_getch();

            if(key == 72)
            {
                selected--;

                if(selected<0)
                    selected=menu.size()-1;
            }

            if(key == 80)
            {
                selected++;

                if(selected>=menu.size())
                    selected=0;
            }
        }

        else if(key == 13)
        {
            // return:
            // 1 = keyboard input
            // 2 = file input
            return selected+1;
        }
    }
}



int main()
{
    vector<string> menu =
    {
        "BFS",
        "Best First Search",
        "A*",
        "Thoat"
    };

    int selected=0;

    while(true)
    {
        clear();

        drawMenu(selected);

        int key=_getch();

        if(key == 224)
        {
            key=_getch();

            if(key == 72)
            {
                selected--;

                if(selected<0)
                    selected=menu.size()-1;
            }

            if(key == 80)
            {
                selected++;

                if(selected>=menu.size())
                    selected=0;
            }
        }

        else if(key == 13)
        {
            if(selected == 3)
                break;

            int inputType = inputMenu();

            string filename="";

            if(inputType == 2)
            {
                clear();

                cout<<"Nhap ten file : ";
                cin>>filename;
            }

            clear();

            cout << "Dang chay : " << menu[selected]
                 << " (Input " << inputType << ")\n";

            switch(selected)
            {
                case 0:
                {
                    // ===== BFS =====

                    // BFS_Run(inputType , filename);

                    // bfs.h :
                    // void BFS_Run(int inputType,
                    //              const string& filename);

                    break;
                }

                case 1:
                {
                    // ===== BEST FIRST SEARCH =====

                    BestFirst_Run(inputType , filename);

                    // bestfirst.h :
                    void BestFirst_Run(int inputType,
                                       const string& filename);

                    break;
                }

                case 2:
                {
                    // ===== A STAR =====

                    // AStar_Run(inputType , filename);

                    // astar.h :
                    // void AStar_Run(int inputType,
                    //                const string& filename);

                    break;
                }
            }

            system("pause");
        }
    }

    return 0;
}