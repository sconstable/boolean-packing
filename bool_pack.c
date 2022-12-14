#include <stdio.h>

int prime_slots [] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251};

void set_bin(int* data, int slot, int state) {
	if (state) {
		*data = *data | (1<<slot);
	} else {
		*data = *data & (~ (1<<slot));
	}
}

int get_bin(int data, int slot) {
	return (data & (1<<slot)) > 0;
}

void set_prime(int* data, int slot, int state) {
	if (state) {
		*data = *data * prime_slots[slot];
	} else {
		*data = *data / prime_slots[slot];
		if (*data < 1) { *data = 1; }
	}
}

int get_prime(int data, int slot) {
	return (data % prime_slots[slot]) == 0;
}	


int main() {
	int bin_data = 0;
	set_bin(&bin_data,  3, 1);
	set_bin(&bin_data, 10, 1);
	set_bin(&bin_data, 22, 1);
	set_bin(&bin_data,  3, 0);

	printf("binary data\n");
	for (int i = 0; i < 32; i++) {
		printf("slot %d - %d\n", i, get_bin(bin_data, i));
	}
	printf("binary state: %d\n", bin_data);

	int prime_data = 1;
	set_prime(&prime_data,  3, 1);
	set_prime(&prime_data, 10, 1);
	set_prime(&prime_data, 22, 1);
	set_prime(&prime_data, 35, 1);
	set_prime(&prime_data,  3, 0);

	printf("prime data\n");
	for (int i = 0; i < 54; i++) {
		printf("slot %d - %d\n", i, get_prime(prime_data, i));
	}
	printf("prime state: %d\n", prime_data);
}
