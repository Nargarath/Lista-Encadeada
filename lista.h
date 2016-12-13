#ifndef _LISTA_H_
#define _LISTA_H_

// classe No
template<class T>
class No{
private:
	T v;
	No* prox;
public:
	No(T v);

	T obterValor(){
		return v;
	}

	No* obterProx(){
		return prox;
	}

	void setProx(No* p);
};

// classe Lista
template<class T>
class Lista
{
private:
	No<T> *cabeca; // primeiro elemento
	No<T> *cauda; // último elemento

public:
	Lista();

	Lista(T v);

	virtual ~Lista(){
		delete cabeca;

	}

	void mostrar();

	bool vazia();

	// insere no início (semelhante a push_front da list)
	void inserir_inicio(T v);


	// insere no final (semelhante a push_back da list)
	void inserir_final(T v);

	// retorna o tamanho da lista
	int tamanho();

	// verifica se um elemento existe na lista e , se verdadeiro, retorna sua posição. se não, retorna -1;
	int busca(T v);
	T acharNo(int pos);

	// remove da lista, remoção do final
	void remover_fim();
	void remover_inicio();
	
				// se houver só 1 elemento
 //mais de dois elementos
		
	void remover_elemento(int indice);
};

#endif