//
//  19951.cpp
//  baekjoon
//
//  Created by 배주현 on 2022/07/01.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int sum[2000002], arr[2000002];

int main(void) {
    scanf("%d",&N);
    vector<pair<int, int>> pv; // 초기에 모기가 출퇴한 시각을 저장
    vector<int> v; // 압축한 좌표의 값을 저장
    
    for (int i=0;i<N;i++) {
        int tmp1, tmp2;
        scanf("%d%d",&tmp1,&tmp2);
        pv.push_back({tmp1,tmp2});
        v.push_back(tmp1);
        v.push_back(tmp2);
    }
    
    // 좌표압축
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    
    for(int i=0;i<pv.size();i++) {
        sum[lower_bound(v.begin(),v.end(),pv[i].first)-v.begin()] += 1;
        sum[lower_bound(v.begin(),v.end(),pv[i].second)-v.begin()] -= 1;
    } // v의 size 만큼의 arr 범위
    
    for (int i=1;i<v.size();i++)
        sum[i]+=sum[i-1];
    
    int maxN=0;
    for(int i=0;i<v.size();i++) {
        maxN = max(maxN,sum[i]);
    }
    
    int Te = 0,Tx = 0;
    bool isContinue = false;
    
    for (int i=0;i<v.size();i++) {
        if(!isContinue && sum[i]==maxN) {
            Te = v[i]; // 압축했던 좌표를 다시 품
            isContinue = true;
        }
        if(isContinue && sum[i]!=maxN) {
            Tx = v[i]; // 압축했던 좌표를 다시 품
            break;
        }
    }
    
    printf("%d\n%d %d\n",maxN,Te,Tx);
}
