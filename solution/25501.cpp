//
//  25501.cpp
//  baekjoon
//
//  Created by 배주현 on 2022/09/11.
//

#include <stdio.h>
#include <string.h>

int cnt = 0;
char s[1001];

int recursion(const char* s, int l, int r, int *cnt) {
    if (l >= r) {
        *cnt += 1;
        return 1;
    }
    else if (s[l] != s[r]) {
        *cnt += 1;
        return 0;
    }
    else {
        *cnt += 1;
        return recursion(s, l + 1, r - 1, cnt);
    }
}

int isPalindrome(const char* s) {
    return recursion(s, 0, strlen(s) - 1, &cnt);
}

int main() {
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", s, 1001);

        printf("%d ", isPalindrome(s));
        printf("%d\n", cnt);
        cnt = 0;
    }
    return 0;
}
