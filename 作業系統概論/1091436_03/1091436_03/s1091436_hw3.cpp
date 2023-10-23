#include <iostream>
#include <pthread.h>
#include <mutex>
using namespace std;
struct producer
{
	int num[3]={0};
	int id=0;
	int ptime=0;
};
struct dispatcher
{
	int time[3]={0};
	int id=0;
};
int item[3]={0};
int times=0; 
string equip[3]={"battery","aircraft","propeller"};
int equi;
int mode=1;
int mode2;
bool finish=true;
producer workers[3];
dispatcher disp[2];
pthread_mutex_t work_mutex;
pthread_mutex_t dis_mutex;
void *work(void* works)
{
	producer*worker = (producer*)works;
	if(worker->id==1)
	{
		worker->num[1]=1;
	}
	while(times<50)
	{
		if(!pthread_mutex_trylock(&work_mutex))
		{
			if(mode==0)
			{
				finish=false;
				if(worker->num[equi]==0&&!(worker->id==1&&equi==1))
				{
					item[equi]=0;
					if(worker->id==1)
					{
						cout<<"Producer 1 (aircraft): get "<<equip[equi]<<endl;
					}
					else
					{
						cout<<"Producer "<<worker->id<<": get "<<equip[equi]<<endl;
					}
					worker->num[equi]=1;
					finish=true;
				}
				if(worker->num[0]==1&&worker->num[1]==1&&worker->num[2]==1)
				{
					times++;
					worker->ptime++;
					if(worker->id==1)
					{
						cout<<"Producer 1 (aircraft): OK, "<<worker->ptime<<" drone(s)\n";
						worker->num[0]=0;
						worker->num[2]=0;
					}
					else
					{
						cout<<"Producer "<<worker->id<<": OK, "<<worker->ptime<<" drone(s)\n";
						worker->num[0]=0;
						worker->num[1]=0;
						worker->num[2]=0;
					}
					finish=true;
				}
				if(finish)
				{
					mode=1;
				}
			}
			pthread_mutex_unlock(&work_mutex);
		}
	}
	return 0;
}
void* dis(void* n)
{
	dispatcher* dispa=(dispatcher*)n;
	while(times<50)
	{
		if(!pthread_mutex_trylock(&dis_mutex))
		{
			if(mode==1&&times<50)
			{
				finish=false;
				if(mode2==0)
				{
					equi=rand()%3;
					while((equi==1&&workers[1].num[1]==1&&workers[2].num[1]==1)||(equi==0&&workers[0].num[0]==1&&workers[1].num[0]==1&&workers[2].num[0]==1)
					||(equi==2&&workers[0].num[2]==1&&workers[1].num[2]==1&&workers[2].num[2]==1)||	item[equi]==1)
					{
						equi=rand()%3;
					}
					item[equi]=1;
					dispa->time[equi]++;
					cout<<"Dispatcher: "<<equip[equi]<<endl;
					finish=true;
				}
				else
				{
					if(dispa->id==1&&!(workers[0].num[0]==1&&workers[0].num[1]==1&&
					workers[1].num[0]==1&&workers[1].num[1]==1
					&&workers[2].num[0]==1&&workers[2].num[1]==1))
					{
						equi=rand()%2;
						while((equi==1&&workers[1].num[1]==1&&workers[2].num[1]==1)||
						(equi==0&&workers[0].num[0]==1&&workers[1].num[0]==1&&workers[2].num[0]==1)||item[equi]==1)
						{
							equi=rand()%2+0;
						}
						item[equi]=1;
						dispa->time[equi]++;
						cout<<"Dispatcher "<<dispa->id<<": "<<equip[equi]<<endl;
						finish=true;
					}
					else if(dispa->id==2&&!(workers[0].num[1]==1&&workers[0].num[2]==1&&
					workers[1].num[1]==1&&workers[1].num[2]==1&&workers[2].num[2]==1
					&&workers[2].num[2]==1))
					{
						equi=rand()%2+1;
						while((equi==1&&workers[1].num[1]==1&&workers[2].num[1]==1)||(equi==2&&workers[0].num[2]==1&&workers[1].num[2]==1&&workers[2].num[2]==1)||
						item[equi]==1)
						{
							equi=rand()%2+1;	
						}
						item[equi]=1;
						dispa->time[equi]++;
						cout<<"Dispatcher "<<dispa->id<<": "<<equip[equi]<<endl;
						finish=true;
					}
				}		
				if(finish)
					mode=0;
			}
			pthread_mutex_unlock(&dis_mutex);
		}
	}
	return 0;
}
int main(int argc,char** argv)
{
	int seed=atoi(argv[2]);
	mode2=atoi(argv[1]);
	if(mode2==0||mode2==1)
	{
		if(seed>100||seed<0)
		{
			cout<<"輸入錯誤！\n";
			return 0;
		}
		srand(seed);
		pthread_mutex_init(&work_mutex,NULL);
		pthread_mutex_init(&dis_mutex,NULL);
		pthread_t dispatch[2];
		pthread_t worker[3];
		for(int i=0;i<=mode2;i++)
		{
			disp[i].id=i+1;
			pthread_create(&dispatch[i],NULL,dis,(void*)&disp[i]);
		}
		for(int i=0;i<3;i++)
		{
			workers[i].id=i+1;
			pthread_create(&worker[i],NULL,work,(void*)&workers[i]);
		}
		for(int i=0;i<3;i++)
		{
			pthread_join(worker[i],NULL);
		}
		for(int i=0;i<=mode2;i++)
		{
			pthread_join(dispatch[i],NULL);
		}
		if(mode2==0)
		{
			cout<<"Dispatcher 總共準備：\n";
			for(int i=0;i<3;i++)
			{
				cout<<equip[i]<<" : "<<disp[0].time[i]<<endl;
			}
		}
		else
		{
			cout<<"Dispatcher 1 總共準備：\n";
			for(int i=0;i<3;i++)
			{
				cout<<equip[i]<<" : "<<disp[0].time[i]<<endl;
			}
			cout<<"Dispatcher 2總共準備：\n";
			for(int i=0;i<3;i++)
			{
				cout<<equip[i]<<" : "<<disp[1].time[i]<<endl;
			}
		}
		for(int i=0;i<3;i++)
		{
			for(int j=i+1;j<3;j++)
			{
				if(workers[i].ptime<workers[j].ptime)
				{
					producer tem=workers[i];
					workers[i]=workers[j];
					workers[j]=tem;
				}
			}
			cout<<"Producer "<<workers[i].id<<": 總共生產"<<workers[i].ptime<<"台"<<endl;
		}
		pthread_mutex_destroy(&work_mutex);
		pthread_mutex_destroy(&dis_mutex);
	}
	else
	{
		cout<<"輸入錯誤！\n";
	}
}
