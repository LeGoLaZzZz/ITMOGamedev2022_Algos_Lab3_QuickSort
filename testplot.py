import matplotlib.pyplot as plt

f = open("cmake-build-debug/performanceResults.txt")
lines = f.readlines()

xdataQuick = []
xdataInsert = []
ydataQuick = []
ydataInsert = []

for line in lines:
    sp = line.split()
    print(sp)

    xdataQuick.append(float(sp[0]))
    xdataInsert.append(float(sp[0]))
    ydataQuick.append(float(sp[1]))
    ydataInsert.append(float(sp[2]))

fig = plt.figure()
ax = fig.add_subplot(1, 1, 1)
ax.plot(xdataQuick, ydataQuick, color='tab:blue', label='quick')
ax.plot(xdataInsert, ydataInsert, color='tab:orange', label='insert')
plt.xlabel('size')
plt.ylabel('microsec')
plt.legend()
plt.show()
