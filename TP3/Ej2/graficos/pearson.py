import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import pylab as pl
import numpy as np
from scipy import stats
from scipy.interpolate import interp1d
import math
f = open('estandarGoloso.txt','r')

longitud = int(f.readline())
longitud = 99
KN = []
for i in range(0,longitud):
    KN.append(int(f.readline()))
elementos = range(0, longitud*5,5)
print "salidel for d"
complejidad = [0 + (n**3) for n in range(0,longitud)]
print "elementos"
print len(elementos)
print elementos
print "KN: "
print len(KN)
print KN
print len(complejidad)
print complejidad
df2 = pd.DataFrame()
df2['elementos'] = elementos
df2['Tiempo'] = KN
df2['Complejidad n^3'] = complejidad
sns.jointplot(df2['Complejidad n^3'], df2['Tiempo'], kind="reg")
sns.plt.show()
