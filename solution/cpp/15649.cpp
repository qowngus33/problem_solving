//
//  15649.cpp
//  baekjoon
//
//  Created by 배주현 on 2022/07/06.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, visited[10];
vector<int> v;

void backtrack(int cnt, int idx) {
    if(cnt == M) {
        for(int i=0;i<M;i++) printf("%d ",v[i]);
        printf("\n");
        return;
    }
    for(int i=1;i<=N;i++) {
        if(!visited[i]) {
            visited[i] = true;
            v.push_back(i);
            backtrack(cnt+1, i);
            v.erase(v.end()-1);
            visited[i] = false;
        }
    }
}

int main(void) {
    scanf("%d%d",&N,&M);
    backtrack(0,1);
}

