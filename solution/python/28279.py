d=[0for _ in range(1000000)]
s,e=0,0
p=print
for c in [*open(0)][1:]:
    a,*b=map(int,c.split())
    l=e-s
    if a==1:d[s:=s-1]=b[0]
    elif a==2:d[(e:=e+1)-1]=b[0]
    elif a==3:p(d[(s:=s+1)-1]if l else -1)
    elif a==4:p(d[e:=e-1]if l else -1)
    elif a==5:p(l)
    elif a==6:p(0if l else 1)
    elif a==7:p(d[s]if l else -1)
    else:p(d[e-1]if l else -1)