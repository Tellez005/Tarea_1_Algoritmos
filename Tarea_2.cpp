#include <bits/stdc++.h>

using namespace std;

int main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    int m;

    cin >> m;

    vector<pair<long long,long long>> meetings(m);

    for (int i = 0; i < m; i++) {

        long long s, e;

        cin >> s >> e;

        meetings[i] = {s, e};

    }

    // TODO: compute minimum number of rooms required

    int rooms = 0;

    cout << rooms << "\n";

    return 0;

}