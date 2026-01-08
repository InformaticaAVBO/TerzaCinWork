# Istruzioni per agenti AI (Copilot / coding agents)

> Scopo: rendere un agente AI immediatamente produttivo su questo repository C++ minimale.

- **Panoramica progetto:** repository contiene un piccolo programma C++ "Battleship" in `Battleship/main.cpp`. È un progetto single-file senza dipendenze esterne, pensato per esercizi didattici.

- **File chiave:**
  - `Battleship/main.cpp` — punto di ingresso e logica principale.
  - `.vscode/tasks.json` — task di build (usa `/usr/bin/g++`).
  - `README.md` — descrizione minima del repository.

- **Build & run (verifiche rapide):**
  - Compilare localmente con il task di VS Code o direttamente in terminale:

    ```bash
    g++ -g Battleship/main.cpp -o Battleship/main
    ./Battleship/main
    ```

  - Il task di VS Code è etichettato "C/C++: g++ compila il file attivo" e utilizza
    `-g` e l'output in `${fileDirname}/${fileBasenameNoExtension}`. Usare questo task per messaggi di errore più chiari.

- **Architettura e pattern osservabili:**
  - Programma single-file con macro globali (es. `#define DIM 10`) e matrici C-style: `char m[DIM][DIM]`.
  - Uso di `using namespace std;` e funzioni free-standing (es. `void stampa(...)`).
  - Non ci sono librerie esterne, test, né CMake/Makefile.

- **Linee guida pratiche per modifiche:**
  - Sii conservativo: applica patch minime e compilabili; verifica la compilazione locale dopo ogni change.
  - Evita di introdurre nuove dipendenze o sistemi di build complessi (CMake, vcpkg) a meno che non sia esplicitamente richiesto.
  - Se modifichi una funzione (firma o comportamento), aggiorna tutte le chiamate nello stesso file.
  - Per refactor visibili in più file, crea una branch feature da `develop` e apri PR verso `main`.

- **Errori e anti-pattern già presenti (esempi utili):**
  - Ciclo annidato con errore di indice: `for (int j=0; i<DIM; j++)` dovrebbe essere `for (int j=0; j<DIM; j++)`.
  - Funzioni dichiarate/incomplete: alcune dichiarazioni (es. `void stampa`) possono mancare del corpo o della firma completa — completare o rimuovere prima della compilazione.

- **Quando e come modificare:**
  - Piccole correzioni di bug o completamento di funzioni → applica direttamente su branch feature, compila e invia PR.
  - Aggiunte significative (nuove cartelle, test, toolchain) → discutere prima con il maintainers/utente.

- **Verifiche consigliate dopo cambiamento:**
  - `g++ -g Battleship/main.cpp -o Battleship/main` → compilazione pulita.
  - Eseguire `./Battleship/main` e controllare output/print.

- **Dove cercare ispirazione nel repo:**
  - Aprire `Battleship/main.cpp` per esempi di stile e vincoli: macro globali, array statici, funzioni free.
  - Guardare `.vscode/tasks.json` per il modo consigliato di compilare.

Se qualcosa non è chiaro (es. intent logico di una funzione incompleta), chiedi istruzioni all'utente prima di modificare comportamento business-critical.

---
Chiedimi se vuoi che adatti le istruzioni (es. aggiungere policy di commit, template PR, o test minimalisti).
