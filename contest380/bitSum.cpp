#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pr(a) cout << a << endl;

// The Sum of all set bits from a range K. (1 to K)

int main()
{
  vector<int> bitSum(8, 0);

  int K = 2516;

  while (K>0){
    
    if (K <= 2){
      bitSum[K-1]++;
      --K;
      continue;
    }

    int msb = log2(K);

    int cnt = pow(2, msb);

    int values = K - cnt + 1;

    bitSum[msb] += values;

    while (msb--){
      bitSum[msb] += cnt/2;
    }

    K -= cnt;
  }

  reverse(bitSum.begin(), bitSum.end());

  copy(bitSum.begin(), bitSum.end(), ostream_iterator<int>(cout, " "));



  return 0;
}
