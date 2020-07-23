count = 1
for line in open ('C:/Users/Kleogis/Desktop/Desctop_9_26_19/MuellerLab/AA_Oct_10_2018/AA/AA_cut_with_Adj_water_dihedrals/AA_New_2020/A_Na_00001_Math_Opt.log'):
    if line.startswith (" SCF"):
        print (count, line)    #print (count, line, end=" ") to remove extra lines
        count = count +1

        