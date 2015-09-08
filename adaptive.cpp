
#include<bits/stdc++.h>
#include<cmath>

#define N 26

using namespace std;

typedef struct node
{
	char sym;
	int freq;
	struct node *left, *right, *parent;
	node():sym(0), freq(0), left(NULL), right(NULL), parent(NULL)
	{
	}
} node;

void send(char);
node* search(node *, char);
void sendpos(node *, node *&, string pos="");

int main()
{
	node *root=NULL, *nyt=NULL;
	ifstream file("data.txt");
	string stream;
	getline(file, stream);
	map<char, bool> present;
	for(char a='a';a<='z';a++)
		present[a]=false;
	for(int i=0;i<stream.length();i++)
	{
		char c=stream[i];
		//cout<<c;
		if(present[c])
		{
			node *find=search(root,c);
			sendpos(root, find);
			while(find!=root)
			{
				find->freq++;
				node *p=find->parent;
				if(p->right==find)
				{
					find=p;
					continue;
				}
				if(find->freq > p->right->freq)
					swap(p->left, p->right);
				find=p;
			}
			find->freq++;
			continue;
		}
		if(!root)
		{
			root=new node;
			root->left=new node;
			root->right=new node;
			root->freq++;
			root->right->sym=c;
			root->right->freq++;
			root->left->parent=root;
			root->right->parent=root;
			nyt=root->left;
			send(c);
			present[c]=true;
			continue;
		}
		node *t1=new node, *t2=new node;
		nyt->left=t1, nyt->right=t2;
		sendpos(root, nyt);
		present[c]=true;
		nyt->freq++;
		nyt->right->sym=c;
		nyt->right->freq++;
		t1->parent=nyt;
		t2->parent=nyt;
		nyt=t1;
		send(c);
		if(nyt->parent==root)
			continue;
		node *find=nyt->parent->parent;
		while(find!=root)
		{
			find->freq++;
			node *p=find->parent;
			if(p->right==find)
			{
				find=p;
				continue;
			}
			if(find->freq > p->right->freq)
				swap(p->left, p->right);
			find=p;
		}
		find->freq++;
	}
	file.close();
	return 0;
}

node* search(node *root, char c)
{
	if(!root)
		return NULL;
	if(root->sym==c)
		return root;
	node *sl=search(root->left,c);
	if(sl)
		return sl;
	node *sr=search(root->right,c);
	if(sr)
		return sr;
}

void sendpos(node *root, node *&nyt, string pos)
{
	if(root==nyt)
	{
		cout<<pos;
		return;	
	}
	if(root->left)
		sendpos(root->left, nyt, pos+"0");
	if(root->right)
		sendpos(root->right, nyt, pos+"1");
}
/*void rec(char n )
{
	static int e = log(N)/log(2.0);
	static int r = N-(int)pow(2,e);
	if (root == nyt )
	{
		cout<<pos;
		return;

	}
	if( root->left)
		rec(root->left,nyt,pos+"0");
	if(root->right)
		rec(root->left , nyt,pos +"1");
	if(n-'a'<=2*r-1)
	{	int k=n-1 ;
		char s[e+2];
		s[e+1] =0;
		for (int i=e ; i>=0; i+-- ,k/=2)
			s[i]=(k&1)+'0';
		printf("%s",s);

	}
}
*/
void send(char n)
{
	static int e=log(N)/log(2.0);
	static int r=N-(int)pow(2, e);
	if(n-'a'<=2*r-1 && n-'a'>=0)
	{
		int k=n-1;
		char s[e+2];
		s[e+1]=0;
		for(int i=e;i>=0;i--, k/=2)
			s[i]=(k&1)+'0';
		printf("%s", s);
	}
	else
	{
		int k=n-r-1;
		char s[e+1];
		s[e]=0;
		for(int i=e-1;i>=0;i--, k/=2)
			s[i]=(k&1)+'0';
		printf("%s", s);
	}
}
