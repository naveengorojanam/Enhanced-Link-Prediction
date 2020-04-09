#include<bits/stdc++.h>
using namespace std;

vector<double> positive_emotion;
vector<double> negative_emotion;
vector<string> sentiword;

int main()
{
	#ifndef naveen
	freopen("testing.txt","r",stdin);
	freopen("India_sentiment.txt","w",stdout);
	#endif


		double reader1,reader2;
		string reader3;
		long nn=206941;
		while(nn--)
		{
			cin>>reader1>>reader2>>reader3;
			positive_emotion.push_back(reader1);
			negative_emotion.push_back(reader2);
			sentiword.push_back(reader3);
		}

		unordered_set<char> alphabets;
		alphabets.insert('a');alphabets.insert('b');alphabets.insert('c');alphabets.insert('d');
		alphabets.insert('e');alphabets.insert('f');alphabets.insert('g');alphabets.insert('h');
		alphabets.insert('l');alphabets.insert('k');alphabets.insert('j');alphabets.insert('i');
		alphabets.insert('m');alphabets.insert('n');alphabets.insert('o');alphabets.insert('p');
		alphabets.insert('t');alphabets.insert('s');alphabets.insert('r');alphabets.insert('q');
		alphabets.insert('u');alphabets.insert('v');alphabets.insert('w');alphabets.insert('x');
		alphabets.insert('y');alphabets.insert('z');alphabets.insert('_');alphabets.insert('-');

		int n=0;
		string str;
		while(getline(cin,str))
		{	n++;
			//convert the read string to small letters

			for(int i=0;i<str.length();i++)
			{
				if(str[i]=='A')str[i]='a';else if(str[i]=='B')str[i]='b';else if(str[i]=='C')str[i]='c';
				else if(str[i]=='D')str[i]='d';else if(str[i]=='E')str[i]='e';else if(str[i]=='F')str[i]='f';
				else if(str[i]=='G')str[i]='g';else if(str[i]=='H')str[i]='h';else if(str[i]=='I')str[i]='i';
				else if(str[i]=='J')str[i]='j';else if(str[i]=='K')str[i]='k';else if(str[i]=='L')str[i]='l';
				else if(str[i]=='M')str[i]='m';else if(str[i]=='N')str[i]='n';else if(str[i]=='O')str[i]='o';
				else if(str[i]=='P')str[i]='p';else if(str[i]=='Q')str[i]='q';else if(str[i]=='R')str[i]='r';
				else if(str[i]=='S')str[i]='s';else if(str[i]=='T')str[i]='t';else if(str[i]=='U')str[i]='u';
				else if(str[i]=='V')str[i]='v';else if(str[i]=='W')str[i]='w';else if(str[i]=='X')str[i]='x';
				else if(str[i]=='Y')str[i]='y';else if(str[i]=='Z')str[i]='z';			
			}
			string cleaned_str;
			for(int i=0;i<str.length();i++)
			{
				if(alphabets.find(str[i])!=alphabets.end())
					cleaned_str+=str[i];
				else
					cleaned_str+=" ";
			}

			//creating vecctor of strings from the tweet
			//cout<<cleaned_str<<endl;
			vector<string> words_in_sentence;
			string temp="";
			for(int i=0;i<cleaned_str.length();i++)
			{
				if(alphabets.find(cleaned_str[i])==alphabets.end() && temp.length()>0)
				{
					words_in_sentence.push_back(temp);
					temp="";
				}
				else if(alphabets.find(cleaned_str[i])!=alphabets.end())
				{
					temp+=cleaned_str[i];
				}
			}
		/*	cout<<" number of words "<<words_in_sentence.size()<<endl;
			for(int i=0;i<words_in_sentence.size();i++)
				cout<<words_in_sentence[i]<<endl;

		*/
			//sentiment calculations
			double positive=0.0,negative=0.0;
			double matchcount=0.0;
			double wordmatch=0.0;
			for(int i=0;i<words_in_sentence.size();i++)
			{
				double temppos=0.0,tempneg=0.0;
				bool singleword=false;
				int count=0;
				for(int j=0;j<sentiword.size();j++)
				{	
					if(words_in_sentence[i]==sentiword[j])
					{
						singleword=true;
						//cout<<"matched word "<<sentiword[j]<<endl;
						matchcount+=1;
						count+=1;
						temppos+=positive_emotion[j];
						tempneg+=negative_emotion[j];
					}

				}
				//cout<<"count is "<<count<<endl;
				if(count!=0){
					//cout<<"count is "<<count<<endl;
				positive+=(temppos)/count;
				negative+=(tempneg)/count;	
				wordmatch+=1;
				}
				
			}


			//cout<<"total word match "<<wordmatch<<endl;
			positive/=wordmatch;
			negative/=wordmatch;
			//cout<<"positive emotion is "<<positive<<endl;
			//cout<<"negative emotions is "<<negative<<endl;
			//negative*=-1;
			double emotionvalue;
			if(positive>negative)
			{
				emotionvalue=positive-negative;
			}
			else
			{
				emotionvalue=(-1*negative)+positive;
			}
			if(words_in_sentence.size()>0)
				cout<<words_in_sentence[0]<<" "<<emotionvalue<<endl;

		}
		cout<<"operation performed on "<<n<<" string"<<endl;

	return 0;
}