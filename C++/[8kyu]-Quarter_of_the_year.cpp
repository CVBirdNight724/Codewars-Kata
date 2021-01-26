/* Level: 8kyu

Given a month as an integer from 1 to 12, return to which quarter of the year it belongs as an integer number.

For example: month 2 (February), is part of the first quarter; month 6 (June), is part of the second quarter; and month 11 (November), is part of the fourth quarter.

*/

#include<iostream>
using namespace std;

unsigned count_data = 0;
bool pass = false;

bool cr_assert_eq(int predict, int target){
  cout << "test " << ++count_data << " is ";
  if(predict == target){
    cout << "Pass\n";
    return true;
  }
  cout << "Wrong\n";
  return false;
}

// Answer

int quarter_of(int month) {
  return ((month+2)/3);
}

// Main

int main(){
  cr_assert_eq(quarter_of(3), 1);
  cr_assert_eq(quarter_of(8), 3);
  cr_assert_eq(quarter_of(11), 4);
}