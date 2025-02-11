#include <stdio.h>
#include <math.h>

// Square root function using Newton method
double nSqrt(double x, double guess, int maxIter, double xTol){

    // Check if x is greater than 0
    if (x < 0){
        printf("Value Error: x must be greater than or equal to zero");
        return -1;
    }    

    // Loop til newton method has converged or max iterations reached
    for (int i = 0; i < maxIter; i++){

        // Check if Newton method has converged and return answer
        if (fabs(pow(guess,2) - x) <= xTol){
            return guess;
        }

        // Perform Newton method
        guess -= (pow(guess,2) - x) / (2*guess);
    }

    // Fail message and return 0
    printf("unable to converge after %d iterations", maxIter);
    return -1;
}

// Factorial function 
int nFactorial(int x){

    // Check if x is greater than zero
    if (x < 0){
        printf("Value Error: x must be greater than zero");
        return -1;
    }

    // Perform factorial computation
    int s = 1;
    for (int i = 1; i < x; i++){
        s *= i + 1;
    }
    return s;
}

// Determines the value of e^x using a taylor series about the nearest integer 
double nExponential(double x, int num){

    // Find the nearest integer and raise e to power of that int
    int x0 = x;
    double e_x0 = pow(2.7182818284590451,x0);
    double e_x = 0;

    // Perform taylor expansion using factorial function
    for (int i = 0; i < num; i++){
        e_x += e_x0 * pow((x - x0),i) / nFactorial(i);

    }

    return e_x;
}

// Log base e function using Newton method
double nLog(double x, double guess, int max_iter, double x_tol){

    // Check if x is greater than zero
    if (x <= 0){
        printf("Value Error: x must be greater than zero");
        return -1;
    }

    // Loop until Newton method converges
    for (int i = 0; i < max_iter; i++){

        // If Newton method converges, return the result
        if (fabs(nExponential(guess, 10) - x) <= x_tol){
            return guess;
        }
        
        // Perform Newton method
        guess += -1 + x * nExponential(-guess, 10);

    }

    // Fail message and return -1
    printf("Unable to converge after %d iterations", max_iter);
    return -1;
}

int main(){

    // Ask the user for a number
    float number;
    printf("Enter a number: ");
    scanf("%f", &number);  // Read integer input

    // Define variables that will be used to store results from my functions
    double mySqrt, myExp, myLog = 0;
    int myFac = 0;

    // Compute values using my functions
    mySqrt = nSqrt(number, number, 1000, 1e-6);
    myFac  = nFactorial((int) number);
    myExp  = nExponential(number, 10);
    myLog  = nLog(number, number, 1000, 1e-6);

    // Print and compare to math
    printf("Sqrt(%.5f) \t MyFunc = %.5f\n", number, mySqrt);
    printf("Fact(%d) \t MyFunc = %d\n", (int) number, myFac);
    printf("Exp(%.5f) \t MyFunc = %.5f\n", number, myExp);
    printf("Log(%.5f) \t MyFunc = %.5f\n", number, myLog);

    return 0;
}
