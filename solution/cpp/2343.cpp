//
//  2343.cpp
//  baekjoon
//
//  Created by 배주현 on 2022/07/27.
//

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> v;
int N, M;

int main(void) {
    scanf("%d%d",&N,&M);
    long long sum = 0;
    long long start = 0;
    
    for(int i=0;i<N;i++) {
        long long temp;
        scanf("%lld",&temp);
        v.push_back(temp);
        sum += temp;
        if(temp>start) start = temp;
    }
    
    long long end = sum+1;
    
    while (start<=end) {
        long long mid = (start+end)/2;
        long long tempSum = 0, num = 1;
        long long max = 0;
        for(int i=0;i<v.size();i++) {
            if(tempSum+v[i]<=mid) {
                tempSum+=v[i];
            } else {
                if(tempSum>max) max=tempSum;
                tempSum = v[i];
                num++;
            }
        }
        if(num>M) start = mid+1;
        else end = mid-1;
    }
    printf("%lld\n",start);
}

