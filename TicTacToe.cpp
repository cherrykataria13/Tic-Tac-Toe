#include <iostream>
#include <string>
#include <time.h>
using namespace std;

void game_over()
{
    cout << "\n\n\n\n";
    cout << "\t\t\t  _____       _       ___      ___   ______         _____  __      __  ______   _____    \n";
    cout << "\t\t\t / ___ \\     / \\     |   \\    /   | |  ____|       / ___ \\ \\ \\    / / |  ____| |  __ \\   \n";
    cout << "\t\t\t| |   |_|   /   \\    | |\\ \\  / /| | | |__         | |   | | \\ \\  / /  | |__    | |__| |  \n";
    cout << "\t\t\t| |  ___   / ___ \\   | | \\ \\/ / | | |  __|        | |   | |  \\ \\/ /   |  __|   |  _  /   \n";
    cout << "\t\t\t| |___| | / /   \\ \\  | |  \\__/  | | | |____       | |___| |   \\  /    | |____  | | \\ \\   \n";
    cout << "\t\t\t \\_____/ /_/     \\_\\ |_|        |_| |______|       \\_____/     \\/     |______| |_|  \\_\\  \n";
    cout << "\n\n";
}

class tictactoe_3x3
{
private:
    friend class tictactoe_3x3_auto;
    friend class tictactoe_4x4;
    friend class tictactoe_4x4_auto;
    int ar[3][3];
    int i, j;
    int turn;
    int mark;
    string player1, player2;

public:
    int n = 3;
    tictactoe_3x3() : ar{0, 0, 0, 0, 0, 0, 0, 0, 0}
    {
        turn = 1;
        mark = 1;
    }

    ~tictactoe_3x3()
    {
    }

    void main_menu()
    {
        cout << "\n\tPlayer 1\n\tEnter name : ";
        cin >> player1;
        cout << "\n\tPlayer 2\n\tEnter name : ";
        cin >> player2;

        system("cls");
    }

    void display()
    {
        cout << "\n\n\n\n";
        cout << "\t\t\t\t " << ar[0][0] << " | " << ar[0][1] << " | " << ar[0][2] << "\n";
        cout << "\t\t\t\t---+---+---\n";
        cout << "\t\t\t\t " << ar[1][0] << " | " << ar[1][1] << " | " << ar[1][2] << "\n";
        cout << "\t\t\t\t---+---+---\n";
        cout << "\t\t\t\t " << ar[2][0] << " | " << ar[2][1] << " | " << ar[2][2] << "\n";
        cout << "\n\n\n";
    }

    void turns()
    {
        if (turn == 1)
        {
            cout << endl
                 << "\t"
                 << player1 << "'s turn\n";
        }
        else if (turn == 2)
        {
            cout << endl
                 << "\t"
                 << player2 << "'s turn\n";
        }
    }

    void get_data()
    {
        int num, r, q;
        srand(time(0));
        num = (rand() % 9) + 1;
        if (num % 3 == 0)
        {
            i = num / 3;
            j = 3;
        }
        else
        {
            i = num / 3 + 1;
            j = num % 3;
        }
    }

    void get_data(int n)
    {
    b:
        cout << "\n\tEnter the row number : ";
        cin >> i;
        if (i < 1 || i > n)
        {
            cout << "\n\tInvalid input\n";
            goto b;
        }

    c:
        cout << "\n\tEnter the column number : ";
        cin >> j;
        if (j < 1 || j > n)
        {
            cout << "\n\tInvalid input\n";
            goto c;
        }
    }

    int row()
    {
        for (int x = 0; x < 3; x++)
        {
            if (ar[x][0] == ar[x][1] && ar[x][1] == ar[x][2] && ar[x][0] != 0)
                return 1;
        }
        return 0;
    }

    int column()
    {
        for (int x = 0; x < 3; x++)
        {
            if (ar[0][x] == ar[1][x] && ar[1][x] == ar[2][x] && ar[0][x] != 0)
                return 1;
        }
        return 0;
    }

