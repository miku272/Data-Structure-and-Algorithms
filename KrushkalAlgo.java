import java.util.ArrayList;

class DisjointUnit {
    private int[] parent;
    private int[] rank;

    public DisjointUnit(int totalVertex) {
        parent = new int[totalVertex];
        rank = new int[totalVertex];

        for (int i = 0; i < totalVertex; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    public int findUltimateParent(int vertex) {
        if (parent[vertex] == -1) {
            return vertex;
        }

        parent[vertex] = findUltimateParent(parent[vertex]);

        return parent[vertex];
    }

    public void joinComponent(int comp1, int comp2) {
        int ultimateParentOfComp1 = findUltimateParent(comp1);
        int ultimateParentOfComp2 = findUltimateParent(comp2);

        if (ultimateParentOfComp1 != ultimateParentOfComp2) {
            if (rank[ultimateParentOfComp1] < rank[ultimateParentOfComp2]) {
                parent[ultimateParentOfComp1] = ultimateParentOfComp2;
            } else if (rank[ultimateParentOfComp1] > rank[ultimateParentOfComp2]) {
                parent[ultimateParentOfComp2] = ultimateParentOfComp1;
            } else {
                parent[ultimateParentOfComp2] = ultimateParentOfComp1;
                rank[ultimateParentOfComp1]++;
            }
        }
    }
}

class Edge {
    public int source;
    public int destination;
    public int weight;

    public Edge(int source, int destination, int weight) {
        this.source = source;
        this.destination = destination;
        this.weight = weight;
    }
}

class Graph {
    private ArrayList<Edge> edgeList;
    private int totalVertex;

    public Graph(int totalVertex) {
        edgeList = new ArrayList<Edge>();
        this.totalVertex = totalVertex;
    }

    public void addEdge(int source, int destination, int weight) {
        edgeList.add(new Edge(source, destination, weight));
    }

    public void krushkalsAlgo() {
        edgeList.sort((a, b) -> a.weight - b.weight);

        DisjointUnit disjointUnit = new DisjointUnit(totalVertex);
        int answer = 0;

        System.out.println("Edges in MST are: ");

        for (Edge edge: edgeList) {
            int source = edge.source;
            int destination = edge.destination;
            int weight = edge.weight;

            if (disjointUnit.findUltimateParent(source) != disjointUnit.findUltimateParent(destination)) {
                disjointUnit.joinComponent(source, destination);
                answer += weight;
                System.out.println(source + " -> " + destination + " : " + weight);
            }
        }

        System.out.println("\nTotal weight of MST is: " + answer);
    }
}

public class KrushkalAlgo {
    public static void main(String[] args) {
        Graph graph = new Graph(4);

        graph.addEdge(0, 1, 10);
        graph.addEdge(1, 3, 15);
        graph.addEdge(2, 3, 4);
        graph.addEdge(2, 0, 6);
        graph.addEdge(0, 3, 5);

        graph.krushkalsAlgo();
    }
}