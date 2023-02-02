#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long

vector<int> LIS(vector<int> seq, int N)
{
    vector<int> lengthReturn(N);
    vector<int> length;
    lengthReturn[0] = 1;
    length.push_back(seq[0]);
    
    for (int i=1; i<N; i++) {
        if (seq[i] > length.back()) {
            length.push_back(seq[i]); //push back if simply bigger
        }
        else {
            *lower_bound(length.begin(), length.end(), seq[i]) = seq[i]; //substitute if inbetween
        }
        lengthReturn[i] = length.size();
    }
    return lengthReturn;
}

bool cmp(int a, int b)
{
    return a > b;
}

vector<int> LDS(vector<int> seq, int N)
{
    vector<int> lengthReturn(N);
    vector<int> length;
    lengthReturn[0] = 1;
    length.push_back(seq[0]);
    
    for (int i=1; i<N; i++) {
        if (seq[i] < length.back()) {
            length.push_back(seq[i]); //push back if simply smaller
        }
        else {
            *lower_bound(length.begin(), length.end(), seq[i], cmp) = seq[i]; //substitute if inbetween
        }
        lengthReturn[i] = length.size();
    }
    return lengthReturn;
}

signed main() {
    
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i=0; i<N; i++) {
        cin >> H[i];
    }
    
    vector<int> inl = LIS(H, N);
    vector<int> der = LDS(H, N);
    
    reverse(H.begin(), H.end());
    
    vector<int> inr = LIS(H, N);
    vector<int> del = LDS(H, N);
    
    reverse(inr.begin(), inr.end());
    reverse(del.begin(), del.end());
    
    int inmax = inl[0] + inr[0] - 1;
    int demax = der[0] + del[0] - 1;
    
    for (int i=0; i<N; i++) {
           cout << inl[i] + inr[i] - 1 << " ";
        cout << der[i] + del[i] - 1 << '\n';
    }
    
    for (int i=0; i<N; i++) {
        if (inl[i] + inr[i] - 1 > inmax) {
            inmax = inl[i] + inr[i] - 1;
        }
        if (der[i] + del[i] - 1 > demax) {
            demax = der[i] + del[i] - 1;
        }
    }
    
    if (inmax > demax) {
        cout << inmax << '\n';
    }
    else cout << demax << '\n';
    
    return 0;
}

