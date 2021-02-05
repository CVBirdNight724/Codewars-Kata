/* Level 8kyu: Get the mean of an array

It's the academic year's end, fateful moment of your school report. The averages must be calculated. All the students come to you and entreat you to calculate their average for them. Easy ! You just need to write a script.

Return the average of the given array rounded down to its nearest integer.

The array will never be empty.
*/

#include <iostream>

int count_data = 0;

bool cr_assert_eq(int predict, int target){
    std::cout << "test " << ++count_data << " is ";
    if(predict == target){
        std::cout << "Pass\n";
        return true;
    }
    std::cout << "Wrong\n";
    return false;
}

int get_average(const int *marks, size_t count){
    int avg=0;
    for(int i=0; i<count; i++){
        avg+=marks[i];
    }
    return avg/count;
}

int main(){
    {
    const int marks[] = { 2, 2, 2, 2 };
    int expected = 2;
    int received = get_average(marks, sizeof(marks)/sizeof(marks[0]));
    cr_assert_eq(expected, received);
    }

    {
    const int marks[] = { 1, 5, 87, 45, 8, 8 };
    int expected = 25;
    int received = get_average(marks, sizeof(marks)/sizeof(marks[0]));
    cr_assert_eq(expected, received);
    }

    {
    const int marks[] = { 2,5,13,20,16,16,10 };
    int expected = 11;
    int received = get_average(marks, sizeof(marks)/sizeof(marks[0]));
    cr_assert_eq(expected, received);
    }

    {
    const int marks[] = { 1,2,15,15,17,11,12,17,17,14,13,15,6,11,8,7 };
    int expected = 11;
    int received = get_average(marks, sizeof(marks)/sizeof(marks[0]));
    cr_assert_eq(expected, received);
    }
}