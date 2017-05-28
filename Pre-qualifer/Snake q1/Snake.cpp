#include <iostream>
#include "stdio.h"
#include <stdio.h>
#include <string>
using namespace std;
char* run(int strLength);

int main(int argc, char const *argv[]) {
int strLen;
  int reports = 0;
  std::cin >> reports;
  char* ans[reports];
//input function

    for (int i = 0; i < reports; i++) {
std::cin >> strLen;

    //caliing run function
          ans[i] = run(strLen);

}
for (int i = 0; i < reports; i++) {
//output
      std::cout << ans[i] << '\n';
}
}
char* run(int strLength){
  char* output = "Valid";

          char input,t,h;
          t = 'T';
          h = 'H';
          int open = 0;
       // std::cin >> input;
            for (int i = 0; i < strLength+1; i++) {
               input = getchar();
                       //std::cout << input << std::endl;
                  if (input == h) {

                      if (open == 0) {
                       open = 1;
                     } else if (open == 1) {
                       output = "Invalid";

                     }
                  }
                  if (input == t) {
                    if (open == 1) {
                      open = 0;
                    } else if (open == 0) {
                      output = "Invalid";

                    }
                  }

          }
        //  std::cout << output << std::endl;
          if (open == 1) {
            output = "Invalid";
          }

                if (output != "Invalid") {
                  output = "Valid";
                }
                return output;

}
