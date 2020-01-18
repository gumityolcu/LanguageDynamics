import subprocess
import seaborn as sns
import matplotlib.pyplot as plt

REAL = 2
COLS = 2
ROWS = 2
COLSTEP = 1
ROWSTEP = 100
COLINIT=1
ROWINIT=100
Title = "SFD vs. SFI with SSI=10, IT=1500, RE=50"
X = "SFD"
Y = "SFI"
analyserPath = "/home/rehrev/Documents/Okul/LanguageDynamics/Code/cmake-build-debug/DataAnalyser"
xlabels = list()
ylabels = list()
scores = list()
for j in range(COLINIT, COLS * COLSTEP+COLINIT, COLSTEP):
    xlabels.append(j)

for i in range(ROWINIT, ROWS * ROWSTEP+ROWINIT, ROWSTEP):
    ylabels.append(i)
    row = list()
    for j in range(COLINIT, COLS * COLSTEP+COLINIT, COLSTEP):
        running = 0.0
        miss = 0
        for r in range(1, REAL + 1):
            fileName = "/home/rehrev/Documents/Okul/LanguageDynamics/Code/Data/MemorySpeakerSuccessUpdate|N=10|M=10|S=10|m="+str(j)+"|T="+str(i)+"|REALISATION=" + str(r)
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

plt.title(Title)
plt.xlabel(X)
plt.ylabel(Y)
plt.show()
ax.figure.savefig("output.png")
