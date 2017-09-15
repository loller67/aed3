import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np
from scipy import stats
import random

#leer primero graficar.py


#es basicamente la misma idea, cargas dos curvas, una con el tiempo  y la otra con la complejidad
#que queremos demostrar que es cierta y vemos que tanto se parecen 1 si tienen la misma correlacion y 0 si no tienen nada


lineal = [0 +(n) for n in range(0,50)]
cubica = [0 + (n**3) for n in range(0,50)]
exponencial = [0 + (1.8**n) for n in range(0,50)]



elementos = range(0,50)
tiempo = lineal
complejidad = exponencial


df2 = pd.DataFrame()
df2['elementos'] = elementos
df2['tiempo'] = tiempo
df2['complejidad'] = complejidad
sns.jointplot(df2['complejidad'], df2['tiempo'], kind="reg")
sns.plt.show()
