import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import pylab as pl
import numpy as np
from scipy import stats
from scipy.interpolate import interp1d
import math
f = open('fixed_n_worst_case','r')
peor = []
elementos =[]


for i in range(0,21):
    elementos.append(int(f.readline()))
    peor.append(int(f.readline()))

longitud = len(elementos)
#modificar el n**2 por otro valor
complejidad = [0 + (n**2) for n in range(0,longitud)]
print len(elementos)
print len(peor)
print len(complejidad)
df2 = pd.DataFrame()
df2['elementos'] = elementos
df2['Tiempo'] = peor
df2['Complejidad'] = complejidad
sns.jointplot(df2['Complejidad'], df2['Tiempo'], kind="reg")
sns.plt.show()
