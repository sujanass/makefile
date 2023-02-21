#//////////////////////////////////////////////////////////////////////////////////////////////////////////////////#
#/////////////////////////Copyright  2022 Vivartan Technologies., All rights reserved////////////////////////////#
#//////////////////////////////////////////////////////////////////////////////////////////////////////////////////#
#//                                                                                                              //#
#//All works published under Zilla_Gen_0 by Vivartan Technologies is copyrighted by the Association and ownership//# 
#//of all right, title and interest in and to the works remains with Vivartan Technologies. No works or documents//#
#//published under Zilla_Gen_0 by Vivartan Technologies may be reproduced,transmitted or copied without the expre//#
#//-ss written permission of Vivartan Technologies will be considered as a violations of Copyright Act and it may//#
#//lead to legal action.                                                                                         //#
#//////////////////////////////////////////////////////////////////////////////////////////////////////////////////#
#//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#
#* File Name :
#
#* Purpose :
#
#* Creation Date : 30-05-2023
#
#* Last Modified : Thu 17 Aug 2023 03:30:09 PM IST
#
#* Created By :  
#
#///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#.



#!/usr/bin/env python
import os
import shutil
from os import path
import pwd
import sys
from warnings import *
import time
import random
import keyword
import getopt
import argparse
import re
from datetime import date
# from colorama import Fore,Back,Style

os.system("figlet -c PROJECT - Z")
rtl_top_path = './rtl_top'
pnr_top_path = './pnr_top'
rtl_top_dir = 'rtl_top'
pnr_top_dir = 'pnr_top'
rtl_top_name = 'riscv_top'
pnr_top_name = 'riscv_top'
DesignLibDir  = 'DesignLib'
WorkLibDir  = 'WorkLib'
defines = ""
v_defines = ""
c_define = ""
cov_cmd = ""
cov_sim = ""


seconds       = time.time()                     #seconds passed since epoch
localtime     = time.ctime(seconds)             #to get current time
today         = date.today()                    #to getday
date          = today.strftime("%d_%m")         #to get date and month
pwd           = os.getcwd()                     #present(current) working directory path


rtl = '$proj_dir/RTL/'

spass =0 
sfail_s = 0

## command line aruguments

ap = argparse.ArgumentParser()
ap.add_argument("sim_type", type=str, help="TOP : to compile rtl\nTEST : to run test")
ap.add_argument("test_name", nargs='?', type=str, help="Test Name")
ap.add_argument("--git_en", help="--git_en    :  GitPull latest RTL", action="store_true") 
ap.add_argument("--cov_en", help="--cov_en    :  Coverage Enable", action="store_true") 
ap.add_argument("-y","--regression", action="store_true", help="Fortan source code file 'test_file.f' -->contains list of tests to run")
ap.add_argument("--uvm_test",   help="--uvm_test : for uvm test" , action="store_true")
ap.add_argument("--instr_count", default='1000', type=int, help="--inst_count 100 : number for instruction in uvm test")
ap.add_argument("--verbosity", default="UVM_LOW", type=str, help="--verbosity LOW ")
ap.add_argument("--dump", help="--dump DUMP_EN", action="store_true")
ap.add_argument("--firmware", help="--firmware c instr.dex and data.hex loading enable define", action="store_true")
ap.add_argument("--xls2lst", help="--xls2lst xls runlist convertion into .lst file for regression", action="store_true")
ap.add_argument("--seed", help="--seed to create test reseults in test name+seed folder", action="store_true")

ap.add_argument( "--spikerun",help="--spike DUMP_EN", action="store_true")

