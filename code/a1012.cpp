#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

struct student{
    int id;
    int grade[4];
}stu[2010];
int now;
map<int,char>mm;
int rank1[10000000][4];
bool cmp(student a,student b)
{
    return a.grade[now]>b.grade[now];
}
int main()
{
    mm[0] = 'A';
    mm[1] = 'C';
    mm[2] = 'M';
    mm[3] = 'E';
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>stu[i].id;
//        cout<<stu[i].id<<"xxx"<<endl;
        stu[i].grade[0] = 0;
        for(int j=1;j<4;j++)
        {
            cin>>stu[i].grade[j];           
            stu[i].grade[0]+=stu[i].grade[j];
        }
    }
    for(now=0;now<4;now++)
    {
        sort(stu,stu+n,cmp);
        rank1[stu[0].id][now] = 1;
        for(int i=1;i<n;i++){
		
            if(stu[i].grade[now]!=stu[i-1].grade[now])
                rank1[stu[i].id][now] = i+1;
            else
                rank1[stu[i].id][now] = rank1[stu[i-1].id][now];}
    }
    
    for(int i=0;i<m;i++)
    {
        int q;
        cin>>q;
        if(rank1[q][0]==0)
            cout<<"N/A"<<endl;
        else
        {
            int min = rank1[q][0],minp = 0;
            for(int i=1;i<4;i++)
            {
                if(rank1[q][i]<min)
                {
                    min = rank1[q][i];
                    minp = i;
                }
            }
            cout<<min<<" "<<mm[minp]<<endl;
        }
    }
    return 0;
}
