//
//  16564.cpp
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
    long long start = 0,end = 0;
    
    for(int i=0;i<N;i++) {
        long long temp;
        scanf("%lld",&temp);
        v.push_back(temp);
        sum+=temp;
        if(temp<start) start=temp;
    }
    end = sum+M;
    
    while (start<=end) {
        long long mid = (start+end)/2;
        long long num = 0;
        for(int i=0;i<v.size();i++)
            if(v[i]<mid)
                num+=(mid-v[i]);
        if(num<=M) start = mid+1;
        else end = mid-1;
    }
    printf("%lld\n",end);
}
