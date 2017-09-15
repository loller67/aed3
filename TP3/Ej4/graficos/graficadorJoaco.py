import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import pylab as pl
import numpy as np
from scipy import stats
from scipy.interpolate import interp1d


#f = open('AnalisisAleatorioEj4Hasta21.txt','r')
f = open('datosmalosultimahoraaksdhaksdgansdasd.txt','r')

cantDatos = 18
matrix = []
titulo = f.readline()
titulo = f.readline()
for i in range(0,cantDatos):
    x = f.readline()
    x = map(int ,x.split(' '))
    matrix.append(x)
N = []
M = []
promGL = []
promLT = []
promTE = []
maxGL = []
maxLT = []
maxTE = []
tiempoG = []
tiempoL = []
tiempoT = []
tiempoE = []
promEG = []

print matrix
#N promGL promLT promTE maxGL maxLT maxTE ptG+L ptT ptE
for i in range(0,cantDatos):
    N.append(matrix[i][0])
    #M.append(matrix[i][1])
    promGL.append(matrix[i][1])
    promLT.append(matrix[i][2])
    promEG.append(matrix[i][1]+matrix[i][2])
    #promTE.append(matrix[i][4])
    maxGL.append(matrix[i][3])
    maxLT.append(matrix[i][4])
    #maxTE.append(matrix[i][7])
    tiempoG.append(matrix[i][8])
    tiempoL.append(matrix[i][9])
    tiempoT.append(matrix[i][10])


#para graficar tiempo
df = pd.DataFrame({'N': N, 'Tiempo tabu':tiempoT, 'Tiempo local':tiempoL, 'Tiempo goloso':tiempoG})
plt.clf()
df.plot(x='N',logy = True)
plt.ylabel('Tiempo (ms) ')
plt.show()
