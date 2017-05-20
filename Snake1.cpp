#include<iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int reports;
   std::cin >> reports;
  char* ans[reports];

   for (int i = 0; i < reports; i++) {
     int strLen;
     std::cin >> strLen;
     char* input[strLen];
     for (int j = 0; i < strLen; j++) {
       std::cin >> input[j];
     }
     int open = 0;
     for (int j = 0; j < strLen; j++) {
        if(strcmp(input[j],"H") != 0 && open == 0){
          open +=1;
        }
        if(strcmp(input[j],"H") != 0 && open != 0){
            ans[i] = "Invalid";
            break;
        }
        if(strcmp(input[j],"T") != 0 && open == 1){
            open --;
        }
        if(strcmp(input[j],"T") != 0 && open != 1){
            ans[i] = "Invalid";
            break;
        }
     }
     if(ans[i] != "Invalid"){
       ans[i] = "Valid";
     }

   }
   for (size_t i = 0; i < reports; i++) {
     std::cout << ans[i] << '\n';
   }
  return 0;
}
