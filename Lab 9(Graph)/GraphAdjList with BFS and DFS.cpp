#include<stdio.h>
#include<stdlib.h>
#define NULL_VALUE -999999
#define INFINITY 999999
#define WHITE 1
#define GREY 2
#define BLACK 3

class Queue
{
    int queueInitSize ;
    int queueMaxSize;
    int * data;
    int length;
    int front;
    int rear;
public:
    Queue();
    ~Queue();
    void enqueue(int item); //insert item in the queue
    int dequeue(); //returns the item according to FIFO
    bool empty(); //return true if Queue is empty
};

Queue::Queue()
{
    queueInitSize = 2 ;
    queueMaxSize = queueInitSize;
    data = new int[queueMaxSize] ; //allocate initial memory
    length = 0 ;
    front = 0;
    rear = 0;
}


void Queue::enqueue(int item)
{
	if (length == queueMaxSize)
	{
		int * tempData ;
		//allocate new memory space for tempList
		queueMaxSize = 2 * queueMaxSize ;
		tempData = new int[queueMaxSize] ;
		int i, j;
		j = 0;
		for( i = rear; i < length ; i++ )
		{
			tempData[j++] = data[i] ; //copy items from rear
		}
		for( i = 0; i < rear ; i++ )
		{
			tempData[j++] = data[i] ; //copy items before rear
		}
		rear = 0 ;
		front = length ;
		delete[] data ; //free the memory allocated before
		data = tempData ; //make list to point to new memory
	}

	data[front] = item ; //store new item
	front = (front + 1) % queueMaxSize ;
	length++ ;
}


bool Queue::empty()
{
	if(length == 0) return true ;
	else return false ;
}


int Queue::dequeue()
{
	if(length == 0) return NULL_VALUE ;
	int item = data[rear] ;
	rear = (rear + 1) % queueMaxSize ;
	length-- ;
	return item ;
}


Queue::~Queue()
{
    if(data) delete[] data; //deallocate memory
    data = 0; //set to NULL
}

//****************Queue class ends here************************

//****************Dynamic ArrayList class based************************
class ArrayList
{
    int * list;
    int length ;
    int listMaxSize ;
    int listInitSize ;
public:
    ArrayList() ;
    ~ArrayList() ;
    int searchItem(int item) ;
    void insertItem(int item) ;
    void removeItem(int item) ;
    void removeItemAt(int item);
    int getItem(int position) ;
    int getLength();
    bool empty();
    void printList();
} ;


ArrayList::ArrayList()
{
    listInitSize = 2 ;
    listMaxSize = listInitSize ;
    list = new int[listMaxSize] ;
    length = 0 ;
}

void ArrayList::insertItem(int newitem)
{
    int * tempList ;
    if (length == listMaxSize)
    {
        //allocate new memory space for tempList
        listMaxSize = 2 * listMaxSize ;
        tempList = new int[listMaxSize] ;
        int i;
        for( i = 0; i < length ; i++ )
        {
            tempList[i] = list[i] ; //copy all items from list to tempList
        }
        delete[] list ; //free the memory allocated before
        list = tempList ; //make list to point to new memory
    };

    list[length] = newitem ; //store new item
    length++ ;
}

int ArrayList::searchItem(int item)
{
    int i = 0;
    for (i = 0; i < length; i++)
    {
        if( list[i] == item ) return i;
    }
    return NULL_VALUE;
}

void ArrayList::removeItemAt(int position) //do not preserve order of items
{
    if ( position < 0 || position >= length ) return ; //nothing to remove
    list[position] = list[length-1] ;
    length-- ;
}


void ArrayList::removeItem(int item)
{
    int position;
    position = searchItem(item) ;
    if ( position == NULL_VALUE ) return ; //nothing to remove
    removeItemAt(position) ;
}


int ArrayList::getItem(int position)
{
    if(position < 0 || position >= length) return NULL_VALUE ;
    return list[position] ;
}

