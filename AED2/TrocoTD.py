#GABRIEL DE OLIVEIRA VALENTE ALGORITMO TROCO TOP-DOWN

def troco(x):
    if x==0:
        return 0
    if(b[x-1]!=-1):
        return b[x-1]
    
    b[x-1] = 10**10
    for i in (vet):
        if i>x:
            continue
        else:
            b[x-1] = min(b[x-1],1+troco(x-i))
                    
    return b[x-1]


vet = [50,25,10,5,1]
a = int(input("Digite o troco que deseja saber o minimo de moedas a ser dado: "))
b = [-1]*a

minimo = troco(a)
print("O minimo de moedas para o troco e de:",minimo,"moeda(s)")
