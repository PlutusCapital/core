1. > docker-compose -f masternode.yaml exec mn2 bash
2. > ./plutus-cli -datadir=./.plutus importprivkey "87e22mATMd1dmgvy2Y9DhYpyFqz1XCkRfZkctydAkLxmXvt77N8"
3. > ./plutus-cli -datadir=./.plutus setaccount "DEtSt7gumYkf67x6ny9Mi6XTEoo4efprGY" "plutus"
4. > ./plutus-cli -datadir=./.plutus getbalance "plutus"
5. > ./plutus-cli -datadir=./.plutus sendfromaccount "DEtSt7gumYkf67x6ny9Mi6XTEoo4efprGY" "D82d5uCM48cfF8z7EyT5V1jwauqv8ENnTR" amount