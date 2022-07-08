//
//  1004.cpp
//  baekjoon
//
//  Created by 배주현 on 2022/07/08.
//

#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int dist(pair<int, int> p1, pair<int, int> p2) {
    return (p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second);
}

int main(void) {
    pair<int, int> start, end;
    int T;
    scanf("%d",&T);
    
    for(int i=0;i<T;i++) {
        scanf("%d%d%d%d",&start.first,&start.second,&end.first,&end.second);
        int N, count = 0;
        scanf("%d",&N);
        for(int j=0;j<N;j++) {
            int x,y,diameter;
            scanf("%d%d%d",&x,&y,&diameter);
            if(dist(start,{x,y})<diameter*diameter && dist(end,{x,y})>diameter*diameter)
                count++;
            else if(dist(start,{x,y})>diameter*diameter && dist(end,{x,y})<diameter*diameter)
                count++;
        }
        printf("%d\n",count);
    }
}
