//
//  3649.cpp
//  baekjoon
//
//  Created by 배주현 on 2022/07/02.
//

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> p1,pair<int, int> p2) {
    return (p1.second-p1.first) < (p2.second-p2.first);
}

int main(void) {
    int x,n;
    vector<int> v;
    vector<pair<int, int>> pairV;
    
    while(scanf("%d",&x)==1){
        
        scanf("%d",&n);
        x *= 10000000;
        
        for(int i=0;i<n;i++) {
            int temp;
            scanf("%d",&temp);
            v.push_back(temp);
        }
        
        sort(v.begin(), v.end());
        
        int left=0, right=n-1;
        while(left < right) {
            if(v[left] + v[right] > x) right--;
            else if(v[left] + v[right] < x) left++;
            else {
                pairV.push_back({v[left],v[right]});
                right--;
            }
        }
        
        sort(pairV.begin(), pairV.end(),cmp);
        
        if(pairV.size()==0)
            printf("danger\n");
        else {
            printf("yes %d %d\n",pairV[pairV.size()-1].first,pairV[pairV.size()-1].second);
        }
        v.clear();
        pairV.clear();
    }
}
