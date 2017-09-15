import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import pylab as pl
import random
import numpy as np
# script que dado un documento de texto con
f = open('salida.txt', 'r')
g = open('estandar.txt', 'w')
tamanio = 1970
g.write(str(tamanio)+'\n')
g.write('Iguales'+'\n')
g.write('Creciente'+'\n')
g.write('Decreciente'+'\n')
g.write('Alternado'+'\n')
g.write('Random'+'\n')
for value in range(0,tamanio):
    f.readline()
    titulo = f.readline()
    #g.write(titulo)
    resultados = []
    for value in range(0,10):
        resultados.append(int(f.readline()))
    mean = np.mean(resultados[0:10])
    parteEntera= int(mean)
    g.write(str(parteEntera)+'\n')

    titulo = f.readline()
    #g.write(titulo)
    resultados = []
    for value in range(0,10):
        resultados.append(int(f.readline()))
    mean = np.mean(resultados[0:10])
    parteEntera= int(mean)
    g.write(str(parteEntera)+'\n')

    titulo = f.readline()
    #g.write(titulo)
    resultados = []
    for value in range(0,10):
        resultados.append(int(f.readline()))
    mean = np.mean(resultados[0:10])
    parteEntera= int(mean)
    g.write(str(parteEntera)+'\n')

    titulo = f.readline()
    #g.write(titulo)
    resultados = []
    for value in range(0,10):
        resultados.append(int(f.readline()))
    mean = np.mean(resultados[0:10])
    parteEntera= int(mean)
    g.write(str(parteEntera)+'\n')

    titulo = f.readline()
    #g.write(titulo)
    resultados = []
    for value in range(0,10):
        resultados.append(int(f.readline()))
    mean = np.mean(resultados[0:10])
    parteEntera= int(mean)
    g.write(str(parteEntera)+'\n')
