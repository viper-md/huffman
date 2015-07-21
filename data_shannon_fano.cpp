 
#include<bits/stdc++.h>
#include<cmath>

using namespace std;

class elements
{
public:
	int ascii;
	float prob;
	string code;
	
	void print()
	{
		cout<<(char)this->ascii<<" ("<<this->ascii<<") "<<this->prob<<' '<<this->code<<endl;
	}
};

bool compare(const elements a, const elements b)
{
	return a.prob>b.prob;
}

void shannon_fano(vector<elements> &, int, int);

int main()
{
	freopen("data_shannon_fano.txt", "r", stdin);
	vector<elements> data(128);
	for(int i=0;i<128;i++)
		data[i].ascii=i, data[i].prob=0.0, data[i].code="";
	char c;
	int count=0;
	while(1)
	{
		c=getchar();
		if(c==EOF)
			break;
		int ascii=(int)c;
		data[ascii].prob++;
		count++;
	}
	for(int i=0;i<128;i++)
		data[i].prob/=(float)(count), data[i].ascii=i;
	sort(data.begin(), data.end(), compare);

	int total;
	for(total=0;total<128;total++)
		if(data[total].prob==0.0f)
			break;
	shannon_fano(data, 0, total);
	
	for(int i=0;i<total;i++)
		data[i].print();

	return 0;
}

void shannon_fano(vector<elements> &data, int start, int end)
{
	if(end-start==1)
		return;
	if(end-start==2)
	{
		data[start].code+="0";
		data[end-1].code+="1";
		return;
	}
	float total=0;
	for(int i=start;i<end;i++)
		total+=data[i].prob;
	
	int partition=start;
	float min=0, cur=data[start].prob;
	min=abs(cur-(total-cur));
	for(int i=start+1;i<end;i++)
	{
		cur+=data[i].prob;
		float diff=abs(cur-(total-cur));
		if(diff<min)
			min=diff, partition=i;
		else
			break;
	}
	int i;
	for(i=start;i<=partition;i++)
		data[i].code+="0";
	for(;i<end;i++)
		data[i].code+="1";
	shannon_fano(data, start, partition+1);
	shannon_fano(data, partition+1, end);
}

