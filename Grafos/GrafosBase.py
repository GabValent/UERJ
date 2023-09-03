def geragrafo(n,m):
    g = []
    nomegrafos.append(input("Digite o nome do grafico: "))
    for c in range(0,n):
        l = []
        for j in range(0,n):
            l.append(0)
        g.append(l)
    for c in range(0,n):
        for j in range(c,n):
            if c==j:
                g[c][j] = 0
            else:
                g[c][j] = int(input("Digite 1 se existe aresta entre os vertices {} e {}, 0 se nao: ".format(c,j)))
                g[j][c] = g[c][j]
        
        
    grafos.append(g)
    for i in range(0,n):
        for j in range(0,n):
            print(g[i][j], end = " ")
        print()

grafos = []
nomegrafos = []
opcao = " "
while (opcao != 'c'):

    opcao = input(""" Qual opcao deseja

    a) Inserir um grafo

    b) Consultar os grafos

    c) Sair

    Digite a opcao(a/b/c): """)
    

    if opcao == 'a':
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
                g = grafos[i]
                for i in range(0,vertices):
                    for j in range(0,vertices):
                        print(g[i][j], end = " ")
                    print()
        
        

