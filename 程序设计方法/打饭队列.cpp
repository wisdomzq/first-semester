#include<iostream>
#include<string>
#include<queue>
#include<cstring>
using namespace std;
int n;
int main()
{
    cin>>n;
    int ans=0;
    queue<string> s;
    for(int i=0;i<n;i++)
    {
       string a;
         cin>>a;
   if(a=="Arrive")
   {
         string b;
         cin>>b;
         s.push(b);
    }
    else
{
     if(a=="Leave")
        {
            if(!s.empty())
            {
                s.pop();
            }
        }
        else
        {
            if(a=="QueueHead")
         {
               if(s.empty())
               {
                cout<<"Empty queue"<<endl;
               }
               else
               {
                cout<<s.front()<<endl;
               }
         }
        
         else{
            if(a=="QueueTail")
            {
               if(s.empty())
               {
                cout<<"Empty queue"<<endl;
               }
               else
               {
                cout<<s.back()<<endl;
               }
         }
   
        }
}
       
    }      
}
}
   
         

