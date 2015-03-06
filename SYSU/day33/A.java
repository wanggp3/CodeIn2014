import java.io.*;
import java.math.BigInteger;
import java.util.*;
public class Main{
    public static void main (String[] args){
    BigInteger a,b,na,nb;
        BigInteger f;
        a=new BigInteger("5");
        b=new BigInteger("6");
        for(int i=2;i<=50;i++){
           f=BigInteger.ONE;
           for(int j=1;j<i;j++)f=f.multiply(BigInteger.TEN);
           
           for(int c=1;c<=9;c++){
              na=f.multiply(BigInteger.valueOf(c)).add(a);
              nb=f.multiply(BigInteger.valueOf(c)).add(b);
              if(na.multiply(na).mod(f.multiply(BigInteger.TEN)).equals(na))a=na;
              if(nb.multiply(nb).mod(f.multiply(BigInteger.TEN)).equals(nb))b=nb;
           }
           System.out.println("i= "+i+"="+a.toString());
           System.out.println("i= "+i+"="+b.toString());
        }
    }
}
