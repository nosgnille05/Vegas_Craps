#include <cstdlib>
#include <iostream>
#include <time.h>
#include <array>
using namespace std;

bool players_bets[5] = {true, false, false, false, false}; //Update this as bets are added
/*
 ***BET KEY***
index 0: Field
index 1: n/a
index 2: n/a
index 3: n/a
index 4: n/a
*/
void setBet(int bet_index){
  players_bets[bet_index] = true;
}

void clearBet(int bet_index){
  players_bets[bet_index] = false;
}

bool is_field_roll(int dice_roll){
  if (dice_roll == 2 || dice_roll == 3 || dice_roll == 4 || dice_roll == 9 || dice_roll == 10 || dice_roll == 11 || dice_roll == 12){
    return true;
  }
  else return false;
}

int roll_dice() {
  int roll1 = rand() % 6 + 1;
  int roll2 = rand() % 6 + 1;
  return roll1 + roll2;
}

void print_bets(bool array[]){
  int array_length = sizeof(array) / sizeof(array[0]);
  for (int i = 0; i < array_length; i++){
    std::cout << array[i] << " ";
  }
  std:cout <<"\n";
}

std::array <bool,5> check_roll(bool array[], int players_dice_roll){
  bool winning_bets[5] = {false};
  if (array[0] == true){
    if (is_field_roll(players_dice_roll)){ 
      winning_bets[0] = true;
      }
  }
  
  return winning_bets[];
}


 /* MAIN FUNCTION BELOW */
int main(){
  srand(time(NULL));
  int players_roll = roll_dice();
  print_bets(check_roll(players_bets, players_roll));

  /*
  int roll{};
  std::cout << "\n***DICE TEST**";
  for(int j = 0; j < 20; j++){
    roll = roll_dice();
    std::cout << roll << endl;
  }
  */

return 0;
}