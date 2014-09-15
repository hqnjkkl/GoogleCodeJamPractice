//google problem 1
//2014-9-15 13:13
#include <stdio.h>
#define MOD 1000000007

long long dif, res = 0;

void dfs(int start,int m,int n,int sum,int tmp);

int main()
{
	int t;
	freopen("A-small-attempt1.in","r",stdin);
	freopen("A-small-answer.out","w",stdout);
	scanf("%d",&t);
	long long m,n;
	for(int i=1;i<=t;i++)
	{
		scanf("%I64d %I64d",&m,&n);
		dif = 1;
		for(int j=1;j<=n;j++)
		{
			dif *= j;
		}
		dfs(1,m,n,0,1);
		printf("Case #%d: %I64d\n",i,res);
		res = 0;
	}
	
	//return 0;
}
// start 是当前的第几个字母;sum是总共加起来的长度;tmp是当前除数是多少;
void dfs(int start,int m,int n,int sum,int tmp)
{
	if(start==m+1) // start 代表下一个,sum当前的sum;
	{
		if(sum==n) //当前的sum
		{
			res += dif/tmp;
			return ;
		}
	}
	if(sum>n || start>m)
		return ;
	int tmp2 = 1;
	int time = 1;
	while(sum+time<=n)
	{
		tmp2 *= time;
		dfs(start+1,m,n,sum+time,tmp*tmp2);
		time++;
	}
	return ;
}