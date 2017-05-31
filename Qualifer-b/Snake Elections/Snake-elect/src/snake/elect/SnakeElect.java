/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package snake.elect;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author rahul
 */
public class SnakeElect {

    /**
     * @param args the command line arguments
     * @throws java.io.IOException
     */
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
          BufferedReader inp = new BufferedReader (new InputStreamReader(System.in));
         int testCases = Integer.parseInt(inp.readLine());
         String str;
         int strLength,mong,snak;
         for(int i=0; i < testCases;i++){
             mong =0;
             snak =0;
             str = inp.readLine();
             char[] array =  str.toCharArray();
             strLength = array.length;
             for(int x =0;x < strLength;x++){
              //   System.out.print(array[x]);
                 if(array[x] == 'm'){
                     mong++;
                 }
                 
             }
             
             char search = 'm';
             char use = 'l';
             char[] prev = array;
             
             try {
             
                for(int x =0;x < strLength;x++){
                    if(array[x] == search){
                     //  Boolean plus = false,minus = false;

                        if(x == 0){
                            if(array[x+1] == 's'){

                            array[x+1] = 'd';

                        }
                        } else if(x == strLength -1){
                            if (array[x-1] == 's'){

                            array[x-1] = 'd';
                        }
                        } else {
                      
                        if(array[x+1] == 's' && array[x-1] == 's'){
                           array[x] = use;
                           
                           
                        } else if(array[x+1] == 's'){

                            array[x+1] = 'd';

                        } else if (array[x-1] == 's'){

                            array[x-1] = 'd';
                        }
                       //  System.out.println("test");
                      
                    }
                    }
                }
                   for(int x =0;x < strLength;x++){
                       if(array[x] == use){
                        if(array[x+1] == 's' && array[x-1] == 's'){
                           array[x+1] = 'd';
                           
                           
                           
                        }
                   }
                   }
            
         }catch (Exception ex){
                 }
             for(int x =0;x < strLength;x++){
                 if(array[x] == 's'){
                     snak++;
                 }
                 
             }
          if(snak == mong){
              System.out.println("tie");
          } else if(snak > mong){
              System.out.println("snakes");
              
    } else if (mong > snak){
        System.out.println("mongooses");
    }
         } 
    
} 
}
//code end