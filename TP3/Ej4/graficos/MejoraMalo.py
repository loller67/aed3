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
for i in range(0,40):
    x = f.readline()
    x = map(int ,x.split(' '))
    matrix.append(x)
N = []
M = []
promGL = []
promLE = []
maxGL = []
maxLE = []
tiempo = []

print matrix

for i in range(0,40):
    N.append(matrix[i][0])
    M.append(matrix[i][1])
    promGL.append(matrix[i][2])
    promLE.append(matrix[i][3])
    maxGL.append(matrix[i][4])
    maxLE.append(matrix[i][5])
    tiempo.append(matrix[i][6])



#para graficar el error
# df = pd.DataFrame({'N': N,'M': M,'maxLE':maxLE })
# plt.clf()
# df.plot(x='N')
# plt.ylabel('Cantidad de aristas en la frontera ')
# plt.show()
#
#

#para graficar tiempo
df = pd.DataFrame({'N': N,'tiempo':tiempo})
plt.clf()
df.plot(x='N')
plt.ylabel('tiempo (milisegundos) ')
plt.show()
