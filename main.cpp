
#include <iostream>
#include <vector>
using namespace std;


int max(int a, int b) { return (a > b) ? a : b; }


void  knapSack(int W, vector <int>&wt, vector <int>&val, int n)
{

    
    int i, w;
    vector<vector<int>> K(n+1 , vector<int>(W+1));
    vector <int> el(n);
    for (int i = 0; i < el.size(); i++) {
        el[i] = 0;
    }
    
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +
                    K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    int res = K[n][W];
    cout << res << endl;

    w = W;
    for (i = n; i > 0 && res > 0; i--) {

        
        if (res == K[i - 1][w])
            continue;
        else {

            
            
            el[i-1] = 1;
            
            res = res - val[i - 1];
            w = w - wt[i - 1];
        }
    }
    for (int i = 0; i < el.size(); i++) {
        cout << el[i] << ' ';
    }
}


int main()
{
    int n, K;
    cin >> n >> K;
    vector<int> val(n);
    vector<int> wt(n);
    
    for (int i = 0; i < n; i++) {
        int w, v;
        cin >> v >> w;
        val[i] = v;
        wt[i] = w;
    }
    
     knapSack(K, wt, val, n);
    return 0;
}

