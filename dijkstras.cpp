# include<bits/stdc++.h>
# include <algorithm>
# define inf 1000000000;
using namespace std;

struct  vertex{
	int v;
	int w;
};
struct  compare
{
	bool operator ()(vertex &a , vertex &b){
		return (a.w>b.w);
	}
			
};

class Graph{
	public :
	 int no_vertex;
	 vector <vertex> *adj;
	 int *dist ;
	 
	 Graph(int x){
	 	
	 	no_vertex = x;
	 	adj = new vector <vertex>[no_vertex];
	 	dist = new int  [no_vertex];
	 	int i;
	 	for(i=0;i<no_vertex;i++)
	 		dist[i]=inf;
	 		
	 	
	 }
	 void AddEdge(int s ,int d ,int wt){
	 	
	 	vertex vr  ;
		 vr.v=d;
		 vr.w= wt;
		 adj[s].push_back(vr); 
		 vr.v=s;
		 vr.w=wt;
		 adj[d].push_back(vr);
		
	 }
	 priority_queue <vertex, vector <vertex>,compare > pq;
	 void Dijkstra(int start){
	 	vertex s ;
	 	s.v=start;
	 	s.w= 0;
	 	pq.push(s);
	 	dist[start]=0;
	 	while(!pq.empty()){
	 		vertex u = pq.top();
			pq.pop();
			vertex temp ;
			
	 		
	 		while(!adj[u.v].empty()){
			 		temp =adj[u.v].back();
			 		adj[u.v].pop_back();
			 	//	cout<<"ghh\n";
	 			if(dist[temp.v]>dist[u.v]+temp.w){
	 				dist[temp.v]=dist[u.v]+temp.w;
	 				temp.w=dist[temp.v];
	 				pq.push(temp);
	 				
				 }
			 }
	 		
		 }	
	 }
	 void print(){
	 	int i;
	 	for(i=0;i<no_vertex;i++)
	 		cout<<i<<"->"<<dist[i]<<endl;
	 	
	 }
};


int main(){
	
	int a,b,t;
	cin>>t;
	while(t--){
	
	//cout<<"no of vertices && edge please:";
	cin>>a>>b;
	Graph g(a);
	int i,x,y,w;
	for(i=0;i<b;i++){
		//cout<<"\nEnter edge->";
		cin>>x>>y>>w;
		g.AddEdge(x,y,w);
	}
	//cout<<"\nEnter start vertex->";
	cin>>x;
	g.Dijkstra(x);
	g.print();
}
}