    int diagonal()
    {
        if (ar[0][0] == ar[1][1] && ar[1][1] == ar[2][2] && ar[1][1] != 0)
            return 1;
        if (ar[2][0] == ar[1][1] && ar[1][1] == ar[0][2] && ar[1][1] != 0)
            return 1;
        return 0;
    }

    void result()
    {
        if (mark == 1)
        {
            cout << "\n\tWINNER " << player1;
        }
        else if (mark == 2)
        {
            cout << "\n\tWINNER " << player2;
        }
    }

    void result(int n)
    {
        if (mark == 1)
        {
            cout << "\n\tYOU WIN ";
        }
        else if (mark == 2)
        {
            cout << "\n\tYOU LOOSE ";
        }
    }

    int draw()
    {
        if (ar[0][0] != 0 && ar[0][1] != 0 && ar[0][2] != 0 && ar[1][0] != 0 && ar[1][1] != 0 && ar[1][2] != 0 && ar[2][0] != 0 && ar[2][1] != 0 && ar[2][2] != 0)
            return 1;
        return 0;
    }

    void reset(int n)
    {
        for (int y = 0; y < n; y++)
        {
            for (int z = 0; z < n; z++)
            {
                ar[y][z] = 0;
            }
        }

        turn = 1;
        mark = 1;
    }

    void play_3x3()
    {
        main_menu();
        display();
        while ((row() || column() || diagonal()) == 0)
        {
            turns();
            if (turn == 1)
            {
                mark = 1;
                turn = 2;
            }
            else if (turn == 2)
            {
                mark = 2;
                turn = 1;
            }

        a:
            get_data(n);
            if (ar[i - 1][j - 1] != 0)
            {
                cout << "\n\tInvalid Input\n";
                goto a;
            }
            ar[i - 1][j - 1] = mark;
            system("cls");
            display();
            if (draw())
            {
                break;
            }
        }
        if ((row() || column() || diagonal()) == 1)
        {
            result();
        }
        else
        {
            cout << "\n\tIt's a DRAW\n";
        }

        game_over();

        reset(3);
    }
};

class tictactoe_3x3_auto
{
private:
public:
    int n = 3;
    tictactoe_3x3 a;

    ~tictactoe_3x3_auto()
    {
        game_over();
    }

    void turn_choice()
    {
        cout << "\tWould you like to play first?? (YES/NO) : ";
        string choice;
        cin >> choice;
        if (choice == "YES" || choice == "yes" || choice == "Yes")
        {
            a.turn = 1;
        }
        else
        {
            a.turn = 2;
        }
    }

    void play_3x3_auto()
    {
        turn_choice();
        system("cls");
        a.display();
        while ((a.row() || a.column() || a.diagonal()) == 0)
        {

            if (a.turn == 1)
            {
                a.mark = 1;
                a.turn = 2;
            p:
                a.get_data(n);
                if (a.ar[a.i - 1][a.j - 1] != 0)
                {
                    cout << "\n\tInvalid Input\n";
                    goto p;
                }
            }
            else if (a.turn == 2)
            {
                a.mark = 2;
                a.turn = 1;
            q:
                a.get_data();
                if (a.ar[a.i - 1][a.j - 1] != 0)
                {
                    goto q;
                }
            }

            a.ar[a.i - 1][a.j - 1] = a.mark;
            system("cls");
            a.display();
            if (a.draw())
            {
                break;
            }
        }
        if ((a.row() || a.column() || a.diagonal()) == 1)
        {
            a.result(n);
        }
        else
        {
            cout << "\n\tIt's a DRAW\n";
        }
        a.reset(3);
    }
};

class tictactoe_4x4
{

private:
    int ar[4][4];
    friend class tictactoe_4x4_auto;

public:
    int n = 4;
    tictactoe_3x3 a;