ap.add_argument('-f', "--compile_list", default="$tb_dir/uvme/compile_list.f", type=str, help="-f compile_list")
ap.add_argument('-c',  "--citem", action='append', dest='clist',  type=str, nargs='+', default=[], help="Examples: -c AES,  -c USE_64BIT")
ap.add_argument('-v',  "--vitem", action='append', dest='vlist',  type=str, nargs='+', default=[], help="Examples: -v AES,  -v USE_64BIT")
ap.add_argument('-cv', "--cvitem", action='append', dest='cvlist', type=str, nargs='+', default=[], help="Examples: -cv AES, -cv USE_64BIT")
ap.add_argument('-vc', "--vcitem", action='append', dest='vclist', type=str, nargs='+', default=[], help="Examples: -vc AES, -vc USE_64BIT")

#ap.add_argument("-o", "--o", nargs="+", help="$test$plusargs")
ap.add_argument('-testargs',  "--testplusargs", action='append', dest='testplusargs',  type=str, nargs='+', default=[], help="Test plus args ")
ap.add_argument('-valargs',  "--valueplusargs", action='append', dest='valueplusargs',  type=str, nargs='+', default=[], help="Test plus args ")

args = vars(ap.parse_args())                    #non-keyword arguments
count = args['instr_count']
verbos = args['verbosity']
rtl_list = "$proj_dir/RTL/rtl_compile_list.f"
pnr_list = "$proj_dir/RTL/netlist_compile_list.f"
test_list = args['compile_list']


seed_reg_lst =[0]
## mk_run_dir():
if (".lst" not in str(args['test_name']) and str(args['sim_type'])=='TEST'):
    print("testname ",str(args['test_name']))
    seed = random.randint(0,100000)
    if(str(args['seed'])=='True'):
        simdir = '{}_{}'.format(args['test_name'],seed)
    else:
        if(int(os.path.isdir('./'+str(args['test_name'])))):
            #print "OSCAR : rtl_top exits. Wait I will remove rtl_top"
            shutil.rmtree('./'+str(args['test_name']))
        simdir = '{}'.format(args['test_name'])

    os.mkdir(simdir)
    simdir_path = '{}/{}'.format(pwd,simdir)
elif(".lst"  in str(args['test_name']) and str(args['sim_type'])=='TEST'):
    print("testname ",str(args['test_name']))
    seed = random.randint(0,100000)
    simdir = '{}_{}_{}'.format(today,"Regression",seed)
    os.system('cd $tb_dir/sim/')
    os.mkdir(simdir)
    simdir_path = '{}/{}'.format(pwd,simdir)
    reg_sim_dir_path = simdir_path 
if(str(args['xls2lst'])=='True'):
    #os.system("pwd")
    sim_path = str(os.getcwd())
    sim_path = sim_path[:(sim_path.index("/sim")+4)]  # to get only till sim dir if path changed
    os.chdir(sim_path+"/../scripts/regression_files/")
    #os.system("pwd")
    #os.system("ls")
    os.system("perl xls2lst.pl test.xls")
    #os.system("ls")
    print("xls2lst Conversion done Successfully")
    os.chdir(sim_path)
    #os.system("pwd")
def getstr(s):
  str1 = " +define+"
  return(str1.join(s))

## prase command line arguments
def prase_arg(input_list):
    defs = ""
    for val in args[input_list]:
        if val is not None:
            idef = getstr(val)
            defs += '+define+'
            defs += idef
            defs += ' '
    defines = defs
    return defines
###############

##    check the current directory : sim
def check_sim_dir():
    current_dir = pwd
    true = re.match(r'(.*sim)',current_dir,re.M|re.I)
    if true :
        print("OSCAR : I am in sim directory")
        return True
    else :
        print "OSCAR : I Can't run simulation in :", current_dir, " --->> goto sim directory"
        return False

