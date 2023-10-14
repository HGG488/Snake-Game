#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "Windows.h"
#include <winuser.h>

using namespace std;
#define M 20

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
struct coadaa {
    int x;
    int y;
};
enum clickuri {UP , DOWN , RIGHT, LEFT};

int main()
{
    system("COLOR 30");
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    
    SMALL_RECT windowSize;
    windowSize.Left = 0;
    windowSize.Top = 0;
    windowSize.Right = 21;  
    windowSize.Bottom = 21;  
    if (!SetConsoleWindowInfo(console, TRUE, &windowSize)) {
        // Handle error if needed
    }
    clickuri lastclick = UP;
    int fructx, fructy;
    coadaa coada[M * M] = { NULL };
    int mapa[M][M] = { NULL };
    int x_coada_p;
    int y_coada_p;
    int lungime = 0;
    int x_cap = 2; int x_cap_p = 2;
    int y_cap = 2; int y_cap_p = 2;
    int x_coada = 2;
    int y_coada = 2;
    mapa[2][2] = 1;

    bool caz;
    fructx = rand() % M;
    fructy = rand() % M;
    bool prins = false;
    int c = 0;
    bool print;
    bool gameover = true;
    while (gameover)
    {

        x_cap_p = x_cap;
        y_cap_p = y_cap;

        system("CLS");
        for (int i = 0; i <= M + 1; i++)
            cout << "#";


        for (int i = 0; i <= M - 1; i++)
        {
            cout << endl;
            for (int j = -1; j <= M; j++)
            {
                print = true;
                if (j == -1|| j == M)
                {
                    print = false;
                    cout << "#";
                }
                else {


                    if ((i == x_cap && j == y_cap) && (i != fructx || fructy != j))
                    {
                        cout << "O";
                        print = false;
                    }
                    for (int k = 0; k < lungime; k++)
                    {
                        if ((i == coada[k].x && j == coada[k].y) && (fructx != coada[k].x || fructy != coada[k].y))
                        {
                            print = false;   cout << "o";
                        }
                    }


                    if (i == fructx && j == fructy && (fructx != x_cap || fructy != y_cap))
                    {
                        print = false; cout << "$";
                    }
                }
              
                if (print)
                    cout << " ";
            }
        }
        if (x_cap == fructx && y_cap == fructy)
        {
            prins = true;





            if (lungime >= 1)

            {
                coada[lungime].x = x_coada_p;
                coada[lungime].y = y_coada_p;
            }
            else if (lungime == 0)
            {
                coada[lungime].x = x_cap_p;
                coada[lungime].y = y_cap_p;
            }
            lungime++;
        }

        if (prins)
        {
            fructx = rand() % M;
            fructy = rand() % M;
            prins = false;
        }
        cout << endl;
        for (int i = 0; i <= M + 1; i++)
            cout << "*";


        



        if (lungime == (M * M) - 1)
            gameover = false;




        if (_kbhit()) {


            char p = _getch();
            char c = _getch();


            switch ((c)) {
            case KEY_UP:
                if (x_cap - 1 >= 0)
                {
                    caz = false;
                    x_cap--;
                }
                else
                    x_cap = M - 1;
                lastclick = UP;

                break;
            case KEY_DOWN:
                if (x_cap + 1 <= M - 1)
                {
                    caz = false;
                    x_cap++;
                }
                else
                    x_cap = 0;
                lastclick = DOWN;

                break;
            case KEY_LEFT:
                if (y_cap - 1 >= 0)
                {
                    caz = false;

                    y_cap--;
                }
                else
                    y_cap = M - 1;
                lastclick = LEFT;

                break;
            case KEY_RIGHT:
                if (y_cap + 1 <= M - 1)
                {

                    caz = false;
                    y_cap++;
                }
                else
                    y_cap = 0;
                lastclick = RIGHT;
                break;

            }
        }
        else
        {
            
                switch (lastclick)
                {
                case UP:
                    if (x_cap - 1 >= 0)
                    {
                        caz = false;
                        x_cap--;
                    }
                    else
                        x_cap = M - 1;
                  

                    break;
                case DOWN:
                    if (x_cap + 1 <= M - 1)
                    {
                        caz = false;
                        x_cap++;
                    }
                    else
                        x_cap = 0;
                   

                    break;
                case LEFT:
                    if (y_cap - 1 >= 0)
                    {
                        caz = false;

                        y_cap--;
                    }
                    else
                        y_cap = M - 1;
                    

                    break;
                case RIGHT:
                    if (y_cap + 1 <= M - 1)
                    {

                        caz = false;
                        y_cap++;
                    }
                    else
                        y_cap = 0;
                    
                    break;

                }




                }
                if (lungime > 0)
                    for (int k = 0; k < lungime; k++)
                    {
                        if (x_cap == coada[k].x && y_cap == coada[k].y)

                            gameover = false;
                    }

             

        
      
        x_coada_p = coada[lungime-1].x;

        y_coada_p = coada[lungime - 1].y;


        for (int k = lungime-1; k >0; k--)
        {
            coada[k].x = coada[k - 1].x;
            coada[k].y = coada[k - 1].y;
           
        }
        coada[0].x = x_cap_p;
        coada[0].y = y_cap_p;
          






       



     
       

        Sleep(10);

    }
    cout << endl;
    cout << "GAME OVER";
    return 0;

}