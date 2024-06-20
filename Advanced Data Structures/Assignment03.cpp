/*Activity on vertex(AOV) network: Sandy is a well organized person.
Every day he makes a list of things which need to be done and
enumerates them from 1 to n. However, some things need to be done
before others. Write a C++ code to find out whether Sandy can solve all
his duties and if so, print the correct order*/


/*work to be done: 1. wake up 2. exercise 3. brush 4. take bath 5. worshipping god 
6. Cook Lunch 7. Go to Office 8. have Lunch 9. Come from Office 10.Cook Dinner 11.Have Dinner 12. Go to sleep*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;


class Graph {
    int V;
    int adj[12][12];
    string tasks[12];
    int inDegree[12];

public:
    Graph(int V);
    void addEdge(int v, int w);
    void addTask(int v, string task);
    void topologicalSort();
};

Graph::Graph(int V) {
    this->V = V;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            adj[i][j] = 0;
        }
        inDegree[i] = 0;
    }
}

void Graph::addTask(int v ,string task) {
    tasks[v] = task;
}

void Graph::addEdge(int v, int w) {
    adj[v][w] = 1;
    inDegree[w]++;
}

void Graph::topologicalSort() {
    stack<int> stack;

    for (int i = 0; i < V; ++i) {
        if (inDegree[i] == 0)
            stack.push(i);
    }

    int count = 0;
    int order[12];

    while (!stack.empty()) {
        int v = stack.top();
        stack.pop();
        order[count++] = v;

        for (int i = 0; i < V; ++i) {
            if (adj[v][i]) {
                if (--inDegree[i] == 0)
                    stack.push(i);
            }
        }
    }

    if (count != V) {
        cout <<endl<< "Sandy cannot solve all his duties." << endl;
        return;
    }

    cout << "Sandy can solve all his duties. Correct order is:" << endl;
    for (int i = 0; i < count; ++i) {
        cout <<endl<< i + 1 << ". " << tasks[order[i]] << endl;
    }
}

int main() {

    int ch;
    Graph g(5);
    string tasks[5];
    do{
    cout<<"Menu..."<<endl;
    cout<<"1.Enter the Tasks performed by Sandy"<<endl;
    cout<<"2.Display Taks"<<endl;
    cout<<"3.Enter the order of Tasks"<<endl;
    cout<<"4.Sort the Tasks"<<endl;
    cout<<"Enter your choice: "<<endl;
    cin>>ch;
    switch(ch){
    case 1:
    cout<<"Enter the tasks sandy is going to perform!"<<endl;
    for(int i=0; i<5; i++){
        cout<<"Task "<<i+1<<": ";
        cin>>tasks[i];
        g.addTask(i,tasks[i]);
    }
    cout<<endl<<endl; 
    break;
    
    case 2:
    for(int i=0; i<5; i++){
        cout<<"Task "<<i+1<<": ";
        cout<<tasks[i]<<endl;
    }
    cout<<endl<<endl; 
    break;
    case 3:
    cout<<"Add the Graph Edges: "<<endl;
    int v, w;
    for (int i = 0; i < 4; i++) {
        cout << "Enter dependency for task " << i + 1 << ": ";
        cin >> v >> w;
        g.addEdge(v - 1, w - 1); // Adjust indices to start from 0
    }
    break;

    case 4:
    g.topologicalSort();
    break;
    
    default: 
    cout<<"Invalid choice!"<<endl;
    }}while(ch<=4);

    return 0;
}