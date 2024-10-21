#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int bucket[51][51];
bool is_cloud[51][51];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N, M, d, s;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> bucket[i][j];
        }
    }

    vector<pair<int, int>> clouds;
    clouds.push_back({N - 1, 0});
    clouds.push_back({N - 1, 1});
    clouds.push_back({N - 2, 0});
    clouds.push_back({N - 2, 1});

    while(M--){
        cin >> d >> s;
        d--;
        memset(is_cloud, 0, sizeof(is_cloud));
        vector<pair<int, int>> clouds_copy;
        for(auto cloud : clouds){
            int x = cloud.first;
            int y = cloud.second;
            int nx = (x + dx[d] * s) % N;
            int ny = (y + dy[d] * s) % N;
            if(nx < 0) nx += N;
            if(ny < 0) ny += N;
            bucket[nx][ny]++;
            clouds_copy.push_back({nx, ny});
            is_cloud[nx][ny] = true;
        }

        for(auto cloud : clouds_copy){
            int x = cloud.first;
            int y = cloud.second;
            int cnt = 0;
            for(int i = 1; i <= 7; i += 2){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx > N - 1 || ny > N - 1) continue;
                if(bucket[nx][ny]) cnt++;
            }
            bucket[x][y] += cnt;
        }

        clouds.clear();
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(bucket[i][j] < 2 || is_cloud[i][j]) continue;
                clouds.push_back({i, j});
                bucket[i][j] -= 2;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            ans += bucket[i][j];
        }
    }
    cout << ans;
}