#include<iostream>
#include<cmath>
using namespace std;
class merge
{
	int a[1000];
	int n;
	public:
	void getd()
	{
		cout<<"Enter the number of integrs to be sorted";
		cin>>n;
		int m;
		cout<<"Enter the integers\n";
		for(m=1;m<=n;m++)
		{
			cin>>a[m];
		}
	}
	void mergesort(int p,int r)
	{
		int q;
		if(p<r)
		{
			q=floor((p+r)/2);
			mergesort(p,q);
			mergesort(q+1,r);
			mer(p,q,r);
		}
	}
	void mer(int p,int q,int r)
	{
		int i,n1,n2,le[10],re[10];
		n1=q-p+1;
		n2=r-q;
		for(i=1;i<=n1;i++)
		{
			le[i]=a[p+i-1];
		}
		for(i=1;i<=n2;i++)
		{
			re[i]=a[q+i];
		}
		le[n1+1]=1000;
		re[n2+1]=1000;
		int j,k;
		j=k=1;
		for(i=p;i<=r;i++)
		{
			if(le[j]<=re[k])
			{
				a[i]=le[j];
				j++;
			}
			else
			{
				a[i]=re[k];
				k++;
			}
		}
	}
	void mergesort()
	{
		mergesort(1,n);
	}
	void display()
	{
		int t;
		cout<<"\nSorted order\n";
		for(t=1;t<=n;t++)
		{
		cout<<a[t]<<"\t";
		}
	}
};
int main()
{
	merge o;
	o.getd();
	o.mergesort();
	o.display();
	return 0;
}

