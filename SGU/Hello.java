import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class Solution{
    public static void main(String args[]){
        Scanner cin = new Scanner(System.in);
        BigInteger n,L,R,M;
        BigInteger n = cin.nextBigInteger();
        L=BigInteger.ONE;
        R=n.add(BigInteger.ZERO);
        while(L.compareTo(R)<0){
            M=L.add(R).divide(BigInteger.valueOf(2));
            if(M.multiply(M).compareTo(n)<=0){
                L=M;
            }else R=M;
        }
        System.out.println(L);
    }
}
