#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  
  string input = "";
  string filename = "";
  string file_contents = "";

  cout << "Bem Vindo ao Editor de Texto!" << endl;
  cout << "Digite 'help' para ver a lista de comandos." << endl;

  while (input != "quit") {
    cout << "> ";
    getline(cin, input); // Leitura do que o usuario digitar

    if (input == "help") {
      cout << "Comandos: " << endl;
      cout << "  new - cria um arquivo" << endl;
      cout << "  open <nome do arquivo> - abrindo um arquivo existente" << endl;
      cout << "  save - salva as mudanças no arquivo" << endl;
      cout << "  save <nome do arquivo> - salva mudanças em arquivos novos" << endl;
      cout << "  quit - sai do editor de texto" << endl;
    } else if (input == "new") {
      filename = "";
      file_contents = "";
      cout << "Novo arquivo criado." << endl;
    } else if (input.substr(0, 4) == "open") {
      filename = input.substr(5);
      ifstream file(filename);

      if (file.is_open()) {

        getline(file, file_contents, '\0');
        file.close();
        cout << "Arquivo " << filename << " aberto." << endl;
      } else {
        cout << "Nao e possivel abrir o arquivo " << filename << "." << endl;
      }
    } else if (input == "save") {
      if (filename == "") {
        cout << "Error: Nem um arquivo especificado. Use 'save <nome do arquivo>' para salvar um novo arquivo." << endl;
      } else {
        ofstream file(filename);
        file << file_contents;
        file.close();
        cout << "Alteracoes feitas " << filename << "." << endl;
      }
    } else if (input.substr(0, 4) == "save") {
      filename = input.substr(5);
      ofstream file(filename);
      file << file_contents;
      file.close();
      cout << "Alteraçoes feitas ao novo arquivo " << filename << "." << endl;
    } else if (filename != "") {
      file_contents += input + "\n";
    } else {
      cout << "Error: Comando invalido. Digite 'help' para ver a lista de comandos." << endl;
    }
  }

  return 0;
}