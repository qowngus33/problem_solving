#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

int main(void) {
    int N, M;
    string temp;
    vector<string> v,v2;
    
    scanf("%d%d",&N,&M);
    
    for(int i=0;i<(N+M);i++) {
        cin >> temp;
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end());
    
    for(int i=0;i<(N+M-1);i++)
        if(v[i] == v[i+1])
            v2.push_back(v[i]);
    
    cout << v2.size() << "\n";
    
    for(int i=0;i<v2.size();i++)
        cout << v2[i] << "\n";
    
}
