//Versione esame
int textStats(char *filename) { //ho letto male il testo
  char s[], c;
  int cont = 0, min_len = 20, min_cont = 0, max_len = 0, max_cont = 0, len = 0, m_cont = 0, v_cont = 0, media; //variabile percentuale -> float
  float vocali;

  if ((fp = fopen(filename, "r")) != NULL) { //controllo file
    printf("Error opening file");
    return -1;
  }

  while(!feof(fp)) { //ciclo fino alla fine del file
    fscanf(fp, "%s", s);
    printf("%s", s);
    cont++;

    len = strlen(s);

    if(len > max_len) { //avendo letto male il testo pensavo bisognasse solamente printare le occorrenze della lunghezza più piccola e le occorrenze della lunghezza più grande, in ogni caso la mia condizione è sbagliata perchè dovrebbe essere maggiore e uguale oppure minore e uguale
      max_len = len;
      max_cont++;
    }

    if (len < min_len) {
      min_len = len;
      min_cont++;
    }

    c = fgetc(fp); //volevo prendere il singolo carattere per analizzarlo

    if (isupper(c)) {
      m_cont++;
    }

    if (c == "AEIOUaeiou") {//confunsione con python -> confrontare le vocali e incrementavo il contatore
      v_cont++;
    }
  }

  //printf
  printf("%d string/s with lenght %d\n", min_cont, min_len);
  printf("%d string/s with lenght %d\n", max_cont, max_len);

  media = (m_cont * 100) / cont;
  printf("%d with all capital letters\n", media);

  vocali = v_cont / cont;
  printf("Average number of vowels: %d\n", vocali);

  fclose(fp);

  return cont;
}

//Versione corretta
int textStats(char *filename) {
  char s[20+1], c, vowels[10+1] = "aeiouAEIOU" ; //stringa e vettore per confrontare le vocali
  int m_cont = 0, len = 0, v_cont = 0, v[20]; //contatori + vettore per le occorenze
  float vocali = 0, percentuale, cont = 0, maiuscole = 0; //contatori e variabili per il printf
  FILE *fp; //file

  if ((fp = fopen(filename, "r")) == NULL) {
    printf("Error opening file");
    return -1;
  }

  for(int i = 0; i < 20; i++) { //inizializzo il mio vettore a 0
      v[i] = 0;
  }

  while(!feof(fp)) { //ciclo fino alla fine del file
    fscanf(fp, "%s", s); //prendo le stringhe dal file
    printf("%s ", s);

    len = strlen(s); //lunghezza di una stringa

    v[len-1]++; //lunghezza della stringa = posizione vettore -> incremento

    for (int i = 0; i < len; i++) { //ciclo per avere i singoli caratteri
      c = s[i];

      if (isupper(c)) { //controllo se la mia stringa è scritta in maiuscolo
        m_cont++; //se si, incrementa il contatore
        maiuscole = 1; //variabile booleana
      }

      for(int j = 0; j < strlen(vowels); j++) { //controllo le vocali nel vettore
        if(s[i] == vowels[j]) {
          v_cont++; //aumento il mio contatore
        }
      }
    }
    if (m_cont != len) { //se il mio contatore per le maiuscole non è uguale a len allora il mio contatore torna a 0 e anche la mia variabile booleana
      m_cont = 0;
      maiuscole = 0;
    }
    cont++; //contatore per il numero di parole
  }

  //printf
  printf("\n");
  for (int i = 0; i < 20; i++) {
    if (v[i] != 0)
     printf("%d string/s with lenght %d\n", v[i], (i+1));
  }

  percentuale = (maiuscole * 100) / cont;
  printf("%.2f% with all capital letters\n", percentuale);

  vocali = (v_cont / cont);
  printf("Average number of vowels: %.2f\n", vocali);

  fclose(fp); //chiudo il file

  return cont; //returno la mia variabile cont
}
