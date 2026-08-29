#include <iostream>
using namespace std;
#include <vector>
#include <queue>
int function(vector<int> Lista){
    int count {0};
    queue<int> fila;  
    for(int i {0}; i < Lista.size(); i++){
    if(!fila.empty()){
        fila.push(Lista[i]);
    }

    return count;
    }
}


int main(){

    return 0;
}