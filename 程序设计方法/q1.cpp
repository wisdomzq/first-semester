#include<iostream>
#include<cmath>
using namespace std;
double l1_c,l1_b,l1_j,l1_s,l2_c,l2_b,l2_j,l2_s,c_c,c_z,c_j,c_s,c_sj,c_ss,uc_d,uc_cj;
//c表示次品率，b表示购买单价，j表示检测成本，s表示数量，z表示装配成本，d表示调换损失，cj表示拆解费用
//sj表示成品售价,ss表示售卖数量
double e,uc_s;//收益,不合格的数量
void p1_cost(bool l1,bool l2,bool l3,bool l4)
//l1,l2决定步骤1检测零配件1，检测零部件2，l3决定是否检测成品，l4决定是否拆解
{
    double cost1,l1_c1,l2_c1,c_c1;//步骤1的成本,c1为处理后的次品率 
    double cost2,cost3;//步骤2的成本
    double cost;//总成本
    if(l1==0 && l2==0)//都不检测
    {
    cost1=0;
    c_s=l1_s;
    l1_s=0,l2_s=0;//现在部件1和2的数量
    l1_c1=l1_c,l2_c1=l2_c;
    cost+=cost1;
    if(l3==0)//成品不检测
     {
        cost2=0;
        c_ss=c_s;//售卖数量与之前相等
        cost+=cost2;
        e=c_ss*c_sj;//收益
        c_c1=1-(1-l1_c1)*(1-l2_c1)*(1-c_c);//处理后的次品率
        uc_s=c_ss*c_c1;//不合格的数量
        cost3=uc_s*uc_d;//调换损失
        //重复步骤3





        //
     }
     else//成品检测
     {
          c_c1=1-(1-l1_c1)*(1-l2_c1)*(1-c_c);//处理后的次品率
         cost2=c_s*c_j;//成品检测成本
         c_ss=c_s*(1-c_c1);//售卖的数量
         cost+=cost2;
         e=c_ss*c_sj;//收益
         if(l4==1)//拆解,此时1和2都有不合格的概率
         {
             cost3=(c_s-c_ss)*uc_cj;//拆解成本
             l1_s+=(c_s-c_ss),l2_s+=(c_s-c_ss);//现在部件1和2的数量
             cost+=cost3;
             cout<<"总花费为："<<cost<<endl;
             cout<<"总收益为："<<e<<endl;
             cout<<"步骤1花费为："<<cost1<<endl;
             cout<<"步骤2花费为："<<cost2<<endl;
             cout<<"步骤3花费为："<<cost3<<endl;
         }
         else //不拆解
         {
             cost3=(c_s-c_ss)*(l1_b+l2_b);//丢弃成本
             //此时已经结束
             cost+=cost3;
             cout<<"总花费为："<<cost<<endl;
             cout<<"总收益为："<<e<<endl;
             cout<<"步骤1花费为："<<cost1<<endl;
                cout<<"步骤2花费为："<<cost2<<endl;
                cout<<"步骤3花费为："<<cost3<<endl;
         }
     }
    }
     
    else if(l1==1 && l2==0)//检测零部件1，不检测零部件2
    {
       cost1=l1_s*(1-l1_c)*l1_b+l1_s*l1_j;//检测成本+丢弃成本
        l1_s*=(1-l1_c);
        
        l1_c1=0,l2_c1=l2_c;
        cost1+=l1_s*c_z;//装配成本
        c_s=l1_s;
        l2_s=l2_s-l1_s,l1_s=0;//现在部件1和2的数量
        if(l3==0)//成品不检测
     {
        cost2=0;
        c_ss=c_s;//售卖数量与之前相等
        cost+=cost2;
        e=c_ss*c_sj;//收益
        c_c1=1-(1-l1_c1)*(1-l2_c1)*(1-c_c);//处理后的次品率
        uc_s=c_ss*c_c1;//不合格的数量
        cost3=uc_s*uc_d;//调换损失
    
     }
     else//成品检测
     {
          c_c1=1-(1-l1_c1)*(1-l2_c1)*(1-c_c);//处理后的次品率
         cost2=c_s*c_j;//成品检测成本
         c_ss=c_s*(1-c_c1);//售卖的数量
         cost+=cost2;
         e=c_ss*c_sj;//收益
           if(l4==1)//拆解,此时只有2有不合格的概率
         {
             cost3=(c_s-c_ss)*uc_cj;//拆解成本
             l1_s+=(c_s-c_ss),l2_s+=(c_s-c_ss);//现在部件1和2的数量
             cost+=cost3;
             cout<<"总花费为："<<cost<<endl;
             cout<<"总收益为："<<e<<endl;
             cout<<"步骤1花费为："<<cost1<<endl;
                cout<<"步骤2花费为："<<cost2<<endl;
                cout<<"步骤3花费为："<<cost3<<endl;
         }
         else //不拆解
         {
             cost3=(c_s-c_ss)*(l1_b+l2_b);//丢弃成本
             //此时已经结束
             cost+=cost3;
             cout<<"总花费为："<<cost<<endl;
             cout<<"总收益为："<<e<<endl;
             cout<<"步骤1花费为："<<cost1<<endl;
                cout<<"步骤2花费为："<<cost2<<endl;
                cout<<"步骤3花费为："<<cost3<<endl;
         }
     }
    }
    else if(l1==0 && l2==1)
    {
        cost1=l2_s*(1-l2_c)*l2_b+l2_s*l2_j;//检测成本+丢弃成本
        l2_s*=(1-l2_c);
        l2_c1=0,l1_c1=l1_c;
        cost1+=l2_s*c_z;//装配成本
        c_s=l2_s;
        l1_s=l1_s-l2_s,l2_s=0;//现在部件1和2的数量
        if(l3==0)//成品不检测
     {
        cost2=0;
        c_ss=c_s;//售卖数量与之前相等
        cost+=cost2;
         e=c_ss*c_sj;//收益
        c_c1=1-(1-l1_c1)*(1-l2_c1)*(1-c_c);//处理后的次品率
        uc_s=c_ss*c_c1;//不合格的数量
        cost3=uc_s*uc_d;//调换损失
        //重复步骤3




        
        //
     }
     else//成品检测
     {
          c_c1=1-(1-l1_c1)*(1-l2_c1)*(1-c_c);//处理后的次品率
         cost2=c_s*c_j;//成品检测成本
         c_ss=c_s*(1-c_c1);//售卖的数量
         cost+=cost2;
         e=c_ss*c_sj;//收益
          if(l4==1)//拆解,此时只有1有不合格的概率
         {
             cost3=(c_s-c_ss)*uc_cj;//拆解成本
             l1_s+=(c_s-c_ss),l2_s+=(c_s-c_ss);//现在部件1和2的数量
             cost+=cost3;
             cout<<"总花费为："<<cost<<endl;
             cout<<"总收益为："<<e<<endl;
             cout<<"步骤1花费为："<<cost1<<endl;
                cout<<"步骤2花费为："<<cost2<<endl;
                cout<<"步骤3花费为："<<cost3<<endl;
         }
         else //不拆解
         {
             cost3=(c_s-c_ss)*(l1_b+l2_b);//丢弃成本
             //此时已经结束
             cost+=cost3;
             cout<<"总花费为："<<cost<<endl;
             cout<<"总收益为："<<e<<endl;
             cout<<"步骤1花费为："<<cost1<<endl;
                cout<<"步骤2花费为："<<cost2<<endl;
                cout<<"步骤3花费为："<<cost3<<endl;
         }
     }
    }
    else
    {
        cost1=l2_s*(1-l2_c)*l2_b+l2_s*l2_j+l1_s*(1-l1_c)*l1_b+l1_s*l1_j;//检测成本+丢弃成本
        l2_s*=(1-l2_c);
        l1_s*=(1-l1_c);
        l1_c1=0,l2_c1=0;
        cost1+=l2_s*c_z;//装配成本
        c_s=l2_s;//成品数量
        l1_s=0,l2_s=0;//现在部件1和2的数量
        if(l3==0)//成品不检测
     {
        cost2=0;
        c_ss=c_s;//售卖数量与之前相等
        cost+=cost2;
         e=c_ss*c_sj;//收益
        c_c1=1-(1-l1_c1)*(1-l2_c1)*(1-c_c);//处理后的次品率
        uc_s=c_ss*c_c1;//不合格的数量
        cost3=uc_s*uc_d;//调换损失
        //重复步骤3




        
        //
     }
     else//成品检测
     {
          c_c1=1-(1-l1_c1)*(1-l2_c1)*(1-c_c);//处理后的次品率
         cost2=c_s*c_j;//成品检测成本
         c_ss=c_s*(1-c_c1);//售卖的数量
         cost+=cost2;
         e=c_ss*c_sj;//收益
          if(l4==1)//拆解,此时部件全部合格
         {
             cost3=(c_s-c_ss)*uc_cj;//拆解成本
             l1_s+=(c_s-c_ss),l2_s+=(c_s-c_ss);//现在部件1和2的数量
             cost+=cost3;
             cout<<"总花费为："<<cost<<endl;
             cout<<"总收益为："<<e<<endl;
             cout<<"步骤1花费为："<<cost1<<endl;
                cout<<"步骤2花费为："<<cost2<<endl;
                cout<<"步骤3花费为："<<cost3<<endl;
         }
         else //不拆解
         {
             cost3=(c_s-c_ss)*(l1_b+l2_b);//丢弃成本
             //此时已经结束
             cost+=cost3;
             cout<<"总花费为："<<cost<<endl;
             cout<<"总收益为："<<e<<endl;
             cout<<"步骤1花费为："<<cost1<<endl;
                cout<<"步骤2花费为："<<cost2<<endl;
                cout<<"步骤3花费为："<<cost3<<endl;
         }
     }
    }
   
   
}

