N = input()
num_list = list(map(int,input().split()))

stack = []
number = 1
ans = "Nice\n"
for num in num_list:
    if num == number:
        number += 1
    else:
        while len(stack)!=0 and stack[-1]==number:
            number = stack.pop() + 1
        if (len(stack)!=0 and num<stack[-1]) or len(stack)==0:
            stack.append(num)
        else:
            ans = "Sad\n"
            break
print(ans)



