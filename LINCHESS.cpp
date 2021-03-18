
#include <bits/stdc++.h>
using namespace std;
bool checkByNinga(vector<int> me,vector<int> nin)
{	
	if(me[0]==nin[0]||me[1]==nin[1]||(me[0]-me[1]==nin[0]-nin[1])||(me[0]+me[1]==nin[0]+nin[1]))
	 return true;
	// find all valid knight positions of ninja 
	int xMove[8] = { 2, 2, -2, -2, 1, 1, -1, -1 };
    int yMove[8] = { 1, -1, 1, -1, 2, -2, 2, -2 };
	for(int i=0;i<8;i++)
	{
		if(me[0]==nin[0]+xMove[i]&&me[1]==nin[1]+yMove[i])
		return true;
	}
	return false;
}
bool checkByKing(vector<int> me,vector<int> king)
{
	// find all 8 (valid only) positions of king 
	int xMove[8] = { 1, 1, -1, -1, 0, 0, 1, -1 };
    int yMove[8] = { 1, -1, 1, -1, 1, -1, 0, 0 };
	for(int i=0;i<8;i++)
	{
		if(me[0]==king[0]+xMove[i]&&me[1]==king[1]+yMove[i])
		return true;
	}
	return false;
}
bool checkStale(vector<int> me,vector<int> nin,vector<int> king)
{
	// find all 8 positions of Me in vector allMe	
	int xMove[8] = { 1, 1, -1, -1, 0, 0, 1, -1 };
    int yMove[8] = { 1, -1, 1, -1, 1, -1, 0, 0 };
	for(int i=0;i<8;i++)
	{	// check validity
		vector<int> newMe{me[0]+xMove[i],me[1]+yMove[i]};
		if(!(newMe[0]>=0&&newMe[0]<8&&newMe[1]>=0&&newMe[1]<8))
		continue;
		if((!checkByNinga(newMe,nin))&&(!checkByKing(newMe,king)))
		return false;
	}
	return true;
}
	int getC(int a)
	{
		int ct=0;
		while(a)
		{
			a=a&(a-1);
			ct++;
		}
		return ct;	
	}
	bool isG(string &st1,string &st2)
	{	// st1 inside st2
		int i=0;
		int j=0;
		while(st1[i]!='\0'&&st2[j]!='\0')
		{
			if(st1[i]==st2[j])
			{   i++;
				j++; }
			else j++;
		}
		if(st1[i]=='\0') return true;
		return false;	
	}

int main(){ 
	int t,n,i,sm,a,j,k,first,p,b,tn,s,mx,catsObs,catsHiding,c,d,l,ct,cfuel,f,mn,ans;
	string st;
	cin>>t;
	unordered_map<int,int> mp;
	
		while(t--)
		{ 
			cin>>n>>k;
			mn=INT_MAX;
			ans=-1;
			while(n--)
			{
				cin>>p;
				if(abs(k-p)%p==0)
				{	if(abs(k-p)/p<mn)
					 { mn=min(mn,abs(k-p)/p); ans=p; }
				}
			}
				cout<<ans<<endl;
		}
					return 0;  	
}
