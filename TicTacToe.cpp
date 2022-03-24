#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

class tictactoe
{
	protected:
		char p1[20],p2[20],cp[20];
		char map[3][3];
		char winner[20],hw[20];
		int n,flag,status,count;
		int f[10];
		char item;
	
	public:
		void tictactoeSet()
		{
			status=count=flag=0;
			item=NULL;
			map[0][0]='1';
			map[0][1]='2';
			map[0][2]='3';
			map[1][0]='4';
			map[1][1]='5';
			map[1][2]='6';
			map[2][0]='7';
			map[2][1]='8';
			map[2][2]='9';
			for(int i=1;i<10;i++)
			{
				f[i]=0;
			}
		}
		void startgame()
		{
			tictactoeSet();
			system("cls");
			cout<<"\t\tTic Tac Toe\n";
			cout<<"\t\t-----------\n";
			cout<<"\nWelcome...\n";
			cout<<"Enter First Player Name:";
			cin>>p1;
			cout<<"Enter Second Player Name:";
			cin>>p2;
		}
		void drawmap()
		{
			int cnt=0;
			system("cls");
			cout<<"\t\tTic Tac Toe\n";
			cout<<"\t\t-----------\n";
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					cout<<map[i][j];
					if(j!=2)
					{
						cout<<" | ";
					}
				}
				cout<<endl;
				if(i!=2)
				{
					cout<<"---------\n";
				}
			}
			char temp;
			if(status==1)
			{
				cout<<"\n"<<hw<<"\n\n";
				cout<<"Congratulations...\n";
				cout<<cp<<" Is Winner...\n\n";
				cout<<"Want to play again(y/n):";
				temp=getch();
				if(temp=='y' || temp=='Y')
				{
					tictactoeSet();
					drawmap();
				}
				else if(temp=='n' || temp=='N')
				{
					exit(0);
				}
				else
				{
					cout<<"\nInvalid.";
					getch();
					exit(0);
				}
			}
			else if(status==2)
			{
				cout<<"\nit's Tie\n\n";
				cout<<"Want to play again(y/n):";
				temp=getch();
				if(temp=='y' || temp=='Y')
				{
					tictactoeSet();
					drawmap();
				}
				else if(temp=='n' || temp=='N')
				{
					exit(0);
				}
				else
				{
					cout<<"\nInvalid.";
					getch();
					exit(0);
				}
			}
		}
		void input()
		{
			if(flag==0)
			{
				strcpy(cp,p1);
				flag=1;
				item='X';
			}
			else if(flag==1)
			{
				strcpy(cp,p2);
				flag=0;
				item='O';
			}
			cout<<endl<<item;
			cout<<endl<<cp<<"'s Turn...\n";
			abc:	
			cout<<"Enter The Field Number:";
			cin>>n;
			if(n==1 && f[1]!=1)
			{
				map[0][0]=item;
				f[1]=1;
				count++;
			}
			else if(n==2 && f[2]!=1)
			{
				map[0][1]=item;
				f[2]=1;
				count++;
			}
			else if(n==3 && f[3]!=1)
			{
				map[0][2]=item;
				f[3]=1;
				count++;
			}
			else if(n==4 && f[4]!=1)
			{
				map[1][0]=item;
				f[4]=1;
				count++;
			}
			else if(n==5 && f[5]!=1)
			{
				map[1][1]=item;
				f[5]=1;
				count++;
			}
			else if(n==6 && f[6]!=1)
			{
				map[1][2]=item;
				f[6]=1;
				count++;
			}
			else if(n==7 && f[7]!=1)
			{
				map[2][0]=item;
				f[7]=1;
				count++;
			}
			else if(n==8 && f[8]!=1)
			{
				map[2][1]=item;
				f[8]=1;
				count++;
			}
			else if(n==9 && f[9]!=1)
			{
				map[2][2]=item;
				f[9]=1;
				count++;
			}
			else if(n==0)
			{
				char temp;
				cout<<"Play again(y/n):";
				temp=getch();
				if(temp=='y' || temp=='Y')
				{
					tictactoeSet();
					drawmap();
					input();
				}
				else if(temp=='n' || temp=='N')
				{
					exit(0);
				}
				else
				{
					cout<<"\nInvalid.";
					getch();
					exit(0);
				}
			}
			else
			{
				cout<<"\nInvalid Field Number or Field Is Already Used\n";
				goto abc;
			}
		}
		void check()
		{
			if(count==9)
			{
				status=2;
			}
			else if(map[0][0]==item && map[0][1]==item && map[0][2]==item)
			{
				strcpy(winner,cp);
				status=1;
				strcpy(hw,"row match");
			}
			else if(map[1][0]==item && map[1][1]==item && map[1][2]==item)
			{
				strcpy(winner,cp);
				status=1;
				strcpy(hw,"row match");
			}
			else if(map[2][0]==item && map[2][1]==item && map[2][2]==item)
			{
				strcpy(winner,cp);
				status=1;
				strcpy(hw,"row match");

			}
			else if(map[0][0]==item && map[1][0]==item && map[2][0]==item)
			{
				strcpy(winner,cp);
				status=1;
				strcpy(hw,"Column match");
			}
			else if(map[0][1]==item && map[1][1]==item && map[2][1]==item)
			{
				strcpy(winner,cp);
				status=1;
				strcpy(hw,"Column match");
			}
			else if(map[0][2]==item && map[1][2]==item && map[2][2]==item)
			{
				strcpy(winner,cp);
				status=1;
				strcpy(hw,"Column match");
			}
			else if(map[0][0]==item && map[1][1]==item && map[2][2]==item)
			{
				strcpy(winner,cp);
				status=1;
				strcpy(hw,"Cross match");
			}
			else if(map[0][2]==item && map[1][1]==item && map[2][0]==item)
			{
				strcpy(winner,cp);
				status=1;
				strcpy(hw,"Cross match");
			}
		}
};

int main()
{
	system("cls");
	tictactoe t;
	t.startgame();
	while(1)
	{
		t.drawmap();
		t.input();
		t.check();
	}
	return 0;
}
