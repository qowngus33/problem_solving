#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <queue>
#include <map>
#include <cctype>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    string str;
    map<int,string> poketmonInfo;
    map<string,int> poketmonInfo2;
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        cin >> str;
        poketmonInfo[i+1] = str;
        poketmonInfo2[str] = i+1;
    }
    
    for(int i=0;i<M;i++) {
        cin >> str;
        if((int)str[0]>=65 && (int)str[0]<=90)
            cout << poketmonInfo2[str] << "\n";
        else
            cout << poketmonInfo[stoi(str)] << "\n";
    }
}


