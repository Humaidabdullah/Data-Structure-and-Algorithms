#include<iostream>
using namespace std;
class ins
{
        int n;
        int a[10];
        public:
        void getdetails()
        {	
        	cout<<"Enter the number of integers";
            cin>>n;
            int i;
            cout<<"Enter the integers\n";
        	for(i=0;i<n;i++)
            {
                cin>>a[i];
            }
        }
        void sort()
        {
            int p,j,c,ct=0;
            int tmp;
            for(p=1;p<=n-1;p++)
            {
                tmp=a[p];c=0;
                for(j=p;j>0 && a[j-1]>tmp;j--)
                    {
                        a[j]=a[j-1];
                        c++;
                    } 
				ct=ct+c;
				a[j]=tmp;
                cout<<"Pass"<<p<<"\t";
                display();
                cout<<"\t"<<c;
                cout<<"\n";
            }
            cout<<"Total swaps\t"<<ct;
        }
        void display()
        {
                int i;
                for(i=0;i<n;i++)
                {
                        cout<<a[i]<<"\t";
                }

        }
};
int main()
{
ins o1;
o1.getdetails();
o1.sort();
cout<<"\nAfter sorting\t";
o1.display();
return 0;
}

                                                                             


