void chebyshev (int n, double a, double b, double* xi);

void newtonCoef (int n, double* xi, double (*f) (double), double* bi);

double newtonAval (int n, double* xi, double* bi, double x);
