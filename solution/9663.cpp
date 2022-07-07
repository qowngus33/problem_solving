//
//  9663.cpp
//  baekjoon
//
//  Created by 배주현 on 2022/07/07.
//

#include <stdio.h>

using namespace std;

int N;
int ans = 0;
int list[16][16];

void nqueen(int idx) {
    if(idx>=N) {
        ans++;
        return;
    }
    for(int j=0;j<N;j++) {
        if(list[idx][j]==0) {
            for(int k=1;k<N;k++) {
                if(idx+k<N) list[idx+k][j]++;
                if(idx+k<N && j+k<N) list[idx+k][j+k]++;
                if(idx+k<N && j-k>=0) list[idx+k][j-k]++;
            }
            nqueen(idx+1);
            for(int k=1;k<N;k++) {
                if(idx+k<N) list[idx+k][j]--;
                if(idx+k<N && j+k<N) list[idx+k][j+k]--;
                if(idx+k<N && j-k>=0) list[idx+k][j-k]--;
            }
        }
    }
    return;
}

int main(void) {
    scanf("%d",&N);
    nqueen(0);
    printf("%d",ans);
}
