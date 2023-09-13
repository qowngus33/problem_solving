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

int equationList[4];
int numberList[12];
int N;
int result;
vector<int> v;

int calculator(int temp1, int n, int temp2) {
    switch (n) {
        case 0:
            temp2 += temp1;
            return temp2;
        case 1:
            temp2 -= temp1;
            return temp2;
        case 2:
            temp2 *= temp1;
            return temp2;
        case 3:
            temp2 =  temp2 / temp1;
            return temp2;
    }
    return -1;
}

void calcul(int n) {
    if(n == N) {
        v.push_back(result);
        return;
    }
    
    for(int i=0;i<4;i++) {
        if(equationList[i] > 0) {
            int pre = result;
            result = calculator(numberList[n], i, result);
            equationList[i]--;
            calcul(n+1);
            equationList[i]++;
            result = pre;
        }
    }
}


int main(void) {
    scanf("%d",&N);
    
    for(int i=0;i<N;i++) {
        int temp;
        scanf("%d",&temp);
        numberList[i] = temp;
    }
    
    scanf("%d%d%d%d",&equationList[0],&equationList[1],&equationList[2],&equationList[3]);
    
    result = numberList[0];
    
    calcul(1);
    
    sort(v.begin(), v.end());
    
    cout << v[v.size()-1] << endl << v[0]  << endl;
   
}
