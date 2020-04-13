#include<iostream>
using namespace std;
class quick
{
    int n;
    int p;
    int q;
    int r;
    int a[10];
public:
    void getd()
    {
		cout<<"Enter the number of integers";
        cin>>n;
        int i;
		cout<<"Enter the integers";
        for(i=0;i<n;i++)
            {
            cin>>a[i];
            }
    }
    void quicksort(int p,int r)
    {
    	if(p<r)
        {
            q=partition(p,r);
            quicksort(p,q-1);
            quicksort(q+1,r);
        }
    }
    int partition(int p,int r)
    {
        int i,j;
        int x,tmp;
        x=a[r];
        i=p-1;
        for(j=p;j<=r-1;j++)
        {
			 if(a[j]<=x)
            {
                i=i+1;
                tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
        }
            tmp=a[i+1];
            a[i+1]=a[r];
            a[r]=tmp;
            return i+1;
    }
    void display()
    {
        int i;
        for(i=0;i<n;i++)
        {
            cout<<a[i]<<"\t";
        }
    }
	void quicksort()
    {
        quicksort(0,n-1);
    }
};
int main()
{
quick o1;
o1.getd();
o1.quicksort();
cout<<"After sorting\t";
o1.display();
return 0;
}



