#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define n 15

int graph[n][n];

int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[])
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < n; i++)
        printf("%d \t\t\t\t %d\n", i, dist[i]);
}

void dijkstra(int src)
{
    int dist[n];
    bool sptSet[n];

    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < n; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist);
}

void add_edge(int s, int d, int w) {
    if(s>=n) {
        printf("\nSource node value exceeds maximum number of nodes. Edge not created.");
        return;
    }
    if(d>=n) {
        printf("\nDestination node value exceeds maximum number of nodes. Edge not created.");
        return;
    }

    graph[s][d] = w;
    graph[d][s] = w;
    printf("\nEdge added successfully");
}

void delete_edge(int s, int d) {
    if(s>=n) {
        printf("\nSource node value exceeds maximum number of nodes. Edge could not be deleted.");
        return;
    }
    if(d>=n) {
        printf("\nDestination node value exceeds maximum number of nodes. Edge could not be deleted.");
        return;
    }

    graph[s][d] = 0;
    graph[d][s] = 0;
    printf("\nEdge deleted successfully");
}

void display_matrix() {
    printf("\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("\t%d", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int choice, v1, v2, w, start;
    while(1) {
        printf("\nEnter 1 to add an edge, 2 to delete an edge, 3 to display the adjacency matrix, 4 for Dijkstra's Algorithm, 5 to exit.");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter vertex 1: ");
                scanf("%d", &v1);
                printf("\nEnter vertex 2: ");
                scanf("%d", &v2);
                printf("\nEnter weight: ");
                scanf("%d", &w);

                add_edge(v1, v2, w);
                break;
            case 2:
                printf("\nEnter vertex 1: ");
                scanf("%d", &v1);
                printf("\nEnter vertex 2: ");
                scanf("%d", &v2);

                delete_edge(v1, v2);
                break;
            case 3:
                display_matrix();
                break;
            case 4:
                printf("\nEnter starting node: ");
                scanf("%d", &start);
                dijkstra(start);
                break;
            case 5:
                exit(0);
}
}
}