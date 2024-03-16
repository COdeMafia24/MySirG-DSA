int linear(int a[],int n,int x ){
    for(int i=0;i<n;i++){
        if(a[i]==x)
            return x;
    }
    return -1;
}