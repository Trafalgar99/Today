#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

struct record{
    char name[10];
    int age,net_wealth;
};

bool cmp(record a,record b)
{
    if(a.net_wealth!=b.net_wealth)
        return a.net_wealth>b.net_wealth;
    else if(a.age!=b.age)
        return a.age<b.age;
    else
        return strcmp(a.name,b.name)<0;
}
record records[100000];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%s",records[i].name);
        scanf("%d %d",&records[i].age,&records[i].net_wealth);
    }
    sort(records,records+n,cmp);
    
    for(int i=1;i<=k;i++)
    {
        int kk,mina,maxa;
        cin>>kk>>mina>>maxa;
        printf("Case #%d:\n",i);
        int m=0;
        for(int j=0;j<n;j++)
        {
            if(records[j].age>=mina&&records[j].age<=maxa)
            {
                printf("%s %d %d\n",records[j].name,records[j].age,records[j].net_wealth);
                m++;
                if(m==kk) break;
            }
        }
        if(m==0)
            printf("None\n");
    }
    return 0;
}
