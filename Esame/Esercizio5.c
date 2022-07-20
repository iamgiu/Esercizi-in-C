//Versione esame
int textStats(char *filename) {
  char s[], c;
  int cont = 0, min_len = 20, min_cont = 0, max_len = 0, max_cont = 0, len = 0, m_cont = 0, v_cont = 0, media;
  float vocali;

  if ((fp = fopen(filename, "r")) != NULL) {
    printf("Error opening file");
    return -1;
  }

  while(!feof(fp)) {
    fscanf(fp, "%s", s);
    printf("%s", s);
    cont++;

    len = strlen(s);

    if(len > max_len) {
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
