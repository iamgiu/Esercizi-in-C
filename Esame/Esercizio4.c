//Versione esame
char *findSubstring(char s1[], char s2[]) {
  //variabile char per memorizzare la mia sotto_sequenza nel caso ci sia
  char sotto_sequenza[]; //sarebbe più corretto scriverlo in questo modo -> char *sotto_sequenza;
  //variabile int fa da contatore
  int seq = 0;

//tratto le due stringhe come matrice
  for (int i = 0; i < strlen(s1); i++) { //primo ciclo for sulla prima stringa
    for (int j = 0; j < strlen(s2); j++) { //secondo ciclo for sulla seconda stringa
      if (s1[i] == s2[j]) { //correzione: s1[i+j] == s2[j]
        seq++; //aumento il mio contatore se la prima stringa nella posizione i+j è uguale alla seconda nella posizione j
        sotto_sequenza = s2; //va fatto dopo
      }
    }
    if (seq == strlen(s2)) { //se il mio contatore seq è uguale alla lunghezza della seconda stringa
      sotto_sequenza = s2;
      return sotto_sequenza; //ritorna sotto_sequenza
    }
    else {
      seq = 0; //se no il mio contatore torna a 0
    }
  }
  return NULL; //ritorna NULL se la sequenza di caratteri in s2 non è presente in s1
}

//Versione con correzioni
char *findSubstring(char s1[], char s2[]) {
  char *sotto_sequenza;
  int seq = 0;

  for (int i = 0; i < strlen(s1); i++) {
    for (int j = 0; j < strlen(s2); j++) {
      if (s1[i + j] == s2[j]) {
        seq++;
      }
    }
    if (seq == strlen(s2)) {
      return sotto_sequenza;
    }
    else {
      seq = 0;
    }
  }
  return NULL;
}
