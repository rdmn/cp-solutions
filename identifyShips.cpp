#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;


map<int,int> identifyShips(vector<vector<int>> mat){

    // FAST;
    // FILE;
    
    int row[] = {1, 0, -1, 0};
    int col[] = {0, 1, 0, -1};

    int N = mat[0].size();
    int M = mat.size();
    
  
    int flag=0;
    vector<vector<int>> processed;
    processed.resize(M, vector<int>(N));

    map<int,int> ans;

    for(int i =0;i<M;i++)
        for(int j=0;j<N;j++)
            processed[i].push_back(0);

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if ((mat[i][j] == 1 || mat[i][j] == 3) && processed[i][j] == 0)
            {   
                
                int size = 1;
                if(mat[i][j]==3)  flag = 1;

                queue<pair<int, int>> q;
                q.push(make_pair(i, j));

                processed[i][j] = 1;

                while (!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++)
                    {
                        if ((x + row[k] >= 0 && x + row[k] < M && y + col[k] >= 0 && y + col[k] < N) 
                        && (mat[x + row[k]][y + col[k]] != 2) && (mat[x + row[k]][y + col[k]] !=0) 
                        && !processed[x + row[k]][y + col[k]])
                        {
                            size++;
                            if(mat[x + row[k]][y + col[k]]==3)  flag = 1;
                            processed[x + row[k]][y + col[k]] = 1;
                            q.push(make_pair(x + row[k], y + col[k]));
                        }
                    }
                }

                if (flag == 1){
                    ans[size]++;
                    flag=0;
                }
            }
    return ans;
}


int main(){

    vector< vector<int> > mat = {   {2, 1, 0, 0, 2},
                                    {3, 2, 2, 2, 1},
                                    {1, 2, 1, 2, 3},
                                    {3, 2, 3, 2, 2},
                                    {1, 2, 1, 2, 1},
                                    {1, 2, 2, 2, 1},
                                    {2, 3, 3, 2, 2}};

    map<int,int> ans = identifyShips(mat);
    cout<<"{";
    for (auto e: ans) cout<< e.second << " : " << e.first << ", ";
    cout<< "}";
    return 0 ;
}