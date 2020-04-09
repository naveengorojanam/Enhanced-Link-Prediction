#include<bits/stdc++.h>
using namespace std;

void common_neighbours(vector<int> communities, vector<vector<int>> graph, int vertices)
{	
	priority_queue<int> res;
	vector<int> score;
	vector<int> source;
	vector<int> destination;
	for(int i=0;i<communities.size();i++)
	{
		for(int j=i+1;j<communities.size();j++)
		{

			if(graph[communities[i]][communities[j]]==0)
			{
				int count=0;
				for(int k=0;k<communities.size();k++)
				{
					if(graph[communities[i]][communities[k]] + graph[communities[j]][communities[k]]==2)
						count++;
				}
				//cout<<"Score for edge possibility b/w "<<communities[i]<<" and "<<communities[j]<<" is "<<count<<endl;
				res.push(count);
				score.push_back(count);
				source.push_back(communities[i]);
				destination.push_back(communities[j]);
			}
		}
	}
	cout<<"displaying the results in descending order"<<endl;
	while(res.empty()==false)
	{
		int x=res.top();
		for(int i=0;i<score.size();i++)
		{
			if(score[i]==x)
			{
				cout<<"Edge b/w "<<source[i]<<"  and "<<destination[i]<<" score: "<<x<<endl;
				score[i]=-1;
			}	
		}
		res.pop();
	}


	cout<<endl;
}


void jaccard_coefficient(vector<int> communities, vector<vector<int>> graph, int vertices)
{	
	priority_queue<float> res;
	vector<float> score;
	vector<int> source;
	vector<int> destination;
	for(int i=0;i<communities.size();i++)
	{
		for(int j=i+1;j<communities.size();j++)
		{

			if(graph[communities[i]][communities[j]]==0)
			{
				float count=0,by=0;
				for(int k=0;k<communities.size();k++)
				{
					if(graph[communities[i]][communities[k]] + graph[communities[j]][communities[k]]==2)
						count++;
					if(graph[communities[i]][communities[k]]==1 || graph[communities[j]][communities[k]]==1)
						by+=1;
				}
				//cout<<"Score for edge possibility b/w "<<communities[i]<<" and "<<communities[j]<<" is "<<count<<endl;
				//cout<<"count is "<<count<<" & by is "<<by<<endl;
				count/=by;
				res.push(count);
				score.push_back(count);
				source.push_back(communities[i]);
				destination.push_back(communities[j]);
			}
		}
	}
	cout<<"displaying the results in descending order"<<endl;
	while(res.empty()==false)
	{
		int x=res.top();
		for(int i=0;i<score.size();i++)
		{
			if(score[i]==x)
			{
				cout<<"Edge b/w "<<source[i]<<"  and "<<destination[i]<<" score: "<<x<<endl;
				score[i]=-1;
			}	
		}
		res.pop();
	}


	cout<<endl;
}

int main()
{
	#ifndef naveen
		freopen("zachary_type1.txt","r",stdin);
		//freopen("output.txt","w",stdout);
	#endif

		int vertices;
		cin>>vertices;
		int graph[vertices][vertices];
		for(int i=0;i<vertices;i++)
			for(int j=0;j<vertices;j++)
				graph[i][j]=0;
		int edges,source,destination;
		cin>>edges;
		for(int i=0;i<edges;i++)
		{
			cin>>source>>destination;
			graph[source][destination]=1;
			graph[destination][source]=1;
		}
		vector<vector<int>> graphvector;
		for(int i=0;i<vertices;i++)
		{
			vector<int> temp;
			for(int j=0;j<vertices;j++)
			{
				temp.push_back(graph[i][j]);
			}
			graphvector.push_back(temp);
		}
		//This part contains the communities created by the Girvan Newman Algorithm [cmty.py]
	vector<vector<int>> communities = {{1, 2, 4, 8, 12, 13, 14, 18, 20, 22}, {32, 3, 25, 26, 28, 29}, {5, 6, 7, 11, 17}, {33, 34, 9, 15, 16, 19, 21, 23, 24, 27, 30, 31}, {10}};
	//vector<vector<int>> communities = {{1,2,3,4},{5,6,7,8}};
	cout<<"Generating Link Predictions based on common_neighbours "<<endl<<endl;	
	for(int i=0;i<communities.size();i++)
	{
		cout<<"Calculating for the Community "<<i+1<<endl;
		common_neighbours(communities[i],graphvector,vertices);
		//jaccard_coefficient(communities[i],graphvector,vertices);
		cout<<endl<<endl;
	}


	cout<<"Generating Link Predictions based on jaccard_coefficient"<<endl<<endl;
	for(int i=0;i<communities.size();i++)
	{
		cout<<"Calculating for the Community "<<i+1<<endl;
		//common_neighbours(communities[i],graphvector,vertices);
		jaccard_coefficient(communities[i],graphvector,vertices);
		cout<<endl<<endl;
	}
	return 0;
}