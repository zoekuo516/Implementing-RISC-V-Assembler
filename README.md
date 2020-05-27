# Implementing-RISC-V-Assembler

輸入inst

輸出

建立兩個function : HexToBinary_12bit & HexToBinary_5bit，都是從十進位轉二進位，只是分別要回傳12 bit跟5 bit;function裡先input一個值做mod 2判斷是0還是1，讓他能轉成binary，再做一個for迴圈把數字倒過來再把多的補零。

main function 裡先輸入一個為string的inst，然後遇到逗號或左括號跟右括號都轉為空格，以便等等好操作，然後利用stringstream把inst裡的東西push back到regist裡，再用if來做判斷，判斷第一個的inst符合哪一個條件，就進去做裡面要做的事情，最後輸出machine code。
