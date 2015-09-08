
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cout<<"Enter no. of symbols: ";
	cin>>n;
	int freq[n], cum[n+1];
	cum[0]=0.0f;
	cout<<"Enter the frequencies of all the symbols respectively : ";
	for(int i=0;i<n;i++)
	{
		cin>>freq[i];
		cum[i+1]=cum[i]+freq[i];
	}
	int m=ceil(log2(cum[n]))+2;
	cout<<"Enter the string : ";
	string a;
	cin>>a;
	int l=0, u=0;
	for(int i=0;i<m;i++)
		u|=(1<<i);
	int new_l, new_u;
	int scale=0;
	for(char c: a)
	{
		int x=c-'0';
		new_l=l+((u-l+1)*(cum[x-1])/cum[n]);
		new_u=l-1+((u-l+1)*(cum[x])/cum[n]);
		while(1)
		{
			int tmp=(1<<(m-1));
			int tmp2=(1<<(m-2));
			int msb1=new_l&tmp;
			int msb2=new_u&tmp;
			int lastsent;
			if(msb1+msb2==0)
			{
				cout<<0;
				int tt=~tmp;
				new_l&=tt;
				new_u&=tt;
				new_l*=2;
				new_u*=2;
				new_u++;
				lastsent=0;
				while(scale>0)
				{
					cout<<1-lastsent;
					scale--;
				}
			}
			else if(msb1>0 && msb2>0)
			{
				cout<<1;
				int tt=~tmp;
				new_l&=tt;
				new_u&=tt;
				new_l*=2;
				new_u*=2;
				new_u++;
				lastsent=1;
				while(scale>0)
				{
					cout<<1-lastsent;
					scale--;
				}
			}
			else if((new_l&tmp2) && (new_u&tmp2)==0)
			{
				int tt=~tmp;
				new_l&=tt;
				new_u&=tt;
				new_l*=2;
				new_u*=2;
				new_u++;
				
				tt=~tmp;
				new_l&=tt;
				new_u|=(1<<(m-1));
				scale++;
			}
			else
				break;
		}
		l=new_l;
		u=new_u;
	}
	cout<<(l&(1<<(m-1)));
	string bin_scale="";
	while(scale)
	{
		bin_scale=(scale&1?"1":"0")+bin_scale;
		scale/=2;
	}
	cout<<bin_scale;
	for(int i=m-2;i>=0;i--)
		cout<<(l&(1<<i));
	return 0;
}

