/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package main;

//mport java.io.BufferedReader;
import java.io.IOException;
//import java.io.InputStreamReader;
import java.util.Scanner;

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
          //BufferedReader inp = new BufferedReader (new InputStreamReader(System.in));
          Scanner in = new Scanner(System.in);
         int testCases = in.nextInt();
       
         int largest = 0;
         int numberTrue =0 ,hour,prev = -1,hourCount = 0;
         
         for(int i =0;i < testCases;i++){
       //  int xNumber = Integer.parseInt(inp.readLine());
        // int yNumber = Integer.parseInt(inp.readLine());
        int xNumber = in.nextInt();
        int yNumber = in.nextInt();
           int grid[][] = new int[xNumber][yNumber];
         int replace[][] = new int[xNumber][yNumber];
         for(int x = 0;x < xNumber;x++){
             for(int y =0;y < yNumber;y++){
                 grid[x][y] = in.nextInt();
                 replace[x][y] = grid[x][y];
             }
         }
        
         hour =0;
         numberTrue =0;
         hourCount =0;
         prev = -1;
         while(numberTrue < (xNumber*yNumber)){
              numberTrue =0;
           for(int x =0;x < xNumber-1;x++){
               for(int y=0;y< yNumber-1;y++){
                     largest = 0;  
                  if(grid[x][y] > largest){
                  largest = grid[x][y];    
                  }
                  if(grid[x][y+1] > largest){
                        largest = grid[x][y+1];   
                  }
                  if(grid[x+1][y] > largest){
                        largest = grid[x+1][y];   
                  }
                  if(grid[x+1][y+1] > largest){
                        largest = grid[x+1][y+1];   
                  }
                  if(grid[x][y] == grid[x][y+1] && grid[x][y] == grid[x+1][y] && grid[x][y]== grid[x+1][y+1]){
                      numberTrue +=4;
                      //hour--;
                  }else{
                    replace[x][y] = replace[x][y+1] = replace[x+1][y] = replace[x+1][y+1] = largest;
                    if(prev != hour){
                        hourCount++;
                    }  
                    prev = hour;
                      
                    
                  }
               }
           }
            for(int x = 0;x < xNumber;x++){
             for(int y =0;y < yNumber;y++){
                
                 grid[x][y] =  replace[x][y];
             }
         }
         hour++;
         }
         System.out.println(hourCount);
         }
         
    }
    
}
