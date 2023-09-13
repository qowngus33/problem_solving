//
//  2473.cpp
//  baekjoon
//
//  Created by 배주현 on 2022/07/06.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main(void) {
    int N; // 용액의 수
    scanf("%d",&N);
    
    vector<long long> v;
    for(int i=0;i<N;i++) {
        long long temp;
        scanf("%lld",&temp);
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    
    long long ans = 3000000003;
    int a=0,b=1,c=2;
    for(int i=0;i<N-2;i++) {
        int left = i+1;
        int right = N-1;
        while(left<right) {
            if(abs(v[left]+v[right]+v[i])<abs(ans)) {
                ans = abs(v[left]+v[right]+v[i]);
                a = i;
                b = left;
                c = right;
            }
            if(v[left]+v[right]+v[i]<0) left++;
            else if(v[left]+v[right]+v[i]>0) right--;
            else {
                printf("%lld %lld %lld\n",v[i],v[left],v[right]);
                exit(0);
            }
        }
    }
    printf("%lld %lld %lld\n",v[a],v[b],v[c]);
}
