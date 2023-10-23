#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <time.h>
using namespace std;
struct memory_word
{
	pid_t tid =0;
 	string id;
	vector<string> words;
	vector<int>	times;
	int self=0;
	double avgtime;
	int tidcheck=0;
};
vector<string> allword;
memory_word mem[50];
int word_size=0;
double alltime[50];
void *cal(void* m)
{
	clock_t start,finish;
	start=clock();
	memory_word *memo = (memory_word *)m;
	memo->tid=gettid();
	while(memo->tidcheck==0);
	pid_t pid=memo->tid;
	alltime[memo->self]=0;
	cout<<"[TID="<<pid<<"] DocID:"<<memo->id<<" [";
	for(int i=0;i<allword.size();i++)
	{
		int place;
		bool check=false;
		for(int j=0;j<memo->words.size();j++)
		{
			if(memo->words[j]==allword[i])
			{
				check=true;
				place=j;
			}
		}
		if(check)
		{
			cout<<memo->times[place];
		}
		else
		{
			cout<<"0";
		}
		if(i<allword.size()-1)
		{
			cout<<",";
		}
		else
		{
			cout<<"]\n";
		}
	}
	for(int i=0;i<word_size;i++)
	{
		double cos,vsvx=0,vs2vx2=0,vs=0,vx=0;
		if(memo->self!=i)
		{
			for(int j=0;j<memo->words.size();j++)
			{
				for(int k=0;k<mem[i].words.size();k++)
				{
					if(memo->words[j]==mem[i].words[k])
					{
						vsvx+=memo->times[j]*mem[i].times[k];
					}
				}
			}
			for(int k=0;k<mem[i].times.size();k++)
			{
				vx+=mem[i].times[k]*mem[i].times[k];
			}
			for(int j=0;j<memo->times.size();j++)
			{
				vs+=memo->times[j]*memo->times[j];
			}
			vs2vx2=sqrt(vs)*sqrt(vx);
			cos=vsvx/vs2vx2;
			alltime[memo->self]+=cos;
			cout<<"[TID="<<pid<<"] "<<"cosine("<<memo->id<<","<<mem[i].id<<")="<<setprecision(4)<<cos<<endl;
		}
	}
	memo->avgtime=alltime[memo->self]/(word_size-1);
	cout<<"[TID="<<pid<<"] "<<"Avg_cosine: "<<memo->avgtime<<endl;
	cout<<"[TID="<<pid<<"] CPU time: "<<1000*(double(clock()-start))/CLOCKS_PER_SEC<<"ms\n";
	return 0;
}

int main(int argc,char** argv)
{
	clock_t start,finish;
	start=clock();
	fstream ff;
	ff.open(argv[1]);
	string str;
	int mode = 0;
	while(getline(ff,str))
	{
		int place=0;
		if(mode==0)
		{
			mem[word_size].id=str;
			mem[word_size].self=word_size;
			mode=1;
		}
		else if(mode==1)
		{
			bool check=true;
			bool checkall=true;
			int boo=true;
			for(int i=0;i<str.size();i++)
			{
				if(!(str[i]>='a'&&str[i]<='z')&&!(str[i]>='A'&&str[i]<='Z')&&!(str[i]>='0'&&str[i]<='9')&&place<str.size())
				{
					string word_tem=str.substr(place,i-place);
					for(int i=0;i<word_tem.size();i++)
					{
						if(word_tem[i]>='0'&&word_tem[i]<='9')
							boo=false;
					}
					place=i+1;
					if(boo)
					{
						for(int i=0;i<mem[word_size].words.size();i++)
						{
							if(mem[word_size].words[i]==word_tem)
							{
								mem[word_size].times[i]++;
								check=false;
							}
						}
						for(int i=0;i<allword.size();i++)
						{
							if(allword[i]==word_tem)
								checkall=false;
						}
						if(check)
						{
							mem[word_size].words.push_back(word_tem);
							mem[word_size].times.push_back(1);
						}
						if(checkall)
						{
							allword.push_back(word_tem);
						}
					}
					while(str[i+1]==' ')
					{
						i++;
						place++;
						
					}
					check=true;
					checkall=true;
					boo=true;
				}
			}
			check=true;
			checkall=true;
			boo=true;	
			string word_tem=str.substr(place,str.size()-place);
			if(word_tem.size()>0)
			{
				for(int i=0;i<word_tem.size();i++)
				{
					if(word_tem[i]>='0'&&word_tem[i]<='9')
								boo=false;
				}
				if(boo)
				{
					for(int i=0;i<mem[word_size].words.size();i++)
					{
						if(mem[word_size].words[i]==word_tem)
						{
							mem[word_size].times[i]++;
							check=false;
						}
					}
					for(int i=0;i<allword.size();i++)
					{
						if(allword[i]==word_tem)
							checkall=false;
					}
					if(check)
					{
						mem[word_size].words.push_back(word_tem);
						mem[word_size].times.push_back(1);
					}
					if(checkall)
					{
						allword.push_back(word_tem);
					}
				}
			}
			word_size++;
			mode=0;
		}
	}
	pthread_t t1[50];
	for(int i=0;i<word_size;i++)
	{
		pthread_create(&t1[i],NULL,cal,(void*)&mem[i]);
		while(mem[i].tid==0);
		cout<<"[Main thread]: create TID:"<<mem[i].tid<<", DocID:"<<mem[i].id<<endl;
		mem[i].tidcheck=1;
	}
	for (int i = 0; i < word_size; i++)
  		pthread_join(t1[i],NULL);
	double answer=0;
	int answer2=0;
	int number1=0;
	int number2=0;
	for (int i = 0; i < word_size; i++)
	{
		number1=0;
		for(int j=0;j<mem[i].id.size();j++)
		{
			if(mem[i].id[j]>='0'&&mem[i].id[j]<='9')
			{
				number1*=10;
				number1+=mem[i].id[j]-48;
			}
		}
		if(i==0)
			number2=number1;
		if(answer<=mem[i].avgtime)
		{
			if(answer==mem[i].avgtime)
			{
				if(number1<number2)
				{
					answer=mem[i].avgtime;
					answer2=i;
					number2=number1;
				}
			}
			else
			{
				answer=mem[i].avgtime;
				answer2=i;
				number2=number1;
			}
		}
	  }
	cout<<"[Main thread] KeyDocID:"<<mem[answer2].id<<" Highest Average Cosine:"<<answer<<endl;
	cout<<"[Main thread] CPU time:"<<1000*(double(clock()-start))/CLOCKS_PER_SEC<<"ms\n";
}
