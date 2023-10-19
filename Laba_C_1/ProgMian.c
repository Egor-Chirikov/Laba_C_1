#define _CRT_SECURE_NO_WARNINGS
#define N 50

#include <stdio.h>
#include <locale.h>

void skipLine() {
	char ch;
	while (scanf("%c", &ch))
		if (ch == '\n')
			break;	
}

int myBaceInput() {
	int inp;
	while (1)
	{	
		if (!scanf("%i", &inp) || inp <= 1 || inp > 36) {
			printf("\n!!����� n ������ ���� 1 < n <= 36 � �������� �� ����!!\n��������� ���� ������� ���������: ");
			skipLine();
			continue;
		}
		break;
	}
	skipLine();
	return inp;
}

int myCharArrayInput(char str[], int strBuc, int endBuc, int strNum, int endNum) {
	int ln = 0;

	printf("������� �����: ");
	for (int i = 0; ; i++) {
		if (i >= N) {
			printf("\n!!��������� ���� ����� ������� �������!!");
			skipLine();
			return 0;
		}

		if (!scanf("%c", str + i)) {
			printf("\n!!����������� ����!!");
			skipLine();
			return 0;
		}

		if (str[i] == '\n')
			break;

		if (!((strBuc <= str[i] && str[i] <= endBuc) || (strNum <= str[i] && str[i] <= endNum))) {
			printf("\n!!����� ������ ������� �� ���� � ��������� ���� ����������� ��������!!");
			skipLine();
			return 0;
		}

		ln++;
	}

	return ln;
}

long int myPow(int num, unsigned short stepn) {
	long int ret = 1;
	long int rem = num;

	for (int i = 0; i < stepn; i++)
		ret *= num;
	if (ret < num)
		return 0;
	return ret;
}

int main() {
	int bace, newBace, lnOld = 0, lnNew = 0;
	long int sumOld = 0;
	char strtBuc = 'A', endBuc;
	char strtNum = '0', endNum;
	char strOld[N];
	int strNew[N];

	setlocale(LC_ALL, "");

	printf("\n������� ������� ���������: ");
	bace = myBaceInput();
	endBuc = strtBuc + (bace - 11);
	endNum = strtNum - 1 + (bace <= 9 ? bace : 10);
	
	printf("������� ������� ������� ���������: ");
	newBace = myBaceInput();

	do {
		lnOld = myCharArrayInput(strOld, strtBuc, endBuc, strtNum, endNum);
	} while (!lnOld);

	for (int i = 0; i < lnOld; i++)
		if (strtBuc <= strOld[i] && strOld[i] <= endBuc)
			sumOld += (strOld[i] - (strtBuc - 10)) * myPow(bace, lnOld - i - 1);
		else
			sumOld += (strOld[i] - strtNum) * myPow(bace, lnOld - i - 1);

	if (sumOld < 0) {
		printf("\n�� �������� �������� ������� ��������� ������� ����� �� �� ����������� ���������.");
		return 0;
	}

	for (lnNew = 0; sumOld > 0; lnNew++)
	{
		if (lnNew >= N) {
			printf("\n��������� ���� ����� ������� �������. �� �������� �������� ������� ��������� ������� ����� �� �� ����������� �������.");
			return 0;
		}
		strNew[lnNew] = sumOld % newBace;
		sumOld /= newBace;
	}
	
	printf("\n");
	for (int i = lnNew - 1; i >= 0; i--)
		printf("%i", strNew[i]);
}