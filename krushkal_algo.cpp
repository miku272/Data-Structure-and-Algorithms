#include <iostream>
#include <vector>
#include <algorithm>

class DisjointSet
{
private:
    int *parent;
    int *rank;

public:
    DisjointSet(int total_vertex)
    {
        parent = new int[total_vertex];
        rank = new int[total_vertex];

        for (int i = 0; i < total_vertex; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    int findUltimateParent(int vertex)
    {
        if (parent[vertex] == -1)
        {
            return vertex;
        }

        return parent[vertex] = findUltimateParent(parent[vertex]);
    }

    void joinComponent(int comp1, int comp2)
    {
        int ultimateParentOfComp1 = findUltimateParent(comp1);
        int ultimateParentOfComp2 = findUltimateParent(comp2);

        if (ultimateParentOfComp1 != ultimateParentOfComp2)
        {
            if (rank[ultimateParentOfComp1] < rank[ultimateParentOfComp2])
            {
                parent[ultimateParentOfComp1] = ultimateParentOfComp2;
            }
            else if (rank[ultimateParentOfComp1] > rank[ultimateParentOfComp2])
            {
                parent[ultimateParentOfComp2] = ultimateParentOfComp1;
            }
            else
            {
                parent[ultimateParentOfComp2] = ultimateParentOfComp1;
                rank[ultimateParentOfComp1] += 1;
            }
        }
    }
};

class Graph
{
private:
    std::vector<std::vector<int>> edgeList;
    int total_vertex;

public:
    Graph(int total_vertex)
    {
        this->total_vertex = total_vertex;
    }

    void addEdge(int weight, int source, int destination)
    {
        edgeList.push_back({weight, source, destination});
    }

    void krushKalAlgo()
    {
        std::sort(edgeList.begin(), edgeList.end());

        DisjointSet d(total_vertex);
        int answer = 0;

        std::cout << "Minimum Spanning Tree:\n";

        for (auto edge : edgeList)
        {
            int weight = edge[0];
            int source = edge[1];
            int destination = edge[2];

            if (d.findUltimateParent(source) != d.findUltimateParent(destination))
            {
                d.joinComponent(source, destination);

                answer += weight;

                std::cout << source << " --> " << destination << " = " << weight << "\n";
            }
        }

        std::cout << "\nMinimum Cost: " << answer;
    }
};

int main(int argc, char const *argv[])
{
    Graph g(4);

    g.addEdge(0, 1, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 0, 6);
    g.addEdge(0, 3, 5);

    g.krushKalAlgo();

    return 0;
}
