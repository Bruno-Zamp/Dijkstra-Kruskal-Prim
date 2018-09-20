/*/ =======================================================================

                                        Programa: Grafo com Dijkstra, Prim e Kruskal em C++
                    Descrição:  Perunta ao usuário dois valor, cria tabela e informa o menor caminho
                                                            Bruno de Almeida Zampirom
                                                                    158788@upf.br

                                                        Ciências da Computação - UPF
                                            Estrura de Dados II - Evandro Luis Viapiana
                                                                Copyright (c) 2017

========================================================================== /*/

#include <iostream>
#include "Grafo.h"

//===========================================DIJKSTRA CAMINHO===========================================
void Dijkstra_Caminho(Grafo &grafo,std::list<Vertice>::iterator IT,std::list<Vertice>::iterator itO)
{
    if(IT->ant!="") //Percorre o caminho inverso de Pesquisa
    {
        std::cout<<IT->ant;
        if(IT->ant!=itO->rotulo)
            std::cout<<", ";
        std::list<Vertice>::iterator aux;
        procura_vertice(grafo,IT->ant,aux);
        Dijkstra_Caminho(grafo,aux,itO);
    }
}

//===========================================DIJKSTRA MOSTRA===========================================
void Dijkstra_Mostra(Grafo &grafo,std::list<Vertice>::iterator itO)
{
    for(auto it=grafo.vertices.begin() ; it != grafo.vertices.end() ; ++it )
    {
        if(it->dist==INFINITO || it==itO)      //Caso não exista caminho para este valor
            std::cout  <<"  "<< it->rotulo <<" :**\n";
        else
        {
            std::cout  <<"  "<< it->rotulo <<" :"<<it->dist;
            if(it->dist<10)
                std::cout<<" ";
            std::cout<<"  {";
            Dijkstra_Caminho(grafo,it,itO);
            std::cout<<"}"<<std::endl;
        }
    }
}

//===========================================DIJKSTRA DISTÂNCIA===========================================
void Dijkstra_Distancia(Grafo &grafo, std::list<Vertice>::iterator &ITA, std::list<Vertice>::iterator &ITP, std::list<Aresta>::iterator &AR)
{
    if(ITP->dist > ITA->dist + AR->custo) //Caso o custo com o anterior seja menor que o atual. . .
    {
        ITP->dist= ITA->dist + AR->custo; //distância do vertice anterior + o custo da aresta
        ITP->ant=  ITA->rotulo;
    }
}

//===========================================DIJKSTRA VIZINHOS===========================================
void Dijkstra_Vizinhos(Grafo &grafo, std::list<Vertice>::iterator IT)
{
    std::list<Vertice>::iterator itPROX;     //para saber em qual vertice seguir após este
    double maior=INFINITO;
    IT->visitado=true;                        //marca como visitado
    for(auto ita= IT->arestas.begin() ; ita != IT->arestas.end() ; ++ita) //   percorrendo os vizinhos . . .
    {
        std::list<Vertice>::iterator ITP;
        procura_vertice(grafo, ita->v->rotulo,ITP);  //procurando vertice do vizinho
        Dijkstra_Distancia(grafo, IT, ITP, ita);
    }
    for(auto it=grafo.vertices.begin() ; it != grafo.vertices.end() ; ++it ) //proximo vértice a ser pesquisado
        if(!it->visitado && it->dist<maior) // Procura entre os ainda não visitados o de menor custo
        {
            itPROX=it;
            maior=itPROX->dist;
        }
    if(maior < INFINITO )Dijkstra_Vizinhos(grafo,itPROX); //caso ainda tenha algum não pesquisado
}

//===========================================MAIN DO DIJKTRA===========================================

int Dijkstra(Grafo &grafo)
{
    std::list<Vertice>::iterator itO,itD;
    std::string origem, destino;
    std::cout<<" Informe o vertice de origem e o de destino: ";
    std::cin>>origem>>destino;
    if( !procura_vertice( grafo, origem, itO ) ||  !procura_vertice( grafo, destino, itD ))
    {
        std::cout <<"\n *** Erro em Dijkstra: vertice nao encontrado \n";
        return false;
    }
    itO->visitado=true; //inicializando o vertice de origem . . .
    itO->dist=0;
    Dijkstra_Vizinhos(grafo, itO);  //criando tabela
    Dijkstra_Mostra(grafo,itO);             //mostrando a tabela;
    if(itD->dist<INFINITO)
        std::cout<<"  Melhor caminho entre "<<itO->rotulo<<" e "<<itD->rotulo<<": "<<itD->dist<<std::endl;
    else
        std::cout<<"  Nao existe caminho entre "<<itO->rotulo<<" e "<<itD->rotulo<<std::endl;
    for(auto it=grafo.vertices.begin() ; it != grafo.vertices.end() ; ++it ) //Resetando o grafo
    {
        it->visitado=false;
        it->dist=INFINITO;
        it->ant="";
    }
}
