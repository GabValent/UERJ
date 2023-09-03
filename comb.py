def comb(np,t):
    for i in range(t,n):
        p[np-1] = i+1
    
        print(p)
        
        comb(np+1,i+1)
n = 4
q = 4
p = [-1]*q
comb(1,0)
