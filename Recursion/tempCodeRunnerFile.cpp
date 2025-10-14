if(n==1) return 1; 
    if(n==0) return 0;
    
    return nthFibonacci(n-1) + nthFibonacci(n-2);
}