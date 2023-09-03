def imprime(g,n):
    for i in range(0,n):
        print("[{}]".format(i), end = " ")
        for j in range(0,n):
            print(g[i][j], end = " ")
        print()
        
def contagem(num):
    a = num
    if a==1:
        return 1
    else:
        a = a + contagem(a-1)
        return a

def geragrafo(n,m):
    g = []
    count = contagem(n-1)
    counta = m
    nomegrafos.append(input("Digite o nome do grafico: "))
    for c in range(0,n):
        l = []
        for j in range(0,n):
            l.append(0)
        g.append(l)
        
    if m!=0:
        for c in range(0,n):
            for j in range(c,n):
                if c!=j:
                    if counta == 0:
                        g[c][j] = 0
                        g[j][c] = 0
                    elif count-counta<=0:
                        g[c][j] = 1
                        g[j][c] = 1
                    else:
                        g[c][j] = int(input("Digite 1 se existe aresta entre os vertices {} e {}, 0 se nao: ".format(c,j)))
                        if g[c][j] == 1:
                            counta = counta-1
                        g[j][c] = g[c][j]
                        count = count-1    
    grafos.append(g)
    imprime(g,n)

def completo(n):
    g = []
    nomegrafos.append(input("Digite o nome do grafico: "))
    for i in range(0,n):
        l = []
        for j in range(0,n):
            if i==j:
                l.append(0)
            else:
                l.append(1)
        g.append(l)
    grafos.append(g)
    imprime(g,n)

def bipartido(n1,n2):
    n = n1+n2
    g = []
    nomegrafos.append(input("Digite o nome do grafico: "))
    for i in range(0,n):
        l = []
        for j in range(0,n):
            if i==j or i>n1:
                l.append(0)
            else:
                l.append(1)
        g.append(l)
    grafos.append(g)
    imprime(g,n)

def caminho(n):
    g = []
    nomegrafos.append(input("Digite o nome do grafico: "))
    for i in range(0,n):
        l = []
        for j in range(0,n):
            if i==j or j!=i+1:
                l.append(0)
            else:
                l.append(1)
        g.append(l)
    grafos.append(g)
    imprime(g,n)
    
def ciclo(n):
    g = []
    nomegrafos.append(input("Digite o nome do grafico: "))
    for i in range(0,n):
        l = []
        for j in range(0,n):
            if (j==i+1 or (i==n-1 and j==0)) and i!=j:
                l.append(1)
            else:
                l.append(0)
        g.append(l)
        
    grafos.append(g)
    imprime(g,n)

def roda(n):
    g = []
    nomegrafos.append(input("Digite o nome do grafico: "))
    for i in range(0,n+1):
        l = []
        for j in range(0,n+1):
            if (j==i+1 or (i==n-1 and j==0) or i== n) and i!=j:
                l.append(1)
            else:
                l.append(0)
        g.append(l)
        
    grafos.append(g)
    imprime(g,n+1)

def cubo(n):
    g = []
    nomegrafos.append(input("Digite o nome do grafico: "))
    for i in range(0,(2**n)):
        l = []
        for j in range(0,2**n):
            l.append(0)
        g.append(l)
        
    for c in range(0,2**n):
        aux = []
        for i in range(0,n+1):
            if i==0 and c%2!=0:
                continue
            else:
                if 2**i+c<=7:
                    aux.append((2**i)+c)
        for j in aux:
            g[c][j] = 1
            g[j][c] = 1
    """   posicao = (2**j)-1
                g[c][c+posicao] = 1
                g[c+posicao][c] = 1""" 
    grafos.append(g)
    imprime(g,2**n)
    
    

#PROGRAMA PRINCIPAL COMECA AQUI

grafos = []
nomegrafos = []
opcao = " "
while (opcao != 'd'):

    opcao = input("""
    Qual opcao deseja

    a) Inserir um grafo

    b) Consultar os grafos

    c) Produzir um grafo de classe especial

    d) Sair

    Digite a opcao(a/b/c): """)
    

    if opcao == 'a':
        vertices = int(input("Quantos vertices tem o grafo?: "))
        
        while(vertices<=0):
            print("ERROR: insira um grafo com numero de vertices positivos")
            vertices = int(input("Quantos vertices tem o grafo?: "))
                  
        arestas = int(input("Quantas arestas tem o grafo?: "))

        while(arestas > (vertices*(vertices-1))/2):
            print("ERROR: O numero de arestas e maior que o permitido: ")
            arestas = int(input("Quantas arestas tem o grafo?: "))
            
        geragrafo(vertices,arestas)
            
    elif opcao == 'b':
        if len(grafos)==0:
            print("ERROR: nao tem nenhum grafo registrado")
            opcao = " "
        else:
            nomeg = input("Qual grafo deseja consultar?: ")
            if nomeg not in nomegrafos:
                print("ERROR: grafo nao encontrado")
            else:
                for i in range(0,len(nomegrafos)):
                    if nomeg == nomegrafos[i]:
                        posicao = i
                imprime(grafos[posicao],len(grafos[posicao]))

    elif opcao == 'c':
        esp = int(input("""
        Qual o grafo especial deseja?

        1 - Grafo Completo

        2 - Bipardido Completo

        3 - Estrela

        4 - Caminho

        5 - Ciclo

        6 - Roda

        7 - Cubo

        Digite o numero da opcao desejada: """))

        if esp == 1:
            n = int(input("Quantos vertices tem o grafo? "))
            completo(n)
            
        elif esp == 2:
            n1 = int(input("Quantos vertices tem o primeiro grupo do grafo? "))
            n2 = int(input("Quantos vertices tem o segundo grupo do grafo? "))
            bipartido(n1,n2)

        elif esp == 3:
            n2 = int(input("Quantos vertices tem a do grafo, sem contar com o centro? "))
            bipartido(1,n2)

        elif esp == 4:
            n = int(input("Quantos vertices tem o grafo? "))
            caminho(n)

        elif esp == 5:
            n = int(input("Quantos vertices tem o grafo? "))
            while(n<=3):
                print("ERROR: insira um numero de vertices maior ou igual a 3")
                n = int(input("Quantos vertices tem o grafo?: "))
            ciclo(n)

        elif esp == 6:
            n = int(input("Quantos vertices tem o grafo, sem contar com o centro? "))
            while(n<=3):
                print("ERROR: insira um numero de vertices maior ou igual a 3")
                n = int(input("Quantos vertices tem o grafo?: "))
            roda(n)
            
        elif esp == 7:
            n = int(input("Qual a ordem de grandeza do grafo?(digite n para 2^n)? "))
            while(n<0):
                print("ERROR: insira um numero de vertices maior ou igual a 3")
                n = int(input("Quantos vertices tem o grafo?: "))
            cubo(n)
            

            
            
    
        
        

