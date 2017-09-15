import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import pylab as pl
import numpy as np
from scipy import stats
from scipy.interpolate import interp1d

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
print len(elementos)
df = pd.DataFrame({'elementos': elementos,'Iguales':Iguales,'Random':Random,'Creciente':Creciente,'Decreciente': Decreciente,'Alternada': Alternada})
plt.clf()
df.plot(x='elementos')
plt.ylabel('Tiempo (microsegundos)')
plt.show()
