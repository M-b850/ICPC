#     دنباله اعداد فیبوناچی

بسیاری از فرآیندهای طبیعی از جمله ترکیب ساختار بدن موجودات زنده نظم مشخصی دارند و از دنباله اعدادی تبعیت می‌کنند که امروزه با نام دنباله اعداد فیبوناچی (فیبوناتچی - Fibonacci) شناخته می‌شود. مشهورترین خاصیت این اعداد نسبت دو جمله متوالی آنها به ازای جملات بزرگ دنباله است که به عدد طلایی مشهور است.

این دنباله از جمله دنباله‌های عددی است که در طراحی سوالات مسابقات برنامه‌نویسی نیز استفاده می‌شود و گاهی در حل سوالات کاربرد دارد. از این رو آشنایی با روش‌های مختلف تولید جملات آن حائز اهمیت است.

**تعریف**:
 دنباله اعداد فیبوناچی روی اعداد حسابی به صورت زیر تعریف می‌شود:
 

$$
fibonacci(n) = \begin{cases}
    0 & \text{if } n = 0 \\
    1 & \text{if } n = 1 \\
    fibonacci(n - 1) + fibonacci(n - 2) & \text{if } n > 1
\end{cases}
$$

همانگونه که از تعریف مشخص است، جملات این دنباله از جمع دو جمله قبلی آن با شروع از دو مقدار صفر و یک به دست می‌آید:
<br>
``
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...
``

## محاسبه بازگشتی  
ساده‌ترین راهکار برای محاسبه اعداد دنباله فیبوناچی استفاده از تابع بازگشتی زیر است:
```c++
long long fibo_1(int n){
    if(n < 2)
        return n;

    return fibo_1(n - 1) + fibo_1(n - 2);
}
```
این تابع فراخوانی تابع با مقدار n را به فراخوانی بازگشتی با دو مقدار بسیار نزدیک به n تبدیل می‌کند. بنابراین می‌توان پیش‌بینی کرد که زمان تولید خروجی نسبت به اندازه ورودی از مرتبه نمایی باشد.

 برای مثال فراخوانی‌های بازگشتی تابع برای محاسبه  $F7$ در شکل زیر آمده است:
![Tree F(7)](https://raw.githubusercontent.com/M-b850/ICPC/main/media/fibonacci/fibonacci_1.jpg)


به این ترتیب برای محاسبه $F7$ تابع مذکور $41$ بار فراخوانی می‌شود که در مقایسه با مقدار $n$ مقرون به صرفه نیست. دلیل این فراخوانی‌های زیاد تکرار در محاسبه جملات میانی است. به عنوان نمونه بر اساس شکل فوق مقدار $F2$ هشت بار به صورت تکراری محاسبه شده است.

## محاسبه با استفاده از روش برنامه‌نویسی پویا
برای رفع مشکل فراخوانی‌های تکراری در محاسبات می‌توان از روش برنامه‌نویسی پویا و حرکت از جزء به کل استفاده کرد:
```c++
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
```

مرتبه اجرایی محاسبه جمله n-ام دنباله فیبوناچی با این راهکار $Θ(n)$ است که در مقایسه با روش قبل (مرتبه نمایی) عملکرد بسیار بهتری دارد. همچنین با توجه به کنار گذاشتن فراخوانی‌های بازگشتی حافظه کمتری مصرف می‌شود.

**نکته**: در صورتی که نیاز به در اختیار داشتن تمام جملات دنباله در یک بازه مشخص باشد، این روش بهترین راهکار ممکن است و کافی‌ست مقدار f3 در هر تکرار کد فوق در یک مخزن جدا مانند آرایه ذخیره شود.


