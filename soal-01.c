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
typedef struct stack {
	int data;
	struct stack *next;
} stack;
 
// deklarasi variabel awal
int pop(stack **x);
void push(stack **x, int data);
void printStack(stack *x);
void debuggerPrint(stack *input, stack *output);
int coprime(int x, int y);
int lcm(int x, int y);
int gcd(int x, int y);

// fungsi utama
int main(){ 
	// deklarasi stack input dan output
	stack *input = NULL; 
	stack *output = NULL;  
	
	int userinput = 0; 
	int counter = 0; 
	int isFirstIteration = 0;

	// variabel temporary untuk menyimpan data yang dipop dari struct
	int pop_out;
	int pop_inp;
	int pop_out_1;
	int pop_out_2;

	// while loop untuk mengambil input angka dari user
	// loop berhenti bila user memberi input 0
	while (1){ 
		counter++;
		printf("Input angka ke-%d: ", counter);
		scanf("%d", &userinput);
		
		if (userinput == 0){
			printf("\n");
			break;
		} 
		else{
			push(&input, userinput);
		} 
	}
	
	// menampilkan stack input sebelum dikosongkan pada proses komputasi  
	printf("Stack input: ");
	printStack(input); 

	// while loop untuk melakukan komparasi elemen stack input 
	// loop berhenti bila stack input sudah kosong
	while(input!=NULL){ 
		// iterasi pertama, pop dua elemen input untuk ditinjau
		if (isFirstIteration == 0){ 
			pop_out = pop(&input);
			pop_inp = pop(&input); 
			
			// kondisi dimana kedua bilangan koprima. Kedua bilangan tersebut masuk ke stack output
			if (coprime(pop_inp,pop_out) == 1){ 
				push(&output, pop_out);
				push(&output, pop_inp);
			}

			
			// kondisi dimana kedua bilangan tidak koprima. KPK dari kedua bilangan tersebut dimasukkan ke stack output
			else{  
				int lcmOut = lcm(pop_out,pop_inp);  
				push(&output, lcmOut);  
			} 
			isFirstIteration = 1; 
		}

		// iterasi kedua dan seterusnya, pop 1 elemen stack input dan 1 elemen stack output untuk ditinjau
		else{  
			pop_out = pop(&output);
			pop_inp = pop(&input);  
			
			// bila 2 bilangan tsb koprima, kedua bilangan tersebut masuk ke stack output
			if (coprime(pop_inp,pop_out) == 1){ 
				push(&output, pop_out);
				push(&output, pop_inp); 
			}

			// kondisi dimana kedua bilangan tidak koprima
			else{  
				// push KPK kedua bilangan ke stack output
				push(&output, lcm(pop_out,pop_inp)); 

				// while loop untuk meninjau apakah KPK yang dipush memiliki koprima dengan elemen sebelumnya pada stack output 
				while(output->next != NULL){   
					pop_out_1 = pop(&output);
					pop_out_2 = pop(&output); 
					
					if (coprime(pop_out_1,pop_out_2) == 1){ 
						push(&output, pop_out_2);
						push(&output, pop_out_1);
						break;
					}
					else{
						push(&output, lcm(pop_out_1, pop_out_2));
					}
				}
			}

		} 
	}
	
	// print hasil algoritma
	printf("Stack output: ");
	printStack(output);
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

// fungsi push elemen ke stack
void push(stack **x, int data) {
	stack *temp = (stack*)malloc(sizeof(stack));
	temp->data = data;
	temp->next = *x;
	*x = temp;
}

// fungsi untuk pop elemen terakhir dari stack 
int pop(stack **x) {
	if (*x == NULL)
		return 0;
	stack *temp = *x;
	int ret = temp->data;
	*x = (*x)->next;
	free(temp);
	return ret;
}

// fungsi untuk print elemen stack
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

// fungsi bantuan untuk keperluan debugging (print stack input dan output)
void debuggerPrint(stack *input, stack *output){
	printf("INPUT: ");
	printStack(input);
	printf("OUTPUT: ");
	printStack(output);
}
