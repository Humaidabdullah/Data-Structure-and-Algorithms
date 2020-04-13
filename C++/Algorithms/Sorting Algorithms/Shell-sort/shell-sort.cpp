#include<iostream> 
using  namespace std; 
class shell 
{ 
int n; 
int a[20]; 
public: 
    void get() 
    { 
        cout<<"Enter the total no of integers"; 
        cin>>n; 
        int i; 
        cout<<"Enter the elements";
        for(i=0;i<n;i++) 
        { 
            cin>>a[i]; 
        } 
    } 
    void  sort() 
    { 
        int  j,p,pass,i=0; 
        int temp; 
            for(pass=n/2;pass>0;pass=pass/2) 
          	{ 
                for(p=pass;p<=n-1;p++) 
              	{ 
                    temp=a[p]; 
                    for(j=p;j>=pass&&a[j-pass]>temp;j=j-pass) 
                    { 
                        a[j]=a[j-pass]; 
                    }                 
                a[j]=temp; 
                } 
            cout<<"pass"<<i+1<<"\t";i++; 
            display(); 
            cout<<"\n"; 
           	} 
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
shell o1; 
o1.get(); 
o1.sort(); 
cout<<"Sorted array\n";
o1.display(); 
return 0; 
} 


