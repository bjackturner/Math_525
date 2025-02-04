import numpy as np
import matplotlib.pyplot as plt

def gaussian_elimination(A:np.ndarray, b:np.ndarray) -> np.ndarray:

    # Make sure matrices A and b have same number of elements
    if A.shape[0] != b.shape[0]:
        raise SyntaxError(f"Error: A and b must have same length in one dimension")

    # Make sure all arrays are filled with floats
    A = A.astype(float)
    b = b.astype(float)
    num = b.shape[0]
    
    # Forward elimination
    for i in range(num):

        # Find row with maximum absolute value in column i
        max_row = np.argmax(np.abs(A[i:, i])) + i

        # Raise error for singular matrix
        if A[max_row, i] == 0:
            raise ValueError("Error: singular matrix, cannot find solution")
        
        # Swap rows if necessary
        if max_row != i:
            A[[i, max_row]] = A[[max_row, i]]
            b[i], b[max_row] = b[max_row], b[i]
        
        # Eliminate entries 
        for j in range(i+1, num):
            factor = A[j, i] / A[i, i]
            A[j, i:] -= factor * A[i, i:]
            b[j] -= factor * b[i]
    
    # Back substitution
    x = np.zeros(num)
    for i in range(num-1, -1, -1):
        x[i] = (b[i] - np.dot(A[i, i+1:], x[i+1:])) / A[i, i]
    
    return x

# Sets up matrix for polynomial interpolation
def polynomial_config(x:np.ndarray) -> np.ndarray:

    # Check if x a one dimensional numpy array
    if not isinstance(x, np.ndarray):
        raise SyntaxError(f"Error: x must be type np.ndarray")
    
    if x.ndim > 1:
        raise SyntaxError(f"Error: x must be a one dimensional array")

    # Count number of points and create nxn matrix
    num = x.shape[0]
    A = np.zeros((num,num), dtype="float64")

    # Fill each column with value of x^n_column
    for i in range(num):
        A[:,i] = x**i

    return A

# Setup up matrix 
x = np.array([-0.1, -0.02, 0.02, 0.1])
y = np.cos(x)
A = polynomial_config(x)
num = x.shape[0]

# Solve system for cubic polynomial 
coeff = gaussian_elimination(A, y)
print(f"Solution: {x}")

# Approximate f(x) = cos(x)
for i, x_i in enumerate(x):
    print(f"f({x_i}) = {np.cos(x_i)} \tp({x_i}) ={np.sum(coeff * x_i**np.arange(num))}")

## Plotting

# Create empty arrays
x = np.linspace(-2,2,1000)
f = np.zeros_like(x)
p = np.zeros_like(x)

# Approximate f(x) = cos(x)
for i, x_i in enumerate(x):
    f[i] = np.cos(x_i)
    p[i] = np.sum(coeff * x_i**np.arange(num))

plt.figure()
plt.plot(x,f, label="f(x)")
plt.plot(x,p, label="p(x)")
plt.grid()
plt.legend()
plt.show()