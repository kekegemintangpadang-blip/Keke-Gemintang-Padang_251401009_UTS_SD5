#include <iostream>
using namespace std;

int main() {
    int lapisan[2][3][4];
    int ganjil = 1;
    int kelipatan = 5;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            lapisan[0][i][j] = ganjil;
            ganjil += 2;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            lapisan[1][i][j] = kelipatan;
            kelipatan += 5;
        }
    }

    cout << "Rata-rata:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            int rata_rata = ((lapisan[0][i][j] + lapisan[1][i][j]) / 2);
            cout << rata_rata << " ";
        }
        cout << endl;
    }

    return 0;
}