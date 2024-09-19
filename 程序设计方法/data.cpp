#include<iostream>
using namespace std;
int main()
{
    int s1=4000,s2=4000;
    for(double i=0.01;i<=0.25;i+=0.01)
    {
       for(int b=4;b<=30;b+=2)
       {
        for(int j=2;j<=15;j++)
        {
           
                
                    for(int d=4;d<=30;d+=2)
                    {
                        
                           
                                
                                    for(int c=2;c<=15;c++)
                                    {
                                        for(int c1=6;c1<=30;c1+=2)
                                        for(int c2=5;c2<=40;c2+=5)
                                        cout<<i<<" "<<b<<" "<<j<<" "<<s1<<" "<<i<<" "<<d<<" "<<s2<<" "<<i<<" "<<6<<" "<<c<<" "<<56<<" "<<c1<<" "<<c2<<endl;
                                    }
                                }
                            
                        
                    
                
            
        }
       }
    }
}