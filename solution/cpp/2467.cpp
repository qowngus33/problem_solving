//
//  2467.cpp
//  baekjoon
//
//  Created by 배주현 on 2022/07/03.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> p1,pair<int, int> p2) {
    return abs(p1.first-p1.second) > abs(p2.first-p2.second) ;
}

int main(void) {
    int N;
    vector<int> v;
    pair<int, int>  ans;
    scanf("%d",&N);
    
    for(int i=0;i<N;i++) {
        int temp;
        scanf("%d",&temp);
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    
    int value = 2000000001;
    int left=0,right=N-1;
    while(left<right) {
        if(abs(v[left]+v[right])<value) {
            value = abs(v[left]+v[right]);
            ans.first = v[left];
            ans.second = v[right];
        } else if(abs(v[left]+v[right])==0) {
            ans.first = v[left];
            ans.second = v[right];
            break;
        }
        
        if (v[left]+v[right]>0) right--;
        else if (v[left]+v[right]<0) left++;
    }
    printf("%d %d",ans.first,ans.second);
}
