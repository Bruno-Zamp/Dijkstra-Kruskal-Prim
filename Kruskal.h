/*/ =================================================================

                        Programa: Grafo com Dijkstra, Prim e Kruskal em C++
            Descrição:  Perunta ao usuário um valor e executa o algoritmo de Kruskal
                                            Bruno de Almeida Zampirom
                                                    158788@upf.br

                                        Ciências da Computação - UPF
                                                Copyright (c) 2017

==================================================================== /*/

#include "Prim.h"

//===========================================KRUSKAL EXISTE CAMINHO===========================================
bool Kruskal_ExisteCaminho(Vertice*  ITS, Vertice*  ITR,Vertice*  ITA)
{
    if(ITS==ITR)return true;    // Caso existir caminho
    for(auto ita= ITS->arestas.begin() ; ita != ITS->arestas.end() ; ++ita)
    {
        if(ita->visitado && ita->v !=ITA)       //  Enquanto existir arestas não visitadas
            if(Kruskal_ExisteCaminho(ita->v, ITR,ITS))
                break;
    }
}

//===========================================DIJKSTRA PROCURA===========================================
bool Kruskal_Procura(Grafo &grafo, std::list<Vertice>::iterator & IT, std::list<Aresta>::iterator &FI)
{
    auto menor=INFINITO;
    std::list<Aresta>::iterator ar;
    for(auto ita= IT->arestas.begin() ; ita != IT->arestas.end() ; ++ita) //   percorrendo os vizinhos procurando a aresta com menor peso . . .
    {
        if(!ita->visitado && ita->custo<menor && !ita->v->visitado || !ita->visitado && ita->custo<menor && !Kruskal_ExisteCaminho(ita->v,&*IT,ita->v)) // caso tenha custo menor que o atual e a aresta não foi visitado ainda ou caso não exista caminho entre ita e IT
        {
            ar=ita;
            menor=ita->custo;
        }
    }
    if(menor<INFINITO)  //Caso encontrou algum  . . .
    {
        FI=ar;
        return true;
    }
    return false;
}

//===========================================DIJKSTRA PRÓXIMO===========================================
bool Kruskal_Prox(Grafo &grafo,std::list<Vertice>::iterator &pai, std::list<Vertice>::iterator &filho) //Percorre os Vertices já visitados
{
    auto prox=INFINITO;
    std::list<Aresta>::iterator ar,aresta;
    for(auto it=grafo.vertices.begin() ; it != grafo.vertices.end() ; ++it ) // Percorre entre todos os vertices
    {
        if(Kruskal_Procura(grafo,it,ar))
            if(ar->custo<prox)      // Dentre as todas arestas que sustentam o criterio da função acima escolhe a de menor custo
            {
                prox=ar->custo;
                pai=it;
                aresta=ar;
            }
    }
    if(prox<INFINITO)                               // Caso encontrou algum . . .
    {
        procura_vertice(grafo,aresta->v->rotulo,filho);
        std::list<Aresta>::iterator aresta2;
        procura_aresta(*filho, aresta->rotulo, aresta2);
        aresta2->visitado=aresta->visitado=true;
        return true;
    }
    return false;
}

//===========================================DIJKSTRA INCLUI===========================================
void Kruskal_Inclui(Grafo &grafo)
{
    std::list<Vertice>::iterator PAI;
    std::list<Vertice>::iterator FILHO;
    while(Kruskal_Prox(grafo,PAI,FILHO)) //enquanto ainda conter vertices que sustentam as exigencias acima
    {
        std::cout<<"PAI   : "<<PAI->rotulo<<std::endl;
        std::cout<<"Filho : "<<FILHO->rotulo<<std::endl;
        FILHO->visitado=PAI->visitado=true;
    }
}

//====================================KRUSKAL ESCOLHE AUTOMATICO========================================
std::list<Vertice>::iterator Kruskal_escolheAuto(Grafo &grafo) //Para selecionar a menor aresta
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

//==========================================KRUSKAL PARA ÁRVORE===========================================
bool Kruskal_ParaArvore(Vertice* PAI,Vertice* ANT)
{
    for(auto ita= PAI->arestas.begin() ; ita != PAI->arestas.end() ; ++ita)
        if(ita->visitado && ita->v!= ANT)
        {
            inserirfilho(raiz,ita->v->rotulo,PAI->rotulo);
            Kruskal_ParaArvore(ita->v, PAI);
        }
}

//===========================================KRUSKAL MAIN===========================================
void Kruskal(Grafo &grafo)
{
    std::string sol;
    std::cout<<" Informe o vertice de origem da arvore (ou 'auto'): ";
    std::cin>>sol;
    std::list<Vertice>::iterator it;
    if(sol=="auto")
    {
        it=Kruskal_escolheAuto(grafo);
        goto continua;
    }
    else if(procura_vertice(grafo,sol,it))
    {
continua:
        alocarRaiz(raiz,it->rotulo);            // Inserindo o valor solicitado como raiz
        it->visitado=true;                          // Marcando como visitado
        Kruskal_Inclui(grafo);                  // Função principal do programa
        Kruskal_ParaArvore(&*it,&*it);
        mostra(raiz);
        for(auto it=grafo.vertices.begin() ; it != grafo.vertices.end() ; ++it ) //Resetando arvore e as flags alterado pelo algoritmo. . .
        {
            for(auto ita= it->arestas.begin() ; ita != it->arestas.end() ; ++ita)
                ita->visitado=false;
            it->visitado=false;
            it->dist=INFINITO;
        }
        raiz->info.clear();
        raiz=nullptr;
    }
    else
        std::cout <<"\n *** Erro em Kruskal: valor nao encontrado \n";
}
