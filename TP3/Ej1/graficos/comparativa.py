import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import pylab as pl
import numpy as np
from scipy import stats
from scipy.interpolate import interp1d

f = open('estandar.txt','r')
Complete = []
Path = []
Bipartite = []
Star = []
longitud = int(f.readline())
compete = f.readline()
for i in range(0,26):
    Complete.append(int(f.readline()))
path = f.readline()
for i in range(0,26):
    Path.append(int(f.readline()))
bipartite = f.readline()
for i in range(0,26):
    Bipartite.append(int(f.readline()))
star = f.readline()
for i in range(0,26):
    Star.append(int(f.readline()))


elementos = range(5,135,5)
print len(Complete)
print len(elementos)
print elementos
df = pd.DataFrame({'elementos': elementos,'Complete':Complete,'Path':Path,'Bipartite':Bipartite,'Star': Star})
plt.clf()
df.plot(x='elementos',logy=True)
plt.ylabel('Tiempo (microsegundos)')
plt.show()
