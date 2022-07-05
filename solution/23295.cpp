//
//  23295.cpp
//  baekjoon
//
//  Created by 배주현 on 2022/07/05.
//

#include <stdio.h>

using namespace std;

const int MAX = 100010;
long long list[MAX],sum[MAX];

int main(void) {
    long long N, T; // 참가자 수, 스터디 시간
    scanf("%lld%lld",&N,&T);
    
    for(long long i=0;i<N;i++) {
        long long K;
        scanf("%lld",&K);
        
        for(long long i=0;i<K;i++) {
            long long S,E;
            scanf("%lld%lld",&S,&E);
            list[S] += 1;
            list[E] -= 1;
        }
    }
    
    for(long long i=1;i<MAX;i++) {
        list[i] += list[i-1];
    }
    sum[0] = list[0];
    for (long long i=1;i<MAX;i++) sum[i] += sum[i-1]+list[i];
    
    long long ans = sum[T-1];
    long long S = 0;
    for(long long i=0;i<MAX-T;i++) {
        if(sum[i+T-1]-sum[i-1]>ans) {
            ans = sum[i+T-1]-sum[i-1];
            S = i;
        }
    }
    printf("%lld %lld\n",S,S+T);
}

