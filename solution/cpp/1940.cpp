//
//  1940.cpp
//  backjoon
//
//  Created by 배주현 on 2022/06/29.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 주몽

int main(void) {
    int N,M;
    vector<int> v;
    
    scanf("%d%d",&N,&M);
    
    int temp;
    for(int i=0;i<N;i++) {
        scanf("%d",&temp);
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end());
    
    int left = 0, right = N-1, ans = 0;
    
    while(left < right) {
        if(v[left] + v[right] > M) right--;
        else if(v[left] + v[right] < M) left++;
        else {
            ans++;
            right--;
        }
    }
    
    printf("%d",ans);
}
