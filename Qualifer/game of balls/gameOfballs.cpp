#include <iostream>
#include <math.h>
using namespace std;
char grid[11][11];
int space2;
void solve(int x,int y);
int main(int argc, char const *argv[]) {

    int cases;
    std::cin >> cases;
    int x,y;
    char temp;
    for (size_t i = 0; i < cases; i++) {
          std::cin >> x >> y;
          for (int j = 0; j < x; j++) {
              for (int k = 0; k < y; k++) {
                      std::cin >> temp;
                      grid[j][k] = temp;
              }
          }
          solve(x,y);
    }
  return 0;
}
bool checkSpace(int x,int y){
 std::cout << " " << '\n';
  int Space = 0;
  for (int j = 0; j < x; j++) {
      for (int k = 0; k < y; k++) {
std:: cout << grid[j][k] << '\t';
            if (grid[j][k] == '*') {
              Space++;
            }

      }
std:: cout << " " << '\n';
  }
//std:: cout << Space << '\n';
  if (Space == 1) {
    space2 = 0;
    return true;
  } else if (Space == 2) {
    space2 = 1;
    return false;
  }
  else  {
  //space2 = false;
    return false;
  }

}
void solve(int x,int y) {
  int answers[5002][3];
  int answer;
  int steps[5002][3];
answer = 0;
int temp;
while ((checkSpace(x,y) ==  false)) {


  if (answer > 15) {
    std:: cout << "-1" << '\n';
    break;
  }
  if (space2 == 1) {
    //std::cout << "Answer : " << answer << '\n';
    //std::cout << "Inside space2" << '\n';
          for (int i = 0; i < x; i++) {
                  for (int j = 0; j < y; j++) {
                        if (grid[i][j] == '*' && grid[i][j] == grid[i+1][j]) {

                            if(j == 0){
                              grid[i+1][j+1] = '*';
                              grid[i][j] = '.';
                              answers[answer][0] = i;
                              answers[answer][1] = j;
                              answers[answer][2] = i;
                              answers[answer][3] = j + 1;
                              answers[answer + 1][0] = i;
                              answers[answer + 1][1] = j + 1;
                              answers[answer + 1][2] = i + 1;
                              answers[answer + 1][3] = j + 1;
                              answer +=2;
                            goto end_of_while;
                            } else {
                              //  std::cout << "Inside if" << '\n';
                              grid[i+1][j-1] = '*';
                              grid[i][j] = '.';
                              answers[answer][0] = i;
                              answers[answer][1] = j;
                              answers[answer][2] = i;
                              answers[answer][3] = j -1;
                              answers[answer + 1][0] = i;
                              answers[answer + 1][1] = j - 1;
                              answers[answer + 1][2] = i + 1;
                              answers[answer + 1][3] = j - 1;
                                answer +=2;
                                goto end_of_while;
                            }
                        }
                        if (grid[i][j] == '*' && grid[i][j] == grid[i][j-1]) {
                          grid[i][j+1] = '*';
                          grid[i][j-1]= '.';
                          answers[answer][0] = i;
                          answers[answer][1] = j -1;
                          answers[answer][2] = i;
                          answers[answer][3] = j + 1;
                          answer++;
                          space2 == 0;
                            goto end_of_while;
                        }
                  }
          }
    }

  for (int j = 0; j < x; j++) {
      for (int k = 0; k < y; k++) {
            if (grid[j][k] == '.') {
                  if ((grid[j][k+2] == '*') && (grid[j][k+1] == '*')) {
                      //std:: cout << "grid before :" << grid[j][k] <<  grid[j][k+1] << grid[j][k+2] << '\n';
                      grid[j][k] = '*';
                      grid[j][k+1] = '.';
                      grid[j][k+2] = '.';
                      answers[answer][0] = j;
                      answers[answer][1] = k + 2;
                      answers[answer][2] = j;
                      answers[answer][3] = k;
                      answer++;
                      //break;
                      //std:: cout << "grid after :" << grid[j][k] <<  grid[j][k+1] << grid[j][k+2] << '\n';

                  } else if ((grid[j][k-2] == '*') && (grid[j][k-1] == '*')) {
                      //std:: cout << "grid before :" << grid[j][k] <<  grid[j][k-1] << grid[j][k-2] << '\n';
                        grid[j][k] = '*';
                        grid[j][k-1] = '.';
                        grid[j][k-2] = '.';
                        answers[answer][0] = j;
                        answers[answer][1] = k - 2;
                        answers[answer][2] = j;
                        answers[answer][3] = k;
                        answer++;

                        //std:: cout << "grid after :" << grid[j][k] <<  grid[j][k-1] << grid[j][k-2] << '\n';
                        break;

                    } else if (grid[j][k+1] == '*') {
                        //std:: cout << "grid before :" << grid[j][k] <<  grid[j][k+1]  << '\n';
                      grid[j][k] = '*';
                      grid[j][k+1] = '.';
                      answers[answer][0] = j;
                      answers[answer][1] = k+1;
                      answers[answer][2] = j;
                      answers[answer][3] = k;
                      answer++;
                      //std:: cout << "grid after :" << grid[j][k] <<  grid[j][k+1]  << '\n';
                      break;

                    } else if (grid[j][k-1] == '*') {
                      //std:: cout << "grid before :" << grid[j][k] <<  grid[j][k-1]  << '\n';

                      grid[j][k] = '*';
                      grid[j][k-1] = '.';
                      answers[answer][0] = j;
                      answers[answer][1] = k-1;
                      answers[answer][2] = j;
                      answers[answer][3] = k;
                      answer++;
                      //std:: cout << "grid after :" << grid[j][k] <<  grid[j][k-1]  << '\n';
                        break;
                    } else if (grid[j+1][k] == '*') {
                      grid[j][k] = '*';
                      grid[j+1][k] = '.';

                      answers[answer][0] = j+1;
                      answers[answer][1] = k;
                      answers[answer][2] = j;
                      answers[answer][3] = k;
                      answer++;
                        break;
                    } else if (grid[j-1][k] == '*') {
                      grid[j][k] = '*';
                      grid[j-1][k] = '.';

                      answers[answer][0] = j-1;
                      answers[answer][1] = k;
                      answers[answer][2] = j;
                      answers[answer][3] = k;
                      answer++;
                      break;
                    }

              }
      }

  }
end_of_while :
std::cout << "answer :" << answer-1 << '\n';
for (size_t j = 0; j < 4; j++) {
      std::cout << answers[answer-1][j] + 1 << '\t';
      steps[answer-1][j] = answers[answer-1][j] + 1;
}
std::cout << " " << '\n';
if (answer == 9 || answer == 11 || answer == 7) {
  for (size_t j = 0; j < 4; j++) {
        std::cout << answers[answer-2][j] + 1 << '\t';
        steps[answer-2][j] = answers[answer-2][j] + 1;

  }
    std::cout << " " << '\n';
}
if (answer == 5 ) {
  for (int i = 1; i < 3; i++) {
    for (size_t j = 0; j < 4; j++) {
          std::cout << answers[answer-i][j] + 1 << '\t';
          steps[answer-i][j] = answers[answer-i][j] + 1;
    }
      std::cout << " " << '\n';
  }
  }





}
  if (answer == 5001) {
    answer = 5000;
  }

  std:: cout << answer << '\n';
  for (size_t i = 0; i < answer; i++) {
    for (size_t j = 0; j < 4; j++) {
          std::cout << steps[i][j] + 1 << '\t';

    }
    std::cout << " " << '\n';
  }
}
