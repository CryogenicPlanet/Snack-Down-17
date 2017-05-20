#include <iostream>
#include "stdio.h"
using namespace std;
char* run(int strlen);

int main(int argc, char const *argv[]) {
int strLen;
  int reports = 0;
  std::cin >> reports;
std::cout << "In Main" << '\n';
  // array of ouput
  std::cout << "report" << reports << '\n';
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
char* run(int strLen){
 std::cout << "In run" << '\n';
if (strLen == 0) {
  std::cout << "In if" << '\n';
  //this is where the problem is mainly it is not taking the string length multiple times it is taking only once and then failing
  scanf("%d\n",&strLen );
}
  std::cout << "strLen" << strLen << '\n';
          char* output;

          char input,t,h;
          t = 'T';
          h = 'H';
          int open = 0;
            for (int i = 0; i < strLen; i++) {
                  std::cin.get(input);
                  if (input == h) {
                      if (open == 0) {
                       open = 1;
                     } else if (open == 1) {
                       output = "Invalid";
                       return output;
                     }
                  }
                  if (input == t) {
                    if (open == 1) {
                      open =0;
                    } else if (open == 0) {
                      output = "Invalid";
                      return output;
                    }
                  }

          }
                output = "Valid";
                return output;

}
