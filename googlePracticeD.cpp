#include <stdio.h>
#include <vector>

using namespace std;
int process = 0,index=0;
void dfs(int n,int left,int k,int right,vector<char> &sta);

int main()
{
	int t,n,k;
	//D-small-practice.in
		freopen("D-small-practice (1).in","r",stdin);
	freopen("D-small-practice.out","w",stdout);
	scanf("%d",&t);
	vector<char> sta;
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		scanf("%d",&k);
		process = 0;
		index = 0;
		printf("Case #%d: ",i);
		dfs(n,0,k,0,sta);
		if(process==0)
		{
			printf("Doesn't Exist!\n");
		}else
		{
			printf("\n");
		}
		sta.clear();
	}
	return 0;
}

//left:左边有多少；right:右边有多少；index第几个
void dfs(int n,int left,int k,int right,vector<char> &sta)
{
	if(sta.size()==2*n)
	{
		index ++;
	}
	if(process==1)
	{
		return ;
	}
	if(index==k)
	{
		for(int i=0;i<sta.size();i++)
		{
			printf("%c",sta[i]);
		}
		process = 1;
		return ;
	}
	if(right>left)
	{
		return ;
	}
	if(left<n)
	{
		sta.push_back('(');
		dfs(n,left+1,k,right,sta);
		sta.pop_back();
	}
	if(right<left)
	{
		sta.push_back(')');
		right;
		dfs(n,left,k,right+1,sta);
		sta.pop_back();
	}
	return ;
}