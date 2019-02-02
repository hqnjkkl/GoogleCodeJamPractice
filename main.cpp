////
////  main.cpp
////  googleCodeJam
////
////  Created by HuQiaoNan on 14-8-18.
////  Copyright (c) 2014年 HuQiaoNan. All rights reserved.
////
//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//struct Num
//{
//    int led[7];
//};
//vector<Num> myc(10);
//
//void myinit()
//{
//    Num num; //9 -4
//    
//    for(int i=0;i<7;i++)
//    {
//        num.led[i] = 1;
//    }
//    num.led[4] = 0;
//    myc[9] = num;
//    //8 - 
//    for(int i=0;i<7;i++)
//    {
//        num.led[i] = 1;
//    }
//    myc[8] = num;
//    //7 - 3,4,5,6
//    for(int i=0;i<7;i++)
//    {
//        num.led[i] = 1;
//    }
//    for(int i=3;i<7;i++)
//    {
//        num.led[i] = 0;
//    }
//     myc[7] = num;
//    //6-1
//    for(int i=0;i<7;i++)
//    {
//        num.led[i] = 1;
//    }
//        num.led[1] = 0;
//    myc[6] = num;
//    //5-1,4
//    for(int i=0;i<7;i++)
//    {
//        num.led[i] = 1;
//    }
//    num.led[1] = 0;
//    num.led[4] = 0;
//    myc[5]=num;
//    //4-0,3,4
//    for(int i=0;i<7;i++)
//    {
//        num.led[i] = 1;
//    }
//    num.led[1] = 0;
//    num.led[3] = 0;
//    num.led[4] = 0;
//    myc[4]=num;
//    //3-4,5
//    for(int i=0;i<7;i++)
//    {
//        num.led[i] = 1;
//    }
//    num.led[4] = 0;
//    num.led[5] = 0;
//    myc[3]=num;
//    
//    //2-2,5
//    for(int i=0;i<7;i++)
//    {
//        num.led[i] = 1;
//    }
//    num.led[2] = 0;
//    num.led[5] = 0;
//    myc[2]=num;
//    
//    //1-0,3,4,5,6
//    for(int i=0;i<7;i++)
//    {
//        num.led[i] = 0;
//    }
//    num.led[1] = 1;
//    num.led[2] = 1;
//    myc[1]=num;
//    
//    //0-6
//    for(int i=0;i<7;i++)
//    {
//        num.led[i] = 1;
//    }
//    num.led[6] = 0;
//    myc[0]=num;
//        
//}
//
//int dfsJudge(Num &broken,vector<Num> &input,vector<Num> &res,int cur,int cloCur)
//{
//    if(cur<0)
//    {
//        return 1;
//    }
//    for(int i=0;i<7;i++)
//    {
//        if(input[cur].led[i]==myc[cloCur].led[i])
//        {
//            if(input[cur].led[i]==1)
//            {
//                if(broken.led[i]==0)
//                {
//                    return 0;
//                }
//            }
//        }else
//        {
//            if(myc[cloCur].led[i]==1)
//            {
//                // should be bright
//                if(broken.led[i]==1)
//                {
//                    return 0;
//                }
//            }else // should not be lit
//            {
//                if(broken.led[i]==0)
//                {
//                    return 0;
//                }
//            }
//        }
//    }
//    return 1;
//}
//int getNum(Num &comp,vector<Num> &res,int n,vector<Num> &input)
//{
//    Num broken;
//    int isGood=1;
//    for(int i=9;i>=0;i--)
//    {
//        for(int j=0;j<7;j++)
//        {
//            broken.led[j] = 1;
//        }
//        isGood = 1;
//        for(int j=0;j<7;j++)
//        {
//            if((myc[i].led[j]==1)&&(comp.led[j]==0))
//            {
//                broken.led[j] = 0;// the place is broken;
//            }else if((myc[i].led[j]==0)&&(comp.led[j]==1))
//            {
//                isGood = 0;
//                break;
//            }
//        }
//        int cloCur = i-1;
//        int curs = n-2;
//        int isGood2 = 1;
//        //从当前位置开始判断，是否对应都在相应位置有缺口
//        if(isGood==1)
//        {
//            while(curs>=0)
//            {
//                if(cloCur==-1)
//                {
//                    cloCur = 9;
//                }
//                isGood2 = dfsJudge(broken,input,res,curs,cloCur);
//                cloCur--;
//                curs--;
//                if(isGood2==0)
//                {
//                    break;
//                }
//            }
//            if(isGood2==1)
//            {
//                if(cloCur==-1)
//                {
//                    cloCur = 9;
//                }
//                Num res1 = myc[cloCur];
//                for(int i=0;i<7;i++)
//                {
//                    if(broken.led[i]==0)
//                    {
//                        res1.led[i] = 0;
//                    }
//                }
//                res.push_back(res1);
//            }
//        }
//            }
//    return isGood;
//}
//
//
//int main()
//{
//    myinit();
//    int t,n,i,j,k;
//    char c;
//    char leds[10];
//    vector<Num> res;
//    scanf("%d",&t);
//    
//    for(i=0;i<t;i++)
//    {
//        scanf("%d",&n);
//        vector<Num> input(n);
//        for(j=0;j<n;j++)
//        {
//            Num num1;
//            scanf("%s",leds);
//            for(k=0;k<7;k++)
//            {
//                num1.led[k] = leds[k]-'0';
//            }
//            input[n-j-1] = num1;
//        }
//        
//        getNum(input[n-1],res,n,input);
//        printf("Case #%d: ",i+1);
//        if(res.size()==1)
//        {
//            for(k=0;k<7;k++)
//            {
//                printf("%d",res[0].led[k]);
//            }
//            printf("\n");
//        }else if(res.size()==0)
//        {
//            printf("ERROR!\n");
//        }else
//        {
//            int len = 10;
//            vector<vector<int> > myv(len,vector<int>(len,0));
//            
//            printf("%d\n",res.size());
//        }
//        res.clear();
//    }
//    // insert code here...
//   // std::cout << "Hello, World!\n";
//    return 0;
//}
//
//
//
