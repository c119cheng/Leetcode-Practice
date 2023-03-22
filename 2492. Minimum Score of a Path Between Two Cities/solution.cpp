class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector< vector<pair<int, int>>> v(n+1); // adjacency list
        for(int i=0;i<roads.size();i++){
            v[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            v[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }

        // bfs
        vector<bool> visited(n+1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        int cur_min = INT_MAX;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int i=0;i<v[cur].size();i++){
                if(!visited[v[cur][i].first]){
                    q.push(v[cur][i].first);
                    visited[v[cur][i].first] = true;
                }
                cur_min = min(cur_min, v[cur][i].second);
            }
        }
        return cur_min;
    }
};