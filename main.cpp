#include <cstdlib>
#include <iostream>
#include <time.h>
#include <array>
using namespace std;
const int NUM_BETS = 5;
bool players_bets[] = {true, true, true, false, false}; //Update to test players bets
/*
 ***BET KEY***
index 0: Basic Field (3,4,9,10,11)
index 1: Two Field (2)
index 2: Twelve Field (12)
index 3: n/a
index 4: n/a
*/

// Bet Setting
void setBet(int bet_index){
  players_bets[bet_index] = true;
}
void clearBet(int bet_index){
  players_bets[bet_index] = false;
}

// Bet Types
bool is_basic_field_roll(int dice_roll){
  if (dice_roll == 3 || dice_roll == 4 || dice_roll == 9 || dice_roll == 10 || dice_roll == 11){
    return true;
  }
  else return false;
}
bool is_two_field_roll(int dice_roll){
  if (dice_roll == 2){
    return true;
  }
  else return false;
}
bool is_twelve_field_roll(int dice_roll){
  if (dice_roll == 12){
    return true;
  }
  else return false;
}

//Roll Dice
int roll_dice() {
  int roll1 = rand() % 6 + 1;
  int roll2 = rand() % 6 + 1;
  return roll1 + roll2;
}

// Temp for printing bet arrays
void print_bets(bool array[]){
  for (int i = 0; i < NUM_BETS; i++){
    std::cout << array[i] << " ";
  }
  std:cout <<"\n";
}

// Check players bet against dice, only checks bets which player has live
bool * check_roll(bool array[], int players_dice_roll){ 
  static bool winning_bets[5] = {false};
  if (array[0] == true){
    if (is_basic_field_roll(players_dice_roll)){ 
      winning_bets[0] = true;
      }
  }
  if (array[1] == true){ 
    if (is_two_field_roll(players_dice_roll)){ 
      winning_bets[1] = true;
      winning_bets[0] = false;
      }
  }
  if (array[2] == true){
    if (is_twelve_field_roll(players_dice_roll)){ 
      winning_bets[2] = true;
      winning_bets[0] = false;
      }
  }
  
  return winning_bets;
}


 /* MAIN FUNCTION BELOW */
int main(){
  srand(time(NULL));
  int players_roll = roll_dice();
  //int players_roll = 11;
  std::cout << players_roll << endl;
  print_bets(check_roll(players_bets, players_roll));

  /*
  std::cout << "\n***TEST**\n";
  for(int j = 0; j < 20; j++){
    print_bets(check_roll(players_bets, roll_dice()));
  }
  */

return 0;
}