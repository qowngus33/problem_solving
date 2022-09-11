//
//  25305.cpp
//  baekjoon
//
//  Created by 배주현 on 2022/09/11.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    int N, k;
    vector<int> v;
    scanf("%d%d",&N,&k);
    
    for(int i=0;i<N;i++) {
        int temp;
        scanf("%d",&temp);
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end());
    
    printf("%d",v[N-k]);
}
