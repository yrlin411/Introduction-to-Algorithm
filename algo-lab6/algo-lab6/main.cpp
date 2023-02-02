/*#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define int long long
#define infinity 1000000000007

class truck {
public:
    int x;//which truck
    int y;//at most y factory
    int c;//at most c fan
};

class fridge {
public:
    int x;//from x
    int y;//to y
    int c;//capacity c
};

signed main() {
    
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int F, N, M;
    cin >> F >> N >> M;//F farms, N factories, M convenience store
    
    vector<int> ingredient(F, 0);
    for (int i=0; i<F; i++) {
        cin >> ingredient[i];
    }
    vector<int> produce(N, 0);
    for (int i=0; i<N; i++) {
        cin >> produce[i];
    }
    vector<int> store(M, 0);
    for (int i=0; i<M; i++) {
        cin >> store[i];
    }
    
    int C;//C trucks
    cin >> C;
    vector<truck> Truck(C);
    for (int i=0; i<C; i++) {
        cin >> Truck[i].x >> Truck[i].y >> Truck[i].c;
    }
    
    int T;//T refrigerator van (capacity)
    cin >> T;
    vector<fridge> Fridge(T);
    for (int i=0; i<T; i++) {
        cin >> Fridge[i].x >> Fridge[i].y >> Fridge[i].c;
    }
    
    int K;
    cin >> K;//daily less than or equal to K
    
    
    return 0;
}
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define int long long
#define infinity 1000000000007

class edges {
public:
    int a;
    int b;
    int weight;
};

vector<bool> visited;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> smallest;
void dijkstra(int N, vector<int>& distance, vector<vector<pair<int, int>>>& adjacent) {
    
    while (smallest.empty() == false) {
        int current = smallest.top().second;
        smallest.pop();
        
        for (auto i : adjacent[current]) {
            int next = i.second;
            int weight = i.first;
            if (visited[i.second] == true) {
                continue;
            }
            if (distance[next] > distance[current] + weight) {
                distance[next] = distance[current] + weight;
                smallest.push(i);
                visited[i.second] = true;
            }
        }
    }
    
    return;
}

signed main() {
    
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int N, M;//N = # of vertices, M = # of edges
    cin >> N >> M;
    
    vector<vector<pair<int, int>>> adjacent(N);
    vector<vector<pair<int, int>>> reversed(N);
    vector<edges> Edge(M);
    for (int i=0; i<M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adjacent[a-1].push_back(make_pair(c, b-1));
        reversed[b-1].push_back(make_pair(c, a-1));
        Edge[i].a = a-1;
        Edge[i].b = b-1;
        Edge[i].weight = c;
    }
    
    //dijkstra
    vector<int> distance(N, infinity);
    distance[0] = 0;
    visited.resize(N, false);
    smallest.push(make_pair(0, 0));//dist[0] = 0 (pair(dist, vertex))
//    cout << dijkstra(N, distance, adjacent) << '\n';
    dijkstra(N, distance, adjacent);
    
    //dijkstra in reverse
    vector<int> rdistance(N, infinity);
    rdistance[N-1] = 0;
    visited.resize(N, false);
    smallest.push(make_pair(0, N-1));
//    cout << dijkstra(1, rdistance, reversed) << '\n';
    dijkstra(N, rdistance, reversed);
    
    /*for (int i=0; i<N; i++) {
        cout << shortest[i] << " " ;
    }
    cout << '\n';
    for (int i=0; i<N; i++) {
        cout << rshortest[i] << " " ;
    }
    cout << '\n';*/
    
    for (int i=0; i<M; i++) {
        int ans = Edge[i].weight - (distance[N-1] - distance[Edge[i].a] - rdistance[Edge[i].b]);
        if (ans > Edge[i].weight || distance[Edge[i].a] == infinity || rdistance[Edge[i].b] == infinity) {
            cout << -1 << '\n';
        }
        else cout << ans << '\n';
    }
    
    return 0;
}