#############
def git_clone():
    ##  CORE RTL Git Clone, Git Pull## 
    #os.system('rm -rf $proj_dir/RTL/CORE')
    os.system('rm -rf $proj_dir/RTL')
    os.system('mkdir $proj_dir/RTL')

     
    print "OSCAR : Git Cloning Core RTL"
    os.system("git clone https://github.com/ATME-VLSI-Incubation/ZillaGen0clean.git $proj_dir/RTL")
    
    os.system('rm -rf $proj_dir/RTL/zilla_verification/')
    os.system('cp -rf $proj_dir/RTL/Design/CORE $proj_dir/RTL/')
    os.system('cp -rf $proj_dir/RTL/Design/IP $proj_dir/RTL/')
    os.system('cp -rf $proj_dir/RTL/Design/rtl_compile_list.f $proj_dir/RTL/')
    os.system('rm -rf $proj_dir/RTL/Design/')

    ##os.system ("cd $tb_dir/sim/")

    ## IP RTL Git Clone, Git Pull##
    #os.system ("rm -rf $proj_dir/RTL/IP")
    #print "OSCAR :Git Cloning IP RTL"
    #os.system("git clone https://github.com/chandanhp/Zilla_IP_Verif $proj_dir/RTL/IP/")
    ##os.system ("cd $tb_dir/sim/")

#######################  
def coverage_setup():
   if(str(args['cov_en'])=='True'):
      global cov_cmd 
      global cov_sim 
      cov_cmd += "-coverage all -COVFILE $tb_dir/scripts/cov_files/cov_cmd.cf -covdut riscv_top"
      cov_sim += "-covworkdir ../cov_work -COVOVERWRITE"
# 
################################ END OF RTL FILES OPERATIONS ###################################
def test_plusargs(test_args_lst):
    test_args_str =""

    for test_arg_name in test_args_lst:
        test_args_str = test_args_str + '+' + test_arg_name + ' '


    return test_args_str

def value_plusargs(value_args_lst):
    value_args_str =""

    for value_arg_name in value_args_lst:
        value_args_str = value_args_str + '+Value=' + value_arg_name + ' '


    return value_args_str




def compile_files(filelist,lib,v_def):
    #if( len(args['testplusargs'])==1  and len(args['testplusargs'][0])>=1):
    #    testplusargs = test_plusargs(args['testplusargs'][0])
    #    print '=========> testplus args ', testplusargs
    os.system("xmvlog -f {} -f $tb_dir/scripts/xmvlog.arg -SV -INCDIR $XCELIUMHOME/tools.lnx86/methodology/UVM/CDNS-1.1d/sv/src +define+UVM_NO_DPI  +define+UVM_REPORT_DISABLE_FILE_LINE -WORK {} {} ".format(filelist,lib,v_def))

def elab_rtl_files():
    os.system("xmelab -access +rwc -f $tb_dir/scripts/xmelab.arg -process_save -snapshot riscv_top DesignLib.riscv_top")

def elab_files():
    os.system("xmelab -access +rwc -f $tb_dir/scripts/xmelab.arg -process_save WorkLib.riscv_top_tb -coverage all -COVFILE $tb_dir/scripts/cov_files/cov_cmd.cf -covdut riscv_top".format(cov_cmd))

