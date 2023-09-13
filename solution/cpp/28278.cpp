#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>

using namespace std;

//1 X: 정수 X를 스택에 넣는다. (1 ≤ X ≤ 100,000)
//2: 스택에 정수가 있다면 맨 위의 정수를 빼고 출력한다. 없다면 -1을 대신 출력한다.
//3: 스택에 들어있는 정수의 개수를 출력한다.
//4: 스택이 비어있으면 1, 아니면 0을 출력한다.
//5: 스택에 정수가 있다면 맨 위의 정수를 출력한다. 없다면 -1을 대신 출력한다


class Stack {
private:
    int list[1000000];
    int size = 0;
public:
    void Insert(int number);
    int Pop();
    int Top();
    int Size();
};

void Stack::Insert(int number) {
    list[size] = number;
    size++;
}

int Stack::Pop() {
    if(size==0)
        return -1;
    return list[--size];
}

int Stack::Top() {
    if(size==0)
        return -1;
    return list[size-1];
}

int Stack::Size() {
    return size;
}

int main(void) {
    int N; // number of instructions
    Stack stack;
    scanf("%d",&N);
    
    for(int i=0;i<N;i++) {
        int a;
        scanf("%d",&a);
        
        if(a==1) {
            int temp;
            scanf("%d",&temp);
            stack.Insert(temp);
        } else if(a==2) {
            printf("%d\n",stack.Pop());
        } else if(a==3) {
            printf("%d\n",stack.Size());
        } else if(a==4) {
            if(stack.Size()) printf("0\n");
            else printf("1\n");
        } else {
            printf("%d\n",stack.Top());
        }
    }
}
