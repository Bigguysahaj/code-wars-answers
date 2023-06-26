int *getProductArrayExceptSelf(int *arr, int n)
{
    int *ans = new int[n];

    if(!n) return ans;
    
    if(n==1){
        ans[0] = 1; 
        return ans;
    } 
    int m = 1000000007;
    long long int prod = 1;
    int store =-1;
    int count =0;
    for(int i=0; i<n; i++){
        ans[i] = prod;
        prod=(prod*arr[i])%m;
    }

    prod = 1;

    for(int i=n-1; i>=0; i--){

        ans[i] = (ans[i]*prod)%m;
        
        prod = (prod*arr[i])%m;
    }

    return ans;
}