int main()
{
    l1_c=0.1,l1_b=4,l1_j=2,l2_c=0.1,l2_b=18,l2_j=3,c_c=0.1,c_z=6,c_j=3,c_sj=56,uc_d=6,uc_cj=5;
    l1_s=4000,l2_s=4000;

    cout<<"不检测零部件1，不检测零部件2，检测成品，不拆解"<<endl;
    p1_cost(0,0,1,0);
    cout<<"--------------------------------------------"<<endl;
     l1_c=0.1,l1_b=4,l1_j=2,l2_c=0.1,l2_b=18,l2_j=3,c_c=0.1,c_z=6,c_j=3,c_sj=56,uc_d=6,uc_cj=5;
    l1_s=4000,l2_s=4000;

    cout<<"不检测零部件1，不检测零部件2，检测成品，拆解"<<endl;
    p1_cost(0,0,1,1);
    cout<<"--------------------------------------------"<<endl;

     l1_c=0.1,l1_b=4,l1_j=2,l2_c=0.1,l2_b=18,l2_j=3,c_c=0.1,c_z=6,c_j=3,c_sj=56,uc_d=6,uc_cj=5;
    l1_s=4000,l2_s=4000;

    cout<<"检测零部件1，不检测零部件2，检测成品，不拆解"<<endl;
    p1_cost(1,0,1,0);
    cout<<"--------------------------------------------"<<endl;

     l1_c=0.1,l1_b=4,l1_j=2,l2_c=0.1,l2_b=18,l2_j=3,c_c=0.1,c_z=6,c_j=3,c_sj=56,uc_d=6,uc_cj=5;
    l1_s=4000,l2_s=4000;

    cout<<"不检测零部件1，检测零部件2，检测成品，不拆解"<<endl;
    p1_cost(0,1,1,0);
    cout<<"--------------------------------------------"<<endl;
    
     l1_c=0.1,l1_b=4,l1_j=2,l2_c=0.1,l2_b=18,l2_j=3,c_c=0.1,c_z=6,c_j=3,c_sj=56,uc_d=6,uc_cj=5;
    l1_s=4000,l2_s=4000;

    cout<<"检测零部件1，检测零部件2，检测成品，不拆解"<<endl;
    p1_cost(1,1,1,0);
    cout<<"--------------------------------------------"<<endl;
    
}