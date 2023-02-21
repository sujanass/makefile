#!/bin/bash
grep -e \>: -e ret -e mret *.objdump > pc_monitor_1.txt
cut -c3-60 pc_monitor_1.txt > pc_monitor.txt

sed 's/</: /g' pc_monitor.txt > pc_monitor_1.txt

sed 's/>:/ /g' pc_monitor_1.txt > pc_monitor.txt

rm -rf pc_monitor_1.txt

echo "-----------------------------"

echo "PC monitor generated"

echo "-----------------------------"
