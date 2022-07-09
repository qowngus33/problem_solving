//
//  24416.cpp
//  baekjoon
//
//  Created by 배주현 on 2022/07/09.
//

#include <iostream>
#include <string>

using namespace std;

int list[27][200002];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string str;
    cin >> str;
    for(int i=0;i<str.length();i++)
        list[str[i]-97][i+1] = 1;
    
    for(int i=1;i<=str.length();i++)
        for(int j=0;j<27;j++)
            list[j][i] +=  list[j][i-1];
    
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        char ch;
        int a, b;
        cin >> ch >> a >> b;
        cout << list[(int)ch-97][b+1]-list[(int)ch-97][a] << "\n";
    }
    
}
