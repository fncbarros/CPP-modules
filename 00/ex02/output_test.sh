#!/bin/bash
make
./ledger | awk '{print $2}' > logs/new.log
awk '{print $2}' logs/19920104_091532.log > logs/old.log
diff logs/new.log logs/old.log
rm logs/old.log
