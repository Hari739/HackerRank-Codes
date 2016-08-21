#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
struct node{
    int vertexNum;
    node* next;
};

struct vertex{
    node* head;
};
class Graph{
private:	
	int numOfVertex;
	vertex * v ;
public:
	Graph(int n){
		numOfVertex =n;
		v = new vertex [numOfVertex];
		int i=numOfVertex;
		while(i){
			//v[i].head->vertexNum = i;
			v[i].head=NULL;
		 i--;
		}
	}
	
	void AddEdge(int , int);
	void PrintGraph();
	void bfs(int);
	node* NewNode(int );	
};
node* Graph:: NewNode(int x){
	node* temp = new node;
	temp->vertexNum=x;
	temp->next=NULL;
	return temp;
}
 void  Graph::AddEdge(int src,int des){

	node* source =NewNode(src);
	node *destination = NewNode(des);
	source->next=v[des].head;
	v[des].head= source;
	destination->next = v[src].head;
	v[src].head = destination;
	
}
void Graph :: PrintGraph(){
	int n = numOfVertex;
	int i;
	for(i=0;i<n;i++) {
		cout<<i<<"-->";
		node * curr;
		curr =v[i].head;
		while(curr){
			cout<<curr->vertexNum<<"-->";
			curr=curr->next;
		}
		cout<<"NULL"<<endl;
	}
}

void Graph :: bfs(int start){
   		queue<int> q ;
   		bool  visited[numOfVertex] = {false};
   		
   		cout<<start<<"->";
   		visited[start] = true;
   		q.push(start);
   		
   		while(!q.empty()){
   			int u = q.front();
   				    q.pop();
   			node *curr =new node;
			   	  
				for(curr = v[u].head;curr;curr= curr->next)	{
					if(!visited[curr->vertexNum])
					cout<<curr->vertexNum<<"->";
					visited[curr->vertexNum]=true;
					q.push(curr->vertexNum);
				}    	
   			
		   }
   		
   		
   		
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
	Graph g(5);
	g.AddEdge(0,1);
	g.AddEdge(0,4);
	g.AddEdge(1,2);
	g.AddEdge(1,3);
	g.AddEdge(1,4);
	g.AddEdge(2,3);
	g.AddEdge(3,4);
	g.PrintGraph();
	g.bfs(2);
	return 0;
}

