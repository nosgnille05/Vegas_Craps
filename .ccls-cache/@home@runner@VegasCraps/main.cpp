#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

int roll_dice() {
  int roll1 = rand() % 6 + 1;
  int roll2 = rand() % 6 + 1;
  return roll1 + roll2;
}

void increment(int arr[], int pos){
  arr[pos]++;
}

int main(){
  srand(time(NULL));
  int array[13]={0};
  int numRolls=36000;
  int roll{};
  
  for(int i = 0; i < numRolls; i++){
  roll = roll_dice();
  increment(array, roll);
  }

  std::cout << "Sum\tFrequency\tPercentage" << std::endl;

  for(int i=2; i<=12; i++){
    double percent = (double) array[i]/numRolls;
    percent *= 100;
    cout << i << "\t" << array[i] << "\t\t" << percent << endl;
  }

  std::cout << "\n***TEST NUMBER TWO**";
  for(int j = 0; j < 20; j++){
    roll = roll_dice();
    std::cout << roll << endl;
  }

return 0;
}