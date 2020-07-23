# -*- coding: utf-8 -*-
"""
Created on Wed Mar 20 13:41:09 2019

@author: Kleogis
"""

PN_exp = 297.61
C2_exp = 151.2
pC2_exp = 17.5
C3_exp = 158.1
SBN_exp = 286.7
CA_exp = 145.6
pC_exp= 170.9
CB_exp= 118.8
UCO_exp = 292
LCO_exp = 258
Lys87N_exp = 24.1

Ncal1 = -0.9996
Ncal2 = 230.45
NRMSE = 4.3
Ccal1 = -0.9685
Ccal2 = 173.7
CRMSE = 1.5
Ocal1 = -1.0551
Ocal2 = 266.32
ORMSE = 7.5

for line in open('C:/Users/Kleogis/Desktop/TXTstr/A0011110.txt'):
     if line.startswith ('PN'):
         line.split()
         A01_PN = float(line[3:])
         
     if line.startswith ('C2'):
         line.split()
         A01_C2 = float(line[3:])
         
     if line.startswith ('pC2'):
         line.split()
         A01_pC2 = float(line[4:])
         
     if line.startswith ('C3'):
         line.split()
         A01_C3 = float(line[3:])
         
     if line.startswith ('SBN'):
         line.split()
         A01_SBN = float(line[4:])
         
     if line.startswith ('CA'):
         line.split()
         A01_CA = float(line[3:])
         
     if line.startswith ('pC'):
         line.split()
         A01_pC = float(line[3:])
         
     if line.startswith ('CB'):
         line.split()
         A01_CB = float(line[3:])
         
     if line.startswith ('UCO'):
         line.split()
         A01_UCO = float(line[4:])
         
     if line.startswith ('LCO'):
         line.split()
         A01_LCO = float(line[4:])
                      
     if line.startswith ('Lys87N'):
         line.split()
         A01_Lys87N = float(line[7:])
         
         
PN_csh01 = ((A01_PN*Ncal1+Ncal2)-PN_exp)**2/NRMSE**2
C2_csh01 = ((A01_C2*Ccal1+Ccal2)-C2_exp)**2/CRMSE**2
pC2_csh01 = ((A01_pC2*Ccal1+Ccal2)-pC2_exp)**2/CRMSE**2
C3_csh01 = ((A01_C3*Ccal1+Ccal2)-C3_exp)**2/CRMSE**2
SBN_csh01 = ((A01_SBN*Ncal1+Ncal2)-SBN_exp)**2/NRMSE**2
CA_csh01 = ((A01_CA*Ccal1+Ccal2)-CA_exp)**2/CRMSE**2
pC_csh01 = ((A01_pC*Ccal1+Ccal2)-pC_exp)**2/CRMSE**2
CB_csh01 = ((A01_CB*Ccal1+Ccal2)-CB_exp)**2/CRMSE**2
UCO_csh01 = ((A01_UCO*Ocal1+Ocal2)-UCO_exp)**2/ORMSE**2
LCO_csh01 = ((A01_LCO*Ocal1+Ocal2)-LCO_exp)**2/ORMSE**2
Lys87N_csh01 = ((A01_Lys87N*Ncal1+Ncal2)-Lys87N_exp)**2/NRMSE**2

A01sum = PN_csh01 + C2_csh01 + pC2_csh01 + C3_csh01 + SBN_csh01 +CA_csh01 + pC_csh01 +CB_csh01 +UCO_csh01 + LCO_csh01 + Lys87N_csh01
A01X2 = float(A01sum / 11)
print ("A01 X^2:", A01X2)
#print A01_PN
#print PN_csh01
#print C2_csh01
#print pC2_csh01
#print C3_csh01
#print SBN_csh01
#print CA_csh01
#print pC_csh01
#print CB_csh01
#print UCO_csh01
#print LCO_csh01
#print Lys87N_csh01
for line in open('C:/Users/Kleogis/Desktop/TXTstr/A1011010.txt'):
     if line.startswith ('PN'):
         line.split()
         A10_PN = float(line[3:])
         
     if line.startswith ('C2'):
         line.split()
         A10_C2 = float(line[3:])
         
     if line.startswith ('pC2'):
         line.split()
         A10_pC2 = float(line[4:])
         
     if line.startswith ('C3'):
         line.split()
         A10_C3 = float(line[3:])
         
     if line.startswith ('SBN'):
         line.split()
         A10_SBN = float(line[4:])
         
     if line.startswith ('CA'):
         line.split()
         A10_CA = float(line[3:])
         
     if line.startswith ('pC'):
         line.split()
         A10_pC = float(line[3:])
         
     if line.startswith ('CB'):
         line.split()
         A10_CB = float(line[3:])
         
     if line.startswith ('UCO'):
         line.split()
         A10_UCO = float(line[4:])
         
     if line.startswith ('LCO'):
         line.split()
         A10_LCO = float(line[4:])
                      
     if line.startswith ('Lys87N'):
         line.split()
         A10_Lys87N = float(line[7:])
                 
