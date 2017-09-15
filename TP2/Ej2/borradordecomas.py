f = open('tGM','r')
g = open('tGMc','w')

for i in range(0,40):
    variable = f.readline()
    g.write(variable[:-3]+'\n')
