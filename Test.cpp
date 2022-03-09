/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Ajwan Khoury>
 * 
 * Date: 09-03-2022| 04:29
 */
#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Test for those inputs on the Internet-Good Inputs") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));
    
    CHECK(nospaces(mat(13, 5, '@', '-'))== nospaces("@@@@@@@@@@@@@\n"
                                                    "@-----------@\n"
                                                    "@-@@@@@@@@@-@\n"
                                                    "@-----------@\n"
                                                    "@@@@@@@@@@@@@"));
    
    CHECK(nospaces(mat(3, 5, '$', '+'))== nospaces("@@@\n"
                                                    "@+@\n"
                                                    "@+@\n"
                                                    "@+@\n"
                                                    "@@@"));

    CHECK(nospaces(mat(1, 1, '#', ')'))== nospaces("#"));

    CHECK(nospaces(mat(9, 1, '^', '%'))== nospaces("^^^^^^^^^"));                                              
}

TEST_CASE("Another inputs- Good ones"){

    //with one column
    CHECK(nospaces(mat(3, 1, '(', '='))== nospaces("((("));

    //with one row
    CHECK(nospaces(mat(1, 5, 'o', 'f'))== nospaces("o\n"
                                                   "o\n"
                                                   "o\n"
                                                   "o\n"
                                                   "o"));

    //with equall row and column number
    CHECK(nospaces(mat(3, 3, '$', '-'))== nospaces("$$$\n"
                                                   "$-$\n"
                                                   "$$$"));
    
    CHECK(nospaces(mat(5, 5, '#', '@'))== nospaces("#####\n"
                                                   "#@@@#\n"
                                                   "#@#@#\n"
                                                   "#@@@#\n"
                                                   "#####\n"));
    
    //with rows number that is smaller that columns number
    CHECK(nospaces(mat(7, 9, '2', '8'))== nospaces("2222222\n"
                                                   "2888882\n"
                                                   "2822282\n"
                                                   "2828282\n"
                                                   "2828282\n"
                                                   "2828282\n"
                                                   "2822282\n"
                                                   "2888882\n"
                                                   "2222222")); 


    CHECK(nospaces(mat(5, 9, 'H', 'W'))== nospaces("HHHHH\n"
                                                   "HWWWH\n"
                                                   "HWHWH\n"
                                                   "HWHWH\n"
                                                   "HWHWH\n"
                                                   "HWHWH\n"
                                                   "HWHWH\n"
                                                   "HWWWH\n"
                                                   "HHHHH"));
    
    CHECK(nospaces(mat(11, 13, '^', '!'))== nospaces("^^^^^^^^^^^\n"
                                                     "^!!!!!!!!!^\n"
                                                     "^!^^^^^^^!^\n"
                                                     "^!^!!!!!^!^\n"
                                                     "^!^!^^^!^!^\n"
                                                     "^!^!^!^!^!^\n"
                                                     "^!^!^!^!^!^\n"
                                                     "^!^!^!^!^!^\n"
                                                     "^!^!^^^!^!^\n"
                                                     "^!^!!!!!^!^\n"
                                                     "^!^^^^^^^!^\n"
                                                     "^!!!!!!!!!^\n"
                                                     "^^^^^^^^^^^"));

    //with rows number that is bigger that columns number
    CHECK(nospaces(mat(9, 7, '*' , '&'))== nospaces("*********\n"
                                                    "*&&&&&&&*\n"
                                                    "*&*****&*\n"
                                                    "*&*&*&*&*\n"
                                                    "*&*****&*\n"
                                                    "*&&&&&&&*\n"
                                                    "*********\n"));

    CHECK(nospaces(mat(13, 11, '^' , '!'))== nospaces("^^^^^^^^^^^^^\n"
                                                      "^!!!!!!!!!!!^\n"
                                                      "^!^^^^^^^^^!^\n"
                                                      "^!^!!!!!!!^!^\n"
                                                      "^!^!^^^^^!^!^\n"
                                                      "^!^!^!!!^!^!^\n"
                                                      "^!^!^^^^^!^!^\n"
                                                      "^!^!!!!!!!^!^\n"
                                                      "^!^^^^^^^^^!^\n"
                                                      "^!!!!!!!!!!!^\n"
                                                      "^^^^^^^^^^^^^\n"));
}


TEST_CASE("Input an even number-Bad input") {
    
    CHECK_THROWS(mat(10, 5, '$', '%')); // rows number have to be odd number
    
    CHECK_THROWS(mat(7, 2, '!', '(')); // column must be odd number
    
    CHECK_THROWS(mat(8, 4, '&', '*')); //rows and column number have to be odd one
   
}

TEST_CASE("Input negative numbers-Bad input"){
    CHECK_THROWS(mat(-1, 3, '@', '-')); //U write a negative row number

    CHECK_THROWS(mat(5, -7, '(', '+')); //U write a negative column number

    CHECK_THROWS(mat(-13, -9, '!', '$')); //U write a negative row and column numbers

}

TEST_CASE("Input Invaild numbers- Bad inputs"){
   
    CHECK_THROWS(mat(0, 9, '*', '~')); // how to write 0 rows with 9 columns?

    CHECK_THROWS(mat(7, 0, '$', '#')); // how to write 7 rows with 0 columns?
}



