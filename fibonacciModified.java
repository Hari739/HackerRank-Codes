import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    
    
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
          
        Scanner s = new Scanner(System.in);
           int n;
            BigInteger a,b;
            a= s.nextBigInteger();
            b= s.nextBigInteger();
            n= s.nextInt();
         BigInteger[] t= new BigInteger[n];
         t[0]=a;
         t[1]=b;
             for(int i=2;i<n;i++){
              t[i]= t[i-1].pow(2).add(t[i-2]);
          }  
            System.out.print(t[n-1]);
    
    
    }
}
