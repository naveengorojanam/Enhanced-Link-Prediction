#include<bits/stdc++.h>
using namespace std;

int main()
{
	#ifndef naveen
	freopen("Italy_sentiment.txt","r",stdin);
	#endif

	vector<double> emotions;
	unordered_set<int> s;
	vector<string> names;
	double emotion;
	string name;
	while(cin>>name>>emotion)
	{
		emotion*=1000;
		int temp=(int)emotion;
		//double temp2=temp/1000;
		//cout<<temp<<endl;
		emotions.push_back(temp);
		if(s.find(temp)==s.end())
		{
			s.insert(temp);
		}
	}
	vector<int> counts;
	for(auto it=s.begin();it!=s.end();it++)
	{
		int count=0;
		for(int j=0;j<emotions.size();j++)
		{
			if(*it==emotions[j])
				count++;
		}
		cout<<count<<" "<<*it<<endl;
		counts.push_back(count);
	}
	vector<int> xaxis;
	vector<int> ref;
	for(auto it=s.begin();it!=s.end();it++)
	{
		xaxis.push_back(*it);
		ref.push_back(*it);
	}	
	sort(xaxis.begin(),xaxis.end());
	for(int i=0;i<xaxis.size();i++)
	{
		for(int j=0;j<ref.size();j++)
		{
			if(xaxis[i]==ref[j])
			{
				cout<<counts[j]<<",";
			}
		}
	}
	cout<<endl;
	for(int i=0;i<xaxis.size();i++)
		cout<<xaxis[i]<<",";
	cout<<endl;


	return 0;
}