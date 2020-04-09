#include<bits/stdc++.h>
using namespace std;

int main()
{
	#ifndef naveen
	freopen("finaltest.txt","r",stdin);
	freopen("India_testlabels.txt","w",stdout);
	#endif
	vector<double> sentivalues;
	string names;
	double test;
	int scount;
	cin>>scount;
	while(scount--)
	{
		cin>>names>>test;
		sentivalues.push_back(test);
	}
	int community[scount];
	vector<int> temp_comm{172,68,46,38,19,12,9,5,4,4};
	int setter=0;
	for(int i=0;i<scount;i++)
	{
		if(temp_comm[setter]!=0)
		{
			community[i]=1;
			temp_comm[setter]-=1;
		}
		else
		{
			setter++;
			temp_comm[setter]-=1;
		}
	}

	int nodes;
	int edges;
	cin>>nodes>>edges;
	int graph[nodes][nodes];
	for(int i=0;i<nodes;i++)
		for(int j=0;j<nodes;j++)
			graph[i][j]=0;
	for(int i=0;i<edges;i++)
	{
		int source,destination;
		cin>>source>>destination;
		graph[source][destination]=1;
		graph[destination][source]=1;
	}
	vector<double> CN;
	vector<double> JAC;
	vector<double> PA;
	vector<double> SS;
	vector<double> SP;
	vector<double> TC;
	vector<int> label; 
	for(int i=0;i<nodes;i++)
	{
		for(int j=0;j<nodes;j++)
		{
			if(i!=j && graph[i][j]==0)	//no edge
			{
				graph[j][i]=-1;
				unordered_set<double> sour_neighbours;
				unordered_set<double> dest_neighbours;
				unordered_set<double> union_count;
				for(int k=0;k<nodes;k++)
				{
					if(graph[i][k]==1)
					{
						sour_neighbours.insert(k);
						union_count.insert(k);
					}
				}
				for(int k=0;k<nodes;k++)
				{
					if(graph[j][k]==1)
					{
						dest_neighbours.insert(k);
						if(union_count.find(k)==union_count.end())
							union_count.insert(k);
					}
				}
				double cnval=0;
				for(auto it=sour_neighbours.begin();it!=sour_neighbours.end();it++)
				{
					if(dest_neighbours.find(*it)!=dest_neighbours.end())
						cnval++;
				}
				CN.push_back(cnval);
				JAC.push_back(cnval/union_count.size());
				if((sentivalues[i]>0.00 && sentivalues[j]>0.00) || (sentivalues[i]>0.00 && sentivalues[j]>0.00)|| (sentivalues[i]==0.00 && sentivalues[j]==0.00))
					SP.push_back(1);
				else
					SP.push_back(-1);

				if(sentivalues[i]>0.00 && sentivalues[j]>0.00)
					SS.push_back(abs(sentivalues[i]-sentivalues[j]));
				else if(sentivalues[i]<0.00 && sentivalues[j]<0.00)
					SS.push_back(abs(sentivalues[i]-sentivalues[j]));
				else
					SS.push_back(0);
				if(community[i]==community[j])
					TC.push_back(1);
				else
					TC.push_back(-1);
				double pa_val=sour_neighbours.size()*dest_neighbours.size();
				PA.push_back(pa_val);

				if(TC[i]==1)
					label.push_back(1);
				else
					label.push_back(-1);

			}
		}
	}

/*	for(int i=0;i<CN.size();i++)
	{
		cout<<CN[i]<<" "<<JAC[i]<<" "<<PA[i]<<" "<<SP[i]<<" "<<SS[i]<<" "<<TC[i]<<" label "<<label[i]<<endl;
	}
*/
	//print the Training vectors
/*	for(int i=0;i<800;i++)
	{
		cout<<",["<<CN[i]<<","<<JAC[i]<<","<<PA[i]<<","<<SP[i]<<","<<SS[i]<<","<<TC[i]<<"]";
	}
*/	cout<<endl<<endl;
	//test data
//	for(int i=800;i<1000;i++)
//		cout<<",["<<CN[i]<<","<<JAC[i]<<","<<PA[i]<<","<<SP[i]<<","<<SS[i]<<","<<TC[i]<<"]";
	//print the result vectors
//	for(int i=0;i<800;i++)
//		cout<<label[i]<<",";

	for(int i=800;i<1000;i++)
		cout<<"["<<label[i]<<"]"<<endl;

	return 0;
}