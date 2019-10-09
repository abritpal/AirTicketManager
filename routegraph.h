struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

struct adjlistnode
{
    int cost;
    int flnum;
    int neighbour;
    struct adjlistnode *next;
};

struct adjlist
{
    struct adjlistnode *head;
};

typedef struct adjlist AdjList;

struct graph
{
    int vertex;
    int *visited;
    AdjList *arr;
};

typedef struct graph Node;

struct adjlistnode *newAdjListNode(int dest, int fare, int flnum)
{
    struct adjlistnode *newNode = (struct adjlistnode *)malloc(sizeof(struct adjlistnode));
    newNode->neighbour = dest;
    newNode->cost = fare;
    newNode->flnum = flnum;
    newNode->next = NULL;
    return newNode;
}

Node *createGraph(int V)
{
    Node *graph = (Node *)malloc(sizeof(Node));
    graph->vertex = V;
    graph->arr = (struct adjlist *)malloc(V * sizeof(struct adjlist));
    graph->visited = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; ++i)
    {
        graph->arr[i].head = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(Node *graph, int src, int dest, int cost, int flnum)
{

    struct adjlistnode *newNode = newAdjListNode(dest, cost, flnum);
    newNode->next = graph->arr[src].head;
    graph->arr[src].head = newNode;
}

void printGraph(Node *graph)
{
    char *city[5] = {"MAA", "DEL", "BOM", "BLR", "CCU"};
    int v;
    for (v = 0; v < graph->vertex; v++)
    {
        struct adjlistnode *temp = graph->arr[v].head;
        printf("\nFlights   from   %s\n", city[v]);
        while (temp)
        {
            printf("to ->  %s and  fare  %d   flight no   %d\n", city[temp->neighbour], temp->cost, temp->flnum);
            temp = temp->next;
        }
        printf("\n");
    }
}

// void DFS(Node *graph, int ind)
// {
//     graph->visited[ind] = 1;
//     struct adjlistnode *temp = graph->arr[ind].head;
//     printf("-> %d", ind);
//     while (temp)
//     {
//         if (graph->visited[temp->neighbour] == 0)
//             DFS(graph, temp->neighbour);
//         temp = temp->next;
//     }
// }

// void BFS(Node *graph, int ind)
// {
//     graph->visited[ind] = 1;
//     struct adjlistnode *temp;
//     enqueue(ind);
//     while (!isEmpty())
//     {
//         ind = getFront();
//         printf("-> %d", ind);
//         dequeue();
//         temp = graph->arr[ind].head;
//         while (temp != NULL)
//         {
//             if (graph->visited[temp->neighbour] == 0)
//             {
//                 graph->visited[temp->neighbour] = 1;
//                 enqueue(temp->neighbour);
//             }
//             temp = temp->next;
//         }
//     }
// }

int checkcon(Node *g, int src, int dest)
{
    struct adjlistnode *tr = g->arr[src].head;

    while (tr != NULL)
    {
        if (tr->neighbour == dest)
            return 1;
        tr = tr->next;
    }
    return 0;
}
int findRoute(Node *g, int src, int dest)
{
    struct adjlistnode *city1 = g->arr[src].head;
    int *arr1;
    arr1 = (int *)malloc(sizeof(int));
    struct adjlistnode *city2 = g->arr[dest].head;
    int *arr2;
    arr2 = (int *)malloc(sizeof(int));
    int i = 0;
    while (city1 != NULL)
    {
        arr1[i] = city1->neighbour;
        city1 = city1->next;
        i++;
    }

    printf("\n");
    int j = 0;
    while (city2 != NULL)
    {
        arr2[j] = city2->neighbour;
        city2 = city2->next;
        j++;
    }

    printf("\n");

    for (int k = 0; k < i; k++)
    {
        for (int l = 0; l < j; l++)
        {
            if (arr1[k] == arr2[l])
                return arr1[k];
        }
    }
}

int fare(Node *g, int src, int dest)
{
    int flightFare = 0;
    if (checkcon(g, src, dest))
    {
        struct adjlistnode *temp = g->arr[src].head;
        while (temp != NULL)
        {
            if (temp->neighbour == dest)           
                return temp->cost;           
            temp = temp->next;
        }
    }
    else
    {
        int connectingCity = findRoute(g, src, dest);
        return fare(g, connectingCity, dest) + fare(g, src, connectingCity);
    }
}
int flightNo(Node*g,int src,int dest){
    if (checkcon(g,src,dest)){
        struct adjlistnode *temp = g->arr[src].head;
        while (temp != NULL)
        {
            if(temp->neighbour == dest)
                return temp->flnum;
            temp  = temp->next;
        }
    }  
    return -1;  
}

    char *city[5] = {"MAA", "DEL", "BOM", "BLR", "CCU"};

Node* initgraph(Node *graph1){
    graph1 = createGraph(5);

    addEdge(graph1, 0, 1, 100, 123);
    addEdge(graph1, 1, 0, 100, 143);
    addEdge(graph1, 0, 2, 200, 456);
    addEdge(graph1, 2, 0, 200, 466);
    addEdge(graph1, 0, 4, 300, 789);
    addEdge(graph1, 4, 0, 300, 729);
    addEdge(graph1, 1, 3, 400, 642);
    addEdge(graph1, 3, 1, 400, 612);
    addEdge(graph1, 1, 4, 500, 406);
    addEdge(graph1, 4, 1, 500, 416);

    return graph1;
}
