#include <stdio.h>
#include <stdlib.h>

int *adjMatrix, *queue, *visited, *stack;
int n, front, rear, top;

void create_matrix() {
    adjMatrix = malloc((n*n)*sizeof(int));

    if(adjMatrix==NULL) {
        printf("\nMemory allocation error.");
        exit(0);
    }
}

void init_matrix() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            adjMatrix[i*n+j] = 0;
        }
    }

}

void add_edge(int s, int d) {
    if(s>=n) {
        printf("\nSource node value exceeds maximum number of nodes. Edge not created.");
        return;
    }
    if(d>=n) {
        printf("\nDestination node value exceeds maximum number of nodes. Edge not created.");
        return;
    }

    adjMatrix[s*n+d] = 1;
    adjMatrix[d*n+s] = 1;
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

    adjMatrix[s*n+d] = 0;
    adjMatrix[d*n+s] = 0;
    printf("\nEdge deleted successfully");
}

void create_queue() {
    queue = malloc(n*sizeof(int));

    if(queue==NULL) {
        printf("\nMemory allocation error. [Queue..BFS]");
        exit(0);
    }

    front = rear = -1;
}

int isEmptyQueue() {
    if(front==-1 && rear==-1)
        return 1;
    return 0;
}

void enqueue(int value) {
    if(isEmptyQueue()) {
        front = rear = 0;
        queue[rear] = value;
        return;
    }

    rear = (rear+1)%n;
    queue[rear] = value;
}

int dequeue() {
    if(isEmptyQueue()) {
        printf("\n[BFS] Queue is empty. Dequeue not possible.");
        return -1;
    }

    int temp;

    if(front==rear) {
        temp = queue[rear];
        front = -1;
        rear = -1;
        return temp;
    }

    temp = queue[front];
    front = (front+1)%n;
    return temp;
}

void create_stack() {
    stack = malloc(n*sizeof(int));

    if(queue==NULL) {
        printf("\nMemory allocation error. [Queue..BFS]");
        exit(0);
    }

    top = -1;
}

void push(int value) {
    top++;
    stack[top] = value;
}

int pop() {
    return stack[top--];
}

int isEmptyStack() {
    return top==-1;
}

void create_visited() {
    visited = malloc(n*sizeof(int));

    if(visited==NULL) {
        printf("\nMemory allocation error. [Queue..BFS]");
        exit(0);
    }
}

void init_visited() {
    for(int i=0; i<n; i++) {
        visited[i] = 0;
    }
}

void BFS(int start) {
    int temp;
    create_queue();
    init_visited();

    enqueue(start);
    visited[start] = 1;
    printf("\nBFS Traversal: \n");

    while(!isEmptyQueue()) {
        temp = dequeue();
        printf("\t%d", temp);

        for(int i=0; i<n; i++) {
            if(adjMatrix[temp*n+i] && !visited[i]) {
                enqueue(i);
                visited[i]^=1;
            }
        }
    }
}

void DFS(int start) {
    int temp;
    create_stack();
    init_visited();

    push(start);
    visited[start] = 1;
    printf("\nDFS Traversal: \n");

    while(!isEmptyStack()) {
        temp = pop();
        printf("\t%d", temp);

        for(int i=0; i<n; i++) {
            if(adjMatrix[temp*n+i] && !visited[i]) {
                push(i);
                visited[i]^=1;
            }
        }
    }
}

void display_matrix() {
    printf("\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("\t%d", adjMatrix[i*n+j]);
        }
        printf("\n");
    }
}

int main() {
    printf("\nEnter number of nodes: ");
    scanf("%d", &n);

    create_matrix();
    init_matrix();
    create_visited();

    int v1, v2, start;

    int choice;
    while(1) {
        printf("\nEnter 1 to add an edge, 2 to delete an edge, 3 to display the adjacency matrix, 4 for Breadth-First Traversal, 5 for Depth-First Traversal, 6 to exit.");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter vertex 1: ");
                scanf("%d", &v1);
                printf("\nEnter vertex 2: ");
                scanf("%d", &v2);

                add_edge(v1, v2);
                break;
            case 2:
                printf("\nEnter vertex 1: ");
                scanf("%d", &v1);
                printf("\nEnter vertex 2: ");
                scanf("%d", &v2);

                delete_edge(v1, v2);
                break;
            case 3:
                printf("\nAdjacency Matrix: ");
                display_matrix();
                break;
            case 4:
                printf("\nEnter starting vertex: ");
                scanf("%d", &start);
                BFS(start);
                break;
            case 5:
                printf("\nEnter starting vertex: ");
                scanf("%d", &start);
                DFS(start);
                break;
            case 6:
                exit(0);
            default:
                printf("\nPlease enter valid option.");
            }
    }
}