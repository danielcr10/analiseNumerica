#define pi 3.14159265359 
typedef double ** Matriz;
static double calculaF (int i, int j, double * xi, double (*f) (double));
static Matriz mat_cria (int m, int n);

void chebyshev (int n, double a, double b, double* xi);

void newtonCoef (int n, double* xi, double (*f) (double), double* bi);

double newtonAval (int n, double* xi, double* bi, double x);