    tictactoe_4x4() : ar{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    {
        a.turn = 1;
        a.mark = 1;
    }

    ~tictactoe_4x4()
    {
        game_over();
    }

    void display_4x4()
    {
        cout << "\n\n\n\n";
        cout << "\t\t\t\t " << ar[0][0] << " | " << ar[0][1] << " | " << ar[0][2] << " | " << ar[0][3] << "\n";
        cout << "\t\t\t\t---+---+---+---\n";
        cout << "\t\t\t\t " << ar[1][0] << " | " << ar[1][1] << " | " << ar[1][2] << " | " << ar[1][3] << "\n";
        cout << "\t\t\t\t---+---+---+---\n";
        cout << "\t\t\t\t " << ar[2][0] << " | " << ar[2][1] << " | " << ar[2][2] << " | " << ar[2][3] << "\n";
        cout << "\t\t\t\t---+---+---+---\n";
        cout << "\t\t\t\t " << ar[3][0] << " | " << ar[3][1] << " | " << ar[3][2] << " | " << ar[3][3] << "\n";
        cout << "\n\n\n";
    }

    int row_4x4()
    {
        for (int x = 0; x < 4; x++)
        {
            if (ar[x][0] == ar[x][1] && ar[x][1] == ar[x][2] && ar[x][2] == ar[x][3] && ar[x][0] != 0)
                return 1;
        }
        return 0;
    }

    int column_4x4()
    {
        for (int x = 0; x < 4; x++)
        {
            if (ar[0][x] == ar[1][x] && ar[1][x] == ar[2][x] && ar[2][x] == ar[3][x] && ar[0][x] != 0)
                return 1;
        }
        return 0;
    }

    int diagonal_4x4()
    {
        if (ar[0][0] == ar[1][1] && ar[1][1] == ar[2][2] && ar[2][2] == ar[3][3] && ar[1][1] != 0)
            return 1;
        if (ar[3][0] == ar[2][1] && ar[2][1] == ar[1][2] && ar[1][2] == ar[0][3] && ar[2][1] != 0)
            return 1;
        return 0;
    }

    int draw_4x4()
    {
        if (ar[0][0] != 0 && ar[0][1] != 0 && ar[0][2] != 0 && ar[0][3] != 0 && ar[1][0] != 0 && ar[1][1] != 0 && ar[1][2] != 0 && ar[1][3] != 0 && ar[2][0] != 0 && ar[2][1] != 0 && ar[2][2] != 0 && ar[2][3] != 0 && ar[3][0] != 0 && ar[3][1] != 0 && ar[3][2] != 0 && ar[3][3] != 0)
            return 1;
        return 0;
    }

    void play_4x4()
    {
        a.main_menu();
        display_4x4();
        while ((row_4x4() || column_4x4() || diagonal_4x4()) == 0)
        {
            a.turns();
            if (a.turn == 1)
            {
                a.mark = 1;
                a.turn = 2;
            }
            else if (a.turn == 2)
            {
                a.mark = 2;
                a.turn = 1;
            }

        a:
            a.get_data(n);
            if (ar[a.i - 1][a.j - 1] != 0)
            {
                cout << "\n\tInvalid Input\n";
                goto a;
            }
            ar[a.i - 1][a.j - 1] = a.mark;
            system("cls");
            display_4x4();
            if (draw_4x4())
            {
                break;
            }
        }
        if ((row_4x4() || column_4x4() || diagonal_4x4()) == 1)
        {
            a.result();
        }
        else
        {
            cout << "\n\tIt's a DRAW\n";
        }
        a.reset(4);
    }
};

class tictactoe_4x4_auto
{
private:
public:
    int n = 4;
    tictactoe_3x3 a;
    tictactoe_4x4 c;

    ~tictactoe_4x4_auto(){};

    void get_data_4x4_auto()
    {
        int num, r, q;
        srand(time(0));
        num = (rand() % 16) + 1;
        if (num % 4 == 0)
        {
            a.i = num / 4;
            a.j = 4;
        }
        else
        {
            a.i = num / 4 + 1;
            a.j = num % 4;
        }
    }

    void turn_choice_4x4()
    {
        cout << "\tWould you like to play first?? (YES/NO) : ";
        string choice;
        cin >> choice;
        if (choice == "YES" || choice == "yes" || choice == "Yes")
        {
            a.turn = 1;
        }
        else
        {
            a.turn = 2;
        }
    }

