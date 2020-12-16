#include<iostream>

using namespace std;

struct p{
    string s;
    int year,month,day;
}oldest,youngest,mleft,mright,tmp;

void init()
{
    youngest.year = mleft.year = 1814;
    youngest.month = oldest.month = mleft.month = mright.month=9;
    oldest.year = mright.year = 2014;
    youngest.day = oldest.day = mleft.day = mright.day=6;
}
int compare(p a,p b)
{
    if(a.year!=b.year)
    {
        if(a.year>b.year) return -1;
        else return 1;
    }
    else
    {
        if(a.month!=b.month)
        {
            if(a.month>b.month) return -1;
            else return 1;
        }
        else
        {
            if(a.day!=b.day)
            {
                if(a.day>b.day) return -1;
                else return 1;
            }
            else return 0;
        }
    }
    
}

int main()
{
    init();
    int n;
    cin>>n;
    int cnt = 0;
    while(n--)
    {
        cin>>tmp.s;
        scanf("%d/%d/%d",&tmp.year,&tmp.month,&tmp.day);
        if(compare(tmp,mleft)!=1&&compare(tmp,mright)!=-1)
        {
            cnt++;
            if(compare(tmp,youngest)==-1)
            {
                youngest.s = tmp.s;
                youngest.year = tmp.year;
                youngest.month = tmp.month;
                youngest.day = tmp.day;
            }
            if(compare(tmp,oldest)==1)
            {
                oldest.s = tmp.s;
                oldest.year = tmp.year;
                oldest.month = tmp.month;
                oldest.day = tmp.day;
            }
        }
    }
    if(!cnt) cout<<0<<endl;
    else
    cout<<cnt<<' '<<oldest.s<<' '<<youngest.s<<endl;
    return 0;
}
