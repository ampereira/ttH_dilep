#!/bin/sh

FLAG=true

case $1 in
	"omp")
		currfile=ttH_dilep_omp
		;;
	"mic")
		currfile=ttH_dilep_mic
		;;
	"dice")
		currfile=ttH_dilep_dice
		;;
	"cuda")
		currfile=ttH_dilep_cuda
		;;
	*)
		currfile=ttH_dilep
		FLAG=false
		;;
esac

binfile=../bin/$currfile

if [ $binfile -nt $currfile ]
then
	cp $binfile .
	echo "Using newer version of $currfile"
fi

DBG=$1

if [ FLAG ]
then
	DBG=$2
fi

if [ "$DBG" == "debug" ]
then
	if [ uname == "Darwin"]
	then
		sudo gdb ./$currfile --OutputFileName=ttH125_dilepbb_em --SetSystematicsFileName=../RefSys/Ref.txt --Sample=901 --User="CutTriggerEleMuo=1" --User="lepSample=23" 
	else
		gdb ./$currfile --OutputFileName=ttH125_dilepbb_em --SetSystematicsFileName=../RefSys/Ref.txt --Sample=901 --User="CutTriggerEleMuo=1" --User="lepSample=23" 
	fi
else
	time ./$currfile --OutputFileName=ttH125_dilepbb_em --SetSystematicsFileName=../RefSys/Ref.txt --Sample=901 --User="CutTriggerEleMuo=1" --User="lepSample=23" 
fi
