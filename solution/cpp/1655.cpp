//
//  1655.cpp
//  backjoon
//
//  Created by 배주현 on 2022/06/25.
//

#include <iostream>
#include <functional>
#include <queue>

using namespace std;

int main(void) {
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    
    int n,temp;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++) {
        scanf("%d",&temp);
        if(maxheap.size()==0)
            maxheap.push(temp);
        else {
            if(maxheap.size()>minheap.size())
                minheap.push(temp);
            else
                maxheap.push(temp);
            
            if (maxheap.top()>minheap.top()) {
                int tmp = maxheap.top();
                maxheap.pop();
                maxheap.push(minheap.top());
                minheap.pop();
                minheap.push(tmp);
            }
        }
        
        printf("%d\n",maxheap.top());
    }
}
