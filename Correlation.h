/*
 * Correlation.h
 *
 *  Created on: Nov 4, 2016
 *      Author: qxji
 */

#ifndef CORRELATION_H_
#define CORRELATION_H_

#include <vector>
#include <math.h>

namespace Math {

template <class T>
class Correlation {
public:
	Correlation() {}
	virtual ~Correlation() {}


	/*
	 * double rxy = (N*sum(x[i]*y[i]) - sum(x[i])*sum(y[i])) /
	 *			(sqrt(N*sum(pow(x[i], 2)) - pow(sum(x[i]), 2)) *
	 *			 sqrt(N*sum(pow(y[i], 2)) - pow(sum(y[i]), 2)));
	 */

	static double corre(std::vector<T>& x, std::vector<T&> y)
	{
		if (x.empty() || y.empty())
			return 0;

		int N = min(x.size(), y.size());
		double sumx = 0, sumy = 0, summul = 0, sumpowx = 0, sumpowy = 0;
		for (int i = 0; i < N; i++) {
			sumx += x[i];
			sumy += y[i];
			summul += (x[i]*y[i]);
			sumpowx += pow(x[i], 2);
			sumpowy += pow(y[i], 2);
		}

		double a = N*summul - sumx*sumy;
		double b = sqrt(N * sumpowx - pow((T)sumx, 2));
		double c = sqrt(N * sumpowy - pow((T)sumy, 2));

		return a / (b*c);
	}
	static double corre(T x[], T y[], int N)
	{
		if (N <= 0)
			return 0;

		double sumx = 0, sumy = 0, summul = 0, sumpowx = 0, sumpowy = 0;
		for (int i = 0; i < N; i++) {
			sumx += x[i];
			sumy += y[i];
			summul += (x[i]*y[i]);
			sumpowx += pow(x[i], 2);
			sumpowy += pow(y[i], 2);
		}

		double a = N*summul - sumx*sumy;
		double b = sqrt(N * sumpowx - pow((T)sumx, 2));
		double c = sqrt(N * sumpowy - pow((T)sumy, 2));

		return a / (b*c);
	}
	inline int min(int a, int b) {
		return (a < b) ? a : b;
	}
};

} /* namespace Math */

#endif /* CORRELATION_H_ */
