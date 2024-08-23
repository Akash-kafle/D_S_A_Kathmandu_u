
#include "../include/graph.h"

int enter(int n = 0);

/**
 * Generates a random graph with the given number of vertices and edges.
 */
Graph generateRandomGraph(int numVertices, int numEdges)
{
    std::srand(std::time(nullptr));       // Seed the random number generator with the current time.
    bool directed = std::rand() % 2 == 0; // Randomly decide whether the graph is directed or undirected.
    Graph graph(directed);                // Create a random graph (directed or undirected) (50/50).
    // Add vertices to the graph.
    for (int i = 0; i < numVertices; ++i)
    {
        graph.addVertex(i);
    }

    // Add random edges to the graph.
    for (int i = 0; i < numEdges; ++i)
    {
        int vertex1 = std::rand() % numVertices; // Generate a random vertex index.
        int vertex2 = std::rand() % numVertices; // Generate another random vertex index.
        int weight = std::rand() % 10 + 1;       // Generate a random weight between 1 and 10.
        if (vertex1 != vertex2)                  // Ensure that the two vertices are not the same.
        {
            graph.addEdge(vertex1, vertex2, weight);
        }
    }
    return graph;
}

int main()
{
    Graph g(false);
    g = generateRandomGraph(5, 10);
    print("Degree of vertex 0: "), print(g.degree(0)), print("\n"), print("Indegree of vertex 0: "), print(g.indegree(0)), print("\n"); // Print the degree of vertex 0.
    print("Outdegree of vertex 0: "), print(g.outdegree(0)), print("\n"), print("Neighbours of vertex 0: "), print("\n");               // Print the degree of vertex 0.
    for (const auto &neighbour : g.neighbours(0))
    {
        print(neighbour), print(" ");
    }
    print("\n"), print("Neighbour of vertex 0 and vertex 1: "), print(g.neighbour(0, 1)), print("\n");
    g.removeEdge(0, 1); // Remove the edge between vertex 0 and vertex 1.
    try
    {
        print("Neighbour of vertex 0 and vertex 1: "), print(g.neighbour(0, 1)), print("\n");
    }
    catch (const std::exception &e)
    {
        print(e.what()), print("\n");
    }
    g.removeVertex(0); // Remove vertex 0 from the graph.
    try
    {
        print("Degree of vertex 0: "), print(g.degree(0)), print("\n");
    }
    catch (const std::exception &e)
    {
        print(e.what()), print("\n");
    }
    try
    {
        print("Indegree of vertex 0: "), print(g.indegree(0)), print("\n");
    }
    catch (const std::exception &e)
    {
        print(e.what()), print("\n");
    }
    try
    {
        print("Outdegree of vertex 0: "), print(g.outdegree(0)), print("\n");
    }
    catch (const std::exception &e)
    {
        print(e.what()), print("\n");
    }
    for (const auto &neighbour : g.neighbours(0))
    {
        print(neighbour), print(" ");
    }
    print("\n"), g.isDirected() ? print("Directed Graph"), print("\n") : print("Undirected Graph"), print("\n"); // Print whether the graph is directed or undirected.
    print("\n"), print("Graph 1: "), print("\n");
    // Print the vertices and their neighbours.
    for (const auto &[vertex, neighbours] : g.getVertices())
    {
        print("Vertex: "), print(vertex), print("\n");
        for (const auto &[neighbour, weight] : neighbours)
        {
            print("Neighbour: "), print(neighbour), print(" Weight: "), print(weight), print("\n");
        }
    }
    print("\n"), print("Breadth-First Traversal: "), print("\n");
    int start;
    for (int i = 0; i < 5; ++i)
    {
        if (!g.removed(i))
        {
            start = i;
            break;
        }
    }
    BFT(g, start); // Perform a breadth-first traversal of the random graph starting from vertex 0.
    print("\n"), print("Depth-First Traversal: "), print("\n");
    DFT(g, start); // Perform a depth-first traversal of the random graph starting from vertex 0.
    Graph randomGraph = generateRandomGraph(5, 10);
    print("\n"), print("Graph 2: "), print("\n");
    // Print the vertices and their neighbours.
    for (const auto &[vertex, neighbours] : randomGraph.getVertices())
    {
        print("Vertex: "), print(vertex), print("\n");
        for (const auto &[neighbour, weight] : neighbours)
        {
            print("Neighbour: "), print(neighbour), print(" Weight: "), print(weight), print("\n");
        }
    }
    print("\n"), print("Breadth-First Traversal: "), print("\n");
    for (int i = 0; i < 5; ++i)
    {
        if (!randomGraph.removed(i))
        {
            start = i;
            break;
        }
    }
    BFT(randomGraph, start); // Perform a breadth-first traversal of the random graph starting from vertex 0.
    print("\n"), print("Depth-First Traversal: "), print("\n");
    DFT(randomGraph, start); // Perform a depth-first traversal of the random graph starting from vertex 0.
    return 0;
}

/**
 * Prompts the user to enter a number.
 */
int enter(int n)
{
    if (n != 0)
    {
        while (true)
        {
            int j = 0;
            std::cin >> j;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                print("Please enter a valid number: ");
            }
            else if (j < 0)
            {
                print("Please enter a positive number: ");
            }
            else if (j == n)
            {
                print("Please enter a number less than "), print(n), print(": ");
            }
            else if (j >= n)
            {
                print("Please enter a number less than "), print(n), print(": ");
            }
            else
            {
                n = j;
                break;
            }
        }
    }
    else
    {
        while (true)
        {
            std::cin >> n;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                print("Please enter a valid number: ");
            }
            else if (n < 0)
            {
                print("Please enter a positive number: ");
            }
            else
            {
                break;
            }
        }
    }
    return n;
}
