#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge
struct Edge {
    int u, v, weight;
};

// Function to find the subset of an element (for union-find)
int find(int parent[], int i) {
    if(parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

// Function to perform union of two subsets
void unionSets(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

// Comparator function to sort edges by weight
int compare(const void* a, const void* b) {
    struct Edge* e1 = (struct Edge*)a;
    struct Edge* e2 = (struct Edge*)b;
    return e1->weight - e2->weight;
}

// Function to flush input buffer
void flushInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int n, e, i;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    struct Edge edges[e];

    // Input edges
    printf("Enter edges in format (u v weight):\n");
    for(i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    // Sort edges by weight
    qsort(edges, e, sizeof(struct Edge), compare);

    int parent[n];
    for(i = 0; i < n; i++)
        parent[i] = i; // Initially, each vertex is its own parent

    printf("\nEdges in Minimum Spanning Tree (MST):\n");
    int mstWeight = 0;

    for(i = 0; i < e; i++) {
        int uSet = find(parent, edges[i].u);
        int vSet = find(parent, edges[i].v);

        if(uSet != vSet) { // No cycle
            printf("%d -- %d  weight: %d\n", edges[i].u, edges[i].v, edges[i].weight);
            mstWeight += edges[i].weight;
            unionSets(parent, uSet, vSet);
        }
    }

    printf("Total weight of MST: %d\n", mstWeight);

    // Pause reliably before exiting
    flushInput();  // Clear any leftover input
    printf("\nPress Enter to exit...");
    getchar();     // Wait for Enter key

    return 0;
}
