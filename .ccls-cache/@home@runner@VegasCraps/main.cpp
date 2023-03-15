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
double players_bank = 10;
double players_bet_amount{};
double players_bets[5][2] = {{1, players_bet_amount}, {1, players_bet_amount}, {1, players_bet_amount}, {0, players_bet_amount}, {0, players_bet_amount}}; //Update to test players bets
double winning_bets[NUM_BETS][2] = {{0, 2}, {0, 3}, {0, 4}, {0, 0}, {0, 0}};

/*
 ***BET KEY***
index 0: Basic Field (3,4,9,10,11)
index 1: Two Field (2)
index 2: Twelve Field (12)
index 3: n/a
index 4: n/a
*/

double ask_for_bet_amount(){
  double players_bet;
  cout << "How much would you like to bet? ";
  cin >> players_bet;
  if (players_bet_amount > players_bank){
    cout << "Not enough funds!";
    exit(1);
  }
  return players_bet;
}

// Bet Setting
void setBet(int bet_index){
  players_bets[bet_index][0] = 1;
}
void clearBet(int bet_index){
  players_bets[bet_index][0] = 0;
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
void print_bets(double array[NUM_BETS][2]){
  for (int i = 0; i < NUM_BETS; i++){
    for (int j = 0; j < 2; j++){
      cout << array[i][j] << " ";
    }
  }
  cout <<"\n";
}

// Check players bet against dice, only checks bets which player has live
void check_roll(double players_bets_arr[NUM_BETS][2], int players_dice_roll){ 
  if (players_bets_arr[0][0] == 1){
    if (is_basic_field_roll(players_dice_roll)){ 
      winning_bets[0][0] = 1;


      }
  }
  if (players_bets_arr[1][0] == 1){ 
    if (is_two_field_roll(players_dice_roll)){ 
      winning_bets[1][0] = 1;
      winning_bets[0][0] = 0;
      }
  }
  if (players_bets_arr[2][0] == 1){
    if (is_twelve_field_roll(players_dice_roll)){ 
      winning_bets[2][0] = 1;
      winning_bets[0][0] = 0;
      }
  }
}

void payout_bets_on_checked_roll(double checked_roll_arr[NUM_BETS][2]){
  double players_payout{};
  if (checked_roll_arr[0][0] == 1){ //Basic Field Pays 1:1
    cout << "Player Wins Basic Field!" << endl;
    players_payout = players_bets[0][1] * winning_bets[0][1];
    players_bank = players_bank + players_payout;
  }
  if (checked_roll_arr[1][0] == 1){ //Two Field Pays 2:1
    cout << "Player Wins Two Field!" << endl;
    players_payout = players_bets[1][1] * winning_bets[1][1];
    players_bank = players_bank + players_payout;
  }
  if (checked_roll_arr[2][0] == 1){ //Twelve Field Pays 3:1
    cout << "Player Wins Twelve Field!" << endl;
    players_payout = players_bets[2][1] * winning_bets[2][1];
    players_bank = players_bank + players_payout;
  }
  if (checked_roll_arr[4][0] == 1){

  }
  if (checked_roll_arr[5][0] == 1){

  }
  cout << "Players Payout: " << players_payout << endl;
}


 /* MAIN FUNCTION BELOW */
int main(){
  srand(time(NULL));
  
  int players_roll = roll_dice();
  //int players_roll = 11;
  bool game_on = true;
  //while (game_on){
    players_bet_amount = ask_for_bet_amount();
    cout << players_roll << endl;
    check_roll(players_bets, players_roll);
    print_bets(players_bets);
    print_bets(winning_bets);
    payout_bets_on_checked_roll(winning_bets);
    cout << "Players Bank: " << players_bank << endl;
   /* int x{};
    cin >> x;
    if (x == 1){
      game_on = false;
    }
    srand(time(0));
  }
*/



  

return 0;
}