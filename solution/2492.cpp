//
//  2492.cpp
//  baekjoon
//
//  Created by 배주현 on 2022/07/17.
//

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N,M,T,K;
// 지도의 너비, 지도의 높이, 금강석 개수, 정사각형 크기
vector<pair<int, int>> pointSet;

int sum(int x, int y) {
    int ans = 0;
    int idx = 0;
    while(1) {
        if(idx>=pointSet.size()) break;
        if(pointSet[idx].first>=x&&pointSet[idx].first<=x+K&&pointSet[idx].second>=y&&pointSet[idx].second<=y+K)
            ans++;
        idx++;
    }
    return ans;
}


int main(void) {
    scanf("%d%d%d%d",&N,&M,&T,&K);
    
    for(int i=0;i<T;i++) {
        int X,Y;
        scanf("%d%d",&X,&Y);
        pointSet.push_back({X,Y});
    }
    sort(pointSet.begin(), pointSet.end());
    
    int ansX=pointSet[0].first,ansY=pointSet[0].second,ans = 0;
    
    for(int i=0; i<T; i++){
        for(int j=0; j<T; j++){
            int temp = sum(pointSet[i].first,pointSet[j].second);
            if(temp > ans){
                ans = temp;
                ansX = pointSet[i].first;
                ansY = pointSet[j].second+K;
                if(ansX+K>N) ansX = N - K;
                if(ansY>M) ansY = M;
            }
        }
    }

    printf("%d %d\n%d\n",ansX,ansY,ans);
}
