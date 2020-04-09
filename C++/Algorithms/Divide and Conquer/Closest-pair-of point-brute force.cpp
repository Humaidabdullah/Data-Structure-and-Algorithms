#include<iostream>
#include<cmath>
#include<cfloat>
using namespace std; 
 
 float dist(float p1, float p2,float p3,float p4)  
{  
    return sqrt( (p1 - p3)*(p1 - p3) +  (p2 - p4)*(p2 - p4)  );
          
}   
float bruteforce(float P[10][2], int n)  
{  int i,j;
    cout<<"Point-1\tPoint-2\tDistance\n";
    float min = FLT_MAX;  
        for ( i = 0; i <n; i++) 
        {
            for( j=i+1;j<n;j++)
            {
                if (dist(P[i][0], P[i][1],P[j][0],P[j][1]) < min)
                {
                     min = dist(P[i][0], P[i][1],P[j][0],P[j][1]);
                    cout<<i<<"\t"<<j<<"\t"<<min<<"\n";
                } 
            }
        }
    return min;  
}  
float min(int x, int y)  
{  
    return (x < y)? x : y;  
}  
  
int main()  
{  
    int m;
    cout<<"Enter no of points";
    cin>>m;
    float P[m][2];  
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<2;j++)
        {
            cin>>P[i][j];
        }
   }
    cout << "The smallest distance is " << bruteforce(P,m);  
    return 0;  
}  
