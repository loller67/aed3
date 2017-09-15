import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import pylab as pl
import numpy as np
from scipy import stats
from scipy.interpolate import interp1d


f = open('mejoraGolosoLocalaleatorio.txt','r')

matrix = []
titulo = f.readline()
titulo = f.readline()
for i in range(0,90):
    x = f.readline()
    x = map(int ,x.split(' '))
    matrix.append(x)

promGL = []
maxGL = []
nodos = []
tiempo = []
for i in range(0,90):
    nodos.append(matrix[i][0])
    promGL.append(matrix[i][1])
    maxGL.append(matrix[i][2])
    tiempo.append(matrix[i][3])
print promGL
print maxGL

print len(nodos)
print nodos
print len(promGL)
print len(maxGL)


#grafico de la calidad de las soluciones 

df = pd.DataFrame({'nodos': nodos,'promGL':promGL,'maxGL':maxGL })
plt.clf()
df.plot(x='nodos')
plt.ylabel('Cantidad de aristas en la frontera ')
plt.show()



#grafico del tiempo del goloso y el local en milisegundos
#
# df = pd.DataFrame({'nodos': nodos,'tiempo':tiempo})
# plt.clf()
# df.plot(x='nodos')
# plt.ylabel('tiempo Goloso + Local ( milisegundos )')
# plt.show()
