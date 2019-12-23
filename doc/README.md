MASTERNODE SETUP GUIDE
========================

Prerequisite
---------------------
Buy PLT coins.
Your private key will be referred to as {privateKey} throughout this document. 

Get a VPS
---------------------
Minimum requirements: 4 GB RAM, 2 vCPUs, 100 GB SSD
Softwares: git, docker, docker-compose, unzip
static public IP

Setup
----------------------

Inside VM:
1. > mkdir plutus
2. > cd plutus
3.   Download the archive from 
4. > unzip node.zip
5. > docker-compose -f masternode.yaml build
6. > docker-compose -f masternode.yaml up -d
7. > docker exec masternode bash

Inside bash:
    ./plutus-cli -datadirimportprivkey {privateKey}
    ./plutus-cli -datadir=./.plutus createmasternodekey | NOTE: {masternodeKey}
    ./plutus-cli -datadir=./.plutus getaccountaddress {accountName} | NOTE: {accountAddress}
    ./plutus-cli -datadir=./.plutus sendtoaddress {accountAddress} 1000
    Wait for sometime so that the transaction is mined in the chain
    ./plutus-cli -datadir=./.plutus getmasternodeoutputs | Note: {txhash} {outputidx}
    exit

Inside VM:
1. > docker-compose down -v
2. > nano masternode.conf
3. Paste: the values without angle brackets: {accountName} {ip:51472} {masternodeKey} {txhash} {outputidx} 
4. > nano plutus.conf
5. Paste:
 server=1
 logtimestamps=1
 maxconnections=256
 masternode=1
 masternodeaddr=<>:51472
 masternodeprivkey={masternodeKey}
6. > Docker-compose up
7. > docker exec {accountName} bash

Inside bash:
    ./plutus-cli -datadir=./.plutus startmasternode alias false {accountName}
    ./plutus-cli -datadir=./.plutus startmasternode local false