def sim(test):

    if(args["regression"]==True):
        #if (str(args['uvm_test'])=='True'):
        if(int(param[1])==1):
            os.system("xmsim  +UVM_TESTNAME={} +TEST={} +NO_OF_INSTRUCTIONS={} +UVM_VERBOSITY=MEDIUM -svseed {} -process_save WorkLib.riscv_top_tb -covworkdir ../cov_work -COVOVERWRITE  ".format(test,test,count,seed_reg_lst[0]))
        else:
            os.system("xmsim  +UVM_TESTNAME=riscv_r_type_arith +UVM_VERBOSITY={} +{} +riscv_r_type_arith -svseed {} -process_save WorkLib.riscv_top_tb -covworkdir ../cov_work -COVOVERWRITE ".format(verbos,test,seed))
    elif (str(args['uvm_test'])=='True'):

        if( (len(args['valueplusargs'])==1  and len(args['valueplusargs'][0])>=1)   and    ( len(args['testplusargs'])==1  and len(args['testplusargs'][0])>=1)  ):
            testplusargs = test_plusargs(args['testplusargs'][0])
            valueplusargs = value_plusargs(args['valueplusargs'][0]) 
            print '=========> testplus args ', testplusargs
            print '=========> valueplus args ', valueplusargs
            os.system("xmsim  {} {} +UVM_TESTNAME={} +TEST={} +NO_OF_INSTRUCTIONS={} +UVM_VERBOSITY=MEDIUM -svseed {} -process_save WorkLib.riscv_top_tb -covworkdir ../cov_work -COVOVERWRITE  ".format(testplusargs,valueplusargs,test,test,count,seed))        
        elif( len(args['testplusargs'])==1  and len(args['testplusargs'][0])>=1):
            testplusargs = test_plusargs(args['testplusargs'][0])
            print '=========> testplus args ', testplusargs
            os.system("xmsim  {} +UVM_TESTNAME={} +TEST={} +NO_OF_INSTRUCTIONS={} +UVM_VERBOSITY=MEDIUM -svseed {} -process_save WorkLib.riscv_top_tb -covworkdir ../cov_work -COVOVERWRITE  ".format(testplusargs,test,test,count,seed))        
        elif( (len(args['valueplusargs'])==1  and len(args['valueplusargs'][0])>=1) ):
            valueplusargs = value_plusargs(args['valueplusargs'][0]) 
            print '=========> valueplus args ', valueplusargs
            os.system("xmsim {} +UVM_TESTNAME={} +TEST={} +NO_OF_INSTRUCTIONS={} +UVM_VERBOSITY=MEDIUM -svseed {} -process_save WorkLib.riscv_top_tb -covworkdir ../cov_work -COVOVERWRITE  ".format(valueplusargs,test,test,count,seed))        
        else:
            os.system("xmsim  +UVM_TESTNAME={} +TEST={} +NO_OF_INSTRUCTIONS={} +UVM_VERBOSITY=MEDIUM -svseed {} -process_save WorkLib.riscv_top_tb -covworkdir ../cov_work -COVOVERWRITE  ".format(test,test,count,seed))        

    elif (str(args['uvm_test']=='False')):
        os.system("xmsim  +UVM_TESTNAME=riscv_r_type_arith +UVM_VERBOSITY={} +{} +riscv_r_type_arith -svseed {} -process_save WorkLib.riscv_top_tb -covworkdir ../cov_work -COVOVERWRITE ".format(verbos,test,seed))



def compile_rtl():
    if(int(os.path.isdir(rtl_top_path))):
        print "OSCAR : rtl_top exits. Wait I will remove rtl_top"
        shutil.rmtree(rtl_top_path)
    print "OSCAR : creating rtl_top directory for rtl compilation"
    os.mkdir(rtl_top_dir)
    os.chdir(rtl_top_path)
    rpwd = os.getcwd()
    print "OSCAR : I am in rtl_top --> ",rpwd

    if not(int(os.path.isdir(DesignLibDir))):
        os.mkdir(DesignLibDir)

    f = open("cds.lib","w")
    f.write("DEFINE " +DesignLibDir +" ./" +DesignLibDir)
    file.close

    f = open("hdl.var","w")
    f.write("DEFINE VIEW_MAP (VIEW_MAP, .v => v)") 
    file.close

    v_defines = prase_arg('vlist')
    v_defines += prase_arg('vclist')
    v_defines += prase_arg('cvlist')
    
    compile_files(rtl_list,DesignLibDir,v_defines)
    f_name = "xmvlog.log"
    compile_pass = result_check(f_name)    
    if(compile_pass):
        elab_rtl_files()
        f_name = "xmelab.log"
        elab_pass = result_check(f_name)    
 
