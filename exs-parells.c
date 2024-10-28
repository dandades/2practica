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

	for( i = from; i < size; i++ )
		printf("%f ", Vect[i]);
	printf("\n");
}

int main() {

	InitData();
        PrintVect( V1, 0, 10);

}

//------------------------------------------------------------------------
// EXERCICI 2


void PrintRow( float mat[N][N], int row, int from, int numel ){
  for ( int j = from; j <= from+numel; j++ ){
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

int main() {

	InitData();
	float nouVector[N];
	float num = 3.5;

	MultEscalar( V1, nouVector, num);

}

//------------------------------------------------------------------------
// EXERCICI 4

float Scalar( float vect1[N], float vect2[N] ) {
  float producte = 0.0;
  
  for ( int i = 0; i < N; i++ ){
    producte += vect1[i] * vect2[i];
  }
  printf("%f\n", producte);
}

//------------------------------------------------------------------------
// EXERCICI 5 (ACABAR)

float Magnitude( float vect[N] ){

	Scalar( vect[N], vect[N] )
	}
}

//------------------------------------------------------------------------
// EXERCICI 6

int Ortogonal( float vect1[N], float vect2[N] ){
  float producte = 0.0;
  
  for ( int i = 0; i < N; i++ ){
    producte += vect1[i] * vect2[i];
    
  if (producte == 0){
    return 1;
  }else{
    return 0;
  }
}
}

//------------------------------------------------------------------------
// EXERCICI 7 (FER)



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

    printf("%f\n", max);
}

//------------------------------------------------------------------------
// EXERCICI 9 (FER)



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
  printf("%f\n", NFrob);
}

//------------------------------------------------------------------------
// EXERCICI 11 (FER)



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
// MAIN
int main(){
  int row, from, numel;
  
  InitData();
  
  printf("Introdueix el valor per row:");
  scanf("%d", &row);
  printf("Introdueix el valor per from:");
  scanf("%d", &from);
  printf("Introdueix el valor per numel:");
  scanf("%d", &numel); 
  PrintRow( Mat, row, from, numel );

  

  Scalar(V1, V2);
  Scalar(V1, V3);
  Scalar(V2, V3);

  Magnitude(V1);
  Magnitude(V2);
  Magnitude(V3);

  Infininorm(Mat);
  Infininorm(MatDD);
  
  NormFrobenius(Mat);
  NormFrobenius(MatDD);
}


