//
//  1940.cpp
//  baekjoon
//
//  Created by 배주현 on 2022/06/29.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long a[250002];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N,M;
    cin >> N >> M;
    
    cin >> a[0];
    for(int i=1;i<N;i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    
    long long maxNum = a[M-1]-0;
    int count = 1;
    for(int i=M;i<N;i++) {
        if(a[i]-a[i-M]>maxNum) {
            maxNum = a[i]-a[i-M];
            count = 1;
        } else if((a[i]-a[i-M])==maxNum){
            count++;
        }
    }
    if(maxNum==0) cout << "SAD\n";
    else cout << maxNum << "\n" << count << "\n";
}
