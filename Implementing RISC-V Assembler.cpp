
#include <iostream>
#include<string>
#include <string.h> 
#include <stdio.h> 
#include <vector>
#include <cstring>
#define MAX 32
#pragma warning( disable : 4996 )
using namespace std;


vector<string> split(const string& str, const string& delim) {
	vector<string> res;
	if ("" == str) return res;
	//先將要切割的字符串從string類型轉換為char*類型
	char * strs = new char[str.length() + 1]; //不要忘了
	strcpy(strs, str.c_str());

	char * d = new char[delim.length() + 1];
	strcpy(d, delim.c_str());

	char *p = strtok(strs, d);
	
	while (p) {
		string s = p; //分割得到的字符串轉換為string類型
		res.push_back(s); //存入结果數组
		p = strtok(NULL, d);
	}

	return res;
}
string ttt(const string&str)
{
	if (str == "0")
		return "000000000000";
	else {
		int num, i = 0;
		num = stoi(str);
		int bin[MAX], length = 0;
		do
		{
			bin[i] = num % 2;
			num = num / 2;
			i++;
			length++;
		} while (num != 1);
		bin[length] = num;
		length++;
		string result;
		for (i = length - 1; i >= 0; i--)
			result = result + to_string(bin[i]);
		while (result.size() != 12)
			result = "0" + result;
		return result;
	}
}
string ttt2(const string&str)
{
	if (str == "0")
		return "00000";
	else {
		int num, i = 0;
		num = stoi(str);
		int bin[MAX], length = 0;
		do
		{
			bin[i] = num % 2;
			num = num / 2;
			i++;
			length++;
		} while (num != 1);
		bin[length] = num;
		length++;
		string result;
		for (i = length - 1; i >= 0; i--)
			result = result + to_string(bin[i]);
		while (result.size() != 5)
			result = "0" + result;
		return result;
	}
}

