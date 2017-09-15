import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import pylab as pl
import numpy as np
from scipy import stats
from scipy.interpolate import interp1d


f = open('mejoraAleatorio.txt','r')

matrix = []
titulo = f.readline()
titulo = f.readline()
for i in range(0,14):
    x = f.readline()
    x = map(int ,x.split(' '))
    matrix.append(x)

N = []
promGL = []
promLT = []
maxGL = []
maxLT = []
ptgL = []
ptT = []
for i in range(0,14):
    N.append(matrix[i][0])
    promGL.append(matrix[i][1])
    promLT.append(matrix[i][2])
    maxGL.append(matrix[i][3])
    maxLT.append(matrix[i][4])
    ptgL.append(matrix[i][5])
    ptT.append(matrix[i][6])
print promGL
print maxGL

print len(N)
print N
print len(promGL)
print len(maxGL)


#grafico de la calidad de las soluciones goloso local vs tabu

df = pd.DataFrame({'nodos': N,'diferencia de soluciones Goloso y Local ':promGL,'diferencia Tabu ':promLT,'maximo en Goloso y Local':maxGL,'maximo en Tabu':maxLT })
plt.clf()
df.plot(x='nodos')
plt.ylabel('Ejes')
plt.show()



#grafico del tiempo del goloso y el local en milisegundos vs el tabu
#
# df = pd.DataFrame({'nodos': N,'tiempo Goloso y Local ':ptgL, 'tiempo tabu ': ptT})
# plt.clf()
# df.plot(x='nodos',logy = True)
# plt.ylabel('tiempo Goloso + Local ( milisegundos )')
# plt.show()
