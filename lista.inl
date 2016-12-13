#include "lista.h"
#include <iostream>

template <class T>
No<T>::No(T v){
	this->v = v;
	this->prox = NULL;
}


template<class T>
Lista<T>::Lista(){
	cabeca = NULL;
	cauda = NULL;
}

template<class T>
Lista<T>::Lista(T v){
	cabeca = new No<T>(v);
	cauda = cabeca;
}

template<class T>
void Lista<T>::mostrar(){
		std::cout << "\nImprimindo todos os elementos...\n";
		No<T>* c = cabeca;
		if(vazia())
			std::cout << "A lista NAO possui elementos!!\n";
		else{
			while(c){
				std::cout << c->obterValor() << std::endl;
				c = c->obterProx();
			}
			std::cout << std::endl;
		}
}

template<class T>
bool Lista<T>::vazia(){
	return (cabeca == NULL);
}

template<class T>
void Lista<T>::inserir_inicio(T v){
	No<T>* novo_no = new No<T>(v);
	novo_no->setProx(cabeca);
	cabeca = novo_no;
}
template<class T>
void Lista<T>::inserir_final(T v){
		No<T>* novo_no = new No<T>(v);
		if(vazia()){
			cabeca = novo_no;
			cauda = novo_no;
		}else{
			cauda->setProx(novo_no);
			cauda = novo_no;
		}
}

template<class T>
int Lista<T>::busca(T v){
		No<T>* c = cabeca;
		int i = 0;
		while(c){
			if(c->obterValor() == v)
				return i;
			c = c->obterProx();
			i++;
		}
		return -1;
}

template<class T>
int Lista<T>::tamanho(){
		if(vazia()) // se for vazia, entã retorna 0
			return 0;

		No<T>* c = cabeca;
		int tam = 0;
		
		// percorre a lista
		do{
			c = c->obterProx();
			tam++;
		}
		while(c);
		
		return tam;
}
template<class T>
void Lista<T>::remover_fim(){
	if(!vazia()){
				No<T>* ant_ant = cabeca;
				No<T>* ant = cabeca->obterProx();
				No<T>* corrente = cabeca->obterProx()->obterProx();
				while(corrente){
					No<T>* aux = ant;
					ant = corrente;
					ant_ant = aux;
					corrente = corrente->obterProx();
				}
				delete ant_ant->obterProx(); // libera memória
				ant_ant->setProx(NULL); // seta o prox como NULL
				cauda = ant_ant; // atualiza a cauda
			
		}
}

template<class T>
void Lista<T>::remover_inicio(){
		if(!vazia()){
			No<T>* aux = cabeca;
			cabeca = cabeca->obterProx();
			delete aux;
		}
}



