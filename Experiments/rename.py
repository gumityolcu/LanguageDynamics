import subprocess
for i in range(0,55,5):
    for j in range(0,11):
        fileNameBase = "/home/rehrev/Documents/Okul/LanguageDynamics/Code/Data/BaseModel|N=10|M=10|S=10|m=0|SSI=" + str(
                i) + "|SFI=" + str(
                j) + "|SFD=1|LSI=0|LFI=0|LFD=0|T=1500|REALISATION="
        for r in range(99,49,-1):
            p = subprocess.Popen(["mv", fileNameBase+str(r), fileNameBase+str(r+1)], stdout=subprocess.PIPE, stderr=subprocess.PIPE)

print("Done")

