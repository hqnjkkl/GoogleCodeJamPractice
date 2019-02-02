//
//  googleP2.cpp
//  googleCodeJam
//
//  Created by HuQiaoNan on 14-8-18.
//  Copyright (c) 2014年 HuQiaoNan. All rights reserved.
//

//#include "googleP2.h"
//#include <stdio.h>
//#include <iostream>
//
//using namespace std;
//
//int map[23][23];
//int map2[23][23];
//int map3[23][23];
//
//void change(int n);
//void copy(int n);
//void output(int n);
//void change2(int n);
//void copy2(int n);
//void swaprl(int n,int m[23][23]);
//void swaprl2(int n,int m[23][23]);
//
//void initial()
//{
//    int i,j;
//    for(i=0;i<23;i++)
//    {
//        for(j=0;j<23;j++)
//        {
//            map[i][j] = map2[i][j] = map3[i][j] = 0;
//        }
//    }
//    return ;
//}
//void copy(int n)
//{
//    int i=0,j=0,k=0;
//    for(j=0;j<n;j++)
//    {
//        for(k=0;k<n;k++){
//            map2[j][k] = 0;
//        }
//    }
//
//    for(i=0;i<n;i++)
//    {
//        j = k = n-1;
//        while(j>=0)
//        {
//            if(map[i][j]!=0)
//            {
//                map2[i][k] = map[i][j];
//                j--;
//                k--;
//            }else
//            {
//                while(j>=0&&map[i][j]==0)
//                {
//                    j--;
//                }
//            }
//        }
//    }
//        return ;
//}
//    
//void change(int n)
//{
//    int i=0,j=0,k=0;
//    for(j=0;j<n;j++)
//    {
//        for(k=0;k<n;k++)
//        {
//            map3[j][k] = 0;
//        }
//    }
//    for(k=0;k<n;k++)
//    {
//    i = n-1;
//    j = n-1;
//    while(i>=0)
//    {
//        if(i>0)
//        {
//            if(map2[k][i]==map2[k][i-1])
//            {
//                map3[k][j] = map2[k][i]*2;
//                i-=2;
//                j--;
//            }else
//            {
//                map3[k][j] =map2[k][i];
//                i--;
//                j--;
//            }
//        }else
//        {
//            map3[k][j] =map2[k][i];
//            i--;
//            j--;
//        }
//    }
//   }
//    return ;
//}
//
//void change2(int n)
//{
//    int i,j,k;
//    
//    for(j=0;j<n;j++)
//    {
//        for(k=0;k<n;k++)
//        {
//            map3[j][k] = 0;
//        }
//    }
//    for(k=0;k<n;k++)
//    {
//        i = j = 0;
//        while(i<n)
//        {
//            if(i<n-1)
//            {
//                if(map2[i][k]==map2[i+1][k])
//                {
//                    map3[j][k] = map2[i][k]*2;
//                    i+=2;
//                    j++;
//                }else
//                {
//                    map3[j][k] = map2[i][k];
//                    i++;
//                    j++;
//                }
//            }else
//            {
//                map3[j][k] = map2[i][k];
//                i++;
//                j++;
//            }
//        }
//    }
//    return ;
//}
//void copy2(int n)
//{
//    int i,j,k;
//    for(j=0;j<n;j++)
//    {
//        for(k=0;k<n;k++){
//            map2[j][k] = 0 ;
//        }
//        
//        for(i=0;i<n;i++) //column
//        {
//            j = k = 0;
//            while(j<n)
//            {
//                if(map[j][i]!=0)
//                {
//                    map2[k][i] = map[j][i];
//                    j++;
//                    k++;
//                }else
//                {
//                    while(j<n&&map[j][i]==0)
//                    {
//                        j++;
//                    }
//                }
//            }
//        }
//        
//    }
//    return ;
//}
//
//    void output(int n)
//    {
//        int i,j;
//        for(i=0;i<n;i++)
//        {
//            for(j=0;j<n;j++)
//            {
//                printf("%d",map3[i][j]);
//                if(j!=n-1)
//                {
//                    printf(" ");
//                }else
//                {
//                    printf("\n");
//                }
//            }
//        }
//    }
//    
//    void swaprl(int n,int myMap[23][23])
//    {
//        int i,j,k;
//        int tmp = 0;
//        for(i=0;i<n;i++)
//        {
//            j = 0;
//            k = n-1;
//            while(j<k)
//            {
//                tmp = myMap[i][j];
//                myMap[i][j] = myMap[i][k];
//                myMap[i][k] = tmp;
//                j++;
//                k--;
//            }
//        }
//        return ;
//    }
//    
//    void swaprl2(int n,int myMap[23][23])
//    {
//        int i,j,k;
//        int tmp = 0;
//        for(i=0;i<n;i++)
//        {
//            j = 0;
//            k = n-1;
//            while(j<k)
//            {
//                tmp = myMap[j][i];
//                myMap[j][i] = myMap[k][i];
//                myMap[k][i] = tmp;
//                j++;
//                k--;
//            }
//        }
//        return ;
//    }
//
//
//
//int main()
//{
//    int t=0,n=0;
//    char dir[10];
//    
//    freopen("/Users/huqiaonan/B-large-practice.in","r", stdin);
//    
//    freopen("/Users/huqiaonan/t3.txt","w", stdout);
//    
//    scanf("%d",&t);
//    int i,j,k;
//    
//    for(i=0;i<t;i++){
//        scanf("%d",&n);
//        scanf("%s",dir);
//        initial();
//        for(j=0;j<n;j++)
//        {
//            for(k=0;k<n;k++){
//                scanf("%d",&map[j][k]);
//            }
//        }
//        printf("Case #%d:\n",i+1);
//        if(dir[0]=='r')
//        {
//            copy(n);
//            change(n);
//            output(n);
//        }else if(dir[0]=='l'){
//            swaprl(n,map);
//            copy(n);
//            change(n);
//            swaprl(n,map3);
//            output(n);
//        }else if(dir[0]=='u'){
//            copy2(n);
//            change2(n);
//            output(n);
//        }else if(dir[0]=='d'){
//            swaprl2(n,map);
//            copy2(n);
//            change2(n);
//            swaprl2(n,map3);
//            output(n);
//        }
//        
//    }
//    return 0;
//}

