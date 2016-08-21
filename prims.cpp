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
	 vector <Edge> *array;
	 
	 bool *Visited;
	 int *parent;
		Graph(int x ,int y ){
		 no_vertex =x;
			no_edge =y;
			Visited = new bool[no_vertex];
			parent = new int [no_vertex];
			array = new vector <Edge> [no_vertex];
		}
		
		void AddEdge(){
				
				int i,u,v,w;
				Edge temp ;
				
				for(i=0;i<no_edge;i++){
				cout<<"\nENTER EDGE \n:->";
				cin>>u>>v>>w;
				temp.cost= w;
				temp.dest=v;
				temp.src=u;
				array[temp.src].push_back(temp);
				array[temp.dest].push_back(temp);
			}
					
		}
	
	
		priority_queue <Edge ,vector<Edge>,compare> pq;
		
		void prims(){
			int j;
			for(j=0;j<no_vertex;j++)
				Visited[j]=false;
			int sum =0;
			Visited[0]=true;
			while(!array[0].empty()){
				pq.push(array[0].back());
				array[0].pop_back();
			}
			int i =0;
			while(true){
				Edge t;
				t = pq.top();
					pq.pop();
				if(Visited[t.dest]==false&&Visited[t.src]==true){
					Visited[t.dest]=true;
					sum+=t.cost;
					cout<<t.cost<<" ";
					while(!array[t.dest].empty()){
						pq.push(array[t.dest].back());
						array[t.dest].pop_back();
					
					}
						i++;					
				}
				else if(Visited[t.src]==false&&Visited[t.dest]==true){
					Visited[t.src]=true;
					sum+=t.cost;
					cout<<t.cost<<" ";
					while(!array[t.src].empty()){
						pq.push(array[t.src].back());
						array[t.src].pop_back();
					
					}
						i++;					
				}
				if(i==no_vertex-1)
				break;	 
			}
			cout<<"MST COST==>$$"<<sum<<endl;
		}
		
};

int main(){
	
	Graph g(7,9);
	g.AddEdge();
	g.prims();
}

