#include <iostream>
using namespace std;

long long fibo_1(int n){
    if(n < 2)
        return n;

    return fibo_1(n - 1) + fibo_1(n - 2);
}

long long fibo_2(int n){
    if(n < 2)
        return n;

    int f1 = 0, f2 = 1, f3;

    for(int i = 2 ; i <= n ; i++){
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }

    return f3;
}

int main(){
    return 0;
}

