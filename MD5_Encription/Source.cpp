#include<iostream>
#include<conio.h>
using namespace std;

// Sub-String Retriver
char* subString(char*, int, int);

class MD5Processor
{
	long int A, B, C, D, a, b, c, d;
public:
	
	MD5Processor();
	
	long int getA();
	long int getB();
	long int getC();
	long int getD();

	int functionF(int, int, int);
	int functionG(int, int, int);
	int functionH(int, int, int);
	int functionI(int, int, int);
	
    void roundOne(char*);
	void roundTwo(char*);
	void roundThree(char*);
	void roundFour(char*);

	void MD5Genrator(char*);
};

MD5Processor::MD5Processor()
{
	A = 0x01234567;
	B = 0x89abcdef;
	C = 0xfedcba98;
	D = 0x76543210;
}

//get functions -->
long int MD5Processor::getA()
{
	return A;
}
long int MD5Processor::getB()
{
	return B;
}
long int MD5Processor::getC()
{
	return C;
}
long int MD5Processor::getD()
{
	return D;
}
//<--

// Operational Functions-->
int MD5Processor::functionF(int x, int y, int z)
{
	return (x&y) | (~x&z);
} 
int MD5Processor::functionG(int x, int y, int z)
{
	return (x&z) | (y&~z);
}
int MD5Processor::functionH(int x, int y, int z)
{
	return x^y^z;
}
int MD5Processor::functionI(int x, int y, int z)
{
	return y ^ (x | ~z);
}
//  <--



// Modifier Rounds -->
void MD5Processor::roundOne(char *str)
{
	
	A = B + ((A + functionF(B, C, D) + str[0] + 1) << 7);
	D = A + ((D + functionF(A, B, C) + str[1] + 2) << 12);
	C = D + ((C + functionF(D, A, B) + str[2] + 3) << 17);
	B = C + ((B + functionF(C, D, A) + str[3] + 4) << 22);

	A = B + ((A + functionF(B, C, D) + str[4] + 5) << 7);
	D = A + ((D + functionF(A, B, C) + str[5] + 6) << 12);
	C = D + ((C + functionF(D, A, B) + str[6] + 7) << 17);
	B = C + ((B + functionF(C, D, A) + str[7] + 8) << 22);

	A = B + ((A + functionF(B, C, D) + str[8] + 9) << 7);
	D = A + ((D + functionF(A, B, C) + str[9] + 10) << 12);
	C = D + ((C + functionF(D, A, B) + str[10] + 11) << 17);
	B = C + ((B + functionF(C, D, A) + str[11] + 12) << 22);

	A = B + ((A + functionF(B, C, D) + str[12] + 13) << 7);
	D = A + ((D + functionF(A, B, C) + str[13] + 14) << 12);
	C = D + ((C + functionF(D, A, B) + str[14] + 15) << 17);
	B = C + ((B + functionF(C, D, A) + str[15] + 16) << 22);
}

void MD5Processor::roundTwo(char *str)
{
	A = B + ((A + functionG(B, C, D) + str[1] + 17) << 5);
	D = A + ((D + functionG(A, B, C) + str[6] + 18) << 9);
	C = D + ((C + functionG(D, A, B) + str[11] + 19) << 14);
	B = C + ((B + functionG(C, D, A) + str[0] + 20) << 20);

	A = B + ((A + functionG(B, C, D) + str[5] + 21) << 5);
	D = A + ((D + functionG(A, B, C) + str[10] + 22) << 9);
	C = D + ((C + functionG(D, A, B) + str[15] + 23) << 14);
	B = C + ((B + functionG(C, D, A) + str[4] + 24) << 20);

	A = B + ((A + functionG(B, C, D) + str[9] + 25) << 5);
	D = A + ((D + functionG(A, B, C) + str[14] + 26) << 9);
	C = D + ((C + functionG(D, A, B) + str[3] + 27) << 14);
	B = C + ((B + functionG(C, D, A) + str[8] + 28) << 20);

	A = B + ((A + functionG(B, C, D) + str[13] + 29) << 5);
	D = A + ((D + functionG(A, B, C) + str[2] + 30) << 9);	
	C = D + ((C + functionG(D, A, B) + str[7] + 31) << 14);
	B = C + ((B + functionG(C, D, A) + str[12] + 32) << 20);

}

