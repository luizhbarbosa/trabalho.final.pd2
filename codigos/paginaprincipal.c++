#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int NUM_SALAS = 7;
const int CAPACIDADE_SALAS[NUM_SALAS] = {70, 30, 20, 70, 20, 20, 30};
const int NUM_HORARIOS = 4;
const string HORARIOS[NUM_HORARIOS] = {"08-10", "10-12", "14-16", "16-18"};

int main() {
    // Inicializa as salas com valores iniciais de -1, que significa vazia
    vector<vector<int>> salas(NUM_SALAS, vector<int>(NUM_HORARIOS, -1));

    // Pede o dia da semana que deseja alocar
    int dia;
    do {
        cout << "Digite o dia da semana que deseja alocar (1-5): ";
        cin >> dia;
    } while (dia < 1 || dia > 5);

    // Loop para alocar as turmas até a capacidade semanal máxima
    int turmas_alocadas = 0;
    bool alocarOutroDia = true;
    while (alocarOutroDia && turmas_alocadas < 140) {
        // Pede a quantidade de turmas a alocar
        int num_turmas;
        cout << "Quantas turmas deseja alocar? ";
        cin >> num_turmas;

        // Loop para alocar cada turma
        for (int i = 0; i < num_turmas && turmas_alocadas < 140; i++) {
            // Pede as informações da turma
            string nome_turma;
            int tamanho_turma, horario;
            cout << "Informe o nome da turma: ";
            cin >> nome_turma;
            cout << "Informe o tamanho da turma: ";
            cin >> tamanho_turma;
            cout << "Informe o horário (0-3): ";
            cin >> horario;

            // Verifica se a turma cabe em alguma sala disponível no horário desejado
            bool alocado = false;
            for (int s = 0; s < NUM_SALAS; s++) {
                if (CAPACIDADE_SALAS[s] >= tamanho_turma && salas[s][horario] == -1) {
                    salas[s][horario] = i;
                    cout << "Turma " << nome_turma << " alocada na sala " << s+1 << " no horário " << HORARIOS[horario] << endl;
                    alocado = true;
                    turmas_alocadas++;
                    break;
                }
            }
            if (!alocado) {
                cout << "Não foi possível alocar a turma " << nome_turma << endl;
            }
        }

        // Pergunta se deseja alocar mais turmas
        char resposta;
        cout << "Deseja alocar mais turmas? (s/n) ";
        cin >> resposta;
        alocarOutroDia = (resposta == 's' || resposta == 'S');
    }

    return 0;
}