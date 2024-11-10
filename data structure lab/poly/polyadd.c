#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int coeff;
	int expo;
} Poly;

int readPolynomial(Poly *p);
int addPolynomial(Poly *p1, Poly *p2, Poly *p3, int term1, int term2);
void displayPolynomial(Poly *p, int terms);

int main() {
	int t1, t2, t3;

	Poly *p1 = malloc(10 * sizeof(Poly));
	Poly *p2 = malloc(10 * sizeof(Poly));
	Poly *p3 = malloc(10 * sizeof(Poly));

	printf("Enter the first polynomial: \n");
	t1 = readPolynomial(p1);
	displayPolynomial(p1, t1);

	printf("Enter the second polynomial: \n");
	t2 = readPolynomial(p2);
	displayPolynomial(p2, t2);

	printf("Resultant polynomial: \n");
	t3 = addPolynomial(p1, p2, p3, t1, t2);
	displayPolynomial(p3, t3);
}

int readPolynomial(Poly *p) {
	int terms;

	printf("\nEnter the number of terms: ");
	scanf("%d", &terms);

	printf("\n");

	for (int i=0; i<terms; i++) {
		printf("Enter the coefficient: ");
		scanf("%d", &p[i].coeff);
		printf("Enter the exponent: ");
		scanf("%d", &p[i].expo);
	}

	printf("\n");

	return terms;
}

int addPolynomial(Poly *p1, Poly *p2, Poly *p3, int term1, int term2) {
	int i, j, k;
	i = j = k = 0;

	while (i < term1 && j < term2) {
		if (p1[i].expo == p2[j].expo) {
			p3[k].expo = p1[k].expo;
			p3[k].coeff = p1[i].coeff + p2[j].coeff;
			i++, j++, k++;
		}

		if (p1[i].expo > p2[j].expo) {
			p3[k].expo = p1[i].expo;	
			p3[k].coeff = p1[i].coeff;
			i++, k++;
		}

		if (p1[i].expo < p2[j].expo) {
			p3[k].expo = p2[j].expo;	
			p3[k].coeff = p2[j].coeff;
			j++, k++;
		}
	}

	while (i < term1) {
		p3[k].expo = p1[i].expo;
		p3[k].coeff = p1[i].coeff;
		i++, k++;
	}

	while (j < term2) {
		p3[k].expo = p2[j].expo;
		p3[k].coeff = p2[j].coeff;
		j++, k++;
	}

	return k;
}

void displayPolynomial(Poly *p, int terms) {
	for (int i=0; i<terms-1; i++) {
		printf("(%d)x^%d + ", p[i].coeff, p[i].expo);
	}
	printf("(%d)x^%d\n", p[terms-1].coeff, p[terms-1].expo);

	printf("\n");
}