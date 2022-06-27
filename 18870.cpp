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

int main(void) {
    
    int n, temp;
    vector<int> v;
    cin >> n;
    
    for(int i=0;i<n;i++) {
        cin >> temp;
        v.push_back(temp);
    }
    
    vector<int> cv(v);
    sort(cv.begin(), cv.end());
    cv.erase(unique(cv.begin(), cv.end()), cv.end());
    
    for (int i=0; i<n; i++) {
        auto it = lower_bound(cv.begin(), cv.end(), v[i]);
        cout << it - cv.begin() << ' ';
    }
}
