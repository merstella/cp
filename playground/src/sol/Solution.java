import java.util.*;

public class Solution {
    private int time = 0;  // Global variable to track discovery time for DFS

    // Function to check if a graph is connected using Depth-First Search (DFS)
    public boolean isGraphConnected(Map<Integer, List<Integer>> adjList, Set<Integer> nodes) {
        Set<Integer> visited = new HashSet<>();  // Set to track visited nodes
        Stack<Integer> stack = new Stack<>();     // Stack for DFS

        // Start DFS from any node (the first one from the node set)
        int startNode = nodes.iterator().next();
        stack.push(startNode);

        // Perform DFS
        while (!stack.isEmpty()) {
            int currentNode = stack.pop();

            if (!visited.contains(currentNode)) {
                visited.add(currentNode);  // Mark the node as visited

                // Explore all neighbors of the current node
                for (int neighbor : adjList.getOrDefault(currentNode, new ArrayList<>())) {
                    if (!visited.contains(neighbor)) {
                        stack.push(neighbor);  // Push unvisited neighbors onto the stack
                    }
                }
            }
        }

        // The graph is connected if we visited all the nodes
        return visited.size() == nodes.size();
    }

    // Function to perform DFS and find bridges in the graph
    public void findBridges(int u, int parent, Map<Integer, List<Integer>> adjList, boolean[] visited, int[] disc, int[] low, List<int[]> bridges) {
        visited[u] = true;               // Mark the current node as visited
        disc[u] = low[u] = ++time;      // Set discovery time and low value

        // Explore all adjacent vertices
        for (int v : adjList.getOrDefault(u, new ArrayList<>())) {
            if (!visited[v]) {
                // Visit the adjacent vertex
                findBridges(v, u, adjList, visited, disc, low, bridges);

                // Check if the subtree rooted at v has a connection back to one of the ancestors of u
                low[u] = Math.min(low[u], low[v]);

                // If the lowest vertex reachable from v is below u in DFS tree, then (u, v) is a bridge
                if (low[v] > disc[u]) {
                    bridges.add(new int[]{u, v});  // Add the bridge to the list
                }
            } else if (v != parent) {
                // Update low[u] to the discovery time of v if v is already visited and v is not the parent of u
                low[u] = Math.min(low[u], disc[v]);
            }
        }
    }

    // Function to construct the adjacency list and node set from the set of edges
    public Map<Integer, List<Integer>> constructAdjList(Set<int[]> edges, Set<Integer> nodes) {
        Map<Integer, List<Integer>> adjList = new HashMap<>();

        // Build adjacency list and track all unique nodes
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList.computeIfAbsent(u, k -> new ArrayList<>()).add(v); // Add v to u's list
            adjList.computeIfAbsent(v, k -> new ArrayList<>()).add(u); // Add u to v's list
            nodes.add(u);  // Track unique nodes
            nodes.add(v);
        }

        return adjList;
    }

    // Function to check if the graph is connected
    public boolean checkConnectivity(Set<int[]> edges) {
        Set<Integer> nodes = new HashSet<>();  // Set to store nodes
        Map<Integer, List<Integer>> adjList = constructAdjList(edges, nodes); // Construct adjacency list
        return isGraphConnected(adjList, nodes); // Check if the graph is connected
    }

    // Function to determine if two edges can be removed without disconnecting the graph
    public boolean canRemove(Set<int[]> edges) {
        // Construct adjacency list and set of nodes
        Set<Integer> nodes = new HashSet<>();
        Map<Integer, List<Integer>> adjList = constructAdjList(edges, nodes);
        int numNodes = nodes.size();  // Calculate number of nodes
        int maxNode = Collections.max(nodes); // Get the highest node value
        boolean[] visited = new boolean[maxNode + 1]; // Visited array for DFS
        int[] disc = new int[maxNode + 1]; // Discovery times array
        int[] low = new int[maxNode + 1]; // Lowest discovery times array
        List<int[]> bridges = new ArrayList<>(); // List to store found bridges

        // Perform DFS from all unvisited nodes to find bridges
        for (int node : nodes) {
            if (!visited[node]) {
                findBridges(node, -1, adjList, visited, disc, low, bridges);
            }
        }

        // Check if the number of nodes minus the number of bridges is less than 2
        return !(numNodes - bridges.size() < 2);
    }

    // Function to find the highest and lowest degree nodes in the graph
    public int[] findHighestAndLowestDegreeNodes(Map<Integer, List<Integer>> adjList) {
        int maxDegree = -1; // Highest degree found
        int minDegree = Integer.MAX_VALUE; // Lowest degree found
        int maxNode = -1; // Node with the highest degree
        int minNode = -1; // Node with the lowest degree

        // Iterate through the adjacency list to find degrees
        for (Map.Entry<Integer, List<Integer>> entry : adjList.entrySet()) {
            int node = entry.getKey(); // Current node
            int degree = entry.getValue().size(); // Degree of the current node

            // Update highest degree node
            if (degree > maxDegree) {
                maxDegree = degree;
                maxNode = node; // Update the highest degree node
            }

            // Update lowest degree node
            if (degree < minDegree) {
                minDegree = degree;
                minNode = node; // Update the lowest degree node
            }
        }

        return new int[]{maxNode, minNode};  // Return both nodes as an array
    }

    // Function to remove the edge between the node with the highest degree and a node with a non-lowest degree
    public void removeEdgeBetweenHighestAndNonLowest(Map<Integer, List<Integer>> adjList) {
        int[] nodes = findHighestAndLowestDegreeNodes(adjList); // Find highest and lowest degree nodes
        int highestNode = nodes[0];
        int lowestNode = nodes[1];

        // Remove an edge between highestNode and any non-lowest neighbor
        List<Integer> neighbors = adjList.get(highestNode);
        for (int neighbor : neighbors) {
            if (neighbor != lowestNode) { // Ensure not removing edge to the lowest node
                adjList.get(highestNode).remove(Integer.valueOf(neighbor)); // Remove edge from highestNode
                adjList.get(neighbor).remove(Integer.valueOf(highestNode)); // Remove edge from neighbor
                break; // Remove one edge and stop
            }
        }
    }

    // Function to balance the graph by removing edges and calculating degree difference
    public int balanceGraph(Set<int[]> edges) throws IllegalArgumentException {
        // Check for the number of edges
        if (edges.isEmpty()) {
            throw new IllegalArgumentException("The input graph must have at least one edge."); // Error if no edges
        }

        // Check for connectivity
        if (!checkConnectivity(edges)) {
            throw new IllegalArgumentException("The input graph must be connected."); // Error if disconnected
        }

        // Check if it is possible to remove edges
        if (!canRemove(edges)) {
            throw new IllegalArgumentException("It is impossible to remove two nodes without causing the graph to become disconnected."); // Error if cannot remove edges
        }

        Set<Integer> nodes = new HashSet<>();
        Map<Integer, List<Integer>> adjList = constructAdjList(edges, nodes); // Construct adjacency list
        removeEdgeBetweenHighestAndNonLowest(adjList); // Remove an edge
        removeEdgeBetweenHighestAndNonLowest(adjList); // Remove another edge

        // Find the degree difference after trying
        int highestDegree = adjList.get(findHighestAndLowestDegreeNodes(adjList)[0]).size(); // Highest degree after removal
        int lowestDegree = adjList.get(findHighestAndLowestDegreeNodes(adjList)[1]).size(); // Lowest degree after removal

        return highestDegree - lowestDegree;
    }
}
