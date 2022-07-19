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


/*
Q1:
برنامه‌ای بنویسید که با دریافت n
جمله‌ی nام دنباله فیبوناچی یا همان f(n) را محاسبه کند.
چون ممکن است این مقدار بزرگ باشد، باقی‌مانده‌ی آن را به پیمانه آ محاسبه کنید

آ : 
۱۰ ** ۹ + ۷

*/

long long fibo_3(int n){
    const int MOD = 1e9 + 7;
    const int MAXN = 1e6;
    long long fib[MAXN];
    fib[0] = 0, fib[1] = 1;

    for (int i = 2; i <= n; i++){
        fib[i] = (fib[i-1] + fib[i-2]) % MOD;
    }
    return fib[n];
}

int n;
int main(){
    cin >> n;
    cout << fibo_3(n) << endl;
    return 0;
}
