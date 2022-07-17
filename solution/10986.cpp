//
//  10986.cpp
//  baekjoon
//
//  Created by 배주현 on 2022/07/11.
//

#include <stdio.h>

using namespace std;

long long list[1000001];

int main(void) {
    int N, M;
    scanf("%d%d",&N,&M);
    
    scanf("%lld",&list[1]);
    for(int i=2;i<=N;i++) {
        scanf("%lld",&list[i]);
        list[i] += list[i-1];
        list[i]%=M;
    }
    
    int ans = 0;
    for(int j=1;j<=N;j++)
        for(int i=0;i<=N-j;i++)
            if((list[i+j]-list[i])%M==0) ans++;
        
    printf("%d\n",ans);
}
