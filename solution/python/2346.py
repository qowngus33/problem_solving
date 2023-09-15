import collections
import sys

N = int(input())
numbers = list(map(int,sys.stdin.readline().strip().split()))
d = collections.deque([(i,x+1) for x,i in enumerate(numbers)])

num = d.popleft()
for i in range(N-1):
    r = num[0]+1 if num[0]<0 else num[0]-1
    d.rotate(r*-1)
    print(num[1], end=" ")
    num = d.pop() if num[0] < 0 else d.popleft()

print(num[1], end=" ")
