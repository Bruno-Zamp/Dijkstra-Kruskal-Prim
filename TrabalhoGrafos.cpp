/*/ =================================================================

                        Programa: Grafo com Dijkstra, Prim e Kruskal em C++
            Descri��o: Main do programa, chama a fun��o selecionada pelo usu�rio
                                            Bruno de Almeida Zampirom
                                                    158788@upf.br

                                        Ci�ncias da Computa��o - UPF
                                                Copyright (c) 2017

==================================================================== /*/

#include "Kruskal.h"

using namespace std;

//==============================================================================
int main()
{
    cout<<" Bruno de Almeida Zampirom\n Email : 158788@upf.br \n";
    while(1)
    {
        cout<<"\n L - Leitura "<<endl;
        cout<<" D - Dijkstra"<<endl;
        cout<<" P - Prim"<<endl;
        cout<<" K - Kruskal"<<endl;
        cout<<" F - Fim"<<endl;
        cout<<" ";
        char a;
        cin>>a;
        switch(a)
        {
        case 'L':
            leitura(grafo);
            break;
        case 'D':
            if(grafo.vertices.size()>0)Dijkstra(grafo);
            break;
        case 'P':
            if(grafo.vertices.size()>0)Prim(grafo);
            break;
        case 'K':
            if(grafo.vertices.size()>0)Kruskal(grafo);
            break;
        case 'F':
            return 0;
        }
    }
}
