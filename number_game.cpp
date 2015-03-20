#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<iomanip>
#include<conio.h>
using namespace std;
int a[4][4],i,j,k,m=0,flag=1,i1,j1,f;
void move(char s)
{
	if(s==72)
	{
		if(i1!=3)
		{
			a[i1][j1]=a[i1+1][j1];
			a[i1+1][j1]=0;
			i1++;
			m++;
		}
	}
	else if(s==75)
	{
		if(j1!=3)
		{
			a[i1][j1]=a[i1][j1+1];
			a[i1][j1+1]=0;
			j1++;
			m++;
		}
	}
	else if(s==77)
	{
		if(j1!=0)
		{
			a[i1][j1]=a[i1][j1-1];
			a[i1][j1-1]=0;
			j1--;
			m++;
		}
	}
	else if(s==80)
	{
		if(i1!=0)
		{
			a[i1][j1]=a[i1-1][j1];
			a[i1-1][j1]=0;
			i1--;
			m++;
		}
	}	
}
int main()
{
	char s;
	unsigned int s1;
    time_t t;
    s1=(unsigned)time(&t);
    srand(s1);
    for(i=0;i<4;i++)
    {
    	for(j=0;j<4;j++)
    		a[i][j]=i*4+j+1;
	}
	a[3][3]=0;
	i1=j1=3;
	for(i=1;i<=1000;i++)
	{
		char c;
		k=rand()%4;
		if(k==0)
			c=72;
		else if(k==1)
			c=75;
		else if(k==2)
			c=77;
		else
			c=80;
		move(c);
	}
	m=0;
	while(flag)
	{
		system("cls");
		cout<<"MOVES: "<<m;
	 	cout<<"\t\t\t\t\t\tPress esc to exit!!\n";
		for(i=0;i<8;i++)
			cout<<"\n";
		for(i=0;i<4;i++)
		{
		    cout<<setw(30);
		    for(j=0;j<4;j++)
		    {
			    if(a[i][j]==0)
					cout<<" "<<setw(8);
			    else
					cout<<a[i][j]<<setw(8);
			}
			cout<<"\n\n";
		}
		f=1;
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				if(i==3&&j==3&&a[i][j]==0)
					break;
				if(a[i][j]!=i*4+j+1)
				{
					f=0;
					break;
				}
			}
			if(!f)
				break;
		}
		if(f==1)
		{
			cout<<"\n\t\t\t\tYou Win!!!\n\n\n";
			flag=0;
			break;
		}
		s=getch();
		if(s==27)
		{
			flag=0;
		}
		else if(s==72||s==75||s==77||s==80)
		{
			move(s);
		}
	}
	cout<<"\t\t\t\t\tGAME OVER!!!";
}
