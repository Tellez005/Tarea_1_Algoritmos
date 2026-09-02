/*
Andres Tellez Bermudez A0164090 
01/09/2026 Tarea 1 Ejercicio 3
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, T;

    cin >> n >> T;

    vector<int> t(n);

    vector<ll> v(n);

    for (int i = 0; i < n; i++) {
        cin >> t[i] >> v[i];
    }

    vector<ll> dp(T + 1, 0);

    for (int i = 0; i < n; i++) {

        for (int tiempo = T; tiempo >= t[i]; tiempo--) {

            dp[tiempo] = max(
                dp[tiempo],
                dp[tiempo - t[i]] + v[i]
            );
        }
    }

    ll best = dp[T];

    cout << best << "\n";

    return 0;
}