def arranjo(np):
    for i in range(0,n):
        p[np-1] = i+1
        if np == q:
            print(p)
        else:
            arranjo(np+1)
n = 5
q = 3
p = [-1]*(q)
arranjo(1)
