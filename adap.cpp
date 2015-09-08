#include <bits/stdc++.h>


using namespace std;

class node {
	public:
		node *left ,*right;
		int ascii;
		
		node()
		{
			left=null;
			right=null;
			
			}
		void inorder(map<char ,vector<bool> > &m , string a="")
		{	if(!this)
				return;
			if(!this->left && this->right)
			{
				m[char(this->ascii)].clear();
				for(int i =0 ; i < a.length();i++)
					m[char(this-ascii)].push_back(a[i]=='1';
							return;
							
			}		
				 this->left->inorder().push_back(a[i]=='1');
				 this->left->inorder().push_back(a[i]=='0');
			
			
			}
	};
	
bool compare(const node* a, const node* b)
{
	return a->prob > b->prob;
	
	}
int main()
{
	
	
	return 0;
	}
