#include <iostream>
#include<conio.h>//??
#include<windows.h>
using namespace  std;

bool gameover;
const int width=40;
const int height=20;
int x, y, fx, fy, score;
int tailx[100],taily[100],ntail=0;
enum eDirection { STOP=0, LEFT, RIGHT, UP, DOWN};//enum
eDirection dir;

void setup()
{	
	gameover=false;
	dir=STOP;
	x=width/2;
	y=height/2;
	fx=rand()%width;
	fy=rand()%height;
	score=0;
}

void draw()
{
	system("cls");//to clear screen
	for(int i=0;i<=width;i++)
		cout<<"#";
	cout<<endl;
	for(int j=0;j<height;j++)
	{
		for(int i=0;i<width;i++)
		{
			if(i==0 || i==width-1)
				cout<<"#";
			if(i==x && j==y)
				cout<<"0";
			else if(i==fx && j==fy)
				cout<<"f";
			else 
			{
				 bool print=false;
				 for(int k=0;k<ntail;k++)
				 {
				 	if(i==tailx[k] && j==taily[k])
				 		{
				 			print=true;
				 			cout<<"o";
				 		}
				 }
				 if(!print)
				cout<<" ";
			}
				
		}
		cout<<endl;
			
	}
	for(int i=0;i<=width;i++)
		cout<<"#";
	cout<<endl<<"Score:"<<score<<endl;
}

void input()
{
	if(_kbhit())//if key is press :1;
	{
		switch(_getch())
		{
			case 'a':
			dir=LEFT;
			break;
			case 'w':
			dir=UP;
			break;
			case 's':
			dir=DOWN;
			break;
			case 'd':
			dir=RIGHT;
			break;
			case 'x':
			gameover=true;
			break;
		}
	}
}

void logic()
{
	
	int px=tailx[0];
	int py=taily[0];
	tailx[0]=x;
	taily[0]=y;
	int p2x,p2y;
	for(int i=1;i<ntail;i++)
	{
		p2x=tailx[i];
		p2y=taily[i];

		tailx[i]=px;
		taily[i]=py;

		px=p2x;
		py=p2y;
	}
	
	switch(dir)
	{
		case LEFT:
		x--;
		break;
		case RIGHT:
		x++;
		break;
		case UP:
		y--;
		break;
		case DOWN:
		y++;
		break;
	}
	for(int i=0;i<ntail;i++)
	{
		if(x==tailx[i] && y==taily[i])
			gameover=true;
	}
	
	if(x<0 || x>=width-1 || y<0 || y>=height)
	{
		cout<<"YOU LOSE";
		gameover=true;
	}
	if(x==fx && y==fy){
		ntail++;
		score+=5;
		fx=rand()%width;
		fy=rand()%height;
	}
}

int main()
{
	int p;
	
	cout<<"w:UP    a:LEFT    d:right    s:DOWN     x:QUIT"<<endl<<"Press any key to play";
	
	cout << "There you go!";
	
	if(_getch())
	{
		
	setup();
	while(!gameover)
	{
		draw();
		input();
		logic();
//		Sleep(10);
	}
	
	}
	
	return 0;
}
