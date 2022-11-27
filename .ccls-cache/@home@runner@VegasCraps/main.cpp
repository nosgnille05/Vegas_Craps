#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

bool players_bets[5] = {true, true, true, false, true}; //Update this as bets are added

int roll_dice() {
  int roll1 = rand() % 6 + 1;
  int roll2 = rand() % 6 + 1;
  return roll1 + roll2;
}

void print_players_bets(){
  int bets_array_length = sizeof(players_bets) / sizeof(players_bets[0]);
  for (int i = 0; i < bets_array_length; i++){
    std::cout << players_bets[i] << " ";
  }
  std:cout <<"\n";
}

void setBet(int bet_index){
  players_bets[bet_index] = true;
}

void clearBet(int bet_index){
  players_bets[bet_index] = false;
}


 /* MAIN FUNCTION BELOW */
int main(){
  srand(time(NULL));
  print_players_bets();
  setBet(3);
  print_players_bets();
  clearBet(0);
  print_players_bets();

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