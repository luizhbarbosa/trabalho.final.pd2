#include <iostream>
#include <vector>

using namespace std;

const int NUM_SALAS = 7;
const int CAPACIDADE_SALAS[NUM_SALAS] = {10, 15, 50, 60, 80, 50, 10};
const int NUM_TURMAS = 7;
const int TAMANHO_TURMAS[NUM_TURMAS] = {80, 10, 20, 60, 40, 15, 15, 15};
const int NUM_HORARIOS = 10;
const string HORARIOS[NUM_HORARIOS] = {"07-08", "08-09", "09-10", "10-11", "11-12", "13-14", "14-15", "16-17", "17-18"};

bool alocarSala(int turma, int horario, vector<vector<int>>& salas) {
    int tamanho_turma = TAMANHO_TURMAS[turma];
    for (int i = 0; i < NUM_SALAS; i++) {
        if (CAPACIDADE_SALAS[i] >= tamanho_turma && salas[i][horario] == -1) {
            salas[i][horario] = turma;
            return true;
        }
    }
    return false;
}

int main() {
    // Inicializa todas as salas com -1, indicando que estão vazias
    vector<vector<int>> salas(NUM_SALAS, vector<int>(NUM_HORARIOS, -1));

    // Tenta alocar cada turma em um horário
    for (int turma = 0; turma < NUM_TURMAS; turma++) {
        bool alocado = false;
        for (int horario = 0; horario < NUM_HORARIOS; horario++) {
            if (horario != 5) { // exclui horário de 12-13
                alocado = alocarSala(turma, horario, salas);
                if (alocado) {
                    break;
                }
            }
        }
        if (!alocado) {
            cout << "A turma " << turma << " nao foi alocada." << endl;
        }
    }

    // Imprime a alocação das turmas nas salas
    for (int i = 0; i < NUM_SALAS; i++) {
        cout << "Sala " << i+1 << ":" << endl;
        for (int j = 0; j < NUM_HORARIOS; j++) {
            cout << "Horario " << HORARIOS[j] << ": ";
            if (salas[i][j] != -1) {
                cout << "Turma " << salas[i][j] << endl;
            } else {
                cout << "Vazia" << endl;
            }
        }
        cout << endl;
    }

    return 0;
}