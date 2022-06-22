#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <utility>
#include <string>
#include <cstring>
#include <string.h>
#include <cstdlib>
#include <stack>
#include <algorithm>

using namespace std;

int list[10001];
int stackSize = 0;

void push(int n) {
    list[stackSize] = n;
    stackSize++;
}

void pop() {
    if(stackSize == 0)
        printf("-1\n");
    else {
        printf("%d\n",list[stackSize-1]);
        stackSize--;
    }
}

int main(void) {
    
    int commandNum;
    
    scanf("%d",&commandNum);
    
    for(int i=0;i<commandNum;i++) {
        string tempStr;
        int temp;
        cin >> tempStr;
        
        if(tempStr == "push") {
            scanf("%d\n",&temp);
            push(temp);
        }
        else if(tempStr == "pop") {
            pop();
        }
        else if(tempStr == "empty") {
            if(stackSize == 0) printf("1\n");
            else printf("0\n");
        }
        else if(tempStr == "size") {
            printf("%d\n",stackSize);
        }
        else if(tempStr == "top") {
            if(stackSize == 0)
                printf("-1\n");
            else
                printf("%d\n",list[stackSize-1]);
        }
    }
}

