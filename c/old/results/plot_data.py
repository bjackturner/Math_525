import numpy as np
import matplotlib.pyplot as plt

data = []

with open("c/results/lab8.data","r") as file:
    for line in file:

        line_data = []

        for num in line.split():
            line_data.append(float(num))

        data.append(line_data)

data = np.array(data)

plt.figure()
plt.plot(data[:,0],data[:,1])
plt.grid()
plt.xlabel(f"X")
plt.ylabel(f"Y")
plt.show()