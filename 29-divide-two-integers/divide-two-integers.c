int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }
    
  
    bool is_negative = (dividend < 0) != (divisor < 0);
    
 
    long long abs_dividend = labs(dividend);
    long long abs_divisor = labs(divisor);

    long long quotient = 0;
    

    while (abs_dividend >= abs_divisor) {
        long long temp_divisor = abs_divisor;
        long long count = 1;
        
       
      
        while ((temp_divisor << 1) <= abs_dividend) {
            temp_divisor <<= 1;
            count <<= 1;
        }
        
       
        abs_dividend -= temp_divisor;
        quotient += count;
    }
    
    
    if (is_negative) {
        return (int)-quotient;
    } else {
        return (int)quotient;
    }
}