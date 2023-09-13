#include <iostream>
#include <stdlib.h>

using namespace std;

int a[10][10];
bool c[3][10][10];
const int n = 9;

int square(int x, int y) {
    return (x/3)+(y/3)*3;
} // 9개의 네모 가운데 어디 네모에 위치해있는지 기록

void go(int z) {
    if (z == 81) {
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++)
                printf("%d ",a[i][j]);
            printf("\n");
        }
        exit(0);
    } // 81개의 칸을 모두 채웠을 때 출력
    
    int x = z/n, y = z%n;
    if (a[x][y] != 0) {
        return go(z+1);
    } else {
        for (int i=1; i<=9; i++) {
            if (c[0][x][i]==0&&c[1][y][i]==0&&c[2][square(x,y)][i]==0) {
                c[0][x][i] = c[1][y][i] = c[2][square(x,y)][i] = true;
                a[x][y] = i;
                go(z+1);
                a[x][y] = 0;
                c[0][x][i] = c[1][y][i] = c[2][square(x,y)][i] = false;
            }
        }
    }
    return;
}

int main(void) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d",&a[i][j]);
            if (a[i][j] != 0) {
                c[0][i][a[i][j]] = true;
                c[1][j][a[i][j]] = true;
                c[2][square(i,j)][a[i][j]] = true;
            }
        }
    }
    go(0);
}
