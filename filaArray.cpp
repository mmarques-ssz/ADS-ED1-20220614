#include <iostream>
using namespace std;

#define MAX 5

struct Fila {
	float nos[MAX+1];
	int ini;
	int fim;
};

Fila* init() {
	Fila *f = new Fila;
	f->ini = 0;
	f->fim = 0;
	return f;
}

int isEmpty(Fila *f) {
	return (f->ini == f->fim);
}

int incrementa(int i) {
	int ret;
	if (i == MAX) {
		ret = 0;
	}
	else {
		ret = i + 1;
	}
	return ret;
}

int count(Fila *f) {
	int qtde = 0;
	int i = f->ini;
	while (i != f->fim) {
		qtde++;
		i = incrementa(i);
	}
	return qtde;
}

void print(Fila *f) {
	int i = f->ini;
	cout << "---------" << endl;
	while (i != f->fim) {
		cout << f->nos[i] << endl;
		i = incrementa(i);
	}
    cout << "---------" << endl;
}

int enqueue(Fila *f, float v) {
	int podeEnfileirar = (incrementa(f->fim) != f->ini);
	if (podeEnfileirar) {
		f->nos[f->fim] = v;
        f->fim = incrementa(f->fim);

	}
	return podeEnfileirar;
}

float dequeue(Fila *f) {
	float ret;
	if (isEmpty(f)) {
		ret = -1;
	}
	else {
		ret = f->nos[f->ini];
		f->ini = incrementa(f->ini);
	}
	return ret;
}

void freeFila(Fila *f) {
	free(f);
}

int main(int argc, char** argv)
{
	Fila *filaFloat;
	filaFloat = init();
	
	cout << "Qtde de elementos: " << count(filaFloat) << endl;
	cout << "Enfileirou: " << enqueue(filaFloat, 1.1) << endl;
	cout << "Enfileirou: " << enqueue(filaFloat, 2.2) << endl;
	cout << "Enfileirou: " << enqueue(filaFloat, 3.3) << endl;
	cout << "Enfileirou: " << enqueue(filaFloat, 4.4) << endl;
	cout << "Enfileirou: " << enqueue(filaFloat, 5.5) << endl;
	cout << "Enfileirou: " << enqueue(filaFloat, 6.6) << endl;
	print(filaFloat);
	cout << "Desenfileirou: " << dequeue(filaFloat) << endl;
	print(filaFloat);
	cout << "Enfileirou: " << enqueue(filaFloat, 6.6) << endl;
	cout << "Qtde de elementos: " << count(filaFloat) << endl;
	print(filaFloat);
	cout << isEmpty(filaFloat);
	cout << "Desenfileirou: " << dequeue(filaFloat) << endl;
	cout << "Desenfileirou: " << dequeue(filaFloat) << endl;
	cout << "Desenfileirou: " << dequeue(filaFloat) << endl;
	cout << "Desenfileirou: " << dequeue(filaFloat) << endl;
	cout << "Desenfileirou: " << dequeue(filaFloat) << endl;
	cout << "Desenfileirou: " << dequeue(filaFloat) << endl;
	cout << "Desenfileirou: " << dequeue(filaFloat) << endl;
    print(filaFloat);
	cout << isEmpty(filaFloat);
	freeFila(f);
	
	return 0;
}