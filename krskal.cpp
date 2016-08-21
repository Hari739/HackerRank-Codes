# include <iostream>
# include <algorithm>
# include <queue>
using namespace std;

struct Edge{
	
	int src;
	int dest;
	int cost;
};
struct compare{
	       bool operator()(Edge &a,Edge &b){
		     return(a.cost>b.cost);
	}
};

class Graph{
	public:
	 int no_vertex;
	 int no_edge;
	 Edge *array ;
	int *parent;
		Graph(int x ,int y ){
			no_vertex =x;
			no_edge =y;
			array = new Edge [no_edge];
			//Visited = new bool[no_vertex];
			parent = new int [no_vertex];
			
		}
		void AddEdge(){
				
				int i,u,v,w;
				Edge temp ;
				for(i=0;i<no_edge;i++){
				cin>>u>>v>>w;
				temp.cost= w;
				temp.dest=v;
				temp.src=u;
				array[i]=temp;
			}
					
		}
		void Union(int x,int y){
			int x_root =find(x);
			int y_root = find(y);
			parent[y_root]=x_root;
		}
		int find(int a){
			if(parent[a]==-1)
				return a;
				else
				return find(parent[a]);
		}
		bool Same_parent(int x , int y){
			int a =find(x);
			int b =find(y);
			if(a==b)
				return true;
			else 
				return false;
		}
		
		bool Iscycle(int a, int b){
			if(Same_parent(a,b))
				return true;
			else 
			   return false;
		}
	
		priority_queue <Edge ,vector<Edge>,compare > pq;
		 void Kruskals(){
		 	int i,sum=0;
		 	for(i=0;i<no_edge;i++){
		 		pq.push(array[i]);
		 		parent[i]=-1;
			 }
			 for(i=0;i<no_edge;i++){
			 	Edge t =pq.top();
			 	if(!Iscycle(t.src,t.dest)){
			 		sum+=t.cost;
			 		Union(t.src,t.dest);
			 			pq.pop();
			 	}
				 else
				 	pq.pop();
			 }
		 	cout<<sum<<endl;
		  }
};
int main(){
    int a,b;
	cin>>a>>b;
	Graph g(a,b);
	g.AddEdge();
	g.Kruskals();
}
	
	

