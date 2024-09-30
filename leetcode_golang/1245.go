
func treeDiameter(edges [][]int) int {
    graph := make(map[int][]int, 0)
    degree := make(map[int]int, 0)
    
    for _, edge := range edges {
        graph[edge[1]] = append(graph[edge[1]], edge[0])
        graph[edge[0]] = append(graph[edge[0]], edge[1])
        degree[edge[0]] += 1
        degree[edge[1]] += 1
    }
    leaves := make([]int, 0)
    // fmt.Println(graph)
    for node, deg := range degree {
        // fmt.Println(node, deg)
        if deg == 1 {
            leaves = append(leaves, node)
        }
    }
    // fmt.Println("Leaves",leaves)
    layers := 0
    vertexLeft := len(edges)+1
    for vertexLeft> 2{
        vertexLeft -= len(leaves)
        // node := bfs[i]
        nextLeaves := make([]int, 0)
        for _,leaf := range(leaves) {
            for _, j := range graph[leaf] {
                degree[j] -= 1
                // fmt.Println("Reducing degree of j", j, degree[j], leaf)
                if degree[j] == 1 {
                    nextLeaves = append(nextLeaves, j)
                }
            }
        }
        // fmt.Println("Next leaves", nextLeaves)
        leaves = nextLeaves
        layers +=1
    }
    
    if vertexLeft==1 {
        return layers*2
    } else {
        return (layers*2)+1
    }
}
