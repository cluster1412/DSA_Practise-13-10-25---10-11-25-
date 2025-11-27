#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct pair_hash {
    size_t operator()(const pair<int,int>& p) const {
        return hash<long long>()(((long long)p.first << 32) ^ p.second);
        }
    };
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    bool solve1(vector<int>& target,int x,int y,unordered_set<pair<int,int>,pair_hash> &vis){
        int cnt = 0;
        queue<pair<int,int>> q;
        q.push({x,y});

        while(!q.empty()){
            pair<int,int> f = q.front();
            q.pop();
            int x1 = f.first;
            int y1 = f.second;

            if(x1==target[0] && y1==target[1]) return true;

            for(int i = 0; i < 4; i++) {
            int nx = x1 + dx[i];
            int ny = y1 + dy[i];

            if (nx < 0 || ny < 0 || nx >= 1000000 || ny >= 1000000) continue;

            if (!vis.count({nx, ny})) {
                vis.insert({nx, ny});
                q.push({nx, ny});
                cnt++;
                if (cnt > 20000) return true;
            }
        }
        }
        return false;
    }
    bool solve(vector<int>& target,int x,int y,unordered_set<pair<int,int>,pair_hash>& vis){
        int cnt = 0;
        queue<pair<int,int>> q;
        q.push({x,y});

        while(!q.empty()){
            pair<int,int> f = q.front();
            q.pop();
            int x1 = f.first;
            int y1 = f.second;

            if(x1==target[0] && y1==target[1]) return true;

            for(int i = 0; i < 4; i++) {
            int nx = x1 + dx[i];
            int ny = y1 + dy[i];

            if (nx < 0 || ny < 0 || nx >= 1000000 || ny >= 1000000) continue;

            if (!vis.count({nx, ny})) {
                vis.insert({nx, ny});
                q.push({nx, ny});
                cnt++;
                if (cnt > 20000) return true;
            }
        }
        }
        return false;
    }

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        if(blocked.size()==0 || source==target) return true;

        unordered_set<pair<int,int>,pair_hash> vis,vis1;
        for(auto i : blocked){
            vis.insert({i[0],i[1]});
            vis1.insert({i[0],i[1]});
        }
        return solve(target,source[0],source[1],vis) && solve1(source,target[0],target[1],vis1);
    }
};