#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
   vector <string> putStar(string s){
      vector <string> ret;
      for(int i = 0; i < s.size(); i++){
         string temp = s.substr(0, i) + "*" + s.substr(i + 1);
         ret.push_back(temp);
      }
      return ret;
   }
   int minMutation(string start, string end, vector<string>& bank) {
      unordered_map < string, vector <string> > graph;
      for(int i = 0; i < bank.size(); i++){
         string s = bank[i];
         vector <string> out = putStar(bank[i]);
         for(int j = 0; j < out.size(); j++){
            graph[out[j]].push_back(s);
         }
      }
      queue <string> q;
      q.push(start);
      set <string> visited;
      visited.insert(start);
      for(int lvl = 1; !q.empty(); lvl++){
         int sz = q.size();
         while(sz--){
            string node = q.front();
            q.pop();
            vector <string> out = putStar(node);
            for(int i = 0; i < out.size(); i++){
               string u = out[i];
               for(int j = 0; j < graph[u].size(); j++){
                  string v = graph[u][j];
                  if(visited.count(v)) continue;
                  if(v == end) return lvl;
                  visited.insert(v);
                  q.push(v);
               }
            }
         }
      }
      return -1;
   }
};
