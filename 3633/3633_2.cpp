#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
typedef long long LL;
using namespace std;

int main()
{
     freopen("input.txt", "r", stdin);
     char value[13]={'3','4','5','6','7','8','9','10','J','Q','K','A','2'};    
     string s;
     getline(cin,s);
     int i,j,k,w;
     int type1,type2;// 1 个 2 对 3：三个 4：炸弹 5：顺子 6：个王 7:对王
     for(i=0;i<s.size();i++) //计算输入的 两副牌的类型
     {
          if(s[i]=='-')
          {
               if(i==1)
                    type1=1;
               else if(s[1]!=' ')  //s[1]不等于空格就是王
               {
                    if(i==11)
                         type1=7;   //这种情况例子：joker JOKER-1 2 3 4 5
                    else
                         type1=6;
               }
               else if(i==3)
                    type1=2;
               else if(i==5)
                    type1=3;
               else if(i==7)
                    type1=4;
               else
                    type1=5;
               break;
          }
     }
    
     j=i;
    
     if(s.size()==j+2)
          type2=1;
     else if(s[j+2]!=' ')    //s[1]不等于空格就是王
     {
          if(s.size()-j-1==11)
               type2=7;       //这种情况例子：1 2 3 4 5-joker JOKER
          else
               type2=6;
     }
     else if(s.size()-j-1==3)
          type2=2;
     else if(s.size()-j-1==5)
          type2=3;
     else if(s.size()-j-1==7)
          type2=4;
     else
          type2=5;    
    
     if(type1==type2)   //如果类型相同
     {
          if(type1==6 && type2==6)
               if(s[0]=='J')
                    for(w=0;w<j;w++)
                         cout<<s[w];
                    else
                         for(w=j+1;w<s.size();w++)
                              cout<<s[w];    
                         else
                         {
                              for(i=0;i<13;i++)  //通过索引表 比较两副牌第一张牌的大小
                                   if(s[0]==value[i])
                                        break;

                                   for(k=0;k<13;k++)
                                        if(s[j+1]==value[k])
                                             break;
                                       
                                        if(i>k)
                                             for(w=0;w<j;w++)
                                                  cout<<s[w];
                                             else
                                                  for(w=j+1;w<s.size();w++)
                                                       cout<<s[w];                   
                         }
     }
     else
     {
          if(type1==6)   //单张牌如果是王  单独处理
               for(w=0;w<j;w++)
                    cout<<s[w];
               else if(type2==6)
                    for(w=j+1;w<s.size();w++)
                         cout<<s[w];    
                   
                    else if(type1==4)
                    {
                         if(type2==7)
                              for(w=j+1;w<s.size();w++)
                                   cout<<s[w];    
                              else
                                   for(w=0;w<j;w++)
                                        cout<<s[w];
                    }
                    else if(type1==7)
                    {
                         for(w=0;w<j;w++)
                              cout<<s[w];    
                    }

                    else if(type2==4 || type2==7)
                         for(w=j+1;w<s.size();w++)
                              cout<<s[w];    
                         else
                              cout<<"ERROR";
     }
     cout<<endl;
     //     cout<<type1<<"     "<<type2<<endl;
     return 0;
}