import numpy as np 
import matplotlib
matplotlib.use('agg')
import matplotlib.pyplot as plt
import math

data=np.loadtxt("datos1.txt", dtype=float, delimiter=",")

plt.plot(data[::2,2], data[::2,0], label="Deberia ser periodica", color="red")
plt.legend()
plt.grid()
plt.title("Coordenada q1 en funcion del tiempo")
plt.xlabel("Tiempo (t)")
plt.ylabel("Variable q1")
plt.savefig("q1(t).png")
plt.clf()


plt.plot(data[1::2,0], data[1::2,1], label="Espacio de fase", color="red")
plt.legend()
plt.grid()
plt.title("Coordenada p2 en funcion de la coordenada q2")
plt.xlabel("Coordenada (q2)")
plt.ylabel("Coordenada (p2)")
plt.savefig("caos.pdf")
plt.clf()

