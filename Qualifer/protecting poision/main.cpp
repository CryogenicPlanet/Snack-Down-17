#include <iostream>

using namespace std;
int run(int grid,int poison,int snakes);
int main(int argc, char const *argv[]) {
  int cases,gridSize,poison,snakes;
  std::cin >> cases;
  for (size_t i = 0; i < cases; i++) {
    std::cin >> gridSize >> poison >> snakes;

  }
  return 0;
}

int run(int gridSize,int poison,int snakes){
bool grid[gridSize][gridSize];
for (size_t i = 0; i < gridSize; i++) {
    for (size_t k = 0; k < gridSize; k++) {
      grid[i][k] = false;
    }
}
int snakesUsed = 0;
int headx,heady,tailx,taily;
int count;
for (size_t i = 0; i < snakes; i++) {
    std::cin >> headx >> heady >> tailx >> taily;
    if (headx == tailx) {
        for (int i = heady-1; i < taily; i++) {
            grid[headx][i] = true;
        }
    } else if (heady == taily) {
      for (size_t i = headx-1; i < tailx; i++) {
          grid[headx][i] = true;
      }
    }
    for (size_t i = ((gridSize - poison)/2); i < (((gridSize - poison)/2)+poison) ; i++) {
        for (size_t k = 0; k < gridSize; k++) {
              if (grid[i][k] == true) {
                count++;
              }
              if (grid[k][i]== true) {
                  count++;
              }
        }
    }
}

}
