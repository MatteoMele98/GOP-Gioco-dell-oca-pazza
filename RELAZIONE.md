# GOP (Gioco dell'Oca Pazza)

Gioco realizzato in C++ che unisce il classico gioco dell'oca al monopoli.

## Features
- **1-4 giocatori**
- **Caselle**
  - Casella di inizio
  - Casella vuota
  - Compra la casella
  - Pesca una carta
  - Casella trappola
  - Casella finale
- **Carte**
  - Guadagna soldi
  - Perdi soldi
  - Vai avanti di n caselle
  - Vai indietro di n caselle
  - Rispondi a una domanda
  - Scambio con il giocatore in testa
  - Scambio con il giocatore in coda

## Scelte implementative

### Cstring

Abbiamo scelto di implementare il testo dei messaggi con l'uso di array di caratteri. Grazie alla libreria **cstring** possiamo manipolare le stringhe in questione in modo semplice, soprattutto con l'uso della funzione  `sprintf(...)`

### Domande

Le domande di cultura generale sono organizzate in un array di strutture (struct) "Question".
Ogni domanda propone 4 possibili rispote. In base alla correttezza della risposta il giocatore ha diritto a un effetto positivo o negativo.

### Gestione degli effetti

Gli effetti sono memorizzati con un enumerazione (enum). Nello specifico:
- **effetti positivi**
  1. moveForward
  2. addMoney
- **effetti negativi**
  3. moveBackward
  4. loseMoney

Grazie all'enumerazione è possibile selezionare **dinamicamente** un effetto positivo o negativo semplicemente scegliendo rispettivamente un numero tra 0-1 oppure tra 2-3.

### Programmazione ad oggetti

L'uso del paradigma ad oggetti ha reso semplice e modulare lo sviluppo del progetto.

#### Oggetti sviluppati:

##### Card - *Carta*

- Classe base, espone un metodo **executeCard** che consente il polimorfismo, quindi è implementato diversamente a seconda del tipo della carta da eseguire
- Estesa da:
  - CardAddMoney - *Guadagna soldi*
  - CardLoseMoney - *perdi soldi*
  - CardMoveForward - *Vai avanti*
  - CardMoveBackward - *Vai indietro*
  - CardPickQuestion - *Pesca una domanda*
  - CardSwapHead - *Scambia la tua posizione con quella del giocatore in testa*
  - CardSwapTile - *Scambia la tua posizione con quella del giocatore in coda*

#####  Square - *Casella*
- Classe base, espone un metodo **executeSquare** che consente il polimorfismo, quindi è implementato diversamente a seconda del tipo della casella da eseguire
- Estesa da:
  - SquareVoid - *Casella vuota*
  - SquareStart - *Casella iniziale*
  - SquareFinish - *Casella finale*
  - SquareBuy - *Casella compra*
  - SquarePitafall - *Casella trappola*
  - SquarePickCard - *Casella pesca una carta*

##### Player - *Giocatore*
- Implementa il **player** ed è caratterizzato principalmente da:
  - nome
  - somma di denaro posseduta
  - posizione

##### Game - *Gioco*
- E' la classe principale è usa i metodi di tutte le altre classi
- Divide il gioco in 3 momenti fondamentali
  1. **Inizializzazione**
  	- startMessage - *Stampa del messaggio di benvenuto*
  	- printRules - *Stampa delle regole*
  	- initBoard - *Crea il tabellone con un numero di caselle compreso tra 70 e 90*. Il tabellone è implementato con un **array di caselle**
  	- initPlayers - *Inizializzazione dei giocatori*. I giocatori sono implementati con un **array di players**

  2. **Ciclo di gioco**
  	- gameLoop - *Lancio dei dadi. Movimento del giocaore sulla casella corrispondente e **esecuzione della casella** *

  3. **Fine**
  	- printWinner - *Stampa del vincitore*
  	- printLooser - *Messaggio nel caso in cui tutti i giocatori sono in bancarotta*
  	- endMessage - *Messaggio finale*;

## Note Finali
Il progetto è stato pensato, realizzato e documentato per essere reso pubblico e open-source, in modo da fornire un esempio concreto del paradigma ad oggetti in C++, applicato allo sviluppo di un semplice gioco, ai neofiti del linguaggio o della programmazione in generale.

## Membri del team
  - **Matteo Mele**
  - **Leonardo Pio Palumbo**
  - **Vincenzo Armandi**
