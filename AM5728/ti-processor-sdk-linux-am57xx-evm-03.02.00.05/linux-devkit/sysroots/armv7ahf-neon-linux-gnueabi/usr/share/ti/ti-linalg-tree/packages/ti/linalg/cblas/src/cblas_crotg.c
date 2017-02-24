

#include "cblas.h"
#include "cblas_f77.h"
void cblas_crotg(  void *a, void *b, float *c, void *s)
{
   F77_crotg(a,b,c,s);
}
