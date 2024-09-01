int reverse(int x){
    int rev=0,r=0;
    while(x!=0)
    {
        r=x%10;
        rev=(10*rev)+r;
        x/=10;
    }
    return rev;
}
