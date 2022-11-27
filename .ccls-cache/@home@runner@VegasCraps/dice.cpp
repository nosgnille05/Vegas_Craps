#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>

int roll_dice(){
  srand(time(0));
  int roll = rand() % 6;
  return roll; 
}

int main(){
  std::cout << roll_dice();
}