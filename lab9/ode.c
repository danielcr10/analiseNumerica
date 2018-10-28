#include <stdio.h>
#include <math.h>
#define MIN(a,b) a<b?a:b 

double Euler (double t0, double t1, double h, double y0, double (*f) (double t, double y)){

  double y1 = y0, t;
  
  for (t = t0; t < t1; t += h) {
    if (t + h > t1)
      h /= 3.0;
    
    y1 += h * f(t, y1);
  }
  
  return y1;
}


double EulerAdapt (double t0, double t1, double h0, double y0, double (*f) (double t, double y), double tol){
  
  double y1,ym,y2,e,fator;

  while(t0<t1)
  {
    y1 = y0 + h0 * f(t0, y0);
    ym = y0 + (h0/2) * f(t0, y0);
    y2 = ym + (h0/2) * f(t0 + (h0/2), ym);
    e = fabs(y1 - y2);
    fator = pow((tol/e), 0.5);
    if(fator < 1)
    {
      h0 = MIN(h0 * fator * 0.9, t1-t0);
    }
    else
    {
      y0 = y2 + (y2 - y1);
      t0 = t0 + h0;
      if(fator > 1.2)
      {
        fator = 1.2;
      }
      h0 = MIN(h0 * fator, t1 - t0);
    }
  }

  return y2 + (y2 - y1);
}