void test() { //正常字符串
	cout << "******test****** " << endl;
	string s;
	string imm;
	while (s != "exit") {
		getline(cin, s);
		string answer = "";
		string temp = "";
		string temp2 = "";
		if (s == "exit") {
			cout << "bye bye";
		}
		//lb x27, 0(x10)
		else {
				s = s.replace(s.find(" "), 1, ",");
				
			std::vector<string> res = split(s, ",");

			if (res[0] == "lb" || res[0] == "lh" || res[0] == "lw" || res[0] == "lbu"
				|| res[0] == "lhu" || res[0] == "sb" || res[0] == "sh" || res[0] == "sw")
			{
				s = s.replace(s.find(" "), 1, "");
				s = s.replace(s.find(")"), 1, "");
				s = s.replace(s.find("("), 1, ",");
				res = split(s, ",");
			}

			for (int i = 0; i < res.size(); ++i)
			{
				if (res[i] == "x0") {
					res[i] = "00000";
				}
				else if (res[i] == "x1") {
					res[i] = "00001";
				}
				else if (res[i] == "x2") {
					res[i] = "00010";
				}
				else if (res[i] == "x3") {
					res[i] = "00011";
				}
				else if (res[i] == "x4") {
					res[i] = "00100";
				}
				else if (res[i] == "x5") {
					res[i] = "00101";
				}
				else if (res[i] == "x6") {
					res[i] = "00110";
				}
				else if (res[i] == "x7") {
					res[i] = "00111";
				}
				else if (res[i] == "x8") {
					res[i] = "01000";
				}
				else if (res[i] == "x9") {
					res[i] = "01001";
				}
				else if (res[i] == "x10") {
					res[i] = "01010";
				}
				else if (res[i] == "x11") {
					res[i] = "01011";
				}
				else if (res[i] == "x12") {
					res[i] = "01100";
				}
				else if (res[i] == "x13") {
					res[i] = "01101";
				}
				else if (res[i] == "x14") {
					res[i] = "01110";
				}
				else if (res[i] == "x15") {
					res[i] = "01111";
				}
				else if (res[i] == "x16") {
					res[i] = "10000";
				}
				else if (res[i] == "x17") {
					res[i] = "10001";
				}
				else if (res[i] == "x18") {
					res[i] = "10010";
				}
				else if (res[i] == "x19") {
					res[i] = "10011";
				}
				else if (res[i] == "x20") {
					res[i] = "10100";
				}
				else if (res[i] == "x21") {
					res[i] = "10101";
				}
				else if (res[i] == "x22") {
					res[i] = "10110";
				}
				else if (res[i] == "x23") {
					res[i] = "10111";
				}
				else if (res[i] == "x24") {
					res[i] = "11000";
				}
				else if (res[i] == "x25") {
					res[i] = "11001";
				}
				else if (res[i] == "x26") {
					res[i] = "11010";
				}
				else if (res[i] == "x27") {
					res[i] = "11011";
				}
				else if (res[i] == "x28") {
					res[i] = "11100";
				}
				else if (res[i] == "x29") {
					res[i] = "11101";
				}
				else if (res[i] == "x30") {
					res[i] = "11110";
				}
				else if (res[i] == "x31") {
					res[i] = "11111";
				}

			}
			
			for (int i = 0; i < res.size(); ++i)
			{
				if (res[i] == "lb")
				{
					//answer = ttt(res[i + 2]) + res[i + 3] + "000" + res[i + 1] + "0000011";

				}
				if (res[i] == "lh")
				{
					answer = ttt(res[i + 2]) + res[i + 3] + "001" + res[i + 1] + "0000011";
				}
				if (res[i] == "lw")
				{
					answer = ttt(res[i + 2]) + res[i + 3] + "010" + res[i + 1] + "0000011";
				}
				if (res[i] == "lbu")
				{
					answer = ttt(res[i + 2]) + res[i + 3] + "100" + res[i + 1] + "0000011";
				}
				if (res[i] == "lhu") 
				{
					answer = ttt(res[i + 2]) + res[i + 3] + "101" + res[i + 1] + "0000011";
				}
				if (res[i] == "sb")
				{
					imm = res[i + 2];
					imm = ttt(imm);
					answer = answer.append(imm, 0, 7);
					answer = answer + res[i + 1] + res[i + 3] + "000";
					answer = answer.append(imm, 7, 5);
					answer = answer + "0100011";

				}
				if (res[i] == "sh")
				{
					imm = res[i + 2];
					imm = ttt(imm);
					answer = answer.append(imm, 0, 7);
					answer = answer + res[i + 1] + res[i + 3] + "001";
					answer = answer.append(imm, 7, 5);
					answer = answer + "0100011";

				}
				if (res[i] == "sw")
				{
					imm = res[i + 2];
					imm = ttt(imm);
					answer = answer.append(imm, 0, 7);
					answer = answer + res[i + 1] + res[i + 3] + "010";
					answer = answer.append(imm, 7, 5);
					answer = answer + "0100011";

				}
			
				if (res[i] == "addi")
				{
					answer = ttt(res[i + 3]) + res[i + 2] + "000" + res[i + 1] + "0010011" ;
				}
				
				if (res[i] == "slti")
				{
					answer = ttt(res[i + 3]) + res[i + 2] + "010" + res[i + 1] + "0010011";
				}

				if (res[i] == "sltiu")
				{
					answer = ttt(res[i + 3]) + res[i + 2] + "011" + res[i + 1] + "0010011";
				}

				if (res[i] == "xori")
				{
					answer = ttt(res[i + 3]) + res[i + 2] + "100" + res[i + 1] + "0010011";
				}

				if (res[i] == "ori")
				{
					answer = ttt(res[i + 3]) + res[i + 2] + "110" + res[i + 1] + "0010011";
				}

				if (res[i] == "andi")
				{
					answer = ttt(res[i + 3]) + res[i + 2] + "111" + res[i + 1] + "0010011";
				}


				if (res[i] == "slli")
				{
					answer = "0000000" + ttt2(res[i + 3]) + res[i + 2] + "001" + res[i + 1] + "0010011";
				}

				if (res[i] == "srli")
				{
					answer = "0000000" + ttt2(res[i + 3]) + res[i + 2] + "101" + res[i + 1] + "0010011";
				}

				if (res[i] == "srai")
				{
					answer = "0100000" + ttt2(res[i + 3]) + res[i + 2] + "101" + res[i + 1] + "0010011";
				}

				if (res[i] == "add")
				{
					answer = "0000000" + res[i + 3] + res[i + 2] + "000" + res[i + 1] + "0110011";
				}

				if (res[i] == "sub")
				{
					answer = "0100000" + res[i + 3] + res[i + 2] + "000" + res[i + 1] + "0110011";
				}

				if (res[i] == "sll")
				{
					answer = "0000000" + res[i + 3] + res[i + 2] + "001" + res[i + 1] + "0110011";
				}

				if (res[i] == "slt")
				{
					answer = "0000000" + res[i + 3] + res[i + 2] + "010" + res[i + 1] + "0110011";
				}

				if (res[i] == "sltu")
				{
					answer = "0000000" + res[i + 3] + res[i + 2] + "011" + res[i + 1] + "0110011";
				}

				if (res[i] == "xor")
				{
					answer = "0000000" + res[i + 3] + res[i + 2] + "100" + res[i + 1] + "0110011";
				}

				if (res[i] == "srl")
				{
					answer = "0000000" + res[i + 3] + res[i + 2] + "101" + res[i + 1] + "0110011";
				}

				if (res[i] == "sra")
				{
					answer = "0100000" + res[i + 3] + res[i + 2] + "101" + res[i + 1] + "0110011";
				}

				if (res[i] == "or")
				{
					answer = "0000000" + res[i + 3] + res[i + 2] + "110" + res[i + 1] + "0110011";
				}

				if (res[i] == "and")
				{
					answer = "0000000" + res[i + 3] + res[i + 2] + "111" + res[i + 1] + "0110011";
				}
				//cout << res[i]<<endl;
			}		
			cout << "answer:" << answer;
		}
	}
}

int main() {
	test();
	system("pause");
	return 0;
}