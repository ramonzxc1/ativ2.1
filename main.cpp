#include <iostream>

using namespace std;

class ListaSequencial
{
private:
    int *lista;
    int tamanho;
    int capacidade;
public:
    ListaSequencial();
    ListaSequencial(int capacidade);
    ~ListaSequencial();
};
/**
 * Default constructor that initializes variables with NULL and 0
*/
ListaSequencial::ListaSequencial()
{
    this->lista = NULL;
    this->tamanho = 0;
    this->capacidade = 0;
}
// 
ListaSequencial::ListaSequencial(int capacidade)
{
    this->lista = new int[capacidade];
    this->tamanho = tamanho;
    this->capacidade = capacidade;
}
ListaSequencial::~ListaSequencial()
{
    delete[] this->lista;
}



int main()
{
    return 0;
}