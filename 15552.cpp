#include <iostream>
using namespace std;

int main(void) {
    int num;
    int x, y;
    
    scanf("%d", &num);
    
    for(int i=0;i<num;i++){
        scanf("%d%d", &x,&y);
        printf("%d\n",x+y);
    }
}
