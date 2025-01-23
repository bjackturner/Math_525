
def sqrt(x:float, guess:float, max_iter=1000, x_tol=1e-8) -> float:
    
    for i in range(max_iter):
        if abs(guess**2 - x) <= x_tol: 
            #print(f"Converge after {i} iterations")           
            return guess
        
        guess -= (guess**2 - x) / (2*guess)

    print(f"Unable to converge after {i} iterations")
    return guess

def factorial(x:int) -> int:

    s = 1
    for k in range(1,x):
        s *= k+1

    return s

def exponential(x:float, n=10) -> float:

    x0 = int(round(x))
    e_x0 = 2.7182818284590451**x0
    e_x = 0

    for i in range(n):
        e_x += e_x0 * (x - x0)**i / factorial(i)

    return e_x

def log(x:float, guess:float, max_iter=1000, x_tol=1e-8) -> float:

    for i in range(max_iter):
        if abs(exponential(guess) - x) <= x_tol: 
            #print(f"Converge after {i} iterations")           
            return guess
        
        guess += -1 + x * exponential(-guess)

    print(f"Unable to converge after {i} iterations")
    return guess

n = 4

print(f"Sqrt({n}) = {sqrt(n, 0.5)}")
print(f"factorial({int(n)}) = {factorial(int(n))}")
print(f"exponential({n}) = {exponential(n)}")
print(f"log({n}) = {log(n, 0.5)}")