int ArrayList::getLength()
{
    return length ;
}

bool ArrayList::empty()
{
    if(length==0)return true;
    else return false;
}

void ArrayList::printList()
{
    int i;
    for(i=0; i<length; i++)
        printf("%d ", list[i]);
    printf("Current size: %d, current length: %d\n", listMaxSize, length);
}

ArrayList::~ArrayList()
{
    if(list) delete [] list;
    list = 0 ;
}

//******************ArrayList class ends here*************************

//******************Graph class starts here**************************
class Graph
{
    Queue Qbfs;
    int nVertices, nEdges ;
    bool directed ;
    ArrayList  * adjList ;
    int *color;
    int *parent;
    int *dist;
    int *hasVisited;
    //define other variables required for bfs such as color, parent, and dist
    //you must use pointers and dynamic allocation

public:
    Graph(bool dir = false);
    ~Graph();
    void setnVertices(int n);
    void addEdge(int u, int v);
    void removeEdge(int u, int v);
    bool isEdge(int u, int v);
    int getDegree(int u);
    void printAdjVertices(int u);
    bool hasCommonAdjacent(int u, int v);
    void printGraph();

    void bfs(int source);
    int getDist(int u,int v);
    int findComponents();
    void dfsVisit(int u);
    void dfs(int source);
};


Graph::Graph(bool dir)
{
    nVertices = 0 ;
    nEdges = 0 ;
    adjList = 0 ;
    directed = dir ; //set direction of the graph
    //define other variables to be initialized
}

void Graph::setnVertices(int n)
{
    this->nVertices = n ;
    if(adjList!=0) delete[] adjList ; //delete previous list
    adjList = new ArrayList[nVertices] ;
    color = new int[nVertices];
    dist = new int[nVertices];
    parent = new int[nVertices];
}

void Graph::addEdge(int u, int v)
{
    if(u<0 || v<0 || u>=nVertices || v>=nVertices) return; //vertex out of range
    this->nEdges++ ;
    adjList[u].insertItem(v) ;
    if(!directed) adjList[v].insertItem(u) ;
}

void Graph::removeEdge(int u, int v)
{
    //removed the edge between u and v if such edge exists
    if(u<0||v<0||u>=nVertices||v>=nVertices)
        return;
    this->nEdges-- ;
    adjList[u].removeItem(v) ;
    if(!directed)
        adjList[v].removeItem(u) ;
}

bool Graph::isEdge(int u, int v)
{
    //returns true if (u,v) is an edge, otherwise should return false
    if(u<0||v<0||u>=nVertices||v>=nVertices)
        return false;
    if( adjList[u].searchItem(v)==NULL_VALUE)
        return false;
    else
        return true;

}

int Graph::getDegree(int u)
{
    //returns the degree of vertex u
    if(u<0||u>=nVertices)
        return NULL_VALUE;
    return
        adjList[u].getLength();
}

void Graph::printAdjVertices(int u)
{
    //prints all adjacent vertices of a vertex u
    if(u<0||u>=nVertices)
        return;
    for(int i=0; i<adjList[u].getLength(); i++)
    {
        printf("%d ",adjList[u].getItem(i));
    }
    printf("\n");
}

bool Graph::hasCommonAdjacent(int u, int v)
{

    //returns true if vertices u and v have common adjacent vertices
    if(u<0||v<0||u>=nVertices||v>=nVertices)
        return false;

    for(int i=0; i<adjList[u].getLength(); i++)
    {
        for(int j=0; j<adjList[v].getLength(); j++)
        {
            if(adjList[u].getItem(i)==adjList[v].getItem(j))
            {
                return true;
            }
        }

    }
    return false;
}


void Graph::printGraph()
{
    printf("\nNumber of vertices: %d, Number of edges: %d\n", nVertices, nEdges);
    for(int i=0; i<nVertices; i++)
    {
        printf("%d:", i);
        for(int j=0; j<adjList[i].getLength(); j++)
        {
            printf(" %d", adjList[i].getItem(j));
        }
        printf("\n");
    }
}

