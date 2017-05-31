
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author rahul
 */
public  class main {
  public static void main (String[] args) throws java.lang.Exception {
        BufferedReader inp = new BufferedReader (new InputStreamReader(System.in));
    int T= Integer.parseInt(inp.readLine());

    for(int i=0;i<T;i++) {
        String s= inp.readLine();
        int[] m= new int[2];
        m[0]=inp.read();
        m[1]=inp.read();

        // Checking whether I am taking the inputs correctly
        System.out.println(s);
        System.out.println(m[0]);
        System.out.println(m[1]);
    
}
   
} }

