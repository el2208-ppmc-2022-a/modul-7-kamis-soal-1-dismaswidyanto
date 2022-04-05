/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 7 - Stacks and Queues
*Percobaan        : -
*Hari dan Tanggal : Kamis, 7 April 2022
*Nama (NIM)       : -
*Asisten (NIM)    : -
*Nama File        : soal-01.c
*Deskripsi        : -
*/

#include <stdio.h>
#include <stdlib.h>

// tipe data simulasi stack
...
 
// deklarasi variabel awal 
int pop( ... );
void push( ... , ... );
void printStack(stack *x); //silakan sesuaikan tipe data stack dengan yang anda gunakan
int coprime(int x, int y);
int lcm(int x, int y);
int gcd(int x, int y);

// fungsi utama
int main(){ 
	// deklarasi stack input dan output
	...

	// while loop untuk mengambil input angka dari user
	// loop berhenti bila user memberi input 0
	printf("Input angka ke-%d: ", ...);
	scanf("%d", ...);

	printf("\n");
	 
	// menampilkan stack input sebelum dikosongkan pada proses komputasi
	printf("Stack input: ");

	// algoritma komparasi elemen stack
	...
	...
	
	
	// print hasil algoritma
	printf("Stack output: ");
	
	return 0;
}

// fungsi push elemen ke stack
void push( ..., ... ) {
	// tulis kode anda disini
	... 
}

// fungsi untuk pop elemen terakhir dari stack 
int pop( ... ) {
	// tulis kode anda disini
	... 
}

// fungsi mencari FPB antara bilangan x dan y
int gcd(int x, int y){      
	printf("x,y=%d,%d\n", x, y);
	while(x != y)
	{
		if(x > y)
			x -= y;
		else
			y -= x;
	} 
	
	int ret = x;
	return ret;
} 

// fungsi mencari KPK antara bilangan x dan y
int lcm(int x, int y){ 
	int result = (x*y) / gcd(x, y); 
	return result;
}

// fungsi mencari koprima antara bilangan x dan y
// return 1 bila koprima
// return 0 bila bukan koprima
int coprime(int x, int y){
	if (gcd(x,y) == 1){
		return 1;
	}
	else{
		return 0;
	} 
}

// fungsi untuk print elemen stack
//Silakan sesuaikan bentuk data anda dengan yang anda gunakan
void printStack(stack *x) {
	stack *temp = x; 

	if (temp == NULL){
		printf("[empty]\n");
		return;
	}
	printf("[");
	while (temp->next != NULL){
		printf("%d, ", temp->data);
		temp = temp->next;
	}
	printf("%d]\n", temp->data);
}