void Graph::bfs(int source)
{
    for(int i=0; i<nVertices; i++)
    {
        color[i]=WHITE;
        dist[i]=INFINITY;
        parent[i]=NULL_VALUE;
    }
    color[source]=GREY;
    dist[source]=0;
    parent[source]=NULL_VALUE;
    Qbfs.enqueue(source);
    printf("BFS traversal: ");
    while(!Qbfs.empty())
    {
        int u=Qbfs.dequeue();
        printf(" %d",u);
        for(int i=0; i<adjList[u].getLength(); i++)
        {
            int v=adjList[u].getItem(i);
            if(v!=NULL_VALUE && color[v]==WHITE)
            {
                color[v]=GREY;
                dist[v]=dist[u]+1;
                parent[v]=u;
                Qbfs.enqueue(v);
            }
        }
        color[u]=BLACK;
    }
    printf("\n");
}

int Graph::getDist(int u,int v)
{
    bfs(u);
    return dist[v];
}

int Graph::findComponents()
{
    int c=0;
    bfs(0);
    c++;
    for(int i=0; i<nVertices; i++)
    {
        if(color[i]==WHITE)
        {
            bfs(i);
            c++;
        }
    }
    return c;
}

void Graph::dfsVisit(int u)
{
    color[u]=GREY;
    for(int i=0; i<adjList[u].getLength(); i++)
    {
        int v=adjList[u].getItem(i);
        //printf(" %d",v);
        if(v!=NULL_VALUE && color[v]==WHITE)
        {
                dfsVisit(v);
        }
    }
    color[u]=BLACK;
}

void Graph::dfs(int source)
{
    for(int i=0; i<nVertices; i++)
    {
        color[i]=WHITE;
    }
    //printf("DFS traversal: \n");
    for(int i=0; i<nVertices; i++)
    {
        if(color[i]==WHITE)
        {
            dfsVisit(i);

        }
    }
}

Graph::~Graph()
{
    delete[] adjList;
    delete[] color;
    delete[] dist;
    delete[] parent;
    //write your destructor here
}

//**********************Graph class ends here******************************


//******main function to test your code*************************
int main(void)
{
    int n;
    Graph g;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    g.setnVertices(n);

    while(1)
    {
        printf("1. Add edge. 2. Remove Edge 3.Check Edge\n");
        printf("4.Get Degree 5.Print Adjacent Vertices 6.Check Common Adjacent\n");
        printf("7. Print Graph 8.Breadth-First Search(BFS)  9.Get Distance 10.Find Components 11.Depth-First Search(DFS) 12. Exit.\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            g.addEdge(u, v);
        }
        else if(ch==2)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            g.removeEdge(u,v);
        }
        else if(ch==3)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            if(g.isEdge(u,v)) printf("It's an Edge");
            else printf("Not an edge");
        }
        else if(ch==4)
        {
            int u;
            scanf("%d",&u);
            int degree = g.getDegree(u);
            printf("%d\n",degree);
        }
        else if(ch==5)
        {
            int u;
            scanf("%d",&u);
            g.printAdjVertices(u);
        }
        else if(ch==6)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            if(g.hasCommonAdjacent(u,v)) printf("They have common adjacent\n");
            else printf("They don't have common adjacent");
        }
        else if(ch==7)
        {
            g.printGraph();
        }
        else if(ch==8)
        {
            int s;
            scanf("%d",&s);
            g.bfs(s);
            printf("\n");
        }
        else if(ch==9)
        {
            int u,v;
            scanf("%d%d", &u, &v);
            printf("%d\n",g.getDist(u,v));
        }
        else if(ch==10)
        {
            printf("Components: %d\n",g.findComponents());
        }
        else if(ch==11)
        {
            int s;
            scanf("%d",&s);
            g.dfs(s);
            printf("\n");
        }
        else if(ch==12)
        {
            break;
        }
    }

}
