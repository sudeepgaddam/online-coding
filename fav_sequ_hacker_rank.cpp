#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>    // std::find
using namespace std;

class Graph
{
    int V;    // No. of vertices
    vector< vector<int> > adj_list;    // An array of adjacency lists    
    vector<bool> mark_visited;
    vector<int> incoming_count;
public:
    Graph(int V);
    void addEdge(int v, int w);
 
    // The main function that finds and prints strongly connected components
    //void printSCCs();
 
    // Function that returns reverse (or transpose) of this graph
    //Graph getTranspose();
    void PrintGraph();
    //void DFS(int start);
    
    vector<int> TopSort();
};
 
Graph::Graph(int V):adj_list(V),mark_visited(V,false), incoming_count(V,0)
{
    this->V = V;
    //adj_list.resize(V);
    //mark_visited.resize(V);
    //incoming_count.resize(V);
}

void Graph::addEdge(int v, int w)
{   
    auto it = find (adj_list[v].begin(), adj_list[v].end(), w);
    
    if (it == adj_list[v].end()) {
        //Not found, So insert
        adj_list[v].push_back(w); // Add w to v’s list.
        incoming_count[w]++;
    }
}
//Print Graph
void Graph::PrintGraph() {
	
	int count = 0;
	for(auto a: adj_list) {
		cout<<count<<":";
		for (auto b: a) {
			
			cout<<b<<"(Incoming count: "<<incoming_count[b]<<" ) ";
			
		}
		cout<<endl;
		count++;
	}
	
}
vector<int> Graph::TopSort() {
	
	vector<int> inc_count(incoming_count);
	//priority_queue<int> zero_inc;
	std::priority_queue<int, std::vector<int>, std::greater<int> > zero_inc;
    vector<int> topsort;
	for(int i=0;i<V;i++) {
		if(inc_count[i]==0 && adj_list[i].size()) {
			zero_inc.push(i);
			
		}
	}
	
	if(zero_inc.size()==0) {
		cout<<"Cycles present, Cant get top sort"<<endl;
	} else {
		while(!zero_inc.empty()) {
			int a = zero_inc.top();
			zero_inc.pop();
			//cout<<a<<" ";
			topsort.push_back(a);
			for(auto b:adj_list[a]) {
				inc_count[b]--;
				if(inc_count[b]==0) {
					zero_inc.push(b);
				}
			}
		}
		
	}
	return topsort;
}



// Driver program to test above functions
int main()
{
    // Create a graph given in the above diagram
    int N,K,a,b,prev;
    cin>>N;
    Graph g(1000000);
    for (int i=0;i<N;i++) {
        cin>>K;
        cin>>prev;
        //cout<<"K"<<K <<"PRev"<<prev<<"Before entering loop"<<endl;
        for (int j=1;j<K-1;j+=2) {
            cin>>a>>b;
            g.addEdge(prev-1,a-1);
            g.addEdge(a-1,b-1);
            prev = b;
            //cout<<"added two edges"<<endl;
            
        }
        if(!(K%2)) {
            cin>>a;
            //cout<<K<<"Adding the last edge"<<endl;
            g.addEdge(prev-1,a-1);
        }
        
    }
    
   // cout << "Following are strongly connected components in given graph \n";
  //  g.PrintGraph();
    vector<int> top = g.TopSort();
    
    
    for(auto bcd : top) {
        
        cout<< bcd+1<<" ";
    }
    //g.printSCCs();
    cout<<endl;
    return 0;
}

