import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import pylab as pl
import numpy as np
from scipy import stats
from scipy.interpolate import interp1d
import math
f = open('estandar.txt','r')
Iguales = []
Creciente = []
Decreciente = []
Alternada = []
Random = []
longitud = int(f.readline())
iguales = f.readline()
creciente = f.readline()
decreciente = f.readline()
alternada = f.readline()
random = f.readline()

for i in range(0,1969):
    Iguales.append(int(f.readline()))
    Creciente.append(int(f.readline()))
    Decreciente.append(int(f.readline()))
    Alternada.append(int(f.readline()))
    Random.append(int(f.readline()))
elementos = range(1, 1970)
print len(Alternada)
longitud = len(Alternada)

complejidad = [0 + (n**2*(math.log(n,2))) for n in range(3,longitud+3)]
print len(elementos)
print len(complejidad)
df2 = pd.DataFrame()
df2['elementos'] = elementos
df2['Tiempo'] = Iguales
df2['Complejidad'] = complejidad
sns.jointplot(df2['Complejidad'], df2['Tiempo'], kind="reg")
sns.plt.show()
