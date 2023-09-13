//
//  1358.cpp
//  baekjoon
//
//  Created by 배주현 on 2022/07/08.
//

#include <stdio.h>

using namespace std;

int dist(int X, int Y, int x, int y) {
    return (X-x)*(X-x)+(Y-y)*(Y-y);
}

int main(void) {
    int w,h,x,y,p,radius;
    scanf("%d%d%d%d%d",&w,&h,&x,&y,&p);
    radius = h/2;
    
    int count = 0;
    for(int i=0;i<p;i++) {
        int tmp1, tmp2;
        scanf("%d%d",&tmp1,&tmp2);
        if(tmp1>=x && tmp1<=x+w && tmp2<=y+h && tmp2>=y) {
            count++;
        }
        else if(dist(tmp1, tmp2, x, y+radius)<=radius*radius) count++;
        else if(dist(x+w, y+radius, tmp1, tmp2)<=radius*radius) count++;
    }
    printf("%d\n",count);
}
