#include <stdio.h>
#include <math.h>
#define PI 3.141592653589

double ab, bc, ca, ae, dc, bf, bac, bca, ad, fc, ao, oe, aeb, aeo, fca, dac, be, af;
double val = 180 / PI;

int main() {

    do{
        scanf("%lf%lf%lf", &ab, &bc, &ca);
    }while(ab <= 0 || bc <= 0 || ca <= 0 || ab > 1000 || bc > 1000 || ca > 1000);
    do{
        scanf("%lf%lf%lf", &ae, &dc, &bf);
    }while(ae <= 0 || dc <= 0 || bf <= 0 || ae >= ab || dc >= bc || bf >= ab);
    af = ab - bf;
    bac = 1.0 * (pow(ab, 2) + pow(ca, 2) - pow(bc, 2)) / (2.0 * ab * ca);
    be = 1.0 * sqrt(pow(ab, 2) + pow(ae, 2) - 2 * ab * ae * bac);
    aeb = 1.0 * (pow(ae, 2) + pow(be, 2) - pow(ab, 2)) / (2.0 * ae * be);
    bca = 1.0 * (pow(ca, 2) + pow(bc, 2) - pow(ab, 2)) / (2.0 * ca * bc);
    ad = 1.0 * sqrt(pow(ca, 2) + pow(dc, 2) - 2 * ca * dc * bca);
    dac = 1.0 * (pow(ad, 2) + pow(ca, 2) - pow(dc, 2)) / (2.0 * ad * ca);
    fc = 1.0 * sqrt(pow(af, 2) + pow(ca, 2) - 2 * af * ca * bac);
    fca = 1.0 * (pow(fc, 2) + pow(ca, 2) - pow(af, 2)) / (2.0 * fc * ca);
    ao = 1.0 * sin(acos(fca)) * (ca / sin(PI - acos(dac) - acos(fca)));
    oe = 1.0 * sqrt(pow(ae, 2) + pow(ao, 2) - 2.0 * ae * ao * dac);
    aeo = 1.0 * (pow(ae, 2) + pow(oe, 2) - pow(ao, 2)) / (2.0 * ae * oe);
    if(fabs(aeb - aeo) <= 0.1) {
        printf("YES");
    }
    else {
        printf("NO");
    }
    return 0;
}