    void play_4x4_auto()
    {
        turn_choice_4x4();
        system("cls");
        c.display_4x4();
        while ((c.row_4x4() || c.column_4x4() || c.diagonal_4x4()) == 0)
        {

            if (a.turn == 1)
            {
                a.mark = 1;
                a.turn = 2;
            p:
                a.get_data(n);
                if (c.ar[a.i - 1][a.j - 1] != 0)
                {
                    cout << "\n\tInvalid Input\n";
                    goto p;
                }
            }
            else if (a.turn == 2)
            {
                a.mark = 2;
                a.turn = 1;
            q:
                get_data_4x4_auto();
                if (c.ar[a.i - 1][a.j - 1] != 0)
                {
                    goto q;
                }
            }

            c.ar[a.i - 1][a.j - 1] = a.mark;
            system("cls");
            c.display_4x4();
            if (c.draw_4x4())
            {
                break;
            }
        }
        if ((c.row_4x4() || c.column_4x4() || c.diagonal_4x4()) == 1)
        {
            a.result(n);
        }
        else
        {
            cout << "\n\tIt's a DRAW\n";
        }
        a.reset(4);
    }
};

void ttt()
{
    cout << "\n\n\n";
    cout << "\t\t\t\t _______   _    ____       _______    _       ____       _______    ____    ______\n";
    cout << "\t\t\t\t|__   __| | |  / __ \\     |__   __|  / \\     / __ \\     |__   __|  / __ \\  |  ____|\n";
    cout << "\t\t\t\t   | |    | | | |  |_|       | |    /   \\   | |  |_|       | |    | |  | | | |__\n";
    cout << "\t\t\t\t   | |    | | | |   _        | |   / ___ \\  | |   _        | |    | |  | | |  __|\n";
    cout << "\t\t\t\t   | |    | | | |__| |       | |  / /   \\ \\ | |__| |       | |    | |__| | | |____\n";
    cout << "\t\t\t\t   |_|    |_|  \\____/        |_| /_/     \\_\\ \\____/        |_|     \\____/  |______|\n";
    cout << "\n\n\n\n";
}

int main()
{
    system("cls");
    string replay;
    int choice;

    do
    {
        ttt();
    z:
        cout << "\t1. 3x3 Tic Tac Toe\n\t2. 4x4 Tic Tac Toe\n";
        cout << "\n\tEnter Choice : ";
        cin >> choice;
        system("cls");
        if (choice == 1)
        {
            ttt();
        x:

            cout << "\t1. One Player\n\t2. Two Player\n";
            cout << "\n\tEnter Choice : ";
            cin >> choice;
            system("cls");
            if (choice == 1)
            {
                tictactoe_3x3_auto a;
                ttt();
                a.play_3x3_auto();
            }
            else if (choice == 2)
            {
                tictactoe_3x3 b;
                ttt();
                b.play_3x3();
            }
            else
            {
                ttt();
                cout << "\n\tInvalid Choice\n\n";
                goto x;
            }
        }

        else if (choice == 2)
        {
            ttt();
        y:

            cout << "\t1. One Player\n\t2. Two Player\n";
            cout << "\n\tEnter Choice : ";
            cin >> choice;
            system("cls");
            if (choice == 1)
            {
                tictactoe_4x4_auto c;
                ttt();
                c.play_4x4_auto();
            }
            else if (choice == 2)
            {
                tictactoe_4x4 d;
                ttt();
                d.play_4x4();
            }
            else
            {
                ttt();
                cout << "\n\tInvalid Choice\n\n";
                goto y;
            }
        }

        else
        {
            ttt();
            cout << "\tInvalid Choice\n\n";
            goto z;
        }
        cout << "\n\n\tWould you like to play again (YES/NO) : ";
        cin >> replay;
        system("cls");
    } while (replay == "YES" || replay == "yes" || replay == "Yes");

    return 0;
}