/*
Andres Tellez Bermudez A0164090 
01/09/2026 Tarea 1 Ejercicio 2
*/

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
        cout<<"El cuarto es "<<s<<" "<<e<<endl; 
        meetings[i] = {s, e};

    }

    // TODO: compute minimum number of rooms required

    int rooms = 0;
    vector<pair<long long,long long>> rooms_check;
    for(int i {0}; i < meetings.size(); i++){
        if(rooms_check.size() == 0){
            rooms_check.push_back(meetings[i]); 
            rooms++; 
        }else{
            for(int j {0}; j < rooms_check.size(); j++){
                if(rooms_check[j].second <= meetings[i].first){
                    rooms_check[j] = meetings[i]; 
                    break; 
                }else if(j == rooms_check.size()-1){
                    rooms_check.push_back(meetings[i]); 
                    break; 
                }else{
                    rooms++; 
                }
            }
        }     


    }
    
    cout << rooms << "\n";

    return 0;

}