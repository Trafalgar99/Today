#include<iostream>
#include<algorithm>

using namespace std;

struct student{
    int id;
    int score[6]={0,-2,-2,-2,-2,-2};
    int num_of_perfect=0;
    int show=0;
    int rnk;
};
int total[6];
student s[100000];
int N,K,M;
bool cmp(student a,student b)
{
    if(a.score[0]!=b.score[0]) return a.score[0]>b.score[0];
    else if(a.num_of_perfect!=b.num_of_perfect) return a.num_of_perfect>b.num_of_perfect;
    else if(a.show!=b.show) return a.show>b.show;
    else return a.id<b.id;
}
int main()
{
    cin>>N>>K>>M;
    for(int i=1;i<=K;i++)
        cin>>total[i];
    while(M--)
    {
        int id,num,point;
        cin>>id>>num>>point;
        if(point>=0)s[id].show = 1;
        if(point>s[id].score[num]) s[id].score[num]=point;
    }
    for(int i=1;i<=N;i++)
    {
        s[i].id = i;
        for(int j=1;j<=K;j++)
        {
            if(s[i].score[j]>=0)s[i].score[0]+=s[i].score[j];
            if(s[i].score[j] == total[j])s[i].num_of_perfect++;
        }
    }
    sort(s+1,s+N+1,cmp);
    for(int i=1;i<=N;i++)
    {
        if(i==1||s[i].score[0]!=s[i-1].score[0])
            s[i].rnk = i;
        else 
            s[i].rnk = s[i-1].rnk;
    }
    for(int i=1;i<=N;i++)
    {
        if(s[i].show==0)break;
        printf("%d %05d %d",s[i].rnk,s[i].id,s[i].score[0]);
        for(int j=1;j<=K;j++)
        {
            if(s[i].score[j]==-2)cout<<" -";
            else if(s[i].score[j]==-1)cout<<" 0";
            else cout<<" "<<s[i].score[j];
        }
        cout<<endl;
    }
}
