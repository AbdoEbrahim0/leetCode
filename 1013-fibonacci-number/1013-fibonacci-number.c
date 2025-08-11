
//recursion
// int fib(int n) {
//     if(n==0)
//     return 0;
//     if (n <= 2)
//         return 1;
    
//     else
//     return fib(n-1) + fib(n-2);
// }

int fib(int n) {
    //(0)=0  (1)=1
    int prev=0, cur=1,out=0;
        if(n==1)
        return 1;
        if(n==0)
        return 0;
    for (int x = 2; x <= n; x++)
    {
        out = (prev + cur);
        prev = cur;
        cur = out;
    }
    return out;
}
/*
n=3
n=2     ,n=1
n=1,n=0 ,n=1

*/