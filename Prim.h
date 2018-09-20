/*/ =================================================================

                        Programa: Grafo com Dijkstra, Prim e Kruskal em C++
            Descrição:  Perunta ao usuário um valor e executa o algoritmo de Prim
                                            Bruno de Almeida Zampirom
                                                    158788@upf.br

                                        Ciências da Computação - UPF
                                                Copyright (c) 2017

==================================================================== /*/

#include "Arvore_geradora_mínima.h"
#include "Dijkstra.h"

//===========================================PRIM PROCURA===========================================
bool Prim_procura(Grafo &grafo, std::list<Vertice>::iterator & IT, std::list<Aresta>::iterator &FI)
{
    auto menor=INFINITO;
    std::list<Aresta>::iterator ar;
    for(auto ita= IT->arestas.begin() ; ita != IT->arestas.end() ; ++ita)        // Percorrendo os vizinhos procurando a aresta com menor peso . . .
    {
        if(ita->custo<menor && !ita->v->visitado)                                         // Caso tenha custo menor que o atual e a aresta não foi visitado ainda
        {
            ar=ita;
            menor=ita->custo;
        }
    }
    if(menor<INFINITO)                                                                              // Caso encontrou algum . . .
    {
        FI=ar;
        return true;
    }
    return false;
}

//===========================================PRIM PRÓXIMO===========================================
bool Prim_Prox(Grafo &grafo,std::list<Vertice>::iterator &pai, std::list<Vertice>::iterator &filho) //Percorre os Vertices já visitados
{
    auto prox=INFINITO;
    std::list<Aresta>::iterator ar,aresta;
    for(auto it=grafo.vertices.begin() ; it != grafo.vertices.end() ; ++it )
    {
        if(it->visitado)                            // Percorre os vertices ja visitados
            if(Prim_procura(grafo,it,ar))   // Caso algum sutente a exigência da função
                if(ar->custo<prox)              // Procura entre estas a de menor custo
                {
                    prox=ar->custo;
                    pai=it;
                    aresta=ar;
                }
    }
    if(prox<INFINITO)                           // Caso encontrou algum . . .
    {
        procura_vertice(grafo,aresta->v->rotulo,filho);
        return true;
    }
    return false;
}

//===========================================PRIM INCLUI===========================================
void Prim_Inclui(Grafo &grafo)
{
    std::list<Vertice>::iterator PAI;
    std::list<Vertice>::iterator FILHO;
    while(Prim_Prox(grafo,PAI,FILHO)) //enquanto ainda conter vertices que sustentam as exigencias acima
    {
        inserirfilho(raiz,FILHO->rotulo,PAI->rotulo);  //Inclui o vertice na arvore
        FILHO->visitado=PAI->visitado=true;
    }
}

//=====================================PRIM ESCOLHE AUTOMATICO======================================
std::list<Vertice>::iterator Prim_escolheAuto(Grafo &grafo) //Para selecionar a menor aresta
{
    std::list<Vertice>::iterator it;
    std::list<Aresta>::iterator ar;
    auto prox=INFINITO;
    for(auto aut=grafo.vertices.begin() ; aut != grafo.vertices.end() ; ++aut)
    {
        if(Prim_procura(grafo,aut,ar))
            if(ar->custo<prox)
            {
                prox=ar->custo;
                it=aut;
            }
    }
    return it;
}

//===========================================PRIM MAIN===========================================
void Prim(Grafo &grafo)
{
    std::string sol;
    std::cout<<" Informe o vertice de origem da arvore (ou 'auto'): ";
    std::cin>>sol;
    std::list<Vertice>::iterator it;
    if(sol=="auto")
    {
        it=Prim_escolheAuto(grafo);
        goto continua;
    }
    else if(procura_vertice(grafo,sol,it))
    {
        continua:
        alocarRaiz(raiz,it->rotulo);            //inserindo o valor solicitado como raiz
        it->visitado=true;                          //marcando como visitado
        Prim_Inclui(grafo);
        mostra(raiz);
        for(auto it=grafo.vertices.begin() ; it != grafo.vertices.end() ; ++it ) //Resetando arvore e os flags alterado pelo algoritmo . . .
        {
            it->visitado=false;
            it->dist=INFINITO;
        }
        raiz->info.clear();
        raiz=nullptr;
    }
    else
        std::cout <<"\n *** Erro em Prim: vertice nao encontrado \n";
}