PN_csh10 = ((A10_PN*Ncal1+Ncal2)-PN_exp)**2/NRMSE**2
C2_csh10 = ((A10_C2*Ccal1+Ccal2)-C2_exp)**2/CRMSE**2
pC2_csh10 = ((A10_pC2*Ccal1+Ccal2)-pC2_exp)**2/CRMSE**2
C3_csh10 = ((A10_C3*Ccal1+Ccal2)-C3_exp)**2/CRMSE**2
SBN_csh10 = ((A10_SBN*Ncal1+Ncal2)-SBN_exp)**2/NRMSE**2
CA_csh10 = ((A10_CA*Ccal1+Ccal2)-CA_exp)**2/CRMSE**2
pC_csh10 = ((A10_pC*Ccal1+Ccal2)-pC_exp)**2/CRMSE**2
CB_csh10 = ((A10_CB*Ccal1+Ccal2)-CB_exp)**2/CRMSE**2
UCO_csh10 = ((A10_UCO*Ocal1+Ocal2)-UCO_exp)**2/ORMSE**2
LCO_csh10 = ((A10_LCO*Ocal1+Ocal2)-LCO_exp)**2/ORMSE**2
Lys87N_csh10 = ((A10_Lys87N*Ncal1+Ncal2)-Lys87N_exp)**2/NRMSE**2

A10sum = PN_csh10 + C2_csh10 + pC2_csh10 + C3_csh10 + SBN_csh10 +CA_csh10 + pC_csh10 +CB_csh10 +UCO_csh10 + LCO_csh10 + Lys87N_csh10
A10X2 = float(A10sum / 11)
print ("A10 X^2:", A10X2)
# Mixing X^2
Reg_coef = 0
i = 0.0001
plist = []
while Reg_coef < 1:
#Reg_coef=Reg_coef + i
    PN_csh_mix = (((A01_PN*Ncal1+Ncal2)*Reg_coef+(1-Reg_coef)*(A10_PN*Ncal1+Ncal2))-PN_exp)**2/NRMSE**2
    C2_csh_mix = (((A01_C2*Ccal1+Ccal2)*Reg_coef+(1-Reg_coef)*(A10_C2*Ccal1+Ccal2))-C2_exp)**2/CRMSE**2
    pC2_csh_mix = (((A01_pC2*Ccal1+Ccal2)*Reg_coef+(1-Reg_coef)*(A10_pC2*Ccal1+Ccal2))-pC2_exp)**2/CRMSE**2
    C3_csh_mix = (((A01_C3*Ccal1+Ccal2)*Reg_coef+(1-Reg_coef)*(A10_C3*Ccal1+Ccal2))-C3_exp)**2/CRMSE**2
    SBN_csh_mix = (((A01_SBN*Ncal1+Ncal2)*Reg_coef+(1-Reg_coef)*(A10_SBN*Ncal1+Ncal2))-SBN_exp)**2/NRMSE**2
    CA_csh_mix = (((A01_CA*Ccal1+Ccal2)*Reg_coef+(1-Reg_coef)*(A10_CA*Ccal1+Ccal2))-CA_exp)**2/CRMSE**2
    pC_csh_mix = (((A01_pC*Ccal1+Ccal2)*Reg_coef+(1-Reg_coef)*(A10_pC*Ccal1+Ccal2))-pC_exp)**2/CRMSE**2
    CB_csh_mix = (((A01_CB*Ccal1+Ccal2)*Reg_coef+(1-Reg_coef)*(A10_CB*Ccal1+Ccal2))-CB_exp)**2/CRMSE**2
    UCO_csh_mix = (((A01_UCO*Ocal1+Ocal2)*Reg_coef+(1-Reg_coef)*(A10_UCO*Ocal1+Ocal2))-UCO_exp)**2/ORMSE**2
    LCO_csh_mix = (((A01_LCO*Ocal1+Ocal2)*Reg_coef+(1-Reg_coef)*(A10_LCO*Ocal1+Ocal2))-LCO_exp)**2/ORMSE**2
    Lys87N_csh_mix = (((A01_Lys87N*Ncal1+Ncal2)*Reg_coef+(1-Reg_coef)*(A10_Lys87N*Ncal1+Ncal2))-Lys87N_exp)**2/NRMSE**2
    Mix_sum = PN_csh_mix + C2_csh_mix + pC2_csh_mix + C3_csh_mix + SBN_csh_mix +CA_csh_mix + pC_csh_mix +CB_csh_mix +UCO_csh_mix + LCO_csh_mix + Lys87N_csh_mix
    Chi_mix_first = float(Mix_sum / 11)
    
    plist.append(Chi_mix_first)
    Reg_coef=Reg_coef + i

print ("Mix X^2:", min(plist))
perc_occup = plist.index(min(plist))*i
print ("Proton at 00010 structure", perc_occup,"%")
print ("Proton at 00001 structure", 1-perc_occup,"%")

#print PN_csh_mix
#print C2_csh_mix
#print pC2_csh_mix
#print C3_csh_mix
#print SBN_csh_mix
#print CA_csh_mix
#print pC_csh_mix
#print CB_csh_mix
#print UCO_csh_mix
#print LCO_csh_mix
#print Lys87N_csh_mix
































