/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 John Slauter
 */

#include "std_lib_facilities.h"
#include "ch5ex7.h"

using namespace ns;

int main(){

    double A, B, C, roots[2];

    try{

        cout << "Enter A: ";

        cin >> A;

        cout << "Enter B: ";

        cin >> B;

        cout << "Enter C: ";

        cin >> C;

        if(!cin){

            throw runtime_error("Invalid Input.");

        }

        roots[0] = quadratic_formula(A, B, C, false);

        roots[1] = quadratic_formula(A, B, C, true);

    }

    catch(exception& err){

        cout << err.what();

        return 1;

    }

    cout << "Roots: " << roots[0];

    if(roots[0] != roots[1]){

        cout << ", " << roots[1];

    }

    return 0;

}

double ns::quadratic_formula(double A, double B, double C, bool negative){


    /*

       if "A" and "B" both equal zero, then there are not any "x" terms present in the equation.
       
       The equation can expressed as: 
       0x^2 + 0x + C = 0 -> C = 0 

       "x" cannot have roots in an equation that does not have "x" terms.

    */

    if(A == 0 && B == 0){

        throw runtime_error("No roots.");

    }

    /*

        if "A" equals zero and "B" does not equal zero, then the equation can be expressed as: 
        0x^2 + Bx + C = 0 -> Bx + C = 0
        
        Solving for "x":
        Bx = -C
        x = -C/B

        "x" will only have one root in this situation.

    */

    if(A == 0 && B != 0){

        return -1*C/B;

    }

    double temp = B*B - 4*A*C;

    /*

        if the result from the expression in the square root is a negative number, then the square root function will result with
        a term that involves "i", an imaginary number. Imaginary numbers are not real; therefore, there are not any real roots.

    */

    if(temp < 0){

        throw runtime_error("No real roots.");

    }

    temp = sqrt(temp);

    /*

        To accommodate the +- part of the quadratic formula, a boolean parameter 
        controls whether the + path or the - path will be evaluated

    */

    if(negative == true){

        temp *= -1;

    }

    temp -= B;

    temp /= 2*A;

    return temp;

}

