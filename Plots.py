import numpy as np
import matplotlib.pyplot as plt
from scipy.io.wavfile import write
Datos=np.loadtxt("archivo1.txt")
Datos2=np.loadtxt("archivo2.txt")
Datos4=np.loadtxt("archivo4.txt")
Sonido=np.loadtxt("archivo3.txt")
write('sonido.wav',50000, Sonido)

plt.figure("Extremos Fijos")
plt.title("Extremos Fijos")
plt.plot(Datos[0], label="t=0")
plt.plot(Datos[1], label="t=1/2T")
plt.plot(Datos[2], label="t=1/4T")
plt.plot(Datos[3], label="t=1/8T")
plt.plot(Datos[4], label="t")
plt.xlabel("Datos")
plt.ylabel("Amplitud")
plt.legend()
plt.savefig("ExtremosFijos.jpg")
plt.close()

plt.figure("Extremos Libres")
plt.title("Extremos Libres")
plt.plot(Datos2[0], label="t=0")
plt.plot(Datos2[1], label="t=1/2T")
plt.plot(Datos2[2], label="t=1/4T")
plt.plot(Datos2[3], label="t=1/8T")
plt.plot(Datos2[4], label="t")
plt.xlabel("Datos")
plt.ylabel("Amplitud")
plt.legend()
plt.savefig("ExtremosLibres.jpg")
plt.close()


datos101=Datos4[50,:]
datos202=Datos4[151,:]
datos303=Datos4[252,:]
datos404=Datos4[353,:]
datos505=Datos4[454,:]

plt.figure("TamborPunto_medio")
plt.title("TamborPunto_medio")
plt.plot(datos101,label="t=0")
plt.plot(datos202,label="t=1/2T")
plt.plot(datos303,label="t=1/4T")
plt.plot(datos404,label="t=1/8T")
plt.plot(datos505,label="t")
plt.xlabel("Datos")
plt.ylabel("Amplitud")
plt.grid()
plt.legend()
plt.savefig("TamborPunto_medio.jpg")
plt.close()

plt.figure("TamborMatriz_completa")
plt.title("TamborMatriz_completa")
plt.plot(Datos4[0:101,:])
plt.plot(Datos4[101:202,:])
plt.plot(Datos4[202:303,:])
plt.plot(Datos4[303:404,:])
plt.plot(Datos4[404:505,:])
plt.xlabel("Datos")
plt.ylabel("Amplitud")
plt.grid()
plt.legend()
plt.savefig("TamborMatriz_completa.jpg")


