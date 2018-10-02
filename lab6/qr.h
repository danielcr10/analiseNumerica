void QR (int m, int n, double** A, double** Q, double** R);

double mmqQR (int m, int n, double** A, double* b, double* x);
double escalar(int n, double* v, double* w);
double norma (int m, double* v);
double* escalarVetor(int n, double a, double* v);
void substituicao (int n, double** a, double* v, double* x);
