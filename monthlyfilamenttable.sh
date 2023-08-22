#!/bin/bash

#ekremiscan

clear

echo " Filament Table"
echo " Write Year and month like ****-** or 2023-07 "
echo ""
echo ""
read Year

echo " $Year filament logs saving to /home/eds_cm/filamentables/"
echo ""
awk '{print $1, "      ", $2}' /home/eds_cm/eko/filament/Daily/filament-$Year-01 > /home/eds_cm/filamentables/$Year-01.csv
awk '{print $1, "      ", $2}' /home/eds_cm/eko/filament/Daily/filament-$Year-02 > /home/eds_cm/filamentables/$Year-02.csv
awk '{print $1, "      ", $2}' /home/eds_cm/eko/filament/Daily/filament-$Year-03 > /home/eds_cm/filamentables/$Year-03.csv
awk '{print $1, "      ", $2}' /home/eds_cm/eko/filament/Daily/filament-$Year-04 > /home/eds_cm/filamentables/$Year-04.csv
awk '{print $1, "      ", $2}' /home/eds_cm/eko/filament/Daily/filament-$Year-05 > /home/eds_cm/filamentables/$Year-05.csv
awk '{print $1, "      ", $2}' /home/eds_cm/eko/filament/Daily/filament-$Year-06 > /home/eds_cm/filamentables/$Year-06.csv
awk '{print $1, "      ", $2}' /home/eds_cm/eko/filament/Daily/filament-$Year-07 > /home/eds_cm/filamentables/$Year-07.csv
awk '{print $1, "      ", $2}' /home/eds_cm/eko/filament/Daily/filament-$Year-08 > /home/eds_cm/filamentables/$Year-08.csv
awk '{print $1, "      ", $2}' /home/eds_cm/eko/filament/Daily/filament-$Year-09 > /home/eds_cm/filamentables/$Year-09.csv
awk '{print $1, "      ", $2}' /home/eds_cm/eko/filament/Daily/filament-$Year-10 > /home/eds_cm/filamentables/$Year-10.csv
awk '{print $1, "      ", $2}' /home/eds_cm/eko/filament/Daily/filament-$Year-11 > /home/eds_cm/filamentables/$Year-11.csv
awk '{print $1, "      ", $2}' /home/eds_cm/eko/filament/Daily/filament-$Year-12 > /home/eds_cm/filamentables/$Year-12.csv
awk '{print $1, "      ", $2}' /home/eds_cm/eko/filament/Daily/filament-$Year-13 > /home/eds_cm/filamentables/$Year-13.csv
awk '{print $1, "      ", $2}' /home/eds_cm/eko/filament/Daily/filament-$Year-14 > /home/eds_cm/filamentables/$Year-14.csv
awk '{print $1, "      ", $2}' /home/eds_cm/eko/filament/Daily/filament-$Year-15 > /home/eds_cm/filamentables/$Year-15.csv
awk '{print $1, "      ", $2}' /home/eds_cm/eko/filament/Daily/filament-$Year-16 > /home/eds_cm/filamentables/$Year-16.csv
awk '{print $1, "      ", $2}' /home/eds_cm/eko/filament/Daily/filament-$Year-17 > /home/eds_cm/filamentables/$Year-17.csv
awk '{print $1, "      ", $2}' /home/eds_cm/eko/filament/Daily/filament-$Year-18 > /home/eds_cm/filamentables/$Year-18.csv
awk '{print $1, "      ", $2}' /home/eds_cm/eko/filament/Daily/filament-$Year-19 > /home/eds_cm/filamentables/$Year-19.csv
awk '{print $1, "      ", $2}' /home/eds_cm/eko/filament/Daily/filament-$Year-20 > /home/eds_cm/filamentables/$Year-20.csv
awk '{print $1, "      ", $2}' /home/eds_cm/eko/filament/Daily/filament-$Year-21 > /home/eds_cm/filamentables/$Year-21.csv
awk '{print $1, "      ", $2}' /home/eds_cm/eko/filament/Daily/filament-$Year-22 > /home/eds_cm/filamentables/$Year-22.csv
awk '{print $1, "      ", $2}' /home/eds_cm/eko/filament/Daily/filament-$Year-23 > /home/eds_cm/filamentables/$Year-23.csv
awk '{print $1, "      ", $2}' /home/eds_cm/eko/filament/Daily/filament-$Year-24 > /home/eds_cm/filamentables/$Year-24.csv
awk '{print $1, "      ", $2}' /home/eds_cm/eko/filament/Daily/filament-$Year-25 > /home/eds_cm/filamentables/$Year-25.csv
awk '{print $1, "      ", $2}' /home/eds_cm/eko/filament/Daily/filament-$Year-26 > /home/eds_cm/filamentables/$Year-26.csv
awk '{print $1, "      ", $2}' /home/eds_cm/eko/filament/Daily/filament-$Year-27 > /home/eds_cm/filamentables/$Year-27.csv
awk '{print $1, "      ", $2}' /home/eds_cm/eko/filament/Daily/filament-$Year-28 > /home/eds_cm/filamentables/$Year-28.csv
awk '{print $1, "      ", $2}' /home/eds_cm/eko/filament/Daily/filament-$Year-29 > /home/eds_cm/filamentables/$Year-29.csv
awk '{print $1, "      ", $2}' /home/eds_cm/eko/filament/Daily/filament-$Year-30 > /home/eds_cm/filamentables/$Year-30.csv

cd /home/eds_cm/filamentables/
tar -czvf filament-$Year.tar.gz $Year*

rm -f $Year*

echo ""
echo ""
echo "filament-$Year.tar.gz Saved to /home/eds_cm/filamentables/"
