#!/bin/bash
#ekremiscan

ips=(10.1.10.37 10.1.10.40 10.1.10.35 10.1.10.36 10.1.10.38 10.1.10.39 10.1.10.25 10.1.10.17 10.1.10.23 10.1.10.22 10.1.10.33 10.1.10.32 10.1.10.20 10.1.10.28 10.1.10.21 10.1.10.26 10.1.10.27 10.1.10.24 10.1.10.44 10.1.10.46 10.1.10.43 10.1.10.45 10.1.10.41 10.1.10.42)
kayit=/home/eds_cm/eko/filament/Daily/filament-$(date +%Y-%m-%d)
exec >$kayit 2>&1

for ip in "${ips[@]}"; do 
	ssh -T $ip << \code
trh=$(date +%Y-%m-%d)
ipcikti=$(ifconfig | grep addr:10 | awk -F: '{print $2}' | awk '{print $1}')
if [[ $ipcikti == '10.1.10.37' ]]; then 
echo "ED01(10.1.10.37) $trh"
elif [[ $ipcikti == '10.1.10.40' ]]; then 
echo "ED02(10.1.10.40) $trh"
elif [[ $ipcikti == '10.1.10.35' ]]; then 
echo "ED03(10.1.10.35 $trh)"
elif [[ $ipcikti == '10.1.10.36' ]]; then 
echo "ED04(10.1.10.36) $trh"
elif [[ $ipcikti == '10.1.10.38' ]]; then 
echo "ED05(10.1.10.38) $trh"
elif [[ $ipcikti == '10.1.10.39' ]]; then 
echo "ED06(10.1.10.39) $trh"
elif [[ $ipcikti == '10.1.10.25' ]]; then 
echo "ED09(10.1.10.25) $trh"
elif [[ $ipcikti == '10.1.10.17' ]]; then 
echo "ED10(10.1.10.17) $trh"
elif [[ $ipcikti == '10.1.10.23' ]]; then 
echo "ED11(10.1.10.23) $trh"
elif [[ $ipcikti == '10.1.10.22' ]]; then 
echo "ED12(10.1.10.22) $trh"
elif [[ $ipcikti == '10.1.10.33' ]]; then 
echo "ED13(10.1.10.33) $trh"
elif [[ $ipcikti == '10.1.10.32' ]]; then 
echo "ED14(10.1.10.32) $trh"
elif [[ $ipcikti == '10.1.10.20' ]]; then 
echo "ED15(10.1.10.20) $trh"
elif [[ $ipcikti == '10.1.10.28' ]]; then 
echo "ED16(10.1.10.28) $trh"
elif [[ $ipcikti == '10.1.10.21' ]]; then 
echo "ED17(10.1.10.21) $trh"
elif [[ $ipcikti == '10.1.10.26' ]]; then 
echo "ED18(10.1.10.26) $trh"
elif [[ $ipcikti == '10.1.10.27' ]]; then 
echo "ED19(10.1.10.27) $trh"
elif [[ $ipcikti == '10.1.10.24' ]]; then 
echo "ED20(10.1.10.24) $trh"
elif [[ $ipcikti == '10.1.10.44' ]]; then 
echo "ED23(10.1.10.44) $trh"
elif [[ $ipcikti == '10.1.10.46' ]]; then 
echo "ED24(10.1.10.46) $trh"
elif [[ $ipcikti == '10.1.10.43' ]]; then 
echo "ED25(10.1.10.43) $trh"
elif [[ $ipcikti == '10.1.10.45' ]]; then 
echo "ED26(10.1.10.45) $trh"
elif [[ $ipcikti == '10.1.10.41' ]]; then 
echo "ED27(10.1.10.41) $trh"
elif [[ $ipcikti == '10.1.10.42' ]]; then 
echo "ED28(10.1.10.42) $trh"
fi


ssh -T scc

log=$(ls -t1 /opt/eds/log/diag/bit/* | head -n 1)

grep HVPS0:TUBE_A $log | awk '$6 > 3.45 && $6 < 4.6' | tail -n 1 | awk '{print "1-3", $6}'
grep HVPS0:TUBE_B $log | awk '$6 > 3.45 && $6 < 4.6' | tail -n 1 | awk '{print "1-1", $6}'
grep HVPS0:TUBE_C $log | awk '$6 > 3.45 && $6 < 4.6' | tail -n 1 | awk '{print "1-2", $6}'
grep HVPS1:TUBE_A $log | awk '$6 > 3.45 && $6 < 4.6' | tail -n 1 | awk '{print "2-2", $6}'
grep HVPS1:TUBE_B $log | awk '$6 > 3.45 && $6 < 4.6' | tail -n 1 | awk '{print "2-3", $6}'
grep HVPS1:TUBE_C $log | awk '$6 > 3.45 && $6 < 4.6' | tail -n 1 | awk '{print "2-1", $6}'
grep HVPS2:TUBE_A $log | awk '$6 > 3.45 && $6 < 4.6' | tail -n 1 | awk '{print "3-1", $6}'
grep HVPS2:TUBE_B $log | awk '$6 > 3.45 && $6 < 4.6' | tail -n 1 | awk '{print "3-2", $6}'
grep HVPS2:TUBE_C $log | awk '$6 > 3.45 && $6 < 4.6' | tail -n 1 | awk '{print "3-3", $6}'

echo ""

code

done	


