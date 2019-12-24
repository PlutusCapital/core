1. > docker-compose -f masternode.yaml exec mn2 bash
2. > ./plutus-cli -datadir=./.plutus importprivkey 87e22mATMd1dmgvy2Y9DhYpyFqz1XCkRfZkctydAkLxmXvt77N8
3. > ./plutus-cli -datadir=./.plutus setaccount DEtSt7gumYkf67x6ny9Mi6XTEoo4efprGY mintaccount
4. > ./plutus-cli -datadir=./.plutus getbalance mintaccount
5. > ./plutus-cli -datadir=./.plutus sendfrom mintaccount D82d5uCM48cfF8z7EyT5V1jwauqv8ENnTR <amount>
