/* Level: 6kpu

Create a function taking a positive integer as its parameter and returning a string containing the Roman Numeral representation of that integer.

Modern Roman numerals are written by expressing each digit separately starting with the left most digit and skipping any digit with a value of zero. In Roman numerals 1990 is rendered: 1000=M, 900=CM, 90=XC; resulting in MCMXC. 2008 is written as 2000=MM, 8=VIII; or MMVIII. 1666 uses each Roman symbol in descending order: MDCLXVI.

Example:

solution(1000); // => "M"

Help:

Symbol    Value
I          1
V          5
X          10
L          50
C          100
D          500
M          1,000

Remember that there can't be more than 3 identical symbols in a row.

More about roman numerals - http://en.wikipedia.org/wiki/Roman_numerals
*/

// Answer

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *solution(int n) {
    static char str[20];
    int a[10];
    int val[] = {1000, 500, 100, 50, 10, 5, 1};
    char key[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    int i = 0, j = 0;
    while(n > 0){
        a[i] = n/val[i];
        n %= val[i];
        if(a[i] == 4){
            if(i%2 == 1){
                str[j] = key[i];
                str[j+1] = key[i-2];
                j += 2;
            }
            else{
                str[j] = key[i];
                str[j+1] = key[i-1];
                j += 2;
            }
        }
        else{
            for(int k=0; k<a[i]; k++){
                str[j] = key[i];
                j++;
            }
        }
        i++;
    }
    return str;
}

// main

int main(){
    printf(solution(1000));
}