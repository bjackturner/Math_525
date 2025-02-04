import math

# Square root function using Newton method
def sqrt(x:float, guess:float, max_iter:int=1000, x_tol:float=1e-8) -> float:
    
    # Check if x is greater than zero
    if x < 0:
        raise ValueError(f"x must be greater than or equal to zero")

    # Loop til newton method has converged 
    for i in range(max_iter):

        # Check if Newton method has converged
        if abs(guess**2 - x) <= x_tol: 
            #print(f"Converge after {i} iterations")           
            return guess
        
        # Perform Newton method
        guess -= (guess**2 - x) / (2*guess)

    print(f"Unable to converge after {i} iterations")
    return guess

# Recursive factorial function 
def factorial(x:int, s:int=1) -> int:

    # Check if x is greater than zero
    if x < 0:
        raise ValueError(f"x must be greater than zero")
    
    # Check if x is an integer
    if type(x) is not int:
        raise ValueError(f"x must be an integer")

    # Recursive factorial 
    if x == 1:
        return s
    elif x == 0:
        return 1
    else:
        return factorial(x - 1, s*x)

# Determines the value of e^x using a taylor series about the nearest integer 
def exponential(x:float, num:int=10) -> float:

    # Find the nearest integer and raise e to power of that int
    x0 = int(round(x))
    e_x0 = 2.7182818284590451**x0
    e_x = 0

    # Perform taylor expansion using factorial function
    for i in range(num):
        e_x += e_x0 * (x - x0)**i / factorial(i)

    return e_x

# Log base e function using Newton method
def log(x:float, guess:float, max_iter=1000, x_tol=1e-8) -> float:

    # Check if x is greater than zero
    if x <= 0:
        raise ValueError(f"x must be greater than zero")

    # Loop until Newton method converges
    for i in range(max_iter):

        # If Newton method converges, return the result
        if abs(exponential(guess) - x) <= x_tol: 
            #print(f"Converge after {i} iterations")           
            return guess
        
        # Perform Newton method
        guess += -1 + x * exponential(-guess)

    print(f"Unable to converge after {i} iterations")
    return guess

num = 10.25

# Outputs
print(f"Sqrt({num}): \tPython = {math.sqrt(num)} \tMy Function = {sqrt(num, 0.5)} \t Relative difference = {abs(math.sqrt(num) - sqrt(num, 0.5))/math.sqrt(num)}")
print(f"factorial({int(num)}): \tPython = {math.factorial(int(num))} \t\tMy Function = {factorial(int(num))} \t\t\t Relative difference = {abs(math.factorial(int(num)) - factorial(int(num)))/math.factorial(int(num))}")
print(f"exp({num}): \tPython = {math.exp(num)} \tMy Function = {exponential(num)} \t Relative difference = {abs(math.exp(num) - exponential(num))/math.exp(num)}")
print(f"log({num}): \tPython = {math.log(num)} \tMy Function = {log(num, 0.5)} \t Relative difference = {abs(math.log(num) - log(num, 0.5))/math.log(num)}")