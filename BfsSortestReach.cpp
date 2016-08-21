# include <iostream>
# include<algorithm>
# include <queue>

using namespace std;

struct Edge{
	
	int src;
	int dest;
	int cost;
	
};

class Graph {
	
	int no_edge;
	
	int no_vertex;
	
	vector <Edge> *array;
	
//	bool *visited;
	
	int *d;
	
	public :
		
		Graph (int x, int y){
			
			no_vertex = x;
			no_edge = y;
			array = new vector <Edge>[no_vertex+1];
		//	visited = new bool [no_vertex+1];
			d = new int [no_vertex+1];
		}
		
	void AddEdge(){
				
				int i,u,v,w;
				Edge temp ;
				for(i=1;i<=no_vertex;i++){
					d[i]=-1;
					//visited[i]=false;
				}
			
				for(i=1;i<=no_edge;i++){
				
				//cout<<"\nENTER EDGE \n:->";
				cin>>u>>v;
				temp.cost= 6;
				temp.dest=v;
				temp.src=u;
				array[temp.src].push_back(temp);
				array[temp.dest].push_back(temp);
			}
					
		}
		queue <Edge> q;
		
	void bfs_sortestPath(int v){
		
		q.push(array[v].front());
		d[v]=0;
	//	visited[v]=true;
		while(!q.empty()){
			Edge t = q.front();
				     q.pop();
				
				    
				while(!array[t.src].empty()){
					Edge u = array[t.src].back();
							array[t.src].pop_back();
					 
					if(d[u.dest]==-1){
						d[u.dest]=d[u.src]+6;
						q.push(u);
						//visited[u.dest]=true;
					}
						
				}
			
				
		}
			
		
	}
	void PrintAns(int c){
		int i; for(i=1;i<=no_vertex;i++){
            if(i!=c)
			cout<<d[i]<<" ";
		}
	}
			
};


int main (){
	int t;
    cin>>t;
    while(t--){
	int a,b;
	cin>>a>>b;
	Graph g(a,b);
	g.AddEdge();
	int c;
	cin>>c;
	g.bfs_sortestPath(c);
	g.PrintAns(c);
	 cout<<"\n";
    }
   
	
}

