//
//  6236.cpp
//  baekjoon
//
//  Created by 배주현 on 2022/07/25.
//

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int N, M;

int main(void) {
    scanf("%d%d",&N,&M);
    int max = 0, sum = 0;
    for(int i=0;i<N;i++) {
        int temp;
        scanf("%d",&temp);
        v.push_back(temp);
        if(temp>max) max=temp;
        sum += temp;
    }
    int start = max;
    int end = sum+1;
    while (start<=end) {
        int mid = (start+end)/2;
        
        int money = mid, num = 1;
        for(int i=0;i<v.size();i++) {
            if(money<v[i]) {
                money = mid;
                num++;
            }
            money-=v[i];
        }
        if(num<=M) end = mid-1;
        else start = mid+1;
    }
    printf("%d\n",start);
}
