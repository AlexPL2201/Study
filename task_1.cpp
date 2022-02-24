#include <string>
#include <iostream>

using namespace std;
int steps[8][2] = { {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1} };

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



int what_next(int pos_x, int pos_y, int counter) {
    int vars[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    for (int i = 0; i < 8; i++) {
        if (pos_x + steps[i][0] < 8 && pos_y + steps[i][1] < 8 && pos_x + steps[i][0] >= 0 && pos_y + steps[i][1] >= 0 && board[pos_y + steps[i][1]][pos_x + steps[i][0]] == 0) {
            vars[i] += 1;
        }
    }
    int next_vars[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

    for (int i = 0; i < 8; i++) {
        int next_x = steps[i][0] + pos_x;
        int next_y = steps[i][1] + pos_y;

        
        for (int j = 0; j < 8; j++) {
            if (vars[i] > 0) {
                
                if (next_x + steps[j][0] < 8 && next_y + steps[j][1] < 8 && next_x + steps[j][0] >= 0 && next_y + steps[j][1] >= 0 && board[next_y + steps[j][1]][next_x + steps[j][0]] == 0) {
                    next_vars[i] += 1;
                }
            }
        }
    }
    int next_vars_min_ind = 0;
    int next_vars_min = 10;
    for (int i = 0; i < 8; i++) {
        if (next_vars[i] < next_vars_min && next_vars[i] != 0) {
            next_vars_min = next_vars[i];
            next_vars_min_ind = i;
        }
        else if (vars[i] < next_vars_min && vars[i] != 0 && counter == 63) {
            next_vars_min = vars[i];
            next_vars_min_ind = i;
        }
    }
    
    return next_vars_min_ind;
}


void show_board(int pos_x, int pos_y, int counter) {
    int ind;
    while (counter < 64) {
        ind = what_next(pos_x, pos_y, counter);
        pos_x += steps[ind][0];
        pos_y += steps[ind][1];
        counter++;
        board[pos_y][pos_x] = counter;
    }
}


int main()
{
    int counter = 1;
    setlocale(LC_ALL, "ru");
    int x0 = 8, y0 = 8;
    while (x0 >= 8 || y0 >= 8 || x0 < 0 || y0 < 0) {
        cout << "Введите координату по X: ";
        cin >> x0;
        cout << "Введите координату по Y: ";
        cin >> y0;
    }
    clock_t start, end;
    board[y0][x0] = counter;
    show_board(x0, y0, counter);
    cout << endl;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout.width(4);
            cout << board[i][j];
        }
        cout << endl;
    }
    return 0;
}
