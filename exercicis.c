#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 512
float V1[N], V2[N], V3[N], V4[N], Mat[N][N], MatDD[N][N];

void InitData(){

	int i,j;
	srand(334411);

	for( i = 0; i < N; i++ )
 		for( j = 0; j < N; j++ ){

 			Mat[i][j]=(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));
 			if ( (abs(i - j) <= 3) && (i != j))
 				MatDD[i][j] = (((i*j)%3) ? -1 : 1)*(rand()/(1.0*RAND_MAX));
 			else if ( i == j )
 				MatDD[i][j]=(((i*j)%3)?-1:1)*(10000.0*(rand()/(1.0*RAND_MAX)));
 			else MatDD[i][j] = 0.0;
 		}

	for( i = 0; i < N; i++ ){

 		V1[i]=(i<N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0;
 		V2[i]=(i>=N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0;
 		V3[i]=(((i*j)%5)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));
	}
}

//------------------------------------------------------------------------
// EXERCICI 1

void PrintVect( float Vect[N], int from, int numel){
	int i;
	int size = ( from + numel );
	for( i = from; i < size; i++ ){
		printf("%f ", Vect[i]);
	}
	printf("\n");
}

//------------------------------------------------------------------------
// EXERCICI 2

void PrintRow( float mat[N][N], int row, int from, int numel ){
	for ( int j = from; j < from+numel; j++ ){ //Signe modificat
  		printf("%f ", mat[row][j]);
	}
	printf("\n");
}

//------------------------------------------------------------------------
// EXERCICI 3

void MultEscalar( float vect[N], float vectres[N], float alfa){
	int i;
	for( i = 0; i < N; i++ ){
		vectres[i] = vect[i] * alfa;
	}
}

//------------------------------------------------------------------------
// EXERCICI 4

float Scalar( float vect1[N], float vect2[N] ) {
	float producte = 0.0;

	for ( int i = 0; i < N; i++ ){
		producte += vect1[i] * vect2[i];
	}
	return producte;
}

//------------------------------------------------------------------------
// EXERCICI 5

float Magnitude( float vect[N] ){
	float resultat;
	resultat = sqrt(Scalar( vect, vect));
	return resultat;
}

//------------------------------------------------------------------------
// EXERCICI 6

int Ortogonal( float vect1[N], float vect2[N] ){
	float producte = Scalar( vect1, vect2 );
	if (producte == 0){
		return 1;
	}else{
		return 0;
	}
}

//------------------------------------------------------------------------
// EXERCICI 7

void Projection( float vect1[N], float vect2[N], float vectres[N]){
	float escalar_uv = Scalar( vect1, vect2 );
	float magnitud_v = Magnitude( vect2 );
	float divisio = (escalar_uv / magnitud_v);

	MultEscalar( vect2, vectres, divisio);
}

//------------------------------------------------------------------------
// EXERCICI 8

float Infininorm(float M[N][N]) {
	float max = 0.0;

	for (int i = 0; i < N; i++) {
		float fila = 0.0;

		for (int j = 0; j < N; j++) {
			fila += fabs(M[i][j]);
		}

		if (fila > max) {
			max = fila;
		}
	}

	return max;
}

//------------------------------------------------------------------------
// EXERCICI 9

float Onenorm(float M[N][N]) {
	float max = 0.0;

	for (int j = 0; j < N; j++) {
		float columna = 0.0;

		for (int i = 0; i <N; i++) {
			columna += fabs(M[i][j]);
		}

		if (columna > max) {
			max = columna;
		}
	}

	return max;
}

//------------------------------------------------------------------------
// EXERCICI 10

float NormFrobenius( float M[N][N] ){
	float suma = 0.0;
	float NFrob = 0.0;

	for (int i = 0; i < N; i++ ){
		for (int j = 0; j < N; j++ ){
			float quadrat = 0.0;
			quadrat = M[i][j] * M[i][j];
			suma += quadrat;
		}
	}
	NFrob = sqrt(suma);
	return NFrob;
}

