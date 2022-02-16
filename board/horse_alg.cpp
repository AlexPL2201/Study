#include <string>
#include <iostream>
#include <algorithm>
#include <Windows.h>

using namespace std;

int board[8][8] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
};

int show_board(int pos_x, int pos_y, int counter) {
    system("cls");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i == pos_y && j == pos_x && board[i][j] == 0)
                board[i][j] = counter;
            else if (i == pos_y && j == pos_x && board[i][j] != 0) {
                system("cls");
                cout << "Ошибка. Конь в пройденной позиции.";
                exit(1);
            }
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int steps[8][2] = { {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1} };
    int counter = 1;
    setlocale(LC_ALL, "ru");
    while (counter < 64) {
        int x0 = 8, y0 = 8;
        while (x0 >= 8 || y0 >= 8 || x0 < 0 || y0 < 0) {
            cout << "Введите координату по X: ";
            cin >> x0;
            cout << "Введите координату по Y: ";
            cin >> y0;
        }
        show_board(x0, y0, counter);
        counter++;
    }
    
    system("pause");
    return 0;
}
