import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import pylab as pl
import numpy as np
from scipy import stats
from scipy.interpolate import interp1d


f = open('resultados.txt','r')

matrix = []
titulo = f.readline()
for i in range(0,18):
    x = f.readline()
    x = map(int ,x.split(' '))
    matrix.append(x)

TGoloso = []
TExacto = []

for i in range(0,18):
    TGoloso.append(matrix[i][3])


for i in range(0,18):
    TExacto.append(matrix[i][4])
print TGoloso
print TExacto

elementos = range(6,24)
print len(elementos)
print elementos
print len(TGoloso)
print len(TExacto)

df = pd.DataFrame({'elementos': elementos,'TGoloso':TGoloso,'TExacto':TExacto})
plt.clf()
df.plot(x='elementos')
plt.ylabel('Tiempo (milisegundos)')
plt.show()
