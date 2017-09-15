import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import pylab as pl
import numpy as np
from scipy import stats
from scipy.interpolate import interp1d


f = open('mejoraMalo.txt','r')

matrix = []
titulo = f.readline()
titulo = f.readline()
for i in range(0,46):
    x = f.readline()
    x = map(int ,x.split(' '))
    matrix.append(x)

promedioYmaximo = []
maxGE = []
nodos = []
aristas = []
for i in range(0,46):
    promedioYmaximo.append(matrix[i][2])
    maxGE.append(matrix[i][3])
    nodos.append(matrix[i][0])
    aristas.append(matrix[i][1])
print promedioYmaximo
print maxGE

print len(nodos)
print nodos
print len(promedioYmaximo)
print len(maxGE)

df = pd.DataFrame({'nodos': nodos,'Diferencia de frontera exacto vs goloso':promedioYmaximo, 'Aristas en grafo':aristas})
plt.clf()
df.plot(x='nodos')
plt.ylabel('Cantidad de aristas en la frontera ')
plt.show()
