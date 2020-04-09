#include<bits/stdc++.h>
using namespace std;

int main()
{
	#ifndef naveen
	freopen("india_graph.txt","w",stdout);
	#endif

	srand(time(0));
	int nodes=5;
	int edges=6;

	int temp=edges;
	int graph[nodes][nodes]={0};
	//adding zeros in graph
	for(int i=0;i<nodes;i++)
	{
		for(int j=0;j<nodes;j++)
		{
			graph[i][j]=0;
		}
		
	}
	int min_eges=nodes;
	temp-=nodes;
	int node_val=0;
	while(min_eges>0)//here we create atleast one edge
	{
		int one=rand()%nodes;
		if(one!=node_val &&graph[node_val][one]!=1)
		{
		graph[node_val][one]=1;
		graph[one][node_val]=1;
		//cout<<"edge between "<<node_val<<"  "<<one<<endl;
		min_eges--;
		node_val++;	
		}
		
	}

//cout<<"temp value is "<<temp<<endl;
	while(temp>0)
	{
		int one=rand()%nodes;
		int two=rand()%nodes;
		//cout<<one<<" "<<two<<endl;
		if(graph[one][two]!=1&& one!=two)
		{
			graph[one][two]=1;
			graph[two][one]=1;
			temp--;	
		}
	}
	cout<<nodes<<endl;
	cout<<edges<<endl;
	for(int i=0;i<nodes;i++)
	{
		for(int j=0;j<nodes;j++)
		{
			if(graph[i][j]==1)
			{
				cout<<i<<" "<<j<<endl;
				graph[j][i]=0;
			}
		}
	}

	return 0;
}