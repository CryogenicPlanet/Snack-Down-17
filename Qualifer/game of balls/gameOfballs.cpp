#include <iostream>
#include <math.h>
using namespace std;
char grid[11][11];
int answers[5002][4];
int ansCount;
int space2;
void solve(int x,int y);
void swap1(int intx,int inty,int endx,int endy);
void swap2(int intx,int inty,int endx,int endy,int midx,int midy);
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

  if (Space == 1) {
    space2 = 0;
    return true;
  } else if (Space == 2) {
    space2 = 1;
    return false;
  }
  else  {
    return false;
  }

}
void solve(int x,int y) {

ansCount = 1;
int temp;
int steps[5002][3];
while ((checkSpace(x,y) ==  false)) {


  if (ansCount > 5000) {
    std:: cout << "-1" << '\n';
    break;
  }
      for (size_t i = 0; i < x; i++) {
            for (size_t j = 0; j < y; j++) {
                if (grid[i][j] == '*') {

                  if (grid[i][j+2]=='.' && grid[i][j+1] == grid[i][j]) {
                    swap2(i,j,i,j+2,i,j+1);
                  } else if (grid[i][j-2]=='.' && grid[i][j-1] == grid[i][j]) {
                    swap2(i,j,i,j-2,i,j-1);
                  } else if (grid[i+2][j]=='.' && grid[i+1][j] == grid[i][j]) {
                    swap2(i,j,i+2,j,i+1,j);
                  } else if (grid[i-2][j]=='.' && grid[i-1][j] == grid[i][j]) {
                    swap2(i,j,i-2,j,i-1,j);
                  }
                    else if (grid[i][j+1] == '.') {
                        swap1(i,j,i,j+1);
                    } else if (grid[i][j-1]=='.') {
                        swap1(i,j,i,j-1);
                    } else if (grid[i+1][j] == '.') {
                        swap1(i,j,i+1,j);
                    } else if (grid[i-1][j] == '.') {
                        swap1(i,j,i-1,j);
                    }
                }
                  std::cout << "outside while" << '\n';
            }
      }
//end_of_while :
std::cout << ansCount << '\n';
for (size_t i = 1; i < ansCount; i++) {
      for (size_t  k = 0;  k < 4;  k++) {
          std::cout << answers[i][k] << '\t';
      }
      std::cout << "" << '\n';
}
std::cout << ansCount << '\n';
}}
void swap1(int intx,int inty,int endx,int endy) {
  std::cout << "inside swap1" << '\n';
  if (answers[ansCount-1][2] == intx && answers[ansCount-1][3] == inty && answers[ansCount-1][0] == endx && answers[ansCount-1][1] == endy) {
      goto end_of;
  } else{
    answers[ansCount][0] = intx + 1;
    answers[ansCount][1] = inty + 1;
    answers[ansCount][2] = endx + 1;
    answers[ansCount][3] = endy + 1;
    ansCount +=1;
    char temp;
  temp =  grid[intx][inty];
  grid[intx][inty] = grid[endx][endy];
  grid[endx][endy] = temp;
}
end_of:
  return;
}
void swap2(int intx,int inty,int endx,int endy,int midx,int midy) {
  std::cout << "inside swap2" << '\n';
  answers[ansCount][0] = intx + 1;
  answers[ansCount][1] = inty + 1;
  answers[ansCount][2] = endx + 1;
  answers[ansCount][3] = endy + 1;
  ansCount +=1;
  char temp;
  temp =  grid[intx][inty];
  grid[midx][midy] = grid[intx][inty] = grid[endx][endy];
  grid[endx][endy] = temp;
}
