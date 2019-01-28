#include "stdafx.h"
#include "stdio.h"
#include "math.h"
#include "time.h"
#include "stdlib.h"


int npoint();
void printfile(int n, int X[], int Y[], int bx, int by, int sx, int sy, double c0, double c1, double c2, double c3, double c4, double c5, double c6, double c7);
void print(int n, int X[], int Y[], int bx, int by, int sx, int sy, double c0, double c1, double c2, double c3, double c4, double c5, double c6, double c7);
int biggestX(int n, int X[]);
int biggestY(int n, int Y[]);
int smallestX(int n, int X[]);
int smallestY(int n, int Y[]);
int checklvl(int n, int X[], int Y[]);
double distance2(int i, int X[], int Y[]);
int* negcase3(int n, int X[], int Y[]);
double* da(int n, int X[], int Y[]);
double distancea(int X, int Y);
double* daneg(int n, int X[], int Y[]);
double distancean(int X, int Y);
int* negative(int n, int X[], int Y[]);
int* positive(int n, int X[], int Y[]);
double* corners(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
double* corner(int x1, int y1, int m1, int x2, int y2, int m2);
double length(double x1, double y1, double x2, double y2); //find the length of the side of the 45* rectangle
int area1(int x1, int x2, int y1, int y2);//finds area of first rectangle
double area2(double l1, double l2);//finds area of second rectangle
void compare(int A1, double A2); //compares areas
int* negativeunder(int n, int X[], int Y[]);
double* corners2(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);


void main()
{
	srand((unsigned)time(NULL));
	int n = npoint();
	beginning:
	int* X = (int*)malloc(n * sizeof(int));
	int j = 0;
	while (j < n)
	{
		X[j] = (pow((-1.),rand()%3+1))*rand();
		++j;
	}
	int* Y = (int*)malloc(n * sizeof(int));
	j = 0;
	while (j < n)
	{
		Y[j] = (pow((-1.), rand() % 3 + 1))*rand();
		++j;
	}
	int lvl = checklvl(n, X, Y);
	//printf("checklvl=%d\n", lvl);
	if (lvl == 1 || lvl == 2)
	{
		free(X);
		free(Y);
		goto beginning;
	}
	if (lvl == 3)
	{
		for (int k=0;k<n; ++k)
		{
			if (X[k] < 0 || Y[k] < 0)
			{
				int *g;
				g = positive(n, X, Y);
				int *q;
				q = negativeunder(n, X, Y);
				double *c;
				c = corners2(q[0], q[1], g[2], g[3], q[2], q[3], g[0], g[1]);
				printf("%d, %d, %d, %d, %d, %d, %d, %d\n",q[0], q[1], g[2], g[3], q[2], q[3], g[0], g[1]);
				int A1 = area1(smallestX(n, X), biggestX(n, X), smallestY(n, Y), biggestY(n, Y));
				double A2;
				A2 = area2(length(c[0], c[1], c[2], c[3]), length(c[2], c[3], c[4], c[5]));
				print(n, X, Y, biggestX(n, X), biggestY(n, Y), smallestX(n, X), smallestY(n, Y), c[0], c[1], c[2], c[3], c[4], c[5], c[6], c[7]);
				printfile(n, X, Y, biggestX(n, X), biggestY(n, Y), smallestX(n, X), smallestY(n, Y), c[0], c[1], c[2], c[3], c[4], c[5], c[6], c[7]);
				compare(A1, A2);
				free(g);
				free(q);
				free(c);
				exit(0);
			}
		
		}
		int *g;
		g = negative(n, X, Y);
		int *q;
		q = positive(n, X, Y);
		double *c;
		c = corners(q[0],q[1],g[2], g[3], q[2], q[3], g[0], g[1] );
		int A1 = area1(smallestX(n, X), biggestX(n, X), smallestY(n, Y), biggestY(n, Y));
		double A2;
		A2 = area2(length(c[0], c[1], c[2], c[3]), length(c[2], c[3], c[4], c[5]));
		print(n, X, Y, biggestX(n, X), biggestY(n, Y), smallestX(n, X), smallestY(n, Y), c[0], c[1], c[2], c[3], c[4], c[5], c[6], c[7]);
		printfile(n, X, Y, biggestX(n, X), biggestY(n, Y), smallestX(n, X), smallestY(n, Y), c[0], c[1], c[2], c[3], c[4], c[5], c[6], c[7]);
		compare(A1, A2);
		free(g);
		free(q);
		free(c);
	}
	free(X);
	free(Y);
}



int npoint()
{
	int n;
	printf("Please give the number of points:\n");
	scanf_s("%d", &n);
	return n;
}
void print(int n, int X[], int Y[], int bx, int by, int sx, int sy, double c0, double c1, double c2, double c3, double c4, double c5, double c6, double c7)
{
	int j = 0;
	while (j < n)
	{
		printf( "(%d, %d)\n", X[j], Y[j]);
		++j;
	}
	printf("The corners of the first rectangle are:\n (%d,%d), (%d,%d), (%d,%d), (%d,%d)\n", sx, sy, sx, by, bx, by, bx, sy);
	printf("The corners of the first rectangle are:\n(%lf, %lf), (%lf, %lf), (%lf, %lf), (%lf, %lf)\n", c0, c1, c2, c3, c4, c5, c6, c7);
}
void printfile(int n, int X[], int Y[], int bx, int by, int sx, int sy, double c0, double c1, double c2, double c3, double c4, double c5, double c6, double c7)
{
	FILE *f;
	fopen_s(&f, "data.txt", "wt");
	int j = 0;
	while (j < n)
	{
		fprintf(f, "%d, %d\n", X[j], Y[j]);
		++j;
	}
	fclose(f);
}
int biggestX(int n, int X[])
{
	int l = X[0];
	for (int i = 1; i < n; i++)
	{
		if (l < X[i])
			l = X[i];
	}
	return l;
}
int biggestY(int n, int Y[])
{
	int l = Y[0];
	for (int i = 1; i < n; i++)
	{
		if (l < Y[i])
			l = Y[i];
	}
	return l;
}
int smallestX(int n, int X[])
{
	int s = X[0];
	for (int i = 1; i < n; i++)
	{
		if (s > X[i])
			s = X[i];
	}
	return s;
}
int smallestY(int n, int Y[])
{
	int s = Y[0];
	for (int i = 1; i < n; i++)
	{
		if (s > Y[i])
			s = Y[i];
	}
	return s;
}
int checklvl(int n, int X[], int Y[])
{
	int u = 0;
	int o = 0;
	int r = 0;
	for (int i = 0; i < n; ++i)
		{
			if (Y[i] > X[i])
			{
				++o;
			}
			if (X[i] > Y[i])
			{
				++u;
			}
		}
	if (u>0&&o==0)
	{
		r = 1;
	}
	if (u==0&&o>0)
	{
		r = 2;
	}
	if ((u>0)&&(o>0))
	{
		r = 3;
	}
	return r;
}
double distance(int i, int X[], int Y[])//line y=x
{
	double d = (sqrt(pow((X[i] + (-1.)*Y[i]),2))) / sqrt(2.);
		return d;
}
double distance2(int i, int X[], int Y[])//line y=-x
{
	double d = ((pow(pow((-1.)*X[i] + (-1.)*Y[i], 2), 0.5)) / (pow(2., 0.5)));
	return d;
}
int* negcase3(int n, int X[], int Y[])
{
	int *r = (int*)malloc(4 * sizeof(int));
	double d = distance2(0, X, Y);
	int k = 0;
	for (int i = 1; i < n; i++)
	{
		if (d < distance2(i, X, Y))
		{
			d = distance2(i, X, Y);
			++k;
		}
	}
	r[0] = X[k];
	r[1] = Y[k];
	d = distance2(0, X, Y);
	k = 0;
	for (int i = 1; i < n; i++)
	{
		if (d > distance2(i, X, Y))
		{
			d = distance2(i, X, Y);
			++k;
		}
	}
	r[2] = X[k];
	r[3] = Y[k];
	return r;
}
//creates array of distances from Y=X
double* da(int n, int X[], int Y[])
{
	double *distancearray = (double*)malloc(n * sizeof(double));
	int k = 0;
	while (k < n)
	{
		distancearray[k] = distancea(X[k], Y[k]);
		++k;
	}
	return distancearray;
}
double distancea(int X, int Y)//line y=x
{
	double d = (sqrt(pow(((double)X + (-1.)*(double)Y), 2))) / sqrt(2.);
	return d;
}
//creates array of distances from Y=-X
double* daneg(int n, int X[], int Y[])
{
	double *distancearray = (double*)malloc(n * sizeof(double));
	int k = 0;
	while (k < n)
	{
		distancearray[k] = distancean(X[k], Y[k]);
		++k;
	}
	return distancearray;
}
double distancean(int X, int Y)//line y=x
{
	double d = (sqrt(pow(((-1.)*(double)X + (-1.)*(double)Y), 2))) / sqrt(2.);
	return d;
}
//finds points furthest and closest to y=-x
int* negative(int n, int X[], int Y[])
{
	int *r = (int*)malloc(4 * sizeof(int));
	int c, location = 0;
	double *d;
		d = daneg(n, X, Y);
	double minimum = d[0];

	for (c = 1; c < n; c++)
	{
		if (d[c] < minimum)
		{
			minimum = d[c];
			location = c;
		}
	}
	r[0] = X[location];
	r[1] = Y[location];
	location = 0;
	double maximum = d[0];

	for (c = 1; c < n; c++)
	{
		if (d[c] >maximum)
		{
			maximum = d[c];
			location = c;
		}
	}
	r[2] = X[location];
	r[3] = Y[location];
	return r;
}
//finds points furthest to y=x
int* positive(int n, int X[], int Y[])
{
	int *r = (int*)malloc(4 * sizeof(int));
	int u = 0;
	int o = 0;
	for (int i = 0; i < n; ++i)
	{
		if (Y[i] > X[i])
		{
			++o;
		}
		if (X[i] > Y[i])
		{
			++u;
		}
	}
	int *uaX = (int*)malloc(u * sizeof(int));
	int *uaY = (int*)malloc(u * sizeof(int));
	int *oaX = (int*)malloc(o * sizeof(int));
	int *oaY = (int*)malloc(o * sizeof(int));
	int no = 0; //index of a point over the line y=x
	int nu = 0;//index of a point under the line y=x
	int i = 0;

	while (i<n)
	{
		if (Y[i] > X[i])
		{
			oaY[no] = Y[i];
			oaX[no] = X[i];
			++no;

		}
		if (X[i] > Y[i])
		{
			uaY[nu] = Y[i];
			uaX[nu] = X[i];
			++nu;
		}
		++i;
	}
	//over the line
	int c, location = 0;
	double *d;
	d = da(o, oaX, oaY);
	double maximum = d[0];

	for (c = 1; c < o; c++)
	{
		if (d[c] > maximum)
		{
			maximum = d[c];
			location = c;
		}
	}
	r[0] = oaX[location];
	r[1] = oaY[location];
	//under the line
	double *d2;
	d2 = da(u, uaX, uaY);
	location = 0;
	double maximum2 = d2[0];

	for (c = 1; c < u; c++)
	{
		if (d2[c] >maximum2)
		{
			maximum2 = d2[c];
			location = c;
		}
	}
	r[2] = uaX[location];
	r[3] = uaY[location];
	return r;
}
//find all corners
double* corners(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	double *corners = (double*)malloc(8 * sizeof(double));
	double *c1;
	c1 = corner(x1, y1, 1, x4, y4, (-1));
	double *c2;
	c2 = corner(x1, y1, 1, x2, y2, (-1));
	double *c3;
	c3 = corner(x2, y2, (-1), x3, y3, 1);
	double *c4;
	c4 = corner(x3, y3, 1, x4, y4, (-1));
	corners[0] = c1[0];
	corners[1] = c1[1];
	corners[2] = c2[0];
	corners[3] = c2[1];
	corners[4] = c3[0];
	corners[5] = c3[1];
	corners[6] = c4[0];
	corners[7] = c4[1];
	return corners;
}
//find a single corner
double* corner(int x1, int y1, int m1, int x2, int y2, int m2)
{
	double *corner = (double*)malloc(2 * sizeof(double));
	double x =(((-1.)*(double)m2*(double)x2)+ (double)y2+((double)m1*(double)x1)- (double)y1)/((double)m1- (double)m2) ;
	double y = (double)m1*(x - (double)x1) + (double)y1;
	corner[0] = x;
	corner[1] = y;

	return corner;
}
double length(double x1, double y1, double x2, double y2)
{
	double l = sqrt(pow((x1 - x2), 2.) + pow(y1 - y2, 2.));
	return l;
}
int area1(int x1, int x2, int y1, int y2)
{
	int A;
	A = (x2 - x1)*(y2 - y1);
	return A;
}
double area2(double l1, double l2)
{
	double A;
	A = l1*l2;
	return A;
}
void compare(int A1, double A2)
{
	printf("The area of the first rectangle is: %d\n", A1);
	printf("The area of the second rectangle is: %lf\n", A2);

	if ((double)A1>A2)
	{
		printf("Area of the first rectangle is greater.\n");
	}
	if ((double)A1<A2)
	{
		printf("Area of the second rectangle is greater.\n");
	}
	if ((double)A1==A2)
	{
		printf("Both areas are the same.\n");
	}
}
int* negativeunder(int n, int X[], int Y[])
{
	int *r = (int*)malloc(4 * sizeof(int));
	int u = 0;
	int o = 0;
	for (int i = 0; i < n; ++i)
	{
		if (Y[i] > (-1)*X[i])
		{
			++o;
		}
		if ((-1)*X[i] > Y[i])
		{
			++u;
		}
	}
	int *uaX = (int*)malloc(u * sizeof(int));
	int *uaY = (int*)malloc(u * sizeof(int));
	int *oaX = (int*)malloc(o * sizeof(int));
	int *oaY = (int*)malloc(o * sizeof(int));
	int no = 0; //index of a point over the line y=x
	int nu = 0;//index of a point under the line y=x
	int i = 0;

	while (i<n)
	{
		if (Y[i] > (-1)*X[i])
		{
			oaY[no] = Y[i];
			oaX[no] = X[i];
			++no;

		}
		if ((-1)*X[i] > Y[i])
		{
			uaY[nu] = Y[i];
			uaX[nu] = X[i];
			++nu;
		}
		++i;
	}
	//over the line
	int c, location = 0;
	double *d;
	d = daneg(o, oaX, oaY);
	double maximum = d[0];

	for (c = 1; c < o; c++)
	{
		if (d[c] > maximum)
		{
			maximum = d[c];
			location = c;
		}
	}
	r[0] = oaX[location];
	r[1] = oaY[location];
	//under the line
	double *d2;
	d2 = daneg(u, uaX, uaY);
	location = 0;
	double maximum2 = d2[0];

	for (c = 1; c < u; c++)
	{
		if (d2[c] >maximum2)
		{
			maximum2 = d2[c];
			location = c;
		}
	}
	r[2] = uaX[location];
	r[3] = uaY[location];
	return r;
}
double* corners2(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	double *corners = (double*)malloc(8 * sizeof(double));
	double *c1;
	c1 = corner(x1, y1, (-1), x4, y4, (1));
	double *c2;
	c2 = corner(x1, y1, (-1), x2, y2, 1);
	double *c3;
	c3 = corner(x2, y2, 1, x3, y3, (-1));
	double *c4;
	c4 = corner(x3, y3, (-1), x4, y4, 1);
	corners[0] = c1[0];
	corners[1] = c1[1];
	corners[2] = c2[0];
	corners[3] = c2[1];
	corners[4] = c3[0];
	corners[5] = c3[1];
	corners[6] = c4[0];
	corners[7] = c4[1];
	return corners;
}