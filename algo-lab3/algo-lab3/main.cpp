#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
using namespace std;
#define int long long
#define double long double

double formula(double point, double atFirst, double add) {
    double a = 0.0;
    a = point*atFirst / ((atFirst+add)*(atFirst+add+1));
    return a;
}

signed main() {
    
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int N, k;
    cin >> N >> k; //k = num of members
    
    vector<double> c(N), p(N); //c[i] = i's point, p[i] = # of people on i
    for (int i=0; i<N; i++) {
        cin >> c[i] >> p[i];
    }
    vector<double> add(N, 0); //add[i] = add how many people on i
    double gain = 0.0; //points gain if adding 1 person
    priority_queue<pair<double, int>> takeMax;
    for (int i=0; i<N; i++) {
        gain = c[i] / (p[i] + 1.0);
        takeMax.push(make_pair(gain, i));
    }
    
    double total = 0.0;
    pair<double, int> max;
    for (int i=0; i<k; i++) {
        max = takeMax.top();
        total += max.first;
        int index = max.second;
        add[index]++;
        takeMax.pop();
        if (p[index]!=0 || add[index]!=0) {
            takeMax.push(make_pair(formula(c[index], p[index], add[index]), index));
        }
    }
    
    cout << fixed << setprecision(10) << total;
    
    return 0;
}
