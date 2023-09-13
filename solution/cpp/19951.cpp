//
//  19951.cpp
//  baekjoon
//
//  Created by 배주현 on 2022/07/01.
//

#include <iostream>
#include <vector>

#define MAX 100100

int N; // 연병장의 수
int M; // 조교의 수
int sum[MAX], arr[MAX], H[MAX];

int main(void) {

    scanf("%d%d",&N,&M);
    
    for (int i=1;i<=N;i++)
        scanf("%d",&H[i]);
    
    int a, b, k;
    for (int i=0;i<M;i++) {
        scanf("%d%d%d",&a,&b,&k);
        arr[a] += k;
        arr[b+1] -= k;
    }
    
    for (int i=1;i<=N;i++)
        sum[i] = sum[i-1]+arr[i];
    
    for (int i=1;i<=N;i++)
        printf("%d ", sum[i]+H[i]);
    
    printf("\n");

}
