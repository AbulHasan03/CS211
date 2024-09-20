#include <iostream>
#include <string>

using namespace std;

const string bb = "##"; // black box
const string wb = "  "; // white box
const string wq = " w"; // white queen
const string bq = " b"; // black queen

void print(const int q[]) {
    string board[8][8];

    // fill board with black and white boxes
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if((i+j)%2 == 0)
                board[i][j] = bb;
            else
                board[i][j] = wb;
        }
    }

    // place queens on board
    for(int i=0; i<8; i++) {
        int row = q[i];
        int col = i;
        if((row+col)%2 == 0)
            board[row][col] = wq;
        else
            board[row][col] = bq;
    }

    // print board
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }

    // reset board to original values
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if((i+j)%2 == 0)
                board[i][j] = bb;
            else
                board[i][j] = wb;
        }
    }
}

bool check(int q[], int col) {
    for(int i=0; i<col; i++) {
        if(q[i] == q[col] || abs(q[col]-q[i]) == col-i)
            return false;
    }
    return true;
}

void backtrack(int &col) {
    col--;
    if(col == -1)
        exit(1);
}

void solve() {
    int q[8];
    q[0] = 0;
    int col = 1;

    while(col >= 0 && col < 8) {
        if(col == 8) {
            print(q);
            backtrack(col);
        }

        q[col] = -1;
        while(q[col] < 8) {
            q[col]++;
            if(q[col] == 8) {
                backtrack(col);
            }

            if(check(q, col))
                break;
        }
        col++;
    }
}

int main() {
    solve();
    return 0;
}
