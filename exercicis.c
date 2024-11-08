// PRÀCTICA 2: OPERACIONS AMB MATRIUS I VECTORS EN C
// GRUP 1, PLAB 811

// Inclusió de biblioteques: Afegim les biblioteques que contenen funcions bàsiques per realitzar el programa.
#include <stdio.h>	// Inclou funcions bàsiques d'entrada i sortida com printf o scanf.
#include <stdlib.h>     // Inclou funcions per generar números aleatoris com rand o srand.
#include <math.h>	// Inclou funcions matemàtiques com sqrt o fabs.


// Definició de constants i variables: Generem constants i variables que s'utilitzaran al llarg del programa
// Definim N com una constant amb valor 512.
#define N 512

// Definim 4 vectors de dimensió N i dues matrius de dimensions NxN (tot i que V4 no es fa servir).
float V1[N], V2[N], V3[N], V4[N], Mat[N][N], MatDD[N][N];

// Funció d'inicialització: Genera els valors pels vectors V1, V2 i V3 i les matrius Mat i MatDD
void InitData(){

	int i,j;
	srand(334411);	// Amb l'ús de srand, els valors generats pels vectors i matrius seran aleatoris entre ells, però cada cop que s'executi el programa sortiran els mateixos números.

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

//-------------------------------------------------------------------------------------------------
// EXERCICI 1: Mostrar elements d'un vector

// Definim la funció PrintVect com un void (no retornarà cap valor al final).
// Incloem 3 paràmetres: vect[N] és el vector sobre el que volem mostrar els valors; from és la primera posició del vector que volem mostrar; i numel és el nombre d'elements a mostrar.
void PrintVect(float vect[N], int from, int numel){

	// Generem una variable size que és la suma de from i numel, és a dir, marca la posició del primer element que no volem mostrar..
	int size = (from + numel);

	// Utilitzem un bucle for per récorrer tots els elements que volem mostrar.
	// Mostrem per pantalla l'element i del vector. Utilizem %f per mostrar una variable de tipus float.
	for(int i = from; i < size; i++){
		printf("%f ", vect[i]);
	}

	// Fem un salt de línia al final per separar la impressió de les següents comandes a realitzar.
	printf("\n");
}

//-------------------------------------------------------------------------------------------------
// EXERCICI 2: Mostrar elements d'una fila d'una matriu

// Definim la funció PrintRow com un void (no retornarà cap valor al final).
// Incloem 4 paràmetres: mat[N][N] és la matriu sobre la qual volem mostrar els valors; row és la fila que volem mostrar; from és el primer element de la fila que volem mostrar; i numel és el nombre d'elements que volem mostrar.
void PrintRow(float mat[N][N], int row, int from, int numel){

	// Generem una variable size que és la suma de from i numel, marca la posició del primer element que no volem mostrar
	int size = (from + numel);

	// Utilitzem un bucle for per récorrer tots els elements que volem mostrar.
	// Mostrem per pantalla l'element j corresponent a la fila determinada.
	for (int j = from; j < size; j++){
  		printf("%f ", mat[row][j]);
	}

	printf("\n");
}

//-------------------------------------------------------------------------------------------------
// EXERCICI 3: Multiplicació d'un vector per un escalar

// Definim la funció MultEscalar com un void (no retornarà cap valor al final).
// Incloem 3 paràmetres: vect[N] és el vector que utilizem per calcular; vectres[N] és el vector resultant de l'operació; i alfa com l'enter que multiplica el vector.
void MultEscalar(float vect[N], float vectres[N], float alfa){

	// Utilitzem un bucle for per récorrer tots els elements del vector.
	for(int i = 0; i < N; i++){

		// Definim l'element i del vector resultant com la multiplicació de l'element i del vector per alfa
		vectres[i] = vect[i] * alfa;
	}
}

//-------------------------------------------------------------------------------------------------
// EXERCICI 4: Càlcul del producte escalar de dos vectors

// Definim la funció Scalar com un float, retornarà un valor float al final.
// Incloem 2 paràmetres: vect1 i vect2 són els vectors que volem calcular el producte escalar.
float Scalar(float vect1[N], float vect2[N]) {

	// Definim una variable prod_escalar com un float amb valor 0. Utilitzarem aquesta variable per guardar el resultat final de l'operació.
	float prod_escalar = 0.0;

	// Utilitzem un bucle for per récorrer tots els elements dels vectors.
	for (int i = 0; i < N; i++){

		// Afegim a prod_escalar la multiplicació dels elements i de vect1 i vect2.
		prod_escalar += vect1[i] * vect2[i];
	}

	// Retornem el valor del producte escalar un cop fet el bucle.
	return prod_escalar;
}

//-------------------------------------------------------------------------------------------------
// EXERCICI 5: Càlcul de la magnitud d'un vector

// Definim la funció Magnitude com un float, retornarà un valor float.
// Incloem 1 paràmetre, que és el vector sobre el qual volem calcular la magnitud.
float Magnitude(float vect[N]){

	// Generem una variable magnitud que és l'arrel quadrada del producte escalar del vector per ell mateix. Retornem el resultat.
	float magnitud = sqrt(Scalar(vect, vect));
	return magnitud;
}

//-------------------------------------------------------------------------------------------------
// EXERCICI 6: Determinar l'ortogonalitat de dos vectors

// Definim la funció Ortogonal com un int, que retornarà un 1 si els vectors són ortogonals i un 0 si no.
// Incloem 2 paràmetres: vect1 i vect2 que són els vectors sobre els quals calculem
int Ortogonal(float vect1[N], float vect2[N]){

	// Definim una variable prod_escalar com el resultat del producte escalar dels dos vectors
	float prod_escalar = Scalar(vect1, vect2);

	// Si el producte escalar és 0, retornem 1, indicant que els vectors són ortogonals. Si no, retornem 0 indicant que no ho són.
	if (prod_escalar == 0){
		return 1;
	}else{
		return 0;
	}
}

//-------------------------------------------------------------------------------------------------
// EXERCICI 7: Calcular el vector projecció d'un vector sobre un altre

// Definim la funció Projection com un void, no retornarà cap valor.
// Incloem 3 paràmetres: vect1 i vect2 són els vectors en els quals calcularem el vector projecció, i vectres serà el vector resultant del càlcul.
void Projection( float vect1[N], float vect2[N], float vectres[N]){

	// Definim una variable prod_escalar_v1v2 com el producte escalar dels dos vectors.
	float prod_escalar_v1v2 = Scalar(vect1, vect2);

	// Definim una variable magnitud_v2 com la magnitud del vect2.
	float magnitud_v2 = Magnitude(vect2);

	// Calculem una variable divisio com la divisió del producte escalar de vect1 i vect2 entre la magnitud de vect2.
	float divisio = (prod_escalar_v1v2 / magnitud_v2);

	// Calculem la multiplicació del vect2 amb la divisió calculada anteriorment i ho guardem al vectres, utilitzant la funció MultEscalar.
	MultEscalar( vect2, vectres, divisio);
}

//-------------------------------------------------------------------------------------------------
// EXERCICI 8: Infini-norma d'una matriu

// Definim la funció Infininorm con un float, retornarà el màxim de les sumes dels valors absoluts dels elements de cada fila de la matriu.
// Incloem 1 paràmetre que és la matriu sobre la que volem calcular.
float Infininorm(float M[N][N]) {

	// Inicialitzem una variable max on guardarem el valor màxim que busquem. La determinem com a 0 en un inici.
	float max = 0.0;

	// Utilitzem un bucle for per récorrer totes les files de la matriu.
	for (int i = 0; i < N; i++) {

		// Generem una variable fila on guardarem el valor de la suma dels valors absoluts de cada element de la fila.
		float fila = 0.0;

		// Utilitzem un bucle for per récorrer tots els elements de la fila.
		for (int j = 0; j < N; j++) {

			// Sumem el valor absolut de l'element a la variable fila. Utilitzem fabs per calcular el valor absolut.
			fila += fabs(M[i][j]);
		}

		// Un cop s'ha realitzat la suma dels valors absoluts de tots els elements de la fila, comprovem si és major que el màxim definit. Si ho és, modifiquem el màxim pel valor de la suma calculada.
		if (fila > max) {
			max = fila;
		}
	}

	// Un cop recorregudes totes les files de les matrius, retornem el màxim de les sumes.
	return max;
}

//------------------------------------------------------------------------
// EXERCICI 9: Norma-ú d'una matriu

// Definim la funció Onenorm com un float, retornarà el màxim de les sumes dels valors absoluts dels elements d'una columna.
// Incloem 1 paràmetre que és la matriu sobre la que volem calcular.
float Onenorm(float M[N][N]) {

	// Realitzem el mateix procediment que l'exercici anterior de la infini-norma, únicament intercanviant els índexs (i,j), ja que en comptes de récorrer tots els elements d'una fila, hem de récorrer els de les columnes.
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
// EXERCICI 10: Norma de Frobenius

// Definim la funció NormFrobenius com un float, que retornarà el resultat de calcular la norma de Frobenius en una matriu.
// Incloem 1 paràmetre que és la matriu sobre la qual volem calcular.
float NormFrobenius(float M[N][N]){

	// Inicialitzem una variable suma que servirà de sumatori de tots els elements al quadrat de la matriu.
	float suma = 0.0;

	// Utilitzem un bucle for per récorrer les files de la matriu.
	for (int i = 0; i < N; i++){

		// Com la norma de Frobenius és la suma dels quadrats de tots els elements, podem utilitzar la funció Scalar amb la fila per ella mateixa per fer la suma de quadrats de cada fila
		float suma_quadrats_fila = Scalar(M[i],M[i]);
		suma += suma_quadrats_fila;
	}

	// Inicialitzem una variable NFrob com l'arrel quadrada de la suma total, i retornem el valor obtingut.
	float NFrob = sqrt(suma);
	return NFrob;
}

//------------------------------------------------------------------------
// EXERCICI 11: Diagonal dominant

// Definim la funció DiagonalDom com un int, que retornarà 1 si la matriu és diagonal dominant i 0 si no ho és.
// Incloem 1 paràmetre que és la matriu sobre la qual volem calcular.
int DiagonalDom(float M[N][N]){

	// Utilitzem un bucle for per récorrer les files de la matriu.
	for(int i = 0; i < N; i++){

		// Inicialitzem una variable element que guardarà el valor de l'element de la diagonal, i una variable suma que guardarà la suma de la resta d'elements
		float element = fabs(M[i][i]);
		float suma = 0.0;

		// Utilitzem un altre bucle for per récorrer cada element de la fila de la matriu
		for(int j = 0; j < N; j++){

			// Si els índexs no coincideixen (per tant, tots els elements excepte l'element de la diagonal), sumem el valor absolut al sumatori prèviament creat.
			if (j != i){
				suma += fabs(M[i][j]);
			}
		}

		// Si la suma de la resta d'elements de la fila és major que l'element diagonal, retornem 0 (no és diagonal dominant). Es deixa d'executar el bucle.
		if (suma > element){
			return 0;
		}
	}

	// Si el bucle s'acaba i tots els elements diagonals són major que les sumes de la resta d'elements, vol dir que és diagonal dominant i retornem 1.
	return 1;
}

//------------------------------------------------------------------------
// EXERCICI 12: Multiplicació d'una matriu per un vector

// Definim la funció Matriu_x_Vector com un void, no retornarà cap valor.
// Incloem 3 paràmetres: M i vect són la matriu i el vector a multiplicar; i vectres és el vector resultat de l'operació,
void Matriu_x_Vector( float M[N][N], float vect[N], float vectres[N] ){

	// Incialitzem una variable que calcularà el producte escalar de cada fila de la matriu amb el vector.
	float prod_escalar;

	// Utilitzem un bucle for per recórrer les files de la matriu.
	for (int i = 0; i < N; i++ ){

		// Calculem el producte escalar de la fila i de la matriu amb el vector. Modifiquem l'element i del vector resultat pel producte escalar calculat.
		prod_escalar = Scalar(M[i], vect);
		vectres[i] = prod_escalar;
	}
}

//------------------------------------------------------------------------
// EXERCICI 13: Resolució de sistemes d'equacions lineals amb el mètode de Jacobi

// Definim la funció Jacobi com un int, retornarà 1 si es pot realitzar el procediment i 0 si no.
// Incloem 4 paràmetres: M i vect que són la matriu i el vector donats; vectres és el vector a calcular; i iter és el nombre d'iteracions del mètode.
int Jacobi(float M[N][N] , float vect[N], float vectres[N], unsigned iter){

	// Primer mirem si la matriu és diagonal dominant. Si ho és, retorna 1 i s'executa el mètode; si no ho és, no s'executa.
	int retorn = DiagonalDom(M);

	if (retorn == 1){

		// Utilitzem un bucle for per realitzar el mètode el número de vegades que es vol iterar.
		for ( int k=0; k<iter; k++){

			// Utilitzem un altre bucle for per recórrer les files de la matriu.
			for ( int i=0; i<N; i++){

				// Inicialitzem una variable suma per guardar la suma de l'element de la matriu per l'element del vector resultat.
				float suma = 0.0;

				// Utilitzem un altre bucle for per recórrer els elements de les files de la matriu.
				for ( int j=0; j<N; j++){

					// Si no és l'element diagonal, afegeix a la suma el producte de l'element de la matriu per l'element del vector resultat corresponent.
					if (i != j){
						suma += M[i][j]*vectres[j];
					}
				}

				// Un cop recorreguda la fila, guarda l'operació corresponent a l'element del vector resultant.
				vectres[i] = (vect[i] - suma) / M[i][i];
			}
		}
	}
	// Retornem 1 si es pot aplicar el mètode de Jacobi i 0 si no.
	return retorn;
}

//------------------------------------------------------------------------
// PUNT EXTRA: Precisió del mètode de Jacobi

// Definim la funció Precisio com un float, que retornarà el valor de la precisió.
// Incloem 3 paràmetres: M i vectB són la matriu i el vector donats per realitzar el mètode de Jacobi; i vectX_aprox és el vector resultat donat en el mètode de Jacobi.
float Precisio(float M[N][N], float vectX_aprox[N], float vectB[N]){

	// Creem un nou vector que és l'aproximació del vector B.
	float vectB_aprox[N];

	// Fem la multiplicació de la matriu M per l'aproximació del vector X, i obtenim els valors de l'aproximació del vector B.
	Matriu_x_Vector(M, vectX_aprox, vectB_aprox);

	// Inicialitzem un vector que serà la diferència dels vectors B_aprox i B. Utilitzem un bucle for per recórrer tots els elements dels vectors i guardem la diferència en l'element i del vector de diferències.
	float diferencia_vectorsB[N];
	for (int i = 0; i < N; i++){
		diferencia_vectorsB[i] = vectB_aprox[i] - vectB[i];
	}

	// Inicialitzem un vector resultat que serà la magnitud del vector de diferències de B i B_aprox
	float resultat = Magnitude(diferencia_vectorsB);

	// Retornem el resultat obtingut.
	return resultat;

}

//------------------------------------------------------------------------
// MAIN: Execució de les diferents proves demanades

int main(){

	// Executem InitData per generar els vectors V1, V2, V3 i les matrius Mat i MatDD
	InitData();


	// En les diferents proves, s'apliquen les funcions prèviament programades pels casos demanats. S'utilitza printf per mostrar els resultats en alguns casos i millorar la llegibilitat en general.
	// També s'utilitza l'estructura if en les proves D, G i K per obtenir els resultats.

	// PROVA A
	printf("PROVA A\n");
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
	PrintRow(MatDD, 100, 95, 10);


	// PROVA D
	printf("\nProva D\n");

	float Infininorma_Mat = Infininorm(Mat);
	float Norma_u_Mat = Onenorm(Mat);
	float NFrobenius_Mat = NormFrobenius(Mat);
	int DiagoDom_Mat = DiagonalDom(Mat);

	printf("Infininorma de Mat = %f",Infininorma_Mat);
	printf("\nNorma ú de Mat = %f",Norma_u_Mat);
	printf("\nNorma de Frobenius de Mat = %f",NFrobenius_Mat);

	if (DiagoDom_Mat == 1){
		printf("\nLa matriu Mat és diagonal dominant\n");
	}else{
		printf("\nLa matriu Mat no és diagonal dominant\n");
	}

	float Infininorma_MatDD = Infininorm(MatDD);
        float Norma_u_MatDD = Onenorm(MatDD);
        float NFrobenius_MatDD = NormFrobenius(MatDD);
        int DiagoDom_MatDD = DiagonalDom(MatDD);

	printf("\nInfininorma de MatDD = %f",Infininorma_MatDD);
        printf("\nNorma ú de MatDD = %f",Norma_u_MatDD);
        printf("\nNorma de Frobenius de MatDD = %f",NFrobenius_MatDD);

        if (DiagoDom_MatDD == 1){
                printf("\nLa matriu MatDD és diagonal dominant\n");
        }else{
                printf("\nLa matriu MatDD no és diagonal dominant\n");
	}


	// PROVA E
	printf("\nProva E\n");
	float escalar_v1_v2 = Scalar(V1,V2);
	float escalar_v1_v3 = Scalar(V1,V3);
	float escalar_v2_v3 = Scalar(V2,V3);

	printf("Escalar <V1,V2> = %f",escalar_v1_v2);
	printf(" Escalar <V1,V3> = %f",escalar_v1_v3);
	printf(" Escalar <V2,V3> = %f\n",escalar_v2_v3);


	// PROVA F
	printf("\nProva F\n");
	float magnitud_v1 = Magnitude(V1);
	float magnitud_v2 = Magnitude(V2);
	float magnitud_v3 = Magnitude(V3);

	printf("Magnitud V1, V2 i V3 = %f %f %f\n",magnitud_v1, magnitud_v2, magnitud_v3);


	// PROVA G
	printf("\nProva G\n");
	float ortogonal_v1_v2 = Ortogonal(V1,V2);
	float ortogonal_v1_v3 = Ortogonal(V1,V3);
	float ortogonal_v2_v3 = Ortogonal(V2,V3);

	if (ortogonal_v1_v2 == 1){
		printf("V1 i V2 són ortogonals\n");
	}
	if (ortogonal_v1_v3 == 1){
		printf("V1 i V3 són ortogonals\n");
	}
	if (ortogonal_v2_v3 == 1){
		printf("V2 i V3 són ortogonals\n");
	}


	// PROVA H
	printf("\nProva H\n");

	float vectres3[N];
	MultEscalar(V3,vectres3,2.0);

	printf("Els elements 0 al 9 i 256 al 265 del resultat de multiplicar V3x2.0 són:\n");
	PrintVect(vectres3,0,10);
	PrintVect(vectres3,256,10);


	// PROVA I
	printf("\nProva I\n");

	float proj_v2_v3[N];
	float proj_v1_v2[N];

	Projection(V2,V3,proj_v2_v3);
	Projection(V1,V2,proj_v1_v2);

	printf("Els elements 0 a 9 del resultat de la projecció de V2 sobre V3 són:\n");
	PrintVect(proj_v2_v3,0,10);
	printf("Els elements 0 a 9 del resultat de la projecció de V1 sobre V2 són:\n");
	PrintVect(proj_v1_v2,0,10);


	// PROVA J
	printf("\nProva J\n");

	float mult_Mat_v2[N];

	Matriu_x_Vector(Mat,V2,mult_Mat_v2);
	printf("Els elements 0 a 9 del resultat de la multiplicació de Mat per v2 són:\n");
	PrintVect(mult_Mat_v2,0,10);


	// PROVA K
	printf("\nProva K\n");

	float resultat_1_iter[N];
	float resultat_1000_iter[N];
	float resultat_Mat[N];

	int aplicable_1_iter = Jacobi(MatDD,V3,resultat_1_iter,1);
	int aplicable_1000_iter = Jacobi(MatDD,V3,resultat_1000_iter,1000);
	int aplicable_Mat = Jacobi(Mat,V3,resultat_Mat,1);

	if (aplicable_1_iter == 0){
		printf("La matriu DD no és diagonal dominant, no es pot aplicar Jacobi\n");
	}else{
		printf("Els elements 0 a 9 de la solució (1 iter) del sistema d'equacions són:\n");
		PrintVect(resultat_1_iter,0,10);
	}

	if (aplicable_1000_iter == 0){
		printf("La matriu DD no és diagonal dominant, no es pot aplicar Jacobi\n");
        }else{
                printf("Els elements 0 a 9 de la solució (1000 iter) del sistema d'equacions són:\n");
                PrintVect(resultat_1000_iter,0,10);
	}

	if (aplicable_Mat == 0){
                printf("La matriu M no és diagonal dominant, no es pot aplicar Jacobi\n");
        }else{
                printf("Els elements 0 a 9 de la solució (1 iter) del sistema d'equacions són:\n");
                PrintVect(resultat_Mat,0,10);
	}

	// PUNT EXTRA
	printf("\nPunt extra\n");
	float precisio_1_iter = Precisio(MatDD, resultat_1_iter, V3);
	float precisio_1000_iter = Precisio(MatDD, resultat_1000_iter, V3);

	printf("La precisió del mètode de Jacobi amb 1 iteració de la prova K és de %f\n", precisio_1_iter);
	printf("La precisió del mètode de Jacobi amb 1000 iteracions de la prova K és de %f\n", precisio_1000_iter);
}