def compile_pnr():
    if(int(os.path.isdir(pnr_top_path))):
        print "OSCAR : pnr_top exits. Wait I will remove pnr_top"
        shutil.rmtree(pnr_top_path)
    print "OSCAR : creating pnr_top directory for pnr compilation"
    os.mkdir(pnr_top_dir)
    os.chdir(pnr_top_path)
    rpwd = os.getcwd()
    print "OSCAR : I am in pnr_top --> ",rpwd

    if not(int(os.path.isdir(DesignLibDir))):
        os.mkdir(DesignLibDir)

    f = open("cds.lib","w")
    f.write("DEFINE " +DesignLibDir +" ./" +DesignLibDir)
    file.close

    f = open("hdl.var","w")
    f.write("DEFINE VIEW_MAP (VIEW_MAP, .v => v)") 
    file.close

    v_defines = prase_arg('vlist')
    v_defines += prase_arg('vclist')
    v_defines += prase_arg('cvlist')
    
    compile_files(pnr_list,DesignLibDir,v_defines)
    f_name = "xmvlog.log"
    compile_pass = result_check(f_name)    
    if(compile_pass):
        elab_rtl_files()
        f_name = "xmelab.log"
        elab_pass = result_check(f_name)    
    

def run_sim(t_name):
    if not (int(os.path.isdir(rtl_top_path))):
        print "OSCAR : rtl_top does not exits. Compile rtl"
        sys.exit()
    else :
        os.chdir(rtl_top_path)
        os.chdir(DesignLibDir)
        rpwd = os.getcwd()
        os.chdir('../..')
    
    if not os.path.isdir(simdir):
        print("-------sim-->",simdir)
        os.makedirs(simdir)    #create directory in sim
    #print("simdir_path",simdir_path) 
    os.chdir(simdir_path)
    if(args["regression"]==True):
        
        seed = random.randint(0,100000)
        simdir_reg = '{}_{}'.format(t_name,seed)
        os.chdir(simdir_path)
        os.mkdir(simdir_reg)
        os.chdir(simdir_reg)
        simdir_reg_path = str(os.getcwd())
        seed_reg_lst[0]=seed
        #print("=========> simdir_path",simdir_reg_path) 
        #print("=========> simdir",simdir) 

    os.makedirs(WorkLibDir)
    os.symlink(rpwd,DesignLibDir) 

    f = open("cds.lib","w")
    f.write("DEFINE " +DesignLibDir +" ./" +DesignLibDir +"\n")
    f.write("DEFINE " +WorkLibDir +" ./" +WorkLibDir)
    file.close

    f = open("hdl.var","w")
    f.write("DEFINE LIB_MAP (rtl_top_name => DesignLibDir , +WorkLibDir )") 
    file.close

    v_defines = prase_arg('vlist')
    v_defines += prase_arg('vclist')
    v_defines += prase_arg('cvlist')
    if (str(args['dump'])=='True'):
        v_defines += ('+define+WAVE_EN')
    if (str(args['firmware'])=='True'):
        v_defines += ('+define+FIRMWARE')
    compile_files(test_list,WorkLibDir,v_defines)
    f_name = "xmvlog.log"
    compile_pass = result_check(f_name)    
    if(compile_pass):
        elab_files()
        f_name = "xmelab.log"
        elab_pass = result_check(f_name)    
        if(elab_pass):
            sim(t_name)
            #print("\n\ntest list:",test_list,"\n\n\n","testname :",t_name)
            f_name = "xmsim.log"
            sim_pass = result_check(f_name)
            gen_report(sim_pass)
        else:
            gen_report(elab_pass)
    else:
        gen_report(compile_pass)

def gls_sim():
    seed = random.randint(0,100000)
    if not (int(os.path.isdir(rtl_top_path))):
        print "OSCAR : rtl_top does not exits. Compile rtl"
    else :
        os.chdir(rtl_top_path)
        os.chdir(DesignLibDir)
        rpwd = os.getcwd()
        os.chdir('../..')
    simdir = '{}_{}'.format(args['test_name'],seed)
    
    if not os.path.isdir(simdir):
             os.makedirs(simdir)    #create directory in sim
    
    os.chdir(simdir_path)
    os.makedirs(WorkLibDir)
    os.symlink(rpwd,DesignLibDir) 

    f = open("cds.lib","w")
    f.write("DEFINE " +DesignLibDir +" ./" +DesignLibDir +"\n")
    f.write("DEFINE " +WorkLibDir +" ./" +WorkLibDir)
    file.close

    f = open("hdl.var","w")
    f.write("DEFINE LIB_MAP (rtl_top_name => DesignLibDir , +WorkLibDir )") 
    file.close

    compile_files(test_list,WorkLibDir,v_defines)
    elab_files()
    sim(str(args['test_name']))



