import numpy as np
import subprocess
import seaborn as sns
import matplotlib.pyplot as plt

REAL = 50
analyserPath = "/home/rehrev/Documents/Okul/LanguageDynamics/Code/cmake-build-debug/DataAnalyser"
xlabels = list()
ylabels = list()
scores = list()
for j in range(0, 11):
    xlabels.append(j)

for i in range(0, 55, 5):
    ylabels.append(i)
    row = list()
    for j in range(0, 11):
        running = 0.0
        miss = 0
        for r in range(1, REAL + 1):
            fileName = "/home/rehrev/Documents/Okul/LanguageDynamics/Code/Data/BaseModel|N=10|M=10|S=10|m=0|SSI=" + str(
                i) + "|SFI=" + str(
                j) + "|SFD=1|LSI=0|LFI=0|LFD=0|T=1500|REALISATION=" + str(r)
            p = subprocess.Popen([analyserPath, fileName], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            bout, e = p.communicate()
            if e:
                miss += 1
                print("Can't find file : " + fileName)
            else:
                out = bout.decode('ascii').strip()
                scr = float(out)
                running += scr
        if miss != REAL:
            running /= (REAL - miss)
        row.append(running)
    scores.append(row)
scores.reverse()
ylabels.reverse()
sns.set()
ax = sns.heatmap(scores, annot=True, xticklabels=xlabels, yticklabels=ylabels)
plt.title("SFI vs. SSI with SFD=1, IT=1500, RE=50")
plt.xlabel("SFI")
plt.ylabel("SSI")
plt.show()
ax.figure.savefig("output.png")
