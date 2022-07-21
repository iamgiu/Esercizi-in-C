//Versione esame
int textStats(char *filename) {
  char s[], c;
  int cont = 0, min_len = 20, min_cont = 0, max_len = 0, max_cont = 0, len = 0, m_cont = 0, v_cont = 0, media;
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

    c = fgetc(fp);

    if (isupper(c)) {
      m_cont++;
    }

    if (c == "AEIOUaeiou") {
      v_cont++;
    }
  }

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
    char s[20];
    int vocali=0, parole=0 ,parolemaiusc=0, len=0, m[20][2];
    FILE *fp;

    if ((fp = fopen(filename, "r")) != NULL) { //controllo file
      printf("Error opening file");
      return -1;
    }

    for (int i = 0; i < 20; i++) {
      m[i][0]=i;
    }

    while(!feof(fp)) {
      fscanf(fp, "%s", s);
      parole++;

      len = strlen(s);
      m[len][1]++;
      
    }
}
