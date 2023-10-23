#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
typedef struct mes
{
	int state;
	int where_attack;
	int parent_pid;
	int child_pid;
	int fin;
}storage;
int main(int argc,char** argv)
{
	int shm_fd = shm_open("share_memory",O_CREAT|O_RDWR,
	S_IRUSR|S_IWUSR);
	size_t len=sizeof(storage);
	ftruncate(shm_fd,len);
	storage* mes;
	mes=(storage*)mmap(0,sizeof(storage),
	PROT_READ|PROT_WRITE,MAP_SHARED,shm_fd,0);
	mes->state = 0;
	mes->fin=0;
	mes->where_attack=0;
	if(argv[3][0]=='0')
	{
		pid_t how = fork();
		if(how>0)
		{
			int seed = atoi(argv[1]);
			srand(seed);
			int first = rand()%16;
			int second = rand()%16;
			int bomb_place[16]={0};
			int attack_times=0;
			int hit_times=0;
			mes->parent_pid=getpid();
			while(abs(first-second)!=4&&!(first-second==1&&first%4==0)&&!(first-second==1&&first%4==1))
				second= rand()%16;
			while(mes->fin==0)
			{
				if(mes->state==1)
				{
				
					printf("[%d Parents]: Random Seed %d\n",mes->parent_pid,seed);
					printf("[%d Parents]: The gunboat (%d,%d),(%d,%d)\n",mes->parent_pid,first/4,first%4,second/4,second%4);
					mes->state=2;
				}
				if(mes->state==3)
				{
					if(mes->where_attack==first||mes->where_attack==second)
					{
						hit_times++;
						if(hit_times==2)
						{
							printf("[%d Parent]: hit and sinking\n",mes->parent_pid);
							printf("[%d Parent]: %d wins with %d bombs\n",mes->parent_pid,mes->child_pid,attack_times);
							mes->fin=1;
						}
						else
						{
							printf("[%d Parent]: hit \n",mes->parent_pid);
						}
					}
					if(hit_times!=2)
					{
						int bomb = rand()%16;
						while(bomb_place[bomb]==1)
						{
							bomb=rand()%16;
						}
						bomb_place[bomb]=1;
						mes->where_attack=bomb;
						attack_times++;
						printf("[%d Parent]: bombing (%d,%d)\n",mes->parent_pid,bomb/4,bomb%4);
						mes->state=4;
					}
				}
			}
		}
		else
		{
			int seed = atoi(argv[2]);
			srand(seed);
			int first = rand()%16;
			int second = rand()%16;
			int bomb_place[16]={0};
			int attack_times=0;
			mes->child_pid=getpid();
			int hit_times=0;
			while(abs(first-second)!=4&&!(first-second==1&&first%4==0)&&!(first-second==1&&first%4==1))
				second= rand()%16;
			mes->state=1;
			while(mes->fin==0)
			{
				if(mes->state==2)
				{
					printf("[%d Chlid]: Random Seed %d\n",mes->child_pid,seed);
					printf("[%d Child]: The gunboat (%d,%d),(%d,%d)\n",mes->child_pid,first/4,first%4,second/4,second%4);
					mes->state=3;
				}
				if(mes->state==4)
				{
					if(mes->where_attack==first||mes->where_attack==second)
					{
						hit_times++;
						if(hit_times==2)
						{
							printf("[%d Child]: hit and sinking\n",mes->child_pid);
							printf("[%d Child]: %d wins with %d bombs\n",mes->child_pid,mes->parent_pid,attack_times);
							mes->fin=1;
						}
						else
						{
							printf("[%d Child]: hit \n",mes->child_pid);
						}
					}
					if(hit_times!=2)
					{
						int bomb = rand()%16;
						while(bomb_place[bomb]==1)
						{
							bomb=rand()%16;
						}
						bomb_place[bomb]=1;
						mes->where_attack=bomb;
						attack_times++;
						printf("[%d Child]: bombing (%d,%d)\n",mes->child_pid,bomb/4,bomb%4);
						mes->state=3;
					}
				}
			}
		}
	}
}
