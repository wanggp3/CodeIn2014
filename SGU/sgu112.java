import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class Solution{
    public static BigInteger getans(int x,int y){
        BigInteger ans=BigInteger.valueOf(x);
        for(int i=1;i<y;i++){
            ans=ans.multiply(BigInteger.valueOf(x));
        }
        return ans;
    }
    public static void main(String args[]){
        Scanner cin = new Scanner(System.in);
        int  a,b;
        a=cin.nextInt();
        b=cin.nextInt();
        BigInteger tmp=getans(b,a);
        System.out.println(getans(a,b).subtract(tmp));
    }
}
