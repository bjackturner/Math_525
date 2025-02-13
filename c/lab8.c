#include <stdio.h>
#include <math.h>

int nFactorial(int x);
int nFactorialRecursive(int x, int s);
double nExponential(double x, int num);

int main(){

    // Ask the user for a number
    int number;
    printf("Enter number of points: ");
    scanf("%d", &number);  // Read integer input

    // Define arrays
    double x[number];
    double y[number];

    // Fill the arrays with e^x
    for (int i = 0; i < number; i++){
        x[i] = (double) 100 * i / (number - 1);
        y[i] = nExponential(x[i], 10);

    }

    // Corrected file path
    FILE *file = fopen("c/results/lab8.data", "w");

    // Write the file
    for (int i = 0; i < number; i++) {
        fprintf(file, "%f %f\n", x[i], y[i]);  // Use %lf for double
    }

    fclose(file);  // Close the file
    
    return 0;
}

// Wrapper function for factorial function (avoids confusion)
int nFactorial(int x){

    // Check if x is greater than zero
    if (x < 0){
        printf("Value Error: x must be greater than zero");
        return -1;
    }

    // Return edge case of x = 0 -> 1
    else if (x == 0){
        return 1;
    }

    // Perform factorial computation
    return nFactorialRecursive(x, 1);
}

// Actual factorial function
int nFactorialRecursive(int x, int s){

    // If finished return the result
    if (x == 1){
        return s;
    }

    // If not finished return recursively 
    else{
        return nFactorialRecursive(x - 1, s*x);
    }
}

// Determines the value of e^x using a taylor series about the nearest integer 
double nExponential(double x, int num){

    // Find the nearest integer and raise e to power of that int
    int x0 = round(x);
    double e_x0 = pow(2.7182818284590451,x0);
    double e_x = 0;

    // Perform taylor expansion using factorial function
    for (int i = 0; i < num; i++){
        e_x += e_x0 * pow((x - x0),i) / nFactorial(i);

    }

    return e_x;
}