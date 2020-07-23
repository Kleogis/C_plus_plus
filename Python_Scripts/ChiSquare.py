# -*- coding: utf-8 -*-
"""
Created on Wed Mar 20 13:41:09 2019

@author: Kleogis
"""

PN_exp = 297.61
C2_exp = 151.2
C2pr_exp = 17.5
C3_exp = 158.1
SBN_exp = 286.7
CA_exp = 145.6
Cpr_exp= 170.9
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

for line in open('C:\Python27\A01.txt'):
     if line.startswith ('276  N    Isotropic =    '):
         #PNline = line
         line.split()
         A01PN = float(line[3:])
     if line.startswith ('C2'):
         #C2line = line
         line.split()
         A01C2 = float(line[3:])
     if line.startswith ('pC2'):
         #C2pline = line
         line.split()
         A01C2prime = float(line[4:])
     if line.startswith ('C3'):
         #C3line = line
         line.split()
         A01C3 = float(line[3:])                      
     if line.startswith ('Lys87N'):
         #Lys87Nline = line
         line.split()
         A01Lys87N = float(line[7:])
PNcsh = ((A01PN*Ncal1+Ncal2)-PNexp)**2/NRMSE**2
C2csh = ((A01C2*Ccal1+Ccal2)-C2exp)**2/CRMSE**2
C2prime = ((A01C2prime*Ccal1+Ccal2)-pC2exp)**2/CRMSE**2
C3csh = ((A01C3*Ccal1+Ccal2)-C3exp)**2/CRMSE**2
Lys87Ncsh = ((A01Lys87N*Ncal1+Ncal2)-Lys87Nexp)**2/NRMSE**2
A01sum = PNcsh + C2csh + C2prime + C3csh + Lys87Ncsh
A01X2 = float(A01sum / 5)
print "A01 X^2:", A01X2
#A01X2 = 1/5*(sum(((A01PN*Ncal1+Ncal2)-PNexp)**2/NRMSE**2, ((A01C2*Ccal1+Ccal2)-C2exp)**2/CRMSE**2, ((A01C2prime*Ccal1+Ccal2)-pC2exp)**2/CRMSE**2, ((A01C3*Ccal1+Ccal2)-C3exp)**2/CRMSE**2, ((A01Lys87N*Ncal1+Ncal2)-Lys87Nexp)**2/NRMSE**2))
#print PNcsh, C2csh, C2prime, C3csh, Lys87Ncsh

for line in open('C:\Python27\B01.txt'):
     if line.startswith ('PN'):
         #PNline = line
         line.split()
         B01PN = float(line[3:])
     if line.startswith ('C2'):
         #C2line = line
         line.split()
         B01C2 = float(line[3:])
     if line.startswith ('pC2'):
         #C2pline = line
         line.split()
         B01C2prime = float(line[4:])
     if line.startswith ('C3'):
         #C3line = line
         line.split()
         B01C3 = float(line[3:])                      
     if line.startswith ('Lys87N'):
         #Lys87Nline = line
         line.split()
         B01Lys87N = float(line[7:])
PNcsh = ((B01PN*Ncal1+Ncal2)-PNexp)**2/NRMSE**2
C2csh = ((B01C2*Ccal1+Ccal2)-C2exp)**2/CRMSE**2
C2prime = ((B01C2prime*Ccal1+Ccal2)-pC2exp)**2/CRMSE**2
C3csh = ((B01C3*Ccal1+Ccal2)-C3exp)**2/CRMSE**2
Lys87Ncsh = ((B01Lys87N*Ncal1+Ncal2)-Lys87Nexp)**2/NRMSE**2
B01sum = PNcsh + C2csh + C2prime + C3csh + Lys87Ncsh
B01X2 = float(B01sum / 5)
print "B01 X^2:", B01X2