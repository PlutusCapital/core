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
```
3.   Download the archive from https://drive.google.com/drive/folders/1LdJFBbQhT4nhNQTnC2DLVrRBpJsTMc4u?usp=sharing
```
4. > unzip node.zip
5. > docker-compose -f masternode.yaml build
6. > docker-compose -f masternode.yaml up -d
7. > docker exec masternode bash

Inside bash:
1. > ./plutus-cli -datadirimportprivkey {privateKey}
2. > ./plutus-cli -datadir=./.plutus createmasternodekey | NOTE: {masternodeKey}
3. > ./plutus-cli -datadir=./.plutus getaccountaddress {accountName} | NOTE: {accountAddress}
4. > ./plutus-cli -datadir=./.plutus sendtoaddress {accountAddress} 1000
```
5. Wait for sometime so that the transaction is mined in the chain
```
6. > ./plutus-cli -datadir=./.plutus getmasternodeoutputs | Note: {txhash} {outputidx}
7. > exit

Inside VM:
1. > docker-compose down -v
2. > nano masternode.conf
3. Paste:
```
{accountName} {ip:51472} {masternodeKey} {txhash} {outputidx}
```
4. > nano plutus.conf
5. Paste:
```
 server=1
 logtimestamps=1
 maxconnections=256
 masternode=1
 masternodeaddr=<>:51472
 masternodeprivkey={masternodeKey}
 ```
6. > Docker-compose up
7. > docker exec {accountName} bash

Inside bash:
1. > ./plutus-cli -datadir=./.plutus startmasternode alias false {accountName}
2. > ./plutus-cli -datadir=./.plutus startmasternode local false
