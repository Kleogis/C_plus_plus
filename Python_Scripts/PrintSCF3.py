with open('C:\Users\Kleogis\Desktop\Desctop_9_26_19\MuellerLab\AA_Oct_10_2018\AA\AA_cut_with_Adj_water_dihedrals\AA\AA_00_0_00\AA_4WatNF_00000.log') as f:
#    f.readline()
    count =0
    plist=[]
    for line in f:
        sp=line.split()
        if len(sp)==6:
            count=count+1
            plist.append(sp)
 #   print count
 #   plist=plist[1:]
#    print plist
    count=1
    desiredCount=300
    x_coord=plist[2]
    y_coord=plist[3]
    z_coord=plist[4]
    for item in plist:
        count=count+1
        if count==desiredCount:  
            print (x_coord)

           #if line.startswith('0 1' or '-1 1' or '-2 1' or '-3 1'):
 #         continue
 #     count 
 #           print line 
#
