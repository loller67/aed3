import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import pylab as pl
import random
import numpy as np
# script que dado un documento de texto con
f = open('pearsonGoloso.txt', 'r')
g = open('estandarGoloso.txt', 'w')
tamanio = 99
g.write(str(tamanio*5)+'\n')
for value in range(0,tamanio):
    titulo = f.readline()
    resultados = []
    for value in range(0,10):
        resultados.append(int(f.readline()))
    mean = np.mean(resultados[0:10])
    parteEntera= int(mean)
    g.write(str(parteEntera)+'\n')
