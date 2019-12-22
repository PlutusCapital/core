#!/bin/sh

touch ./plutus.conf

mkdir .plutus
x=$REMOTES
OLD_IFS=$IFS    # save internal field separator
IFS=","         # set it to '+'
set -- $x       # make the result positional parameters
IFS=$OLD_IFS    # restore IFS
for i in "$@"; do # access each element of array
   echo "addnode = $i" >> ./plutus.conf
done

# echo "server=1" >> ./plutus.conf
# echo "discover=0" >> ./plutus.conf
# echo "daemon=1" >> ./plutus.conf
# echo "logtimestamps=1" >> ./plutus.conf
# echo "maxconnections=256" >> ./plutus.conf
# echo "masternode=1" >> ./plutus.conf
# echo "externalip=$IP" >> ./plutus.conf
# echo "masternodeprivkey=$PRIVKEY" >> ./plutus.conf
echo "rpcuser=rpcuser" >> ./plutus.conf
echo "rpcpassword=111111" >> ./plutus.conf
echo "rpcallowip=10.1.1.34/255.255.255.0" >> ./plutus.conf
echo "rpcallowip=0.0.0.0/0" >> ./plutus.conf
echo "rpcbind=0.0.0.0" >> ./plutus.conf

mv ./plutus.conf ./.plutus
./plutusd -datadir=./.plutus -printtoconsole