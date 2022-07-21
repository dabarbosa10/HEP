import os
import numpy as np
import sys
import subprocess

def createtxt():
    print('Enter the number of the channel:\n')
    print('etau =1 , mutau=2 or tautau=3 (wo quotation)')
    x = int(input())
    if (x== 1 or x== 2 or x== 3):
        print('VALID CHANNEL')
        if x==1:
            path="/Users/diegobarbosa/Desktop/Limits/LimitCardsMaker_Zprime_13TeV_2021/"
            channel="etau"
            path=path+channel
            os.chdir(path)
            print("Directory changed to" + channel + "+" + path)
            dir_list=os.listdir(path)
            os.system("hadd data.root DY+Jets_2016.root QCD_2016.root SingleTop_2016.root VV_2016.root W+Jets_2016.root ttbar_2016.root")
            
        if x==2:
            path="/Users/diegobarbosa/Desktop/Limits/LimitCardsMaker_Zprime_13TeV_2021/"
            channel="mutau"
            path=path+channel
            os.chdir(path)
            print("Directory changed to" + channel + "+" + path)
            dir_list=os.listdir(path)
            os.system("hadd data.root DY_2016.root QC_2016.root ST_2016.root TT_2016.root VV_2016.root WJ_2016.root")
        
        if x==3:
            path="/Users/diegobarbosa/Desktop/Limits/LimitCardsMaker_Zprime_13TeV_2021/"
            channel="tautau"
            path=path+channel
            os.chdir(path)
            print("Directory changed to" + channel + "+" + path)
            dir_list=os.listdir(path)
            os.system("hadd data.root DY+Jets_Histogram.root QCD_Histogram.root SingleTop_Histogram.root VV_Histogram.root W+Jets_Histogram.root tbar\{t\}_Histogram.root")
            
            
            
        

    else:
        print('Not a Valid Channel!')
        sys.exit()
        

def main():
    createtxt()

if __name__ == '__main__':
    main()
