# Implementing-RISC-V-Assembler

## 輸入
單行指令傳入inst
ex. ld x1, 0(x2)

## function介紹
### HexToBinary_12bit & HexToBinary_5bit
用途:
都是從十進位轉二進位，只是分別要回傳12 bit跟5 bit; function裡先input一個值做mod 2判斷是0還是1，讓他能轉成binary，再做一個for迴圈把數字倒過來並把多的補零。

### main function 
用途:
1) 先輸入一個為string的inst，然後遇到 逗號、左括號、右括號 都轉為空格，以便等等好操作。
ex. ld x1  0 x2 

2) 利用stringstream把inst裡的東西push back到regist裡
ex. {"ld","x1","0","x2"}

3) 用if來做判斷，判斷第一個的regist[0](ex. ld)符合哪一個格式，最後輸出machine code。

## 輸出
machine code
