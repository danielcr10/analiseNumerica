void QR (int m, int n, double** A, double** Q, double** R)
{
  double* v = vetcria(n);
  double* w = vetcria(n);
  double** QT = (n, m);
 
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
      multmv();
      R[i][j] = QT[i] * w; //
      w = w - R[i][j] * Q[i];
    }
    R[j][j] = norma(n, w);
    Q[j] = w/r[j][j];
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
