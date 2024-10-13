#include <iostream>
using namespace std;

struct info {
    string nome;
    char tipo;
    int valor;
};

class noh {
    friend class pilha;
private:
    noh* mProximo;
    info mInformacoes;

public:
    noh(info dado) {
        mInformacoes = dado;
        mProximo = nullptr;
    }
};

class pilha {
private:
    noh* mTopo;
    int mTamanho;

public:
    pilha() {
        mTopo = nullptr;
        mTamanho = 0;
    }

    ~pilha() {
        limpar();
    }

    void empilhar(info dado) {
        noh* novo = new noh(dado);
        novo->mProximo = mTopo;
        mTopo = novo;
        mTamanho++;
    }

    info desempilha() {
        if (mTamanho == 0) {
            cout << "Erro: pilha vazia!" << endl;
            return {};  // Retorna um objeto info vazio
        }

        info dado = mTopo->mInformacoes;
        noh* temp = mTopo;
        mTopo = mTopo->mProximo;
        delete temp;
        mTamanho--;
        return dado;
    }

    void limpar() {
        while (mTamanho > 0) {
            desempilha();
        }
    }

    void verificarTopo() {
        if (mTamanho == 0) {
            cout << "Pilha vazia!" << endl;
        } else {
            cout << "Nome: " << mTopo->mInformacoes.nome 
                 << " Tipo: " << mTopo->mInformacoes.tipo 
                 << " Valor: " << mTopo->mInformacoes.valor << endl;
        }
    }

    bool pilhaVazia() {
        return (mTamanho == 0);
    }
};

int main() {
    pilha inventario;
    info item;
    char comando;

    cout << "Digite o comando: ";
    cin >> comando;

    while (comando != 'f') {
        switch (comando) {
            case 'i':
                cin >> item.nome >> item.tipo >> item.valor;
                inventario.empilhar(item);
                break;

            case 'r': {
                info removido = inventario.desempilha();
                if (!removido.nome.empty()) {
                    cout << "Nome: " << removido.nome 
                         << " Tipo: " << removido.tipo 
                         << " Valor: " << removido.valor << endl;
                }
                break;
            }

            case 'l':
                inventario.limpar();
                break;

            case 'e':
                inventario.verificarTopo();
                break;

            default:
                cout << "Comando inválido!" << endl;
                break;
        }

        cout << "Digite o comando: ";
        cin >> comando;
    }

    // Desempilhar e exibir todos os itens ao finalizar o programa
  
    while (!inventario.pilhaVazia()) {
        info removido = inventario.desempilha();
        cout << "Nome: " << removido.nome 
             << " Tipo: " << removido.tipo 
             << " Valor: " << removido.valor << endl;
    }

    return 0;
}
