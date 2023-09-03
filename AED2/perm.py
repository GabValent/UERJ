def permci(np):
    for i in range(0,n-1):
        if not s[i]:
            p[np-1] = i+1
            s[i] = True
            if np == n-1:
                print(p)
            else:
                permci(np+1)
            s[i] = False
n = 10
s = [False]*n
p = [-1]*n
p[n-1] = n
permci(1)
