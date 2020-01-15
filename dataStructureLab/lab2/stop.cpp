#include<stdio.h>
#include<stdlib.h>

struct car{
	char station;		 //A 进入，D  离开
	int number;			 //车牌号 
	int time;			//进入时间 
}message[100];

struct park{
	int Enter;
	int Plate;
}Park[100];

struct street{
	int enter;
	int plate;
}Street[100];

int check(struct park *A,int I)
{
	int i=0;
	while(I!=A[i].Plate)
		i++;
	return i;
}


int main()
{
	int i,j,k,test;
	i=j=k=test=0;
	
	int park_size;
	printf("请输入停车场车位个数：\n");
	scanf("%d",&park_size);
	printf("请依次输入数据：\n");
	while(1)
	{
		scanf("%c%d%d",&message[i].station,&message[i].number,&message[i].time);
		if(message[i].station=='E'&&message[i].number==0&&message[i].time==0)
			break;
		i++;
	}
	//输入数据 
	
	int message_size=i;
	int wait_time,cur_number,Head;
	wait_time=cur_number=Head=0;
	i=j=k=test=0;
	while(i<message_size) 
	{
		if(message[i].station=='A')
		{
			if(park_size!=cur_number)
			{
				Park[j].Plate=message[i].number;
				Park[j].Enter=message[i].time;
				j++;
				cur_number++;
			}
			else
			{
				Street[k].enter=message[i].time;
				Street[k].plate=message[i].number;
				k++;
			}
		}
		if(message[i].station=='D')
		{
			//少考虑如果停车场车位未满就有车离开的情况！！！ 
			test=check(Park,message[i].number);
			wait_time=message[i].time-Park[test].Enter;
			printf("车牌号：%d，停留时间：%d\n",message[i].number,wait_time);
			Park[test].Plate=Street[Head].plate;
			if(Street[Head].enter>(Park[test].Enter+wait_time))
				Park[test].Enter=Street[Head].enter;
			else
				Park[test].Enter +=wait_time;
			Head++;
		}
			
		i++;
	}
	//遍历message处理数据
	 
	return 0;
}
