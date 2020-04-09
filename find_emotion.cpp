#include<bits/stdc++.h>
#include <string.h> 
using namespace std;

int main()
{
	#ifndef naveen
		freopen("senti_1.txt","r",stdin);
		freopen("cleaned_sentiwords.txt","w",stdout);
	#endif
		string str;
		double pos,neg;

		unordered_set<char> alphabets;
		alphabets.insert('a');alphabets.insert('b');alphabets.insert('c');alphabets.insert('d');
		alphabets.insert('e');alphabets.insert('f');alphabets.insert('g');alphabets.insert('h');
		alphabets.insert('l');alphabets.insert('k');alphabets.insert('j');alphabets.insert('i');
		alphabets.insert('m');alphabets.insert('n');alphabets.insert('o');alphabets.insert('p');
		alphabets.insert('t');alphabets.insert('s');alphabets.insert('r');alphabets.insert('q');
		alphabets.insert('u');alphabets.insert('v');alphabets.insert('w');alphabets.insert('x');
		alphabets.insert('y');alphabets.insert('z');alphabets.insert('_');alphabets.insert('-');

	
	vector<double> positive_emotion;
	vector<double> negative_emotion;
	vector<string> emotional_word;
	int sample=30;
	while(cin>>pos)
	{
		cin>>neg;
		getline(cin,str);
		//cout<<str<<endl;
		string temp_string="";
		for(int i=0;i<str.length();i++)
		{
			if(alphabets.find(str[i])!=alphabets.end())
			{
				temp_string+=str[i];
			}
			if(str[i]=='#')
			{
				positive_emotion.push_back(pos);
				negative_emotion.push_back(neg);
				emotional_word.push_back(temp_string);
				//cout<<"pushed  ->"<<temp_string<<endl;
				temp_string="";
			}
		}
	}
	for(int i=0;i<positive_emotion.size();i++)
	{
		cout<<positive_emotion[i]<<" "<<negative_emotion[i]<<" "<<emotional_word[i]<<endl;
	}
	return 0;
}