with open("C:\Users\Kleogis\Desktop\MuellerLab\AA_Oct_10_2018\AA\AA_01_5Wp1.gjf") as f:
    f.readline() 
    count =1
    plist=[]
    for line in f:
        sp=line.split()
        if len(sp)==6:
            count=count+1
            plist.append(sp)
    print plist[0]
    newlist=plist[1]
    x=newlist[2]
    y=newlist[3]
    z=newlist[4]
    print z
 