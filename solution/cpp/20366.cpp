//
//  20366.cpp
//  baekjoon
//
//  Created by 배주현 on 2022/07/05.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;


int main(void) {
    int N;
    vector<int> v;
    scanf("%d",&N);
    
    for(int i=0;i<N;i++) {
        int temp;
        scanf("%d",&temp);
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end());
    
    int ans = 1000000000;
    for(int i=0;i<N-3;i++) {
        for(int j=i+3;j<N;j++) {
            int fix = v[i]+v[j];
            // 슬라이딩 윈도우
            int left=i+1,right=j-1;
            while(left<right) {
                int temp = v[left] + v[right];
                if(abs(temp-fix)<ans) {
                    ans = abs(temp-fix);
                }
                if(temp<fix) left+=1;
                else if(temp>fix) right -= 1;
                else {
                    printf("0\n");
                    exit(0);
                }
            }
        }
    }
    
    printf("%d\n",ans);
}
