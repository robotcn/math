/*
 * FinancialMath.h
 *
 *  Created on: Nov 4, 2016
 *      Author: qxji
 */

#ifndef FINANCIALMATH_H_
#define FINANCIALMATH_H_

#include <stdio.h>
#include <math.h>

typedef long long TSize;

class FinancialMath
{
public:
    static double variane(double x[], TSize N)
    {
        double aver = mean(x, N);
        double temp = 0;

        for(int i = 0; i < N; i++)
        {
             temp += (x[i] - aver) * (x[i] - aver) ;
        }

        return temp / N;

    }
    static double deviation(double x[], TSize N)
    {
    	return sqrt(variane(x, N));
    }
    static double covariance(double x[], double y[], TSize N)
    {
        double total = 0;
        double xmean = mean(x, N);
        double ymean = mean(y, N);

        for(int i = 0; i < N; i++)
        {
            total += (x[i] - xmean) * (y[i] - ymean);
        }

        return total / N;
    }
    static double correlation(double x[], double y[], TSize N)
    {
    	double cov = covariance(x, y, N);

    	double correlation = cov / (deviation(x, N) * deviation(y, N));

    	return correlation;
    }
    static inline double mean(double x[], TSize N)
    {
        double sum = 0;
        for(int i = 0; i < N; i++)
            sum += x[i];
        return (sum / N);
    }

};


#endif /* FINANCIALMATH_H_ */
