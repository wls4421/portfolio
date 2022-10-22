 s#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 1000

int main()
{
	//Encrypt--------------------------------------------------------------------------------------------
	//key 값 입력
	int key[64] = { 0, };
	printf("키 값 입력:");
	for (int i = 0; i < 64; i++)
	{
		scanf("%1d", &key[i]);
		if (key[i] >= 2)
		{
			printf("%d번 키 값 %d\n", i, key[i]);
			printf("%d번 키 값이 잘못되었습니다.\n", i);
			abort();
		}
	}

	//key 값에 의한 register 분할
	int regX[19];
	int regY[22];
	int regZ[23];

	for (int i = 0; i < 19; i++)
	{
		regX[i] = key[i];
	}
	for (int i = 0; i < 22; i++)
	{
		regY[i] = key[i + 19];
	}
	for (int i = 0; i < 23; i++)
	{
		regZ[i] = key[i + 41];
	}

	//plaintext 입력
	char plain[MAX_LENGTH] = { 0, };
	printf("\n\n평문 입력: ");
	scanf(" %[^\n]s", plain);

	//plaintext binary변환
	int plainstream[MAX_LENGTH] = { 0 };
	for (int j = 0; j < strlen(plain); j++)
	{
		int temp = plain[j];

		for (int i = 7; i >= 0; i--)
		{
			if (temp % 2 == 1)
			{
				plainstream[j * 8 + i] = 1;
				temp--;
				temp = temp / 2;
			}
			else
			{
				plainstream[j * 8 + i] = 0;
				temp = temp / 2;
			}
			if (temp == 0)
			{
				break;
			}
		}
	}
	printf("\n\n평문의 2진수 표현은 ");
	for (int i = 0; i < strlen(plain) * 8; i++)
	{
		printf("%d", plainstream[i]);
	}
	printf("   이다.\n");
	//keysteam 생성
	int keystream[MAX_LENGTH] = { 0, };
	int Lengthcount = 0;
	int maj;
	for (int i = 0; i < strlen(plain) * 8; i++)
	{
		if (regX[8] + regY[10] + regZ[10] > 1)
		{
			maj = 1;
		}
		else
		{
			maj = 0;
		}
		int tempX, tempY, tempZ;
		tempX = regX[13] ^ regX[16] ^ regX[17] ^ regX[18];
		tempY = regY[20] ^ regY[21];
		tempZ = regZ[7] ^ regZ[20] ^ regZ[21] ^ regZ[22];
		if (regX[8] == maj)
		{
			for (int j = 17; j >= 0; j--)
			{
				regX[j + 1] = regX[j];
			}
			regX[0] = tempX;
		}
		if (regY[10] == maj)
		{
			for (int k = 20; k >= 0; k--)
			{
				regY[k + 1] = regY[k];
			}
			regY[0] = tempY;
		}
		if (regZ[10] == maj)
		{
			for (int l = 21; l >= 0; l--)
			{
				regZ[l + 1] = regZ[l];
			}
			regZ[0] = tempZ;
		}
		keystream[i] = regX[18] ^ regY[21] ^ regZ[22];
	}

	printf("\nkeystream : ");
	for (int i = 0; i < strlen(plain) * 8; i++)
	{
		printf("%d", keystream[i]);
	}
	printf("\n");

	//cipherstream 생성
	int cipherstream[MAX_LENGTH] = { 0, };
	for (int i = 0; i < strlen(plain) * 8; i++)
	{
		cipherstream[i] = keystream[i] ^ plainstream[i];
	}

	printf("\n\ncipher의 binary는 ");
	for (int i = 0; i < strlen(plain) * 8; i++)
	{
		printf("%d", cipherstream[i]);
	}
	printf("   이다.\n");

	//ciphertext로 변환
	char cipher[MAX_LENGTH] = { 0, };
	int tempC;
	for (int i = 0; i < strlen(plain); i++)
	{
		tempC = cipherstream[i * 8] * 128 + cipherstream[i * 8 + 1] * 64 + cipherstream[i * 8 + 2] * 32 + cipherstream[i * 8 + 3] * 16
			+ cipherstream[i * 8 + 4] * 8 + cipherstream[i * 8 + 5] * 4 + cipherstream[i * 8 + 6] * 2 + cipherstream[i * 8 + 7];
		cipher[i] = tempC;
		printf("\n암호문의 %d번째 ASCII 코드 값 = %d\n", i, tempC);
	}

	//ciphertext 출력
	printf("\n암호문은 ");
	for (int i = 0; i < strlen(plain); i++)
	{
		printf("%c", cipher[i]);
	}
	printf("   이다.\n\n\n");


	//Decrypt--------------------------------------------------------------------------------------

	printf("이전에 사용한 키 값은 : ");
	for (int i = 0; i < 64; i++)
	{
		printf("%d", key[i]);
	}
	printf("   이다.\n\n");
	printf("키 값 입력:");
	for (int i = 0; i < 64; i++)
	{
		scanf("%1d", &key[i]);
		if (key[i] >= 2)
		{
			printf("%d번 키 값 %d\n", i, key[i]);
			printf("%d번 키 값이 잘못되었습니다.\n", i);
			abort();
		}
	}

	//key 값에 의한 register 분할


	for (int i = 0; i < 19; i++)
	{
		regX[i] = key[i];
	}
	for (int i = 0; i < 22; i++)
	{
		regY[i] = key[i + 19];
	}
	for (int i = 0; i < 23; i++)
	{
		regZ[i] = key[i + 41];
	}

	//keysteam 재생성
	Lengthcount = 0;
	for (int i = 0; i < strlen(cipher) * 8; i++)
	{
		if (regX[8] + regY[10] + regZ[10] > 1)
		{
			maj = 1;
		}
		else
		{
			maj = 0;
		}
		int tempX, tempY, tempZ;
		tempX = regX[13] ^ regX[16] ^ regX[17] ^ regX[18];
		tempY = regY[20] ^ regY[21];
		tempZ = regZ[7] ^ regZ[20] ^ regZ[21] ^ regZ[22];
		if (regX[8] == maj)
		{
			for (int j = 17; j >= 0; j--)
			{
				regX[j + 1] = regX[j];
			}
			regX[0] = tempX;
		}
		if (regY[10] == maj)
		{
			for (int k = 20; k >= 0; k--)
			{
				regY[k + 1] = regY[k];
			}
			regY[0] = tempY;
		}
		if (regZ[10] == maj)
		{
			for (int l = 21; l >= 0; l--)
			{
				regZ[l + 1] = regZ[l];
			}
			regZ[0] = tempZ;
		}
		keystream[i] = regX[18] ^ regY[21] ^ regZ[22];
	}

	printf("\nkeystream : ");
	for (int i = 0; i < strlen(plain) * 8; i++) 
	{
		printf("%d", keystream[i]);
	}
	printf("\n");
	//decrypt된 plain 생성
	int decrypt[MAX_LENGTH] = { 0, };
	for (int i = 0; i < strlen(cipher) * 8; i++)
	{
		decrypt[i] = keystream[i] ^ cipherstream[i];
	}

	printf("\n\ndecrypt된 binary는   ");
	for (int i = 0; i < strlen(plain) * 8; i++)
	{
		printf("%d", decrypt[i]);
	}
	printf("   이다.\n\n");

	char result[MAX_LENGTH];
	for (int i = 0; i < strlen(cipher); i++)
	{
		tempC = decrypt[i * 8] * 128 + decrypt[i * 8 + 1] * 64 + decrypt[i * 8 + 2] * 32 + decrypt[i * 8 + 3] * 16
			+ decrypt[i * 8 + 4] * 8 + decrypt[i * 8 + 5] * 4 + decrypt[i * 8 + 6] * 2 + decrypt[i * 8 + 7];
		result[i] = tempC;
		printf("\nDecrypt한 평문의 %d번째 ASCII 코드 값 = %d\n", i, tempC);

	}

	//E+D 결과 출력
	printf("Encrypt + Decrypt된 결과는 ");
	for (int i = 0; i < strlen(cipher); i++)
	{
		printf("%c", result[i]);
	}
	printf("   이다.\n");

	return 0;


}

