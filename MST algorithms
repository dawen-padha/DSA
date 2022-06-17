//Kruskal's Algorithm


#include <iostream>
#include<algorithm>
using namespace std;
class edges{
    public:
    int source;
    int destination;
    int wvalue;
    void printedge(){
     cout<<min(source,destination)<<" "<<max(source,destination)<<" "<<wvalue;
    
    }
};
bool compare(edges e1,edges e2){
return e1.wvalue<e2.wvalue;
}
int findparent(int v,int* parent){
if(parent[v]==v){
return v;
}
return findparent(parent[v],parent);
}
void printmst(edges* input,int v,int e){
      sort(input,input+e,compare);
    
    edges *output=new edges[v-1];
int *parent=new int[v];
    for(int i=0;i<v;i++){
  parent[i]=i;
    }
int count=0;
    int i=0;
    while(count!=v-1){
        edges current=input[i];
        int sourceparent=findparent(current.source,parent);
        int destinationparent=findparent(current.destination,parent);
        if(sourceparent!=destinationparent){
          output[count]=current;
            parent[sourceparent]=destinationparent;
          count++;
        }
      i++;  
        
    }
    for(int i=0;i<v-1;i++){
        output[i].printedge();
        cout<<endl;
    }
}

int main() {
    int v,e;
    cin>>v>>e;
   edges *input=new edges[e];
    for(int i=0;i<e;i++){
        int s,d,w;
        cin>>s>>d>>w;
        input[i].source=s;
        input[i].destination=d;
        input[i].wvalue=w;
    }
    printmst(input,v,e);
    return 0;
}


//Prim's Algorithm




#include<bits/stdc++.h>
#include<climits>
using namespace std;

int findMinVertex(vector<int> &weights, vector<bool>& visited, int n){

	int minVertex = -1;
	for(int i = 0; i < n; i++){
		if(!visited[i] && (minVertex == - 1 || weights[i] < weights[minVertex])){
			minVertex = i;
		}
	}
	return minVertex;
}


void prims(vector<vector<int>> &edges, int n){

	vector<int> parent(n);
    vector<int> weights(n,INT_MAX);
    vector<bool> visited(n,0);
    
	parent[0] = -1;
	weights[0] = 0;

	for(int i = 0; i < n-1 ; i++){
		// Find Min Vertex
		int minVertex = findMinVertex(weights, visited, n);
		visited[minVertex] = true;
		// Explore un visted neighbours
		for(int j = 0; j < n; j++){
			if(edges[minVertex][j] != 0 && !visited[j]){
				if(edges[minVertex][j] < weights[j]){
					weights[j] = edges[minVertex][j];
					parent[j] = minVertex;
				}
			}
		}
	}

	for(int i = 1; i < n; i++){
			cout << min(parent[i],i) << " "<<max(parent[i],i)<< " " << weights[i] << endl;
	}
}

int main() {
	int n;
	int e;
	cin >> n >> e;
	vector<vector<int>> edges(n,vector<int>(n,0));

	for (int i = 0; i < e; i++) {
		int f, s, weight;
		cin >> f >> s >> weight;
		edges[f][s] = weight;
		edges[s][f] = weight;
	}
	prims(edges, n);

	
}



