#include <iostream>
using namespace std;

long long a, b;

long long f(long long index){
    if (index == 1) {
        return 1;
    }
    return a*f(index-1)+b;
}

int main() {
    
    long long N;
    cin >> a >> b >> N;
    
    /*long long num[N+1];
    num[1] = 1;*/
    
    long long index[N];
    for (long long i=0; i<N; i++) {
        cin >> index[i];
    }
    
    for (long long i=1; i<N+1; i++) {
        cout << f(index[i]) << '\n';
    }
    
    return 0;
}
