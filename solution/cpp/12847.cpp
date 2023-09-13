//
//  12847.cpp
//  backjoon
//
//  Created by 배주현 on 2022/06/29.
//

#include <iostream>
#include <algorithm>

using namespace std;
long long a[100001];

int main(void) {
    int n,m;
    scanf("%d%d",&n,&m);
    
    scanf("%lld",&a[0]);
    for(int i=1;i<n;i++) {
        scanf("%lld",&a[i]);
        a[i]+=a[i-1];
    }
    
    long long answer = a[2]-0;
    for(int i=m; i<n; i++) {
        if(a[i]-a[i-m]>answer) answer=a[i]-a[i-m];
    }
    
    printf("%lld",answer);
}
