//
//  2512.cpp
//  baekjoon
//
//  Created by 배주현 on 2022/07/25.
//

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

bool check(int H, long long value) {
    int sum = 0;
    for(int i=v.size()-1;i>=0;i--) {
        if(v[i]<=H) break;
        else {
            sum += (v[i]-H);
        }
    }
    if(sum>=value) return true;
    return false;
}

int main(void) {
    int N, M;
    scanf("%d",&N);
    
    long long sum = 0;
    for(int i=0;i<N;i++) {
        int temp;
        scanf("%d",&temp);
        v.push_back(temp);
        sum += temp;
    }
    sort(v.begin(), v.end());
    scanf("%d",&M);
    if(sum<=M) {
        printf("%d\n",v[N-1]);
    } else {
        int start = 0;
        int end = v[N-1];
        while (start + 1 < end) {
            int mid = (start + end)/2;
            if (check(mid,sum-M)) {
                start = mid;
            } else {
                end = mid;
            }
        }
        printf("%d\n",start);
    }
}
