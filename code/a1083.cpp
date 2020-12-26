#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

struct student{
    char name[11];
    char id[101];
    int score;
};

int N;
bool cmp(student a,student b)
{
    if(a.score!=b.score) return a.score>b.score;
    else return strcmp(a.name,b.name)<0;
}
int main()
{
    cin>>N;
    student s[N];
    for(int i=0;i<N;i++)
        scanf("%s %s %d",s[i].name,s[i].id,&s[i].score);
    sort(s,s+N,cmp);
    int a,b;
    scanf("%d %d",&a,&b);
    int cnt = 0;
    for(int i=0;i<N;i++)
    {
        if(s[i].score>=a&&s[i].score<=b)
        {
            printf("%s %s\n",s[i].name,s[i].id);
            cnt++;
        }
    }
    if(cnt==0)
        printf("NONE\n");
    return 0;
}
