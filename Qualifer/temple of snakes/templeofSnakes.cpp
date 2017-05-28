#include <iostream>
#include <math.h>
using namespace std;
int runOdd(int no);
int runEven(int no);
//int* input(int no);
bool checkTemple(int* input,int no);
int main(int argc, char const *argv[]) {
    int cases = 0;
    std::cin >> cases;

    int size = 0;
    for (size_t i = 0; i < cases; i++) {
        std::cin >> size;
        if (size % 2 == 0) {
            std::cout << runEven(size) << '\n';
        } else {
            std::cout << runOdd(size) << '\n';
        }
    }
    return 0;
}
int runOdd(int no) {
    int operationsDone = 0;
    int midPoint = 0;
    midPoint = ceil(no / 2);
    int input[no];
    for (int i = 0; i < no; i++) {
        std::cin >> input[i];
    }
    int midVal = input[midPoint];

    if (checkTemple(input,no) == true) {
        return operationsDone;
    } else {
        for (int i = 0; i < midPoint; i++) {
            while((input[i] + 1) != input[i +1]) {
                if(input[i] ==  input[i + 1]) {
                    input[i]--;
                } else if (input[i] > input[i +1]) {
                    input[i]--;
                } else if (input[i] < input[i + 1]) {
                    input[i+1]--;
                }
                operationsDone++;
            }
        }
        for (size_t i = no-1; i > midPoint; i--) {
            while((input[i] +1) != input[i - 1]) {
                if(input[i] ==  input[i - 1]) {
                    input[i-1]--;
                } else if (input[i] > input[i  - 1]) {
                    input[i]--;
                } else if (input[i] < input[i - 1]) {
                    input[i-1]--;
                }
                operationsDone++;
            }

        }
        return operationsDone;
    }
}
int runEven(int no) {
    int operationsDone = 0;
    int input[no];
    for (int i = 0; i < no; i++) {
        std::cin >> input[i];
    }
    int midPoint = 0;
    midPoint = ceil(no / 2);
    if (no == 2) {
        if (input[0]==1) {
            operationsDone = input[1] - 0;
            input[1] = 0;

        } else {
            operationsDone = input[0] - 0;
            input[0] = 1;

        }
    }
    if (input[0] == input[1]) {
        operationsDone++;
        input[0]--;
    }
    if (input[no-2] == input[no-1]) {
        input[no-1]--;
        midPoint--;
        operationsDone++;
    }
    int midVal = input[midPoint];
    if (checkTemple(input,no) == true) {
        return operationsDone;
    } else {

        for (int i = 0; i < midPoint; i++) {
            while((input[i] + 1) != input[i +1]) {
                if(input[i] ==  input[i + 1]) {
                    input[i]--;
                } else if (input[i] > input[i +1]) {
                    input[i]--;
                } else if (input[i] < input[i + 1]) {
                    input[i+1]--;
                }
                operationsDone++;
            }
        }

        for (size_t i = no-1; i > midPoint; i--) {
            while((input[i] +1) != input[i - 1]) {
                if(input[i] ==  input[i - 1]) {
                    input[i-1]--;
                } else if (input[i] > input[i  - 1]) {
                    input[i]--;
                } else if (input[i] < input[i - 1]) {
                    input[i-1]--;
                }
                operationsDone++;
            }

        }
        /*
        for (size_t i = 0; i < no; i++) {
          std::cout << input[i] << '\t';
              }
              std::cout << "" << '\n'; */
        return operationsDone;
    }
}
bool checkTemple(int* input,int no) {
    int score = 0;
    int midPoint = 0;
    midPoint = ceil(no / 2) + 1;
    int midarray = midPoint -1;
    int midVal = input[midarray];
    std::cout << midVal << midarray << midPoint << '\n';
    for (int i = 1; i < midPoint; i++) {
        if (input[midarray-i] == midVal - i && input[midarray+i] == midVal - i) {
            score++;
        }
    }
    if (score == (no - midPoint)) {
        return true;
    } else {
        return false;
    }
}
