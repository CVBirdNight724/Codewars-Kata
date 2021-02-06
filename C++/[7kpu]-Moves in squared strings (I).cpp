/* Level 7kpu: Moves in squared strings (I)

    This kata is the first of a sequence of four about "Squared Strings".

    You are given a string of n lines,
    each substring being n characters long : For example :

    s = "abcd\nefgh\nijkl\nmnop"

    We will study some transformations of this square of strings.

    - Vertical mirror : vert_mirror(or vertMirror or vert - mirror)
        
        vert_mirror(s) = > "dcba\nhgfe\nlkji\nponm" 
    
    - Horizontal mirror : hor_mirror(or horMirror or hor - mirror)
                                                                                                  
        hor_mirror(s) = > "mnop\nijkl\nefgh\nabcd" 

    or printed :
        vertical mirror |   horizontal mirror
        abcd-- > dcba   |   abcd-- > mnop
        efgh hgfe       |   efgh ijkl
        ijkl lkji       |   ijkl efgh
        mnop ponm       |   mnop abcd
    
    Task : 
        Write these two functions
                   
    and
        high-order function oper(fct, s) where

        fct is the function of one variable f to apply to the string s(fct will be one of vertMirror, horMirror)

    Exazmples : 
        s = "abcd\nefgh\nijkl\nmnop" 
        oper(vert_mirror, s) = > "dcba\nhgfe\nlkji\nponm" 
        oper(hor_mirror, s) = > "mnop\nijkl\nefgh\nabcd" 
    
    Note : 
        The form of the parameter fct in oper changes according to the language.You can see each form according to the language in "Sample Tests".

                    
    Bash Note : 
        The input strings are separated by, instead of \n.The output strings should be separated by \r instead of \n.See "Sample Tests".

    Forthcoming katas will study other transformations.
*/

/* Solution:

char* vertMirror(char* strng) {
    // your code
}
char* horMirror(char* strng) {
    // your code
}
typedef char* (*generic_func_t) (char*);
char* oper(generic_func_t f, char* s) {
    // your code
}
*/

/* Sample Test:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <criterion/criterion.h>

char* vertMirror(char* strng);
char* horMirror(char* strng);
typedef char* (*generic_func_t) (char*);
char* oper(generic_func_t f, char* s);

void dotest1(char* s, char *expr) {
    char *act = vertMirror(s);
    if(strcmp(act, expr) != 0)
        printf("vertMirror. Error. Expected \n%s\n but got \n%s\n", expr, act);
    cr_assert_str_eq(act, expr, "");
    free(act); act = NULL;
}
void dotest2(char* s, char *expr) {
    char *act = horMirror(s);
    if(strcmp(act, expr) != 0)
        printf("horMirror. Error. Expected \n%s but got \n%s\n", expr, act);
    cr_assert_str_eq(act, expr, "");
    free(act); act = NULL;
}
Test(kata, ShouldPassAllTheTestsProvided) {
      printf("\nvertMirror\n");
    {
        char s1[] = "hSgdHQ\nHnDMao\nClNNxX\niRvxxH\nbqTVvA\nwvSyRu";
        char s2[] = "QHdgSh\noaMDnH\nXxNNlC\nHxxvRi\nAvVTqb\nuRySvw";
        dotest1(s1, s2);
    }
    {
        char s1[] = "IzOTWE\nkkbeCM\nWuzZxM\nvDddJw\njiJyHF\nPVHfSx";
        char s2[] = "EWTOzI\nMCebkk\nMxZzuW\nwJddDv\nFHyJij\nxSfHVP";
        dotest1(s1, s2);
    }
    printf("\nhorMirror\n");
    {
        char s1[] = "lVHt\nJVhv\nCSbg\nyeCt";
        char s2[] = "yeCt\nCSbg\nJVhv\nlVHt";
        dotest2(s1, s2);
    }
    {
        char s1[] = "njMK\ndbrZ\nLPKo\ncEYz";
        char s2[] = "cEYz\nLPKo\ndbrZ\nnjMK";
        dotest2(s1, s2);
    }
}
*/


// Answer

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* vertMirror(char* strng) {
    int pre_vector = 0;
    int size_strng = strlen(strng);
    char* new_strng[size_strng];
    printf("start mem: %d\n", strlen(new_strng));
    for(int i=0; i<size_strng; i++){
        if(strng[i] == '\n' || i == size_strng-1){
            for(int j=pre_vector; j<i; j++){
                if(i == size_strng-1) pre_vector++;
                new_strng[j] = strng[pre_vector+i-j-1]; 
                // printf("j_inv: %c at %d\n", new_strng[j], j);
            }
            if(i != size_strng-1)
                new_strng[i] = '\n';
            pre_vector = i+1;
        }
    }
    // printf("\nstrng: %s\n\nnew_strng: %s\n", strng, new_strng);
    // printf("\nstrlen: %d vs %d\n", strlen(strng), strlen(new_strng));
    return new_strng;
}

void dotest1(char* s, char *expr) {
    char *act = vertMirror(s);
    if(strcmp(act, expr) != 0)
        printf("vertMirror. Error. Expected \n%s\n but got \n%s\n", expr, act);
    // cr_assert_str_eq(act, expr, "");
    free(act); act = NULL;  
}

int main(){
    char s1[] = "IzOTWE\nkkbeCM\nWuzZxM\nvDddJw\njiJyHF\nPVHfSx";
    vertMirror(s1);

}