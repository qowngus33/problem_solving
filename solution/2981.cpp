#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    int c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main(void) {
    int N,temp,value;
    vector<int> v;
    vector<int> tempList;
    vector<int> ans;
    
    scanf("%d",&N);
    scanf("%d",&temp);
    value = temp;
    
    for(int i=0;i<N-1;i++) {
        scanf("%d",&temp);
        tempList.push_back(abs(value - temp));
        value = temp;
    }
    
    int commonValue = gcd(tempList[0], tempList[1]);
    
    for(int i=2;i<tempList.size();i++) {
        commonValue = gcd(commonValue, tempList[i]);
        if(commonValue==1) break;
    }
    
    int flag = 2;
    ans.push_back(commonValue);
    
    while(flag*flag <= commonValue) {
        if(commonValue%flag==0) {
            ans.push_back(flag);
            ans.push_back(commonValue/flag);
            
        }
        flag++;
    }
    
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()),ans.end());
    
    for(int i=0;i<ans.size();i++)
        printf("%d ",ans[i]);
}
