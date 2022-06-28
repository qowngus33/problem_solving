//
//  4949.cpp
//  backjoon
//
//  Created by 배주현 on 2022/06/28.
//

#include <iostream>
#include <stack>
#include <map>

using namespace std;

int main(void) {
    string str;
    map<char, char> mp;
    mp.insert({']','['});
    mp.insert({')','('});
    
    while(1) {
        stack<char> st;
        string ans = "yes\n";
        getline(cin, str);
        if(str==".") break;
        for(int i=0;i<str.length();i++) {
            if(str[i]=='['||str[i]=='(') {
                st.push(str[i]);
            } else if(str[i]==']'||str[i]==')') {
                if(!st.empty()&&st.top()==mp[str[i]])  st.pop();
                else ans = "no\n";
            }
        }
        if(!st.empty()) cout << "no" << "\n";
        else cout << ans;
    }
}
