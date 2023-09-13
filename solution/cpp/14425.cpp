//
//  14425.cpp
//  backjoon
//
//  Created by 배주현 on 2022/06/27.
//

#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    set<string> s;
    int N, M;
    cin >> N >> M;
    
    string str;
    for(int i=0;i<N;i++) {
        cin >> str;
        s.insert(str);
    }
    int count = 0;
    for(int i=0;i<M;i++) {
        cin >> str;
        if(s.find(str)!=s.end()) count++;
    }
    cout << count;
}
