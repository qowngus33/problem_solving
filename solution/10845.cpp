//
//  10845.cpp
//  backjoon
//
//  Created by 배주현 on 2022/06/24.
//

#include <iostream>

using namespace std;

int list[30001];
int endNum = 0;
int frontNum = 0;

void push(int n) {
    list[endNum] = n;
    endNum++;
}

void pop() {
    if(endNum == frontNum)
        printf("-1\n");
    else {
        printf("%d\n",list[frontNum]);
        frontNum++;
    }
}

void back() {
    if(endNum == frontNum)
        printf("-1\n");
    else
        printf("%d\n",list[endNum-1]);
}

void front() {
    if(endNum == frontNum)
        printf("-1\n");
    else
        printf("%d\n",list[frontNum]);
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
            if(frontNum == endNum) printf("1\n");
            else printf("0\n");
        }
        else if(tempStr == "size") {
            printf("%d\n",endNum - frontNum);
        }
        else if(tempStr == "back") {
            back();
        }
        else if(tempStr == "front") {
            front();
        }
    }
}
