#include<iostream>
#include<string>

using namespace std;

struct person{
    string s;
    int hh1,mm1,ss1;
    int hh2,mm2,ss2;
}first,last,tmp;

bool judge(person a,person b,int x)
{
    // 到达时间
    if(x == 1)
    {
        if(a.hh1!=b.hh1)
        {
            if(a.hh1<b.hh1) return true;
            else return false;
        }
        else
        {
            if(a.mm1!=b.mm1)
            {
                if(a.mm1<b.mm1) return true;
                else return false;
            }
            else
            {
                if(a.ss1!=b.ss1)
                {
                    if(a.ss1<b.ss1) return true;
                    else return false;
                }
            }
        }
    }
    else
    {
        //离开时间
        if(a.hh2!=b.hh2)
        {
            if(a.hh2>b.hh2) return true;
            else return false;
        }
        else
        {
            if(a.mm2!=b.mm2)
            {
                if(a.mm2>b.mm2) return true;
                else return false;
            }
            else
            {
                if(a.ss2!=b.ss2)
                {
                    if(a.ss2>b.ss2) return true;
                    else return false;
                }
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    first = {"",23,59,59,0,0,0};
    last = {"",0,0,0,0,0,0};
    for(int i=0;i<n;i++)
    {
        cin>>tmp.s;
        scanf("%d:%d:%d %d:%d:%d",&tmp.hh1,&tmp.mm1,&tmp.ss1,&tmp.hh2,&tmp.mm2,&tmp.ss2);
        if(judge(tmp,first,1))
        {
            first.s = tmp.s;
            first.hh1 = tmp.hh1;
            first.mm1 = tmp.mm1;
            first.ss1 = tmp.ss1;
        }
        if(judge(tmp,last,0))
        {
            last.s = tmp.s;
            last.hh2 = tmp.hh2;
            last.mm2 = tmp.mm2;
            last.ss2 = tmp.ss2;
        }
    }
    cout<<first.s<<' '<<last.s<<endl;
    return 0;
}
