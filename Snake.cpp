#include <iostream>

using namespace std;
char* run();
int main(int argc, char const *argv[]) {
  cout << "Reports =" << '\n';
  int reports = 0;
  std::cin >> reports;
  // array of ouput
  std::cout << "Reports =" << reports << '\n';
  char* ans[reports];
//input function
    for (int i = 0; i < reports; i++) {
          ans[i] = run();

}

}
char* run(){
  std::cout << "In run" << '\n';
          char* output;
          int strLen = 0;
          std::cin >> strLen;
          std::cout << "Strlen" << strLen << '\n';
          char input,t,h;
          t = 'T';
          h = 'H';
          int open,str;
            for (int i = 0; i < strLen+1; i++) {
                  std::cin.get(input);
                  if (input == h) {
                      if (str == 0) {
                        str = 1;
                      }
                      if (open ==0) {
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
          if (str == 0) {
                output =  "Invalid";
                return output;
              } else {
                output = "Valid";
                return output;
              }
}
