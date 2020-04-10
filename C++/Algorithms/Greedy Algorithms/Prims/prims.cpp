#include<iostream>
#include<climits>
using namespace std;
# define t 100
int minimum(int k[],int flag[],int n)
{
    int mini=INT_MAX,minpos,i;
    for(i=0;i<n;i++)
    {
        if(flag[i]==0 && k[i] <mini)
        {
            mini=k[i];
            minpos=i;
        }
    }
        return minpos;
}
void prims(int g[t][t],int no)
{   int n=no;
    int i,j,gp[n],k[n],flag[n],l,m;
    for(i=0;i<n;i++)
    {
        k[i]=INT_MAX;
        flag[i]=0;
    }
    k[0]=0;
    gp[0]=-1;
    for(j=0;j<n-1;j++)
    {
        l=minimum(k,flag,n);
        flag[l]=1;
        for(m=0;m<n;m++)
        {
            if(g[l][m] && flag[m]==0 && g[l][m]<k[m])
            {
                gp[m]=l;
                k[m]=g[l][m];    
            }
        }
    }
    cout<<"Edge \tWeight\n";
    for(i=1;i<n;i++)
    {
        cout<<gp[i]<<" - "<<i<<" \t"<<g[i][gp[i]]<<" \n";
    }
    
}

int main() 
{
    int g[t][t];
    int n,i,j;
    cout<<"Enter the no of vertices of the graph";
    cin>>n;
    
    cout<<"Enter the weighted matrix";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>g[i][j];
        }
    }
    prims(g,n);
}
