/*
Andres Tellez Bermudez A0164090 
01/09/2026 Tarea 1 Ejercicio 1
*/

#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

void merge(vector<ll> &arr, int izquierda, int derecha, int mid, ll &contador) {
    vector<ll> temporal;

    int i = izquierda;
    int j = mid + 1;

    while (i <= mid && j <= derecha) {
        if (arr[i] <= arr[j]) {
            temporal.push_back(arr[i]);
            i++;
        } else {
            temporal.push_back(arr[j]);
            j++;
            contador += mid - i +1; 
        }
    }

    while (i <= mid) {
        temporal.push_back(arr[i]);
        i++;
    }

    while (j <= derecha) {
        temporal.push_back(arr[j]);
        j++;
    }

    for (int k = 0; k < temporal.size(); k++) {
        arr[izquierda + k] = temporal[k];
    }
}

void mergeSort(vector<ll> &Array, int izquierda, int derecha, ll &contador) {
    if (izquierda >= derecha) {
        return;
    }

    int mid = izquierda + (derecha - izquierda) / 2;

    mergeSort(Array, izquierda, mid, contador);
    mergeSort(Array, mid + 1, derecha, contador);

    merge(Array, izquierda, derecha, mid, contador);
}

int main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<long long> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    

    ll inv = 0;


    mergeSort(a, 0, a.size()-1, inv); 
    for(auto i: a){
        cout<<i<<" "; 
    }
    cout << inv << "\n";
    cout<<endl; 
    cout<<inv<<endl; 
    return 0;

}