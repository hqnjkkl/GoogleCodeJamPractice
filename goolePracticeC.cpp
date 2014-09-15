#include <stdio.h>
#include <vector>

using namespace std;

vector<int> input;
int res = 99999;
void dfs(vector<int> &left,int k);
int processed = 1;
int main()
{
	int t,n,k,num;
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d %d",&n,&k);
		for(int j=0;j<n;j++)
		{
			scanf("%d",&num);
			input.push_back(num);
		}
		processed = 1;
		dfs(input,k);
		printf("Case #%d: %d\n",i,res);
		res = 9999999;
		input.clear();
	}
	return 0;
}

void dfs(vector<int> &left,int k)
{
	int len = left.size();
	if(len<res)
		res = len;
	if(processed==0)
		return ;
	int process = 0;
	for(int i=0;i<len;i++)
	{
		if(i<len-2)
		{
			if(left[i+1]-left[i] == left[i+2]-left[i+1])
			{
				if(left[i+1]-left[i]==k)
				{
					vector<int> newLeft = left;
					newLeft.erase(newLeft.begin()+i,newLeft.begin()+i+3);
					if(newLeft.size()<res)
					{
						res = newLeft.size();
					}
					process = 1;
					dfs(newLeft,k);
				}
			}
		}
	}
	if(process==1)
	{
		processed = 0;
	}
	return ;
}
