#include <iostream>

/**
 * Implementação de fila
 */
class Queue {

    private:

        /**
         * Constante que indica o tamanho da fila
         */
        const static int QUEUE_SIZE = 5;

        /**
         * Aloca a memória para a fila
         */
        int *queue = (int*) calloc(0, sizeof(int) * Queue::QUEUE_SIZE);

        /**
         * Posição de início da fila
         */
        int start = 0;

        /**
         * Posição de final da fila
         */
        int end = 0;

        /**
         * Contador de elementos na fila
         */
        int counter = 0;

    public:

        /**
         * Constante para a exeção de ovverflow da fila
         */
        const static int EXCEPTION_STACK_OVERFLOW = 1;

        /**
         * Constante para a exceção de fila vazia
         */
        const static int EXCEPTION_EMPTY_QUEUE = 2;

        /**
         * Construtor nulo
         */
        Queue() {}

        /**
         * Insere um elemento na fila
         * @param el Elemento a ser inserido no vetor
         * @throws EXCEPTION_STACK_OVERFLOW Excedeu o tamanho da fila
         */
        void insert(int el) {

            if(this->counter == Queue::QUEUE_SIZE)
                throw 1;

            this->counter++;
            *(this->queue + this->end) = el;

            if(this->end == (Queue::QUEUE_SIZE - 1))
                this->end = 0;
            else
                this->end++;

        }

        /**
         * Remove o primeiro elemento da fila
         * @throws EXCEPTION_EMPTY_QUEUE
         */
        void pop() {

            if(this->counter == 0)
                throw 2;

            this->counter--;

            *(this->queue + this->start) = 0;

            if(this->start == (Queue::QUEUE_SIZE - 1))
                this->start = 0;
            else
                this->start++;

        }

        int begin() {
            return *(this->queue + this->start);
        }
}