/*Assignment 2:Graph traversal: The area around the college and the prominent 
landmarks of it are represented using graphs. 
Write a menu driven C++ program to represent this as a graph using 
adjacency matrix /list and perform DFS and BFS.*/

#include <iostream> 
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>
 #include <stack>
using namespace std;    

class Graph {
    unordered_map<string, vector<string>> adj_list;

public:
    void add_edge(string u, string v) {
        adj_list[u].push_back(v);
        adj_list[v].push_back(u); // Assuming an undirected graph
    }

    void bfs(string start) {
        unordered_set<string> visited;
        queue<string> q;
        

        q.push(start);
        visited.insert(start);

        while (!q.empty()) {
            string node = q.front();
            q.pop();
            cout<<node<<" ";

            for (string neighbor : adj_list[node]) {
                if (visited.find(neighbor) == visited.end()) {
                    q.push(neighbor);
                    visited.insert(neighbor);
                } 
            }
        }
        }
        void DFS(string s)
		{ unordered_set<string>::iterator itr;
		 unordered_set<string> visited;
		 
		 stack<string> stack;
		 stack.push(s);

		 while(!stack.empty())
		 {
		  s=stack.top();
		  visited.insert(s);
		 
           cout<<endl;
		  cout<<s<<" ";
		  stack.pop();
		  for (string adjacent : adj_list[s]) {
				     if (visited.find(adjacent) == visited.end()) {
				    //cout<<"push"<<adjacent<<endl;
		               
				        stack.push(adjacent);
				    }
				}
		 }
		}
};

int main() {
    Graph graph;
    
    // Adding edges
    graph.add_edge("civil", "cs");
    graph.add_edge("civil", "IT");
    graph.add_edge("civil", "AIDS");
    graph.add_edge("cs", "AIDS");
    graph.add_edge("AIDS", "IT");
    graph.add_edge("cs", "electrical");

    // Performing BFS starting from node 'A'
    graph.bfs("civil");
    cout<<endl;
    graph.DFS("civil");
    // Printing BFS traversal order

    return 0;
}
