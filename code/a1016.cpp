#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

struct record{
    int dd,hh,mm,t;
    string tag;
    
};
map<string,vector<record>>M;
double danjia[24];

bool cmp(record a,record b)
{
    return a.t<b.t;
}
int main()
{
    for(int i=0;i<24;i++)
        cin>>danjia[i];
    int n;
    cin>>n;
    int month;
    for(int i=0;i<n;i++)
    {
        string name,tag;
        int date,hour,minute;char c;
        cin>>name>>month>>c>>date>>c>>hour>>c>>minute>>tag;
        record temp;
        temp.dd = date;temp.hh=hour;temp.mm=minute;temp.tag = tag;
        temp.t = date*1440+hour*60+minute;
        M[name].emplace_back(temp);
    }
    for(auto it = M.begin();it!=M.end();++it)
    {
        auto V = it->second;
        sort(V.begin(),V.end(),cmp);
        double total  = 0;
        for(int i=0;i<V.size();)
        { 
            if(i+1<V.size()&&V[i].tag>V[i+1].tag) //tag的字典序  如果成功找到一对合法的时间 
            {
                if(total == 0)
                {
                    cout<<it->first<<' ';
                    printf("%02d\n",month);
                }
                
                int t1 = V[i].t;
                int t2 = V[i+1].t;
                double fenzhang = 0;
                for(int Time = t1;Time<t2;Time++)
                {
                    fenzhang += danjia[Time%1440/60];
                }
                
                printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",V[i].dd,V[i].hh,V[i].mm,V[i+1].dd,V[i+1].hh,V[i+1].mm,V[i+1].t-V[i].t,fenzhang/100);
                i+=2;
                total += fenzhang;
            }
            else{
                i++;
            }
        }
        if(total!=0)
            printf("Total amount: $%.2f\n",total/100);
    }
    return 0;
}
