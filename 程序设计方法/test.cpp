#include<iostream>
using namespace std;
int main()
{
    int i=0;
    double a,b,r;
    cin>>a>>b;
    while(a>=b*i)i++;
    r=a-b*(i-1);
    cout<<r;

}
