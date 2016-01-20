#include<bits/stdc++.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
using namespace std;
typedef long long ll;
const ll dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
ll x=1,y=1,d=0,n;
string dir[4]={"RIGHT","DOWN","LEFT","UP"};
bool a[111][111],s;
char ch;
int main()
{
    cout<<"Enter size (1...30): ";
    cin>>n;
    cout<<"L or l - turn left\nR or r - turn right\nG X or g X - draw line of length X\nD or d - lower the pen\nU or u - pick up the pen\nQ or q - quit\n";
    system("pause");
    for(;;)
    {
        system("cls");
        cout<<"X:"<<x<<" Y:"<<y<<" "<<dir[d]<<"\n";
        for(ll i=0;i<=n+1;i++)
        {
            for(ll j=0;j<=n+1;j++)
                cout<<((!i||!j||i>n||j>n)?"# ":((i==y&&j==x)?(s?"O ":"o "):(a[i][j]?"* ":". ")));
            cout<<"\n";
        }
        ch=0;
        ch=getch();
        if(!ch)
        {
            cout<<"Error";
            return 0;
        }
        if(ch=='q')
        {
            system("color fc");
            cout<<"Are you sure? (y/n) ";
            char sure;
            cin>>sure;
            if(sure=='y'||sure=='Y')
                break;
            else
            {
                system("color 07");
                system("cls");
                cout<<"X:"<<x<<" Y:"<<y<<" "<<dir[d]<<"\n";
                for(ll i=0;i<=n+1;i++)
                {
                    for(ll j=0;j<=n+1;j++)
                        cout<<((!i||!j||i>n||j>n)?"# ":((i==y&&j==x)?(s?"O ":"o "):(a[i][j]?"* ":". ")));
                    cout<<"\n";
                }
            }
        }
        if(ch=='l')
        {
            d--;
            if(d<0) d=3;
        }
        if(ch=='r')
        {
            d++;
            if(d>3) d=0;
        }
        if(ch=='u')
            s=0;
        if(ch=='d')
            s=1;
        if(ch=='g')
        {
            ll g;
            cin>>g;
            for(ll i=1;i<=g;i++)
            {
                system("cls");
                a[y][x]=s;
                x+=dx[d];
                y+=dy[d];
                a[y][x]=s;
                cout<<"X:"<<x<<" Y:"<<y<<" "<<dir[d]<<"\n";
                for(ll i=0;i<=n+1;i++)
                {
                    for(ll j=0;j<=n+1;j++)
                        cout<<((!i||!j||i>n||j>n)?"# ":((i==y&&j==x)?(s?"O ":"o "):(a[i][j]?"* ":". ")));
                    cout<<"\n";
                }
            }
        }
    }
}
