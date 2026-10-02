class Solution {
public:
    long long power(long long x,long long n){
        if(n==0) return 1;
        long long half = power(x,n/2);
        if(n%2==0){
            return (half*half)%1000000007;
        }
        return (x*half%1000000007*half)%1000000007;
    }
    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;

        long long ans = power(5,even)*power(4,odd);
        return ans % 1000000007;
    }
};