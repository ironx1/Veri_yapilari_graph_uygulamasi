#include <iostream>
#include <string>
using namespace std;

class Graph
{
private:
    struct node//bagli liste yapimiz
    {
        string sehir;
        node *next;
    };
    struct graph//vertex sayisi ve node* turunde diziden olusan struct imiz.
    {
        int numVertices;
        node **adjList;
    };
    graph *grp = nullptr;
    node *createNode(string cityName)
    {
        node *n = new node;
        n->sehir = cityName;
        n->next = nullptr;
        return n;
    }

public:
    Graph(int numVer)//vertex sayisi aliniyor
    {
        grp = new graph;
        grp->numVertices = numVer;
        grp->adjList = new node *[numVer];//numVer kadar node* turunde yer ayriliyor.
        for (int i = 0; i < numVer; ++i)
        {
            grp->adjList[i] = nullptr;//her eleman teker teker null degerini aliyor
        }
    }
    void addEdge(string firstCity, string secCity)
    {
        if (grp == nullptr)
        {
            return;
        }
        for (int i = 0; i < grp->numVertices; ++i)
        {
            if (grp->adjList[i] == nullptr)//node* turundeki dizimizde bosluk ariyoruz
            {
                grp->adjList[i] = createNode(firstCity);//bulunan ilk boslukta sehrimizi yerlestiriyoruz
                grp->adjList[i]->next = createNode(secCity);
                break;
            }
            else if (grp->adjList[i]->sehir == firstCity)
            {
                node *iter = grp->adjList[i];
                while (iter->next != nullptr)
                {
                    iter = iter->next;
                }
                iter->next = createNode(secCity);//eger bosluk yoksa ve veriler eslesiyor ise.
                break;
            }
        }
        for (int i = 0; i < grp->numVertices; ++i)//yukaridaki islemin tam tersi(undirected graph)
        {
            if (grp->adjList[i] == nullptr)
            {
                grp->adjList[i] = createNode(secCity);
                grp->adjList[i]->next = createNode(firstCity);
                break;
            }
            else if (grp->adjList[i]->sehir == secCity)
            {
                node *iter = grp->adjList[i];
                while (iter->next != nullptr)
                {
                    iter = iter->next;
                }
                iter->next = createNode(firstCity);
                break;
            }
        }
    }
    void printGraph()
    {
        if (grp == nullptr)
        {
            return;
        }
        for (int i = 0; i < grp->numVertices; ++i)
        {
            if (grp->adjList[i] != nullptr)
            {
                cout << grp->adjList[i]->sehir << ": ";
                node *iter = grp->adjList[i]->next;
                while (iter != nullptr)
                {
                    cout << iter->sehir << " ";
                    iter = iter->next;
                }
                cout << endl;
            }
        }
    }
};

int main()
{
    //Komsu Ulkeler
    Graph myGraph(10);
    myGraph.addEdge("Turkiye","Bulgaristan");
    myGraph.addEdge("Turkiye","Yunanistan");
    myGraph.addEdge("Turkiye","Suriye");
    myGraph.addEdge("Turkiye","Irak");
    myGraph.addEdge("Turkiye","Iran");
    myGraph.addEdge("Turkiye","Ermenistan");
    myGraph.addEdge("Turkiye","Gurcistan");
    myGraph.addEdge("Bulgaristan","Yunanistan");
    myGraph.addEdge("Bulgaristan","Romanya");
    myGraph.addEdge("Bulgaristan","Sirbistan");
    myGraph.printGraph();
}