//
//  3003.cpp
//  baekjoon
//
//  Created by 배주현 on 2022/09/11.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main(void) {
    int k, q, l, b, n, p;
    scanf("%d%d%d%d%d%d",&k,&q,&l,&b,&n,&p);
    printf("%d %d %d %d %d %d",1-k, 1-q, 2-l, 2-b, 2-n, 8-p);
}
