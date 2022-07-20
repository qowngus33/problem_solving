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
#include <queue>

using namespace std;

int list[129][129];
int bluePaper = 0;
int whitePaper = 0;
string str = "";

void papercut(int i, int j, int n) {
   if(n==1) {
       str += (char)(list[i][j]+48);
       return;
   }
   
    bool flag = true;
    for(int k=i;k<i+n;k++) {
        for(int h=j;h<j+n;h++) {
            if(list[k][h] != list[i][j]) {
                flag = false;
                break;
            }
        }
    }

    if(flag) {
        str += (char)(list[i][j]+48);
        return;
    }
    
    str += '(';
    papercut(i, j, n/2);
    papercut(i, j+n/2, n/2);
    papercut(i+n/2, j, n/2);
    papercut(i+n/2, j+n/2, n/2);
    str += ')';
}

int main(void){
    
    int n;
    string tempStr;
    
    cin >> n;
    
    for(int i=0;i<n;i++) {
        cin >> tempStr;
        for(int j=0;j<n;j++)
            list[i][j] = tempStr.at(j) - '0';
    }
    
    papercut(0,0,n);
    cout << str << endl;
}
