#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#define MAX 32
#pragma warning( disable : 4996 )
using namespace std;

string HexToBinary_12bit(int inputHex)
{
	if (inputHex == 0)
		return "000000000000";
	string ans_reverse="";
	int temp = inputHex;
	while (temp != 0)
	{
		if (temp % 2 == 0)
			ans_reverse += "0";
		else if (temp % 2 == 1)
			ans_reverse += "1";
		temp /=  2;
	}

	string ANS="";
	for (int i = 11; i >= 0; i--) {
		if (i > ans_reverse.length()-1)
			ANS += "0";
		else
			ANS += ans_reverse[i];
	}
	return ANS;
}

string HexToBinary_5bit(int inputHex)	//十進位轉二進位(12bit)
{
	if (inputHex == 0)
		return "00000";
	string ans_reverse = "";
	int temp = inputHex;
	while (temp != 0)
	{
		if (temp % 2 == 0)
			ans_reverse += "0";
		else if (temp % 2 == 1)
			ans_reverse += "1";
		temp /= 2;
	}

	string ANS = "";
	for (int i = 4; i >= 0; i--) {
		if (i > ans_reverse.length() - 1)
			ANS += "0";
		else
			ANS += ans_reverse[i];
	}
	return ANS;
}


int main() {
	cout << "Input instruction : ";
	string inst, imm, answer;

	while (getline(cin, inst)) {
		if (inst == "")
			continue;

		vector<string> regist;

		for (int i = 0; i < inst.length(); i++) {
			if (inst[i]== ',' ||inst[i]== ')' ||inst[i]== '(') {
				inst[i] = ' ';
			}
		}

		stringstream ss(inst);
		string tempGet;
		while (ss >> tempGet) {
			regist.push_back(tempGet);
		}

		for (int i = 0; i < regist.size(); i++)
		{
			if (regist[i] == "x0") {
				regist[i] = "00000";
			}
			else if (regist[i] == "x1") {
				regist[i] = "00001";
			}
			else if (regist[i] == "x2") {
				regist[i] = "00010";
			}
			else if (regist[i] == "x3") {
				regist[i] = "00011";
			}
			else if (regist[i] == "x4") {
				regist[i] = "00100";
			}
			else if (regist[i] == "x5") {
				regist[i] = "00101";
			}
			else if (regist[i] == "x6") {
				regist[i] = "00110";
			}
			else if (regist[i] == "x7") {
				regist[i] = "00111";
			}
			else if (regist[i] == "x8") {
				regist[i] = "01000";
			}
			else if (regist[i] == "x9") {
				regist[i] = "01001";
			}
			else if (regist[i] == "x10") {
				regist[i] = "01010";
			}
			else if (regist[i] == "x11") {
				regist[i] = "01011";
			}
			else if (regist[i] == "x12") {
				regist[i] = "01100";
			}
			else if (regist[i] == "x13") {
				regist[i] = "01101";
			}
			else if (regist[i] == "x14") {
				regist[i] = "01110";
			}
			else if (regist[i] == "x15") {
				regist[i] = "01111";
			}
			else if (regist[i] == "x16") {
				regist[i] = "10000";
			}
			else if (regist[i] == "x17") {
				regist[i] = "10001";
			}
			else if (regist[i] == "x18") {
				regist[i] = "10010";
			}
			else if (regist[i] == "x19") {
				regist[i] = "10011";
			}
			else if (regist[i] == "x20") {
				regist[i] = "10100";
			}
			else if (regist[i] == "x21") {
				regist[i] = "10101";
			}
			else if (regist[i] == "x22") {
				regist[i] = "10110";
			}
			else if (regist[i] == "x23") {
				regist[i] = "10111";
			}
			else if (regist[i] == "x24") {
				regist[i] = "11000";
			}
			else if (regist[i] == "x25") {
				regist[i] = "11001";
			}
			else if (regist[i] == "x26") {
				regist[i] = "11010";
			}
			else if (regist[i] == "x27") {
				regist[i] = "11011";
			}
			else if (regist[i] == "x28") {
				regist[i] = "11100";
			}
			else if (regist[i] == "x29") {
				regist[i] = "11101";
			}
			else if (regist[i] == "x30") {
				regist[i] = "11110";
			}
			else if (regist[i] == "x31") {
				regist[i] = "11111";
			}
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////////// SB-type
		if (regist[0] == "bne")
		{
			//imm[12|10:5] rs2 rs1 001 imm[4:1|11] 1100011
			answer = "*******" + regist[2] + regist[1] + "001" + "*****" + "1100011";
		}
		else if (regist[0] == "beq")
		{
			answer = "*******" + regist[2] + regist[1] + "000" + "*****" + "1100011";
		}
		else if (regist[0] == "blt")
		{
			answer = "*******" + regist[2] + regist[1] + "100" + "*****" + "1100011";
		}
		else if (regist[0] == "bgt")
		{
			answer = "*******" + regist[2] + regist[1] + "101" + "*****" + "1100011";
		}
		else if (regist[0] == "bltu")
		{
			answer = "*******" + regist[2] + regist[1] + "110" + "*****" + "1100011";
		}
		else if (regist[0] == "bgtu")
		{
			answer = "*******" + regist[2] + regist[1] + "111" + "*****" + "1100011";
		}
		////////////////////////////////////////////////////////////////////////////////////////////////////////////// I-type
		else if (regist[0] == "lb")					//lb x12,1(x5)
		{
			answer = HexToBinary_12bit(stoi(regist[2])) + regist[3] + "000" + regist[1] + "0000011";
		}
		else if (regist[0] == "lh")
		{
			answer = HexToBinary_12bit(stoi(regist[2])) + regist[3] + "001" + regist[1] + "0000011";
		}
		else if (regist[0] == "lw")
		{
			answer = HexToBinary_12bit(stoi(regist[2])) + regist[3] + "010" + regist[1] + "0000011";
		}
		else if (regist[0] == "lbu")
		{
			answer = HexToBinary_12bit(stoi(regist[2])) + regist[3] + "100" + regist[1] + "0000011";
		}
		else if (regist[0] == "lhu")
		{
			answer = HexToBinary_12bit(stoi(regist[2])) + regist[3] + "101" + regist[1] + "0000011";
		}
		////////////////////////////////////////////////////////////////////////////////////////////////////////////// I-type
		else if (regist[0] == "addi")
		{
			answer = HexToBinary_12bit(stoi(regist[3])) + regist[2] + "000" + regist[1] + "0010011";
		}
		else if (regist[0] == "slti")
		{
			answer = HexToBinary_12bit(stoi(regist[3])) + regist[2] + "010" + regist[1] + "0010011";
		}
		else if (regist[0] == "sltiu")
		{
			answer = HexToBinary_12bit(stoi(regist[3])) + regist[2] + "011" + regist[1] + "0010011";
		}
		else if (regist[0] == "xori")
		{
			answer = HexToBinary_12bit(stoi(regist[3])) + regist[2] + "100" + regist[1] + "0010011";
		}
		else if (regist[0] == "ori")
		{
			answer = HexToBinary_12bit(stoi(regist[3])) + regist[2] + "110" + regist[1] + "0010011";
		}
		else if (regist[0] == "andi")
		{
			answer = HexToBinary_12bit(stoi(regist[3])) + regist[2] + "111" + regist[1] + "0010011";
		}
		////////////////////////////////////////////////////////////////////////////////////////////////////////////// S-type
		else if (regist[0] == "sd" || regist[0] == "sb" || regist[0] == "sh" || regist[0] == "sw")
		{
			imm = regist[2];
			imm = HexToBinary_12bit(stoi(imm));
			answer = answer.append(imm, 0, 7);
			switch (regist[0][1])
			{
			case 'd':
				answer = answer + regist[1] + regist[3] + "011";
				break;
			case 'b':
				answer = answer + regist[1] + regist[3] + "000";
				break;
			case 'h':
				answer = answer + regist[1] + regist[3] + "001";
				break;
			case 'w':
				answer = answer + regist[1] + regist[3] + "010";
				break;
			}
			answer = answer.append(imm, 7, 5);
			answer = answer + "0100011";
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////
		else if (regist[0] == "slli")
		{
			answer = "0000000" + HexToBinary_5bit(stoi(regist[3])) + regist[2] + "001" + regist[1] + "0010011";
		}
		else if (regist[0] == "srli")
		{
			answer = "0000000" + HexToBinary_5bit(stoi(regist[3])) + regist[2] + "101" + regist[1] + "0010011";
		}
		else if (regist[0] == "srai")
		{
			answer = "0100000" + HexToBinary_5bit(stoi(regist[3])) + regist[2] + "101" + regist[1] + "0010011";
		}
		////////////////////////////////////////////////////////////////////////////////////////////////////////////// R-type
		else if (regist[0] == "add")
		{
			answer = "0000000" + regist[3] + regist[2] + "000" + regist[1] + "0110011";
		}
		else if (regist[0] == "sub")
		{
			answer = "0100000" + regist[3] + regist[2] + "000" + regist[1] + "0110011";
		}
		else if (regist[0] == "sll")
		{
			answer = "0000000" + regist[3] + regist[2] + "001" + regist[1] + "0110011";
		}
		else if (regist[0] == "slt")
		{
			answer = "0000000" + regist[3] + regist[2] + "010" + regist[1] + "0110011";
		}
		else if (regist[0] == "sltu")
		{
			answer = "0000000" + regist[3] + regist[2] + "011" + regist[1] + "0110011";
		}
		else if (regist[0] == "xor")
		{
			answer = "0000000" + regist[3] + regist[2] + "100" + regist[1] + "0110011";
		}
		else if (regist[0] == "srl")
		{
			answer = "0000000" + regist[3] + regist[2] + "101" + regist[1] + "0110011";
		}
		else if (regist[0] == "sra")
		{
			answer = "0100000" + regist[3] + regist[2] + "101" + regist[1] + "0110011";
		}
		else if (regist[0] == "or")
		{
			answer = "0000000" + regist[3] + regist[2] + "110" + regist[1] + "0110011";
		}
		else if (regist[0] == "and")
		{
			answer = "0000000" + regist[3] + regist[2] + "111" + regist[1] + "0110011";
		}
		else {
			answer = "";
			cout << "We don't have this instruction!!!" << endl;
			continue;
		}

		cout << "The answer is : " << answer << endl << "Input next instruction : ";
	}

	return 0;
}
