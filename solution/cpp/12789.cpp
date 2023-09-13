#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    int N; // number of instructions
    int number = 1;
    
    string ans = "Nice\n";
    stack<int> stack;
    
    scanf("%d",&N);
    
    for(int i=0;i<N;i++) {
        int temp;
        scanf("%d",&temp);

        if (temp==number) number++;
        else {
            while(stack.size()!=0 && stack.top()==number) {
                number = stack.top() + 1;
                stack.pop();
            }

            if (stack.size()==0) stack.push(temp);
            else if (stack.size()!=0 && temp<stack.top()) stack.push(temp);
            else {
                ans = "Sad\n";
                break;
            }
        }
    }
    cout << ans;
}