#############
def c_compile(c_test):
    c_defines = prase_arg('clist')
    c_defines = prase_arg('cvlist')
    c_defines = prase_arg('vclist')
    os.chdir ("../firmware")                        #change directory
    os.system("make clean")
    os.system("make TEST={} CUST_TOOL=1 TEST_CNT=5 SPIKE_RUN=0 AES={}".format(c_test,c_defines))
    program_path = os.getcwd()
    file_path = "{}/programs/{}".format(program_path,args['test_name'])
    os.chdir (file_path)
    #os.system("sh {}/pc.sh".format(pwd))
    os.system("sh {}/pc.sh".format('$tb_dir/scripts'))
    os.chdir (simdir_path)
    print ("OSCAR_ : {}".format(simdir_path))
    os.system("ls")
    #os.system("cp {}/*inst.hex $proj_dir/VERIFICAION/uvme/RISCV_TOP/inst.hex".format(file_path))
    #os.system("cp {}/*data.hex $proj_dir/VERIFICATION/uvme/RISCV_TOP/data.hex".format(file_path))
    os.system("cp -rf {}/*inst.hex ./inst.hex".format(file_path))
    os.system("cp -rf {}/*data.hex ./data.hex".format(file_path))
    os.system("cp -rf ./inst.hex {}/../../uvme/RISCV_TOP/".format(simdir_path))
    os.system("cp -rf ./data.hex {}/../../uvme/RISCV_TOP/".format(simdir_path))
    os.chdir (pwd)

############################

def result_check(file_name):
    spass = 1
    FILE = open(file_name)
    if FILE: 
        #if ('UVM_ERROR :    0' or 'UVM_FATAL :   0' or 'error: 0') in FILE.read():    #check for UVM error and FATAL error
        if ( '*E') in FILE.read():    #check for UVM error and FATAL error
            spass = 0
    print spass 
    FILE.close() 
    return spass 


def gen_report(spass):
    os.chdir(pwd) 
    FILE2 = open("{}_report.log".format(date),"a")

    if spass:
        if(str(args['seed'])=='True'  or args['regression']==True ):
            FILE2.write( "####################################################### \n test:{}      seed:{}      status:PASS\n".format(args['test_name'],seed) )
        else:
            FILE2.write( "####################################################### \n test:{}      status:PASS\n".format(args['test_name']) )

    else: 
        if(str(args['seed'])=='True' or args['regression']==True):
            FILE2.write( "####################################################### \n test:{}      seed:{}      status:FAIL\n".format(args['test_name'],seed) )
        else:
            FILE2.write( "####################################################### \n test:{}      status:FAIL\n".format(args['test_name']) )

    FILE2.close()
   ## os.system("cat {}_report.log".format(date))

    os.system("cat {}_report.log".format(date))
########## regression test_list
def run_reg(iFile):
    tests = []
    test_run = []
    FILE = open(iFile).readlines()
    #random.shuffle(FILE)
    c_en = []
    for line in FILE:
        if not line.strip():
            continue
        if line :
            print (line)
            global param
            param =[]
            param = line.strip().split(" ")
            print("param: ",param)
            #print(param[0],"\n",param[1])
            #print(str(param[1])=="--uvm_test")
            if(len(param)>=2 and str(param[1])=="--uvm_test"):
                param[1] = 1
            else:
                param[1] = 0
            #print("param[1]: ",int(param[1]))
            if(str(args['cov_en'])=='True'):
                c_en.append(line.replace("\n","--cov_en"))
                os.system("python $tb_dir/scripts/oscar.py TEST {}".format(c_en[0]))
            else:
                #os.system("python $tb_dir/scripts/oscar.py TEST {}".format(line)) 

                run_sim(param[0])
    
