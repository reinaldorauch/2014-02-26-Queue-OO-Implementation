#include <iostream>
#include <stdlib.h>

#include "queue.cpp"

using namespace std;

void getFromStdin(Queue *fila) {

    int val;
    char op;

    cout << "Digite um valor:\n";

    cin >> val;

    fila->insert(val);

    cout << "Continuar?\n";

    cin >> op;

    if(op == 's')
        getFromStdin(fila);
    else
        return;

}

int main()
{

    Queue fila;

    system("clear");

    cout << "Teste de fila:\n\nInsira alguns elementos da fila:\n\n";

    try {

        getFromStdin(&fila);

        cout << "\n\n";

        fila.print();

        cout << "\n\nPrimeiro elemento da fila:\n" << fila.begin() << "\n\n";

        cout << "Retirando um elemento da fila...";

        fila.pop();

        cout << "\n\nPrimeiro elemento da fila agora:\n" << fila.begin() << "\n\n";

        cout << "Retirando todos os elementos da fila...\n\n";

        do
            fila.pop();
        while(!fila.isEmpty());

        cout << "Lista vazia? " << (fila.isEmpty() ? "Sim" :  "Não") << "\n\n";

    } catch (int e) {

        cout << "\n\n-------------------- ERRO --------------------\n";

        switch(e) {
            case Queue::EXCEPTION_QUEUE_OVERFLOW:
                cout << "Foi excedida a capacidade da fila";
                break;
            case Queue::EXCEPTION_EMPTY_QUEUE:
                cout << "A lista já está vazia";
                break;
            default:
                cout << "Erro desconhecido";
                break;
        }

        cout << "\n\n";

        exit(0);

    }

    return 0;
}