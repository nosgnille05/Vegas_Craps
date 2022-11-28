#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <array>
#include <vector>
#include <string.h>
#include <cstring>
using namespace std;
const int NUM_BETS = 5;
double players_bets[5][2] = {{1, 10}, {1, 10}, {1, 10}, {0, 0}, {0, 0}}; //Update to test players bets
double** winning_bets[NUM_BETS][2] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};
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
  players_bets[bet_index][0] = 1;
}
void clearBet(int bet_index){
  players_bets[bet_index][0] = 0;
}

// Bet Types
double is_basic_field_roll(int dice_roll){
  if (dice_roll == 3 || dice_roll == 4 || dice_roll == 9 || dice_roll == 10 || dice_roll == 11){
    return 1;
  }
  else return 0;
}
double is_two_field_roll(int dice_roll){
  if (dice_roll == 2){
    return 1;
  }
  else return 0;
}
double is_twelve_field_roll(int dice_roll){
  if (dice_roll == 12){
    return 1;
  }
  else return 2;
}

//Roll Dice
int roll_dice() {
  int roll1 = rand() % 6 + 1;
  int roll2 = rand() % 6 + 1;
  return roll1 + roll2;
}

// Temp for printing bet arrays
void print_bets(double array[NUM_BETS][2]){
  for (int i = 0; i < NUM_BETS; i++){
    std::cout << array[i][0] << " ";
  }
  std:cout <<"\n";
}
 // Temp for printing pointer arrays
double winning_bets_point[NUM_BETS][2];
void *point = memcpy(winning_bets_point, winning_bets, sizeof (winning_bets));

void print_pointer_bets(void *pointer){
    for (int x = 0; x<NUM_BETS; x++) {
        for (int y = 0; y<NUM_BETS; y++) {
            cout << pointer[x][y];  
        }  
    }
  std:cout << endl;
}




// Check players bet against dice, only checks bets which player has live
double** check_roll(double players_bets_arr[NUM_BETS][2], int players_dice_roll){ 
  //double** winning_bets[NUM_BETS][2] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};
  if (players_bets_arr[0][0] == 1){
    if (is_basic_field_roll(players_dice_roll)){ 
      **winning_bets[0][0] = 1;
      }
  }
  if (players_bets_arr[1][0] == 1){ 
    if (is_two_field_roll(players_dice_roll)){ 
      **winning_bets[1][0] = 1;
      **winning_bets[0][0] = 0;
      }
  }
  if (players_bets_arr[2][0] == 1){
    if (is_twelve_field_roll(players_dice_roll)){ 
      **winning_bets[2][0] = 1;
      **winning_bets[0][0] = 0;
      }
  }
  
 return **winning_bets;
}

void payout_bets_on_checked_roll(bool checked_roll_arr[]){
  if (checked_roll_arr[0] == true){ //Basic Field Pays 1:1
    
  }
  if (checked_roll_arr[1] == true){ //Two Field Pays 2:1

  }
  if (checked_roll_arr[2] == true){ //Twelve Field Pays 3:1

  }
  if (checked_roll_arr[4] == true){

  }
  if (checked_roll_arr[5] == true){

  }
}


 /* MAIN FUNCTION BELOW */
int main(){
  srand(time(NULL));
  int players_roll = roll_dice();
  //int players_roll = 11;
  std::cout << players_roll << endl;
  print_pointer_bets(check_roll(players_bets, players_roll));

  /*
  std::cout << "\n***TEST**\n";
  for(int j = 0; j < 20; j++){
    print_bets(check_roll(players_bets, roll_dice()));
  }
  */

return 0;
}