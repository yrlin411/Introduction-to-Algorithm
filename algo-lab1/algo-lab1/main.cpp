#include <iostream>
#include <iomanip>
#include <queue>
#include <algorithm>
using namespace std;
typedef long double ld;
typedef pair<ld,int> pai;

int main(){
    cin.tie(0);
      cin.sync_with_stdio(0);
      
      int fur,tm,mindex;
      ld total=0,num;
      pai max;
      cin >> fur >> tm;
      
      ld point[fur];
      ld first[fur];
      ld people[fur];
      priority_queue<pai> pq;
      
      for(int i=0;i<fur;i++){
          people[i] = 0;
          cin >> point[i] >> first[i];
          num = point[i]/ld(first[i]+1);
          pq.push(make_pair(num,i));
    }
    
    for(int i=0;i<tm;i++){
        max = pq.top();
//        cout << max.first<< '\n';
        mindex = max.second;
        total += max.first;
        people[mindex]++;
//        cout << people[mindex] << '\n';
        pq.pop();
//        cout << pq.top().first << '\n';
        if(first[mindex]!=0 || people[mindex]!=0){
            num = point[mindex]*first[mindex]/((people[mindex]+first[mindex])*(people[mindex]+first[mindex]+1));
//            cout << num << endl;
            pq.push(make_pair(num,mindex));
//            cout << pq.top().first << '\n';
        }
        
    }
    
    cout << fixed << setprecision(7) << total;
}
