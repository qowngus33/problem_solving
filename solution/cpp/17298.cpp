#include<iostream>
#include<stack>

using namespace std;
// 오큰수

int N;
stack<int> s;
int ans[1000001], seq[1000001];

int main(void) {
    scanf("%d",&N);
  
    for (int i=0; i<N; i++)
        cin >> seq[i];
    
    for (int i=N-1; i>=0; i--) {
        while (!s.empty() && s.top()<=seq[i]) s.pop();
        
        if (s.empty()) ans[i] = -1;
        else ans[i] = s.top();
        
        s.push(seq[i]);
    }
    
    for (int i=0; i<N; i++)
        printf("%d ",ans[i]);
}

