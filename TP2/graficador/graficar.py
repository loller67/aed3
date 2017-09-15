import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import pylab as pl
import numpy as np
from scipy import stats


"""
Cada lista  se tiene que llenar con los tiempos segun la cantidad de elementos
el primer elemento corresponde a una entrada tam 1
el segundo a tam 2, tercero tam 3 etc en este caso elementos debe ser una tira de
numeros consecutivos, porque es la que grafica la coordenada X
si lo corrimos sumando de a 5 elementos por vez, habria que llegar la lista elementos
con divisores de 5 o del salto que sea, luego hay que llenar la cantidad de listas ( curvas ) que
querramos meter al grafico
"""



lineal = [0 +(n) for n in range(0,50)]
cubica = [0 + (n**3) for n in range(0,50)]
exponencial = [0 + (1.8**n) for n in range(0,50)]

elementos = range(0,50)


print elementos

df = pd.DataFrame({'elementos': elementos,'lineal':lineal,'cubica':cubica,'exponencial':exponencial})
plt.clf()

#logy = True sirve para que la escala sea logaritmica, de esta forma no se aplasta la funcion
#prueben borrarlo y ver como queda el grafico
df.plot(x='elementos', logy = True)
plt.ylabel('Tiempo (milisegundos)')
plt.show()