###############

# run command
def run_main(): 
    if str(args['sim_type'])=="TOP":
        if(str(args['git_en'])=='True'):
            git_clone()
        
        if(int(os.path.isdir("./../../RTL"))):
            compile_rtl()
        else:
            print("OSCAR : RTL is not exits. at below Path: ")
            os.system('echo $proj_dir/RTL')
            print("OSCAR: Kindly enter the below command to get the RTL \noscar TOP --git_en")
       
    elif str(args['sim_type'])=="TEST":
        #coverage_setup()
        if (str(args['regression'])=='True'):
            run_reg(str(args['test_name']))
            os.system("pwd")
            os.chdir(reg_sim_dir_path)
            os.system("pwd")
            os.system("cp -ir $tb_dir/scripts/cov_files {}/".format(reg_sim_dir_path))
            print("reg_sim_dir path: ",reg_sim_dir_path)
            os.system("imc -exec {}/cov_files/cov_merge.cmd".format(reg_sim_dir_path));   
            
        else:
            if not (str(args['uvm_test'])=='True'):
                c_compile(str(args['test_name']));
            run_sim(str(args['test_name']))
    elif str(args['sim_type'])=="PNR":
        compile_pnr()
    elif str(args['sim_type'])=="GLS":
        gls_sim()
    elif str(args['sim_type'])=="SIM_DLT":
        if str(args['test_name']) == "all":
            os.system('rm -rf $tb_dir/sim/*')
            print("Now sim folder is clean ")
            print("sim folder path is: ",pwd)
        elif str(args['test_name']) == "x_rtl":
            if not (int(os.path.isdir(rtl_top_path))):
                print("rtl_top folder is not there in sim folder \nIf you wish to delete entire sim folder use the below command in terminal\noscar SIM_DLT all")
            else:
                os.system('mv rtl_top/ $tb_dir/')
                os.system('rm -rf $tb_dir/sim/*')
                os.system('mv $tb_dir/rtl_top/ ./')
                print("Now sim folder is clean except rtl_top")
                print("sim folder path is: ",pwd)



    elif str(args['sim_type'])=="list":
        print  args['testplusargs'][0] 


###

## Main Program



if(__name__=='__main__'):
    if(check_sim_dir()):
        run_main()
        if (args['spikerun']):
            os.chdir(simdir_path)
            os.system("cp mem_dump.txt ../")
            os.chdir(pwd)
            os.system("python ../scripts/mem_to_data.py")
            os.chdir ("../firmware")
            os.system("make TEST={} CUST_TOOL=1 TEST_CNT=5  SPIKE_RUN=1 > spike_{}.log".format(args['test_name'],seed))
            os.system("mv ./spike_{}.log {}".format(seed,simdir_path))
            os.chdir(pwd)
            os.system("rm -rf *.txt")
            try:
                FILE3 = open("{}/spike_{}.log".format(simdir_path,seed))
            except IOError:
                print ("File not found")
            if ('FAIL') in FILE3.read():
                sfail_s = 1

            FILE3.close()

            FILE2 = open("{}_report.log".format(date),"a")

            if sfail_s:
                    FILE2.write( "spike_test:{}        seed:{}      status:FAIL\n".format(args['test_name'],seed) )
  
            else: 
                    FILE2.write( "spike_test:{}        seed:{}      status:PASS\n".format(args['test_name'],seed) )
            FILE2.close()

            os.system("cat {}_report.log".format(date))
        else:
            pass
    else:
        print "Kindly go to the Simulation folder"

#   os.system("rm -rf x*")
#   exit (0)
##############

