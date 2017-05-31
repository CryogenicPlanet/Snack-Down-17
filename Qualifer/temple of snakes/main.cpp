#include <iostream>
#include "math.h"

using namespace std;

int main(int argc, char const *argv[]) {
  try {
  int cases;
  std::cin >> cases;
  int size,midpoint,midarray,output;
  int x,i;
  int input[100002];
  for (size_t j = 0; j < cases; j++) {
    output = 0;
        std::cin >> size;
        midpoint = ceil(size/2) +1;
        midarray = midpoint-1;

        for (int i = 0; i < size; i++) {
            std::cin >> input[i];
        }

        x = 0;
        i = 0;
        if (size == 2) {
            if (input[0]==1) {
                output += input[1] - 0;
                input[1] = 0;
                x =1;
            } else {
                output += input[0] - 0;
                input[0] = 1;
                x=1;
            }
        }
        if (input[0] == input[1]) {
            output++;
            input[0]--;
            midpoint--;
        }
        if (input[size-2] == input[size-1]) {
            input[size-1]--;
            midpoint--;
            midarray--;
            output++;
        }
        while (x !=1) {
          x = input[midarray-i];
            if (x == midpoint - i) {
                output +=0;
            } else {
              output += x- (midpoint -i);
              input[midarray-i] = midpoint -i;
            }

            if (input[midarray+i] == midpoint -i) {
              output += 0;
            } else {
              output += input[midarray+i] - (midpoint - i);
            }
            i++;
        }
        std::cout << output << '\n';
  }
  return 0;
} catch(const std::out_of_range oor) {

} catch(const std::runtime_error oorr){

}
}