//------------------------------------------------------------------------
// EXERCICI 11

int DiagonalDom( float M[N][N] ){

	for( int i = 0; i < N; i++){
		float element = fabs(M[i][i]);
		float suma = 0.0;

		for( int j = 0; j < N; j++){
			if (j != i){
				suma += fabs(M[i][j]);
			}
		}

		if (suma > element){
			return 0;
		}
	}
	return 1;
}


//------------------------------------------------------------------------
// EXERCICI 12

void Matriu_x_Vector( float M[N][N], float vect[N], float vectres[N] ){

	for (int i = 0; i < N; i++ ){
		float fila = 0.0;

		for (int j = 0; j < N; j++ ){
			float producte = 0.0;
			producte = M[i][j] * vect[j];
			fila += producte;
		}
		vectres[i] = fila;
	}
}
//------------------------------------------------------------------------
// EXERCICI 13

int JAplicable( float M[N][N] ){
	int valid = 0;

	for (int i=0; i<N; i++){
		float fresta = 0.0;

		for (int j=0; i<N; j++){

			if (i != j){
				fresta += M[i][j];
			}
		}

		if ( fabs(M[i][i]) > fresta ){
			valid += 1;
		}
	}

	if (valid = N){
		return 1;
	}else{
		return 0;
	}
}

int Jacobi( float M[N][N] , float vect[N], float vectres[N], unsigned iter ){

	int retorn = JAplicable( M );

	if (retorn == 1){

		float NouV[N];
		for ( int i=0; i<N; i++){
			NouV[i]=0.0;
		}

		for ( int k=0; k<iter; k++){

			for ( int i=0; i<N; i++){
				float suma = 0.0;

				for ( int j=0; j<N; j++){

					if (i != j){
						suma += M[i][j]*NouV[i];
					}
				}

				NouV[i] = (vect[i] - suma) / M[i][i];
			}
		}
		vectres=NouV;
	}
	return retorn;
}

//------------------------------------------------------------------------
// PUNT EXTRA

void Precisio( float vectres[N], float vect[N], float vectres2[N], float precisio ){

	for ( int i=0; i<N; i++){
		vectres2[i]=fabs(vectres[i]-vect[i]);
	}

	precisio = Magnitude( vectres2 ); // És vectres2 i no vect2 ?
}

//------------------------------------------------------------------------
// MAIN

int main(){

	InitData();

	// PROVA A
	printf("Prova A\n");
	printf("V1 del 0 al 9 i del 256 al 265:\n");
	PrintVect(V1, 0, 10);
	PrintVect(V1, 256, 10);

	printf("\nV2 del 0 al 9 i del 256 al 265:\n");
	PrintVect(V2, 0, 10);
	PrintVect(V2, 256, 10);

	printf("\nV3 del 0 al 9 i del 256 al 265:\n");
	PrintVect(V3, 0, 10);
	PrintVect(V3, 256, 10);

	// PROVA B
	printf("\nProva B\n");
	printf("Mat fila 0 i fila 100 del 0 al 9:\n");
	PrintRow(Mat, 0, 0, 10);
	PrintRow(Mat, 100, 0, 10);

	// PROVA C
	printf("\nProva C\n");
	printf("MatDD fila 0 del 0 al 9 i fila 100 del 95 al 104:\n");
	PrintRow(MatDD, 0, 0, 10);
	PrintRow(MatDD, 100, 90, 10);

	// PROVA D
	printf("\nProva D\n");

	float Infininorma_Mat = Infininorm(Mat);
	float Norma_u_Mat = Onenorm(Mat);
	float NFrobenius_Mat = NormFrobenius(Mat);
	int DiagoDom_Mat = DiagonalDom(Mat);

	printf("Infininorma de Mat = %f",Infininorma_Mat);

	float Infininorma_MatDD = Infininorm(MatDD);
        float Norma_u_MatDD = Onenorm(MatDD);
        float NFrobenius_MatDD = NormFrobenius(MatDD);
        int DiagoDom_MatDD = DiagonalDom(MatDD);
}


