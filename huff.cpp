/*
	Author		: Doshi Shreyans
	Date & Time	: 17-Jul-15 11:28:43 AM
*/

#include<bits/stdc++.h>

using namespace std;

class node
{
public:
	int ascii;
	float prob;
	node *left, *right;
	
	node()
	{
		left=right=NULL;
		prob=0.0f;
	}
	
	void print()
	{
		cout<<(char)this->ascii<<" ("<<this->ascii<<") "<<this->prob<<endl;
	}
	
	void inorder(map<char, vector<bool> > &m, string a="")
	{
		if(!this)
			return;
		if(!this->left && !this->right)
		{
			m[(char)this->ascii].clear();
			for(int i=0;i<a.length();i++)
				m[(char)this->ascii].push_back(a[i]=='1');
			return;
		}
		this->left->inorder(m, a+"0");
		this->right->inorder(m, a+"1");
	}
};

bool compare(const node* a, const node* b)
{
//	if(a->prob==b->prob)
//		return a->ascii <= b->ascii;
	return a->prob>b->prob;
}

node* huffman_tree(vector<node *>);

int main()
{
	freopen("data_shannon_fano.txt", "r", stdin);
	
	vector<node *> data(128);
	for(int i=0;i<128;i++)
		data[i]=new node, data[i]->ascii=i;
	char c;
	int count=0;
	while(1)
	{
		c=getchar();
		if(c==EOF)
			break;
		int ascii=(int)c;
		data[ascii]->prob++;
		count++;
	}
	for(int i=0;i<128;i++)
		data[i]->prob/=(float)(count), data[i]->ascii=i;
	sort(data.begin(), data.end(), compare);
	
	node *root=huffman_tree(data);
	
	map<char, vector<bool> > m;
	root->inorder(m);
	for(auto i : m)
	{
		cout<<i.first<<' ';
		for(auto j : i.second)
			cout<<j;
		cout<<endl;
	}
	
	FILE *f=fopen("data_shannon_fano.txt", "r");
	freopen("answer.txt", "w", stdout);
	char buf[count/8+2];
	memset(buf, 0, sizeof buf);
	int k=0;
	for(int i=0;i<count;i++)
	{
		fscanf(f, "%c", &c);
		char byte;
		for(auto j : m[c])
		{
			byte=j?(char)1:(char)0;
			buf[k/8]|=(byte<<(k%8));
			k++;
		}
	}
	printf("%s", buf);
	fclose(f);
	return 0;
}

node* huffman_tree(vector<node *> data)
{
	while(data.back()->prob==0.0f)
		data.pop_back();
	
//	for(int i=0;i<total;i++)
//		data[i]->print();
	
	while(data.size()>2)
	{
		node *last=data[data.size()-1];
		node *snd_last=data[data.size()-2];
		node *comb=new node;
		comb->left=snd_last;
		comb->right=last;
		comb->prob=last->prob+snd_last->prob;
		comb->ascii=0;
		data.pop_back();
		data.pop_back();
		data.push_back(comb);
		sort(data.begin(), data.end(), compare);
	}
	
	node *root=new node;
	root->left=data[0];
	root->right=data[1];
	
	return root;
}
