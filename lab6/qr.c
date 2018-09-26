void QR (int m, int n, double** A, double** Q, double** R)
{
  //TODO: Inicializar vetor v e matriz QT
  //Pegar os v. v[0] = primeira coluna de a, v[1] = segunda coluna de A...
 
  for(int j = 0; j < n; j++)
  {
  
    for(int i = 0; i < m; i++)//preenche o vetor v e w = v
    {
      v[i] = A[i][j]; //todos elementos da primeira coluna
      w[i] = v[i];
    }
    
    for(int i = 0; i < j; i++)
    {
    transposta(m, n, Q, QT);
      R[i][j] = QT[i] * w; //i = j-1
      w = w - r[i][j] * Q[i]; //
    }
    r[j][j] = norma(); //
    q[j] = w/r[j][j];
  }
}

double mmqQR (int m, int n, double** A, double* b, double* x)//retornar 0
{
  QR(m, n, A, Q, R);
  R*x = QT * b; // tem que rolar um for aqui
}

double norma (int m, double* v)
{
  double resul = 0;
  for(int i = 0; i < m; i++)
  {
    resul += pow(v[i]);
  }
  resul = sqrt(resul);
  return resul;
}
