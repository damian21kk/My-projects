// Computer Science 2 project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
#define C 0.47
#define PI 4.*atan(1.0)
double rk4y(double y0, double x0, double h, double m, double g, double r, double y, double z, double wmax);
double rk4x(double y0, double x0, double h, double m, double g, double r, double y, double z, double wmax);
double rk4ydcc(double y0, double x0, double h, double m, double g, double r, double y, double z, double wmax);
double windforce(double w, double r, double ro);
double dccy(double vy, double vx, double r, double m, double g, double y, double z, double wmax);
double accx(double vx, double vy, double r, double m, double g, double y, double z, double wmax);
double accy(double vy, double vx, double r, double m, double g, double y, double z, double wmax);
double density(double z, double g);
double wind(double wmax, double z, double y);
void main()
{
	FILE *f;
	FILE *error;
	fopen_s(&f, "data.txt", "wt");
	fopen_s(&error, "error.txt", "wt");
	double vy = 0;
	double vx = 0;
	double wmax = 0;
	double r = 0;
	double g = 0;
	double nc = 4.;
	double z = 0;
	double m = 0;
	double h = 0;
	double h1 = 0;
	double xi = 0;
	printf("Please give the value of radius of the ball:\n");
	scanf_s("%lf", &r);
	if (r == 0)
	{
		printf("radius cannot be equal to zero, please give a new radius:\n");
		scanf_s("%lf", &r);
	}
	printf("Please specify the mass of the ball:\n");
	scanf_s("%lf", &m);
	if (m == 0)
	{
		printf("mass cannot be equal to zero, please give a new mass:\n");
		scanf_s("%lf", &m);
	}
	printf("Please give the value of initial vertical velocity:\n");
	scanf_s("%lf", &vy);
	printf("Please give the value of initial height:\n");
	scanf_s("%lf", &z);
	if (z == 0)
	{
		printf("initial height cannot be equal to zero, please give a new heigth:\n");
		scanf_s("%lf", &z);
	}
	printf("Please give the value of maximum wind velocity:\n");
	scanf_s("%lf", &wmax);
	printf("Please give the value of gravitational acceleration:\n");
	scanf_s("%lf", &g);
	printf("Please specify the time step:\n");
	scanf_s("%lf", &h1);
	if (h1 == 0)
	{
		printf("time step cannot be equal to zero, please give a new time step:\n");
		scanf_s("%lf", &h1);
	}
	/*printf("Please specify the number of collisions with the ground:\n");
	scanf_s("%lf", &nc);*/
	h = h1;
	double t = 0;
	double y = z;
	double x = 0;
	double vy0 = 0.;
	double i = 0;
	START:
	while (1 > 0)
	{
		/*if (h == h1)
		{
			printf("t=%e,x=%e, y=%e, vx=%e, vy=%e\n", t, x, y, -vx, vy);
			fprintf(f, "%e %e %e %e %e\n", t, x, y, -vx, vy);
		}*/
		vy = rk4y(vy, vx, h, m, g, r, y, z, wmax);
		vx = rk4x(vy0, vx, h, m, g, r, y, z, wmax);
		x = x - vx*h;
		y = y + vy*h;
		vy0 = vy;
		t = t + h;
		if (y <= 0)
		{
			break;
		}
	}
	while (i < (nc - 1.))
	{
		vy = vy*(-1);
		y = 0;
		while (1 > 0)
		{
			/*if (h == h1)
			{
				printf("t=%e,x=%e, y=%e, vx=%e, vy=%e\n", t, x, y, -vx, vy);
				fprintf(f, "%e %e %e %e %e\n", t, x, y, -vx, vy);
			}*/
			vy = rk4ydcc(vy, vx, h, m, g, r, y, z, wmax);
			vx = rk4x(vy0, vx, h, m, g, r, y, z, wmax);
			y = y + vy*h;
			x = x - vx*h;
			vy0 = vy;
			t = t + h;
			if (y <= 0)
			{
				break;
			}
		}
		++i;
	}

	if (h == h1)
	{
		xi = x;
		h = 0.1;
		t = 0;
		y = z;
		x = 0;
		vy0 = 0.;
		i = 0;
		vx = 0;
		goto START;
	}
	fprintf(error, "%lf %lf\n",h, (fabs((fabs(xi) - fabs(x)))) / fabs(xi)*100);
	printf("xi=%lf, x=%lf, time step=%lf, error=%lf\n",xi, x, h, (fabs((fabs(xi)-fabs(x))))/ fabs(xi)*100);
	if ((fabs((fabs(xi) - fabs(x)))) / fabs(xi)>0.001 && h>h1)
	{
		h = h*0.1;
		t = 0;
		y = z;

		x = 0;
		vy0 = 0.;
		i = 0;
		vx = 0;
		goto START;
	}

	fclose(f);
	fclose(error);
}
double rk4ydcc(double y0, double x0, double h, double m, double g, double r, double y, double z, double wmax)
{
	double k1 = dccy(y0, x0, r, m, g, y, z, wmax);
	double k2 = dccy(y0 + 0.5*k1*h, x0, r, m, g, y, z, wmax);
	double k3 = dccy(y0 + 0.5*k2*h, x0, r, m, g, y, z, wmax);
	double k4 = dccy(y0 + k3*h, x0, r, m, g, y, z, wmax);
	double y1 = y0 + (1. / 6.)*(k1 + 4.*k2 + 2 * k3 + k4)*h;
	return y1;
}
double dccy(double vy, double vx, double r, double m, double g, double y, double z, double wmax)
{
	double S = PI*r*r;
	double v = sqrt(pow(vy, 2.) + pow(-vx + wind(wmax, z, y), 2.));
	double k = (C*S*density(y, g)) / (2 * m);
	double ay = -1.*k*v*vy - g;
	//printf("ay=%lf, v=%lf, density=%lf\n", ay, v, density(y, g));
	return ay;
}
double rk4y(double y0, double x0, double h, double m, double g, double r, double y, double z, double wmax)
{
	double k1 = accy(y0, x0, r, m, g, y, z, wmax);
	double k2 = accy(y0 + 0.5*k1*h, x0, r, m, g, y, z, wmax);
	double k3 = accy(y0 + 0.5*k2*h, x0, r, m, g, y, z, wmax);
	double k4 = accy(y0 + k3*h, x0, r, m, g, y, z, wmax);
	double y1 = y0 + (1. / 6.)*(k1 + 4.*k2 + 2 * k3 + k4)*h;
	return y1;
}
double rk4x(double y0, double x0, double h, double m, double g, double r, double y, double z, double wmax)
{
	double k1 = accx(y0, x0, r, m, g, y, z, wmax);
	double k2 = accx(y0, x0 + 0.5*k1*h, r, m, g, y, z, wmax);
	double k3 = accx(y0, x0 + 0.5*k2*h, r, m, g, y, z, wmax);
	double k4 = accx(y0, x0 + k3*h, r, m, g, y, z, wmax);
	double x1 = x0 + (1. / 6.)*(k1 + 4.*k2 + 2 * k3 + k4)*h;
	return x1;
}
double windforce(double w, double r, double ro)
{
	double S = PI*r*r;
	double D = ((ro*w*w*S*C) / 2.);
	return D;
}
double accy(double vy, double vx, double r, double m, double g, double y, double z, double wmax)
{
	double S = PI*r*r;
	double v = sqrt(pow(vy, 2.) + pow(-vx + wind(wmax, z, y), 2.));
	double k = (C*S*density(y, g)) / (2 * m);
	double ay = -1.*k*v*vy - g;
	//printf("ay=%lf, v=%lf, density=%lf\n", ay, v, density(y, g));
	return ay;
}
double accx(double vy, double vx, double r, double m, double g, double y, double z, double wmax)
{
	double S = PI*r*r;
	double v = sqrt(pow(vy, 2.) + pow((vx - wind(wmax, z, y)), 2.));
	double k = (C*S*density(y, g)) / (2 * m);
	double ax = k*(vx - wind(wmax, z, y))*(vx - wind(wmax, z, y));
	return ax;
}
double density(double z, double g)
{
	double k = 1.381*pow(10., -23.);
	double ro0 = 1.225;
	double T = 288.15;
	double m = 28.97*1.661*pow(10., -23.);
	double p = 101325 * pow((1 - ((0.0065*z) / 288.15)), ((g*0.0289644) / (8.31447*0.0065)));
	double ro = (p*0.0289644) / (8.31447*(288.15/*-0.0065*z*/));
	//printf("r0=%lf\n", ro);
	return ro;
}
double wind(double wmax, double z, double y)
{
	double w = wmax - (wmax / z)*y;
	//printf("w=%lf\n", w);
	return w;
}