void MD5Processor::roundThree(char *str)
{
	A = B + ((A + functionH(B, C, D) + str[5] + 33) << 4);
	D = A + ((D + functionH(A, B, C) + str[8] + 34) << 11);
	C = D + ((C + functionH(D, A, B) + str[11] + 35) << 16);
	B = C + ((B + functionH(C, D, A) + str[14] + 36) << 23);

	A = B + ((A + functionH(B, C, D) + str[1] + 37) << 4);
	D = A + ((D + functionH(A, B, C) + str[4] + 38) << 11);
	C = D + ((C + functionH(D, A, B) + str[7] + 39) << 16);
	B = C + ((B + functionH(C, D, A) + str[10] + 40) << 23);

	A = B + ((A + functionH(B, C, D) + str[13] + 41) << 4);
	D = A + ((D + functionH(A, B, C) + str[0] + 42) << 11);
	C = D + ((C + functionH(D, A, B) + str[3] + 43) << 16);
	B = C + ((B + functionH(C, D, A) + str[6] + 44) << 23);

	A = B + ((A + functionH(B, C, D) + str[9] + 45) << 4);	
	D = A + ((D + functionH(A, B, C) + str[12] + 46) << 11);
	C = D + ((C + functionH(D, A, B) + str[15] + 47) << 16);
	B = C + ((B + functionH(C, D, A) + str[2] + 48) << 23);

}

void MD5Processor::roundFour(char *str)
{
	A = B + ((A + functionI(B, C, D) + str[0] + 49) << 6);
	D = A + ((D + functionI(A, B, C) + str[7] + 50) << 10);
	C = D + ((C + functionI(D, A, B) + str[14] + 51) << 15);
	B = C + ((B + functionI(C, D, A) + str[5] + 52) << 21);

	A = B + ((A + functionI(B, C, D) + str[12] + 53) << 6);
	D = A + ((D + functionI(A, B, C) + str[3] + 54) << 10);
	C = D + ((C + functionI(D, A, B) + str[10] + 55) << 15);
	B = C + ((B + functionI(C, D, A) + str[1] + 56) << 21);

	A = B + ((A + functionI(B, C, D) + str[8] + 57) << 6);
	D = A + ((D + functionI(A, B, C) + str[15] + 58) << 10);
	C = D + ((C + functionI(D, A, B) + str[6] + 59) << 15);
	B = C + ((B + functionI(C, D, A) + str[13] + 60) << 21);

	A = B + ((A + functionI(B, C, D) + str[4] + 61) << 6);
	D = A + ((D + functionI(A, B, C) + str[11] + 62) << 10);
	C = D + ((C + functionI(D, A, B) + str[2] + 63) << 15);
	B = C + ((B + functionI(C, D, A) + str[9] + 64) << 21);

}
// <--

//MD5 Genrator -->
void MD5Processor::MD5Genrator(char* msg)
{
	a = A;
	b = B;
	c = C;
	d = D;
	roundOne(msg);
	A += a;
	B += b;
	C += c;
	D += d;

	a = A;
	b = B;
	c = C;
	d = D;
	roundTwo(msg);
	A += a;
	B += b;
	C += c;
	D += d;

	a = A;
	b = B;
	c = C;
	d = D;
	roundThree(msg);
	A += a;
	B += b;
	C += c;
	D += d;

	a = A;
	b = B;
	c = C;
	d = D;
	roundFour(msg);
	A += a;
	B += b;
	C += c;
	D += d;
}
//<--

int main()
{
	MD5Processor md5;
	
	
	int i = 0, j = 0, a = 0, b = 16;
	char *msg, *block, *str;


	// Message Input 


	for (i = 0; sizeof(&msg) > (sizeof(&msg)*(512 * i) - 64); i++);
	
	
	//Padding

	str = new char[sizeof(msg) * 512 * i];	// new message created after padding

	for (j = 0; j < (i * 16); j++)
	{
		block = subString(str, a, b);
		md5.MD5Genrator(block);
		a = b + 1;
		b = b + a;
	} 
	
	cout << std::hex << "MD5 of message is : " << md5.getA() << md5.getB() << md5.getC() << md5.getD();
	
	_getch();
	return 0;
}

char* subString(char* str, int start, int end)
{
	int i, j;
	char *temp = new char[end - start];
	for ( i = start,  j = 0; i <= end; i++, j++)
		temp[j] = str[i];
	temp[j] = '\0';
	return temp;
}