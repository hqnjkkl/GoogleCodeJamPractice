//
//  surroudedRegion.cpp
//  googleCodeJam
//
//  Created by HuQiaoNan on 14-8-20.
//  Copyright (c) 2014年 HuQiaoNan. All rights reserved.
//

#include "surroudedRegion.h"

//
//  main.cpp
//  googleCodeJam
//
//  Created by HuQiaoNan on 14-8-18.
//  Copyright (c) 2014年 HuQiaoNan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Points
{
    int x;
    int y;
    Points(){};
    Points(int x,int y):x(x),y(y){}
};
//9:35->
class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int len1 = board.size(),len2=0;
        int i=0,j=0,k;
        bool change = false;
        vector<Points> changes;
        if(len1>0)
        {
            len2= board[0].size();
            vector<vector<bool> > visit(len1,vector<bool>(len2,false));
            for(i=0;i<len1;i++)
            {
                for(j=0;j<len2;j++){
                    if(!visit[i][j])
                    {
                        if(board[i][j]=='O')
                        {
                            change = true;
                            if(i==0||i==len1-1||j==0||j==len2-1)
                            {
                                change = false;
                            }
                            Points p(i,j);
                            visit[i][j] = true;
                            bfs(visit,p,changes,board,change);
                            if(change)
                            {
                                for(k=0;k<changes.size();k++)
                                {
                                    board[changes[k].x][changes[k].y] = 'X';
                                }
                            }
                            changes.clear();
                        }else
                        {
                            visit[i][j] = true;
                        }
                    }
                }
            }
        }
        return ;
    }
    void bfs(vector<vector<bool> > &visit,Points p,vector<Points> &changes,vector<vector<char>> &board,bool &change)
    {
        queue<Points> que;
        que.push(p);
        changes.push_back(p);
        Points p2;
        int i,j,len,x,y;
        int len1 = board.size(),len2 = board[0].size();
        int dir1[4] = {0,0,1,-1};
        int dir2[4] = {-1,1,0,0};
        while(que.size()>0)
        {
            len = que.size();
            for(i=0;i<len;i++)
            {
                p2 = que.front();
                que.pop();
                for(j=0;j<4;j++)
                {
                    x = p2.x+dir1[j];
                    y = p2.y+dir2[j];
                    if(x<0||x>=len1||y<0||y>=len2||visit[x][y]||board[x][y]=='X')
                    {
                        continue;
                    }else
                    {// the condition to change
                        if(x==0||x==len1-1||y==0||y==len2-1)
                        {
                            change = false;
                        }
                        visit[x][y] = true;
                        Points p3(x,y);
                        que.push(p3);
                        changes.push_back(p3);
                    }
                }
            }
        }
    }
};