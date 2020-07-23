# -*- coding: utf-8 -*-
"""
Created on Wed Mar 20 14:09:10 2019

@author: Kleogis
"""

with open("C:\Users\Kleogis\Desktop\MuellerLab\AA_Oct_10_2018\AA\AA_cut_with_Adj_water_dihedrals\AA\AA_00_0_01\WanLi01_NMR_ethanol.log") as fp:
     for line in fp:
         # line = line.rstrip()
         # if "47" and "Isotropic" in line:
         #     print line 
              
         if line.startswith('  47  O    Isotropic ='):
            print line    
 