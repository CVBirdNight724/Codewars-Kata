/* Level: 5kpu

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Finish the solution so that it returns the sum of all the multiples of 3 or 5 below the number passed in.

    Note: If the number is a multiple of both 3 and 5, only count it once. Also, if a number is negative, return 0(for languages that do have them)

Courtesy of projecteuler.net

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

int solution(int number){
    int sum=0;
    for(int i=1; i<number; i++){
        if(i%5==0 || i%3==0){
            sum+=i;
        }
    }
    return sum;
}

// Main
int main(){
    cr_assert_eq(solution(10), 23);
}