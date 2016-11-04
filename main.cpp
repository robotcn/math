/*
 * main.cpp
 *
 *  Created on: Nov 4, 2016
 *      Author: qxji
 */


#include "FinancialMath.h"
#include <stdio.h>

int main()

{
    {

        printf("\n\nZero Correlation and Covariance Data Set\n");

        double xarr[] = { 8, 6, 4, 6, 8 };
        double yarr[] = { 10, 12, 14, 16, 18 };

        double cov = FinancialMath::covariance(xarr, yarr, 5);
        double cor = FinancialMath::correlation(xarr, yarr, 5);

        printf("Covariance = %.10lf\n", cov);
        printf("Correlation = %.10lf\n", cor);

    }

    {

        printf("\n\nPositive Correlation and Low Covariance Data Set\n");

        double xarr[] = { 0, 2, 4, 6, 8 };

        double yarr[] = { 6, 13, 15, 16, 20 };

        double cov = FinancialMath::covariance(xarr, yarr, 5);
        double cor = FinancialMath::correlation(xarr, yarr, 5);

        printf("Covariance = %.10lf\n", cov);
        printf("Correlation = %.10lf\n", cor);

    }

    {

        printf("\n\nNegative Correlation and Low Covariance Data Set\n");

        double xarr[] = { 8, 6, 4, 2, 0 };

        double yarr[] = { 6, 13, 15, 16, 20 };

        double cov = FinancialMath::covariance(xarr, yarr, 5);
        double cor = FinancialMath::correlation(xarr, yarr, 5);

        printf("Covariance = %.10lf\n", cov);
        printf("Correlation = %.10lf\n", cor);

    }



    {

        printf("\n\nPositive Correlation and High Covariance Data Set\n");

        double xarr[] = { 8, 6, 4, 2, 0 };

        double yarr[] = { 1006, 513, 315, 216, 120 };

        double cov = FinancialMath::covariance(xarr, yarr, 5);
        double cor = FinancialMath::correlation(xarr, yarr, 5);

        printf("Covariance = %.10lf\n", cov);
        printf("Correlation = %.10lf\n", cor);

    }

    {

        printf("\n\nNegative Correlation and High Covariance Data Set\n");

        double xarr[] = { 8, 6, 4, 2, 0 };

        double yarr[] = { 120, 216, 315, 513, 1006 };

        double cov = FinancialMath::covariance(xarr, yarr, 5);
        double cor = FinancialMath::correlation(xarr, yarr, 5);

        printf("Covariance = %.10lf\n", cov);
        printf("Correlation = %.10lf\n", cor);

    }

    return 0;

}
