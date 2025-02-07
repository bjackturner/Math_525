import numpy as np

# Solves Ax = b system
def gaussian_elimination(A:np.ndarray, b:np.ndarray) -> np.ndarray:

    if A.shape[0] != b.shape[0]:
        raise ValueError("Error: A and b must have same length in one dimension")
    
    A = A.astype(float)
    b = b.astype(float)
    num = b.shape[0]
    
    for i in range(num):
        max_row = np.argmax(np.abs(A[i:, i])) + i
        if A[max_row, i] == 0:
            raise ValueError("Error: singular matrix, cannot find solution")
        
        if max_row != i:
            A[[i, max_row]] = A[[max_row, i]]
            b[i], b[max_row] = b[max_row], b[i]
        
        for j in range(i+1, num):
            factor = A[j, i] / A[i, i]
            A[j, i:] -= factor * A[i, i:]
            b[j] -= factor * b[i]
    
    x = np.zeros(num)
    for i in range(num-1, -1, -1):
        x[i] = (b[i] - np.dot(A[i, i+1:], x[i+1:])) / A[i, i]
    
    return x

# Sets up matrix for polynomial interpolation
def polynomial_config(x:np.ndarray, n:int) -> np.ndarray:

    # Check if x a one dimensional numpy array
    if not isinstance(x, np.ndarray):
        raise SyntaxError(f"Error: x must be type np.ndarray")
    
    if x.ndim > 1:
        raise SyntaxError(f"Error: x must be a one dimensional array")

    # Count number of points and create nxn matrix
    A = np.zeros((x.shape[0],n), dtype="float64")

    # Fill each column with value of x^n_column
    for i in range(n):
        A[:,i] = x**i

    return A

# Fid a least square fit of degree n
def least_square_approx(x:np.ndarray, f:np.ndarray, n:int) -> np.ndarray:

    V = polynomial_config(x,n)
    A = V.T @ V
    b = V.T @ f
    return gaussian_elimination(A, b)

def main():

    x = np.linspace(-np.pi, np.pi, 51)
    f = np.cos(x)
    n = 5
    coeffs = least_square_approx(x, f, n)
    
    print("Least squares polynomial coefficients:", coeffs)
    
    import matplotlib.pyplot as plt
    x_fine = np.linspace(-np.pi, np.pi, 200)
    f_approx = np.polyval(coeffs[::-1], x_fine)
    
    plt.plot(x_fine, np.cos(x_fine), label='Exact')
    plt.plot(x_fine, f_approx, linestyle='--', color="red", label='Least Squares Fit')
    plt.legend()
    plt.xlabel('x')
    plt.ylabel('f(x)')
    plt.title(f'{n} Degree Least Square Approximation of cos(x)')
    plt.grid()
    plt.show()

if __name__ == "__main__":
    main()
