//
//  14465.cpp
//  baekjoon
//
//  Created by 배주현 on 2022/07/01.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int list[100002];

int main(void) {
    int N,K,B;
    scanf("%d%d%d",&N,&K,&B);
    
    int temp;
    for(int i=0;i<B;i++) {
        scanf("%d",&temp);
        list[temp] = 1;
    }
    
    for(int i=2;i<=N;i++) list[i] += list[i-1];
    
    int minNum = 1000000000;
    for(int i=K+1;i<=N;i++)
        if(list[i]-list[i-K]<minNum)
            minNum = list[i]-list[i-K];
    
    printf("%d",minNum);
}
