/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author rahul
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        BufferedReader inp = new BufferedReader (new InputStreamReader(System.in));
         int testCases = Integer.parseInt(inp.readLine());
         int number,fences;         
         for(int i =0;i < testCases;i++){
             number = Integer.parseInt(inp.readLine());
             fences =0;
            char grid[][] = new char[2][number];
            String temp;
            char input[];
            for(int x = 0;x < 2;x++){
                temp = inp.readLine();
                input = temp.toCharArray();
                for(int y = 0;y<number;y++){
                   grid[x][y] = input[y];
                    
                }
            }
            // System.out.println();
            for(int x = 0;x < 2;x++){
                for(int y = 0;y<number;y++){
                   // System.out.print(grid[x][y]);
                }
               // System.out.println();
                }
             for(int y =0;y < number;y++){
                 if(grid[0][y]=='*' && grid[1][y]=='*'){
                     fences +=1;
                     break;
                 }
             }
             for(int y=0;y< number-1;y++){
                 if(grid[0][y] =='*' && grid[0][y+1] == '*'){
                     fences += 1;
                     
                 }
                 else if(grid[0][y] =='*' && grid[1][y+1] == '*'){
                     fences += 1;
                   
                 } else if(grid[1][y] =='*' && grid[1][y+1] == '*'){
                     fences += 1;
                   
                 } else if(grid[1][y] =='*' && grid[0][y+1] == '*'){
                     fences += 1;
                   
                 }
                 
             }
             System.out.print(fences);
         }
    }
    
}
