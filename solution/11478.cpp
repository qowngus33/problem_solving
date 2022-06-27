//
//  14425.cpp
//  backjoon
//
//  Created by 배주현 on 2022/06/27.
//

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <queue>
#include <map>
#include <cctype>
#include <set>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    set<string> s;
    string str;
    cin >> str;
    
    for(int i=0;i<str.length();i++) {
        for(int j=1;j<str.length()-i+1;j++) {
            s.insert(str.substr(i,j));
        }
    }
    cout << s.size();
}
