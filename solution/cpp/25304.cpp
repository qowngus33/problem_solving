//
//  25304.cpp
//  baekjoon
//
//  Created by 배주현 on 2022/09/11.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main(void) {
    int X; // 영수증에 적힌 총 금액
    int N; // 물건의 종류
    
    scanf("%d%d",&X,&N);
    
    int sum = 0;
    for(int i=0;i<N;i++) {
        int a, b;
        scanf("%d%d",&a,&b);
        sum += (a*b);
    }
    
    if(sum==X)
        cout << "Yes";
    else
        cout << "No";
}
