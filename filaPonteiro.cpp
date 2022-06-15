#include <iostream>
using namespace std;

struct No {
	float dado;
	No *prox;
};

struct Fila {
	No *ini;
	No *fim; 
};

Fila* init() {
	Fila *f = new Fila;
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

int isEmpty(Fila *f) {
	return (f->ini == NULL);
}

int count(Fila *f) {
	int qtde = 0;
	No *no;
	no = f->ini;
	while (no != NULL) {
		qtde++;
		no = no->prox;
	}
	return qtde;
}

void print(Fila *f) {
	No *no;
	no = f->ini;
	cout << "-------------" << endl;
	while (no != NULL) {
		cout << no->dado << endl;
		no = no->prox;
	}
	cout << "-------------" << endl;
}

void enqueue(Fila *f, float v) {
	No *no = new No;
	no->dado = v;
	no->prox = NULL;
	if (isEmpty(f)) {
		f->ini = no;
	}
	else {
		f->fim->prox = no;
	}
	f->fim = no;
}

float dequeue(Fila *f) {
	float ret;
	if (isEmpty(f)) {
		ret = -1;
	}
	else {
		No *no = f->ini;
		ret = no->dado;
		f->ini = no->prox;
		if (f->ini == NULL) {
			f->fim = NULL;
		}
		free(no);
	}
	return ret;
}

void freeFila(Fila *f) {
	No *no = f->ini;
	while (no != NULL) {
		No *temp = no->prox;
		free(no);
		no = temp;
	}
	free(f);
}

int main(int argc, char** argv)
{
	Fila *filaFloat;
	filaFloat = init();
	cout << "Fila vazia: " << (isEmpty(filaFloat)?"SIM":"NAO") << endl;
	cout << "Qtde de elementos: " << count(filaFloat) << endl;
	enqueue(filaFloat, 1.1);
	enqueue(filaFloat, 2.2);
	enqueue(filaFloat, 3.3);
	enqueue(filaFloat, 4.4);
	cout << "Fila vazia: " << (isEmpty(filaFloat)?"SIM":"NAO") << endl;
	cout << "Qtde de elementos: " << count(filaFloat) << endl;
	print(filaFloat);
	cout << "Desenfileirou: " << dequeue(filaFloat) << endl;
	cout << "Desenfileirou: " << dequeue(filaFloat) << endl;
	enqueue(filaFloat, 5.5);
	print(filaFloat);
	cout << "Desenfileirou: " << dequeue(filaFloat) << endl;
	enqueue(filaFloat, 6.6);
	cout << "Desenfileirou: " << dequeue(filaFloat) << endl;
	print(filaFloat);
	freeFila(filaFloat);		
	return 0;
}