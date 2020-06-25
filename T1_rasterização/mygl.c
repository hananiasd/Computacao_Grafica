#include "mygl.h"

//
// >>> Defina aqui as funções que você implementar <<< 
//


rgba_s interp_linear(float p, rgba_s cor1, rgba_s cor2){ //p é a porcentagem da distancia que ainda falta até chegar ao ponto final
	rgba_s cor;
	cor.r = cor1.r*p + (1-p)*cor2.r;
	cor.g = cor1.g*p + (1-p)*cor2.g;
	cor.b = cor1.b*p + (1-p)*cor2.b;
	cor.a = cor1.a*p + (1-p)*cor2.a;

	return cor;
}

float dist(pixel_s p1, pixel_s p2){ //calcula a distancia entre dois pontos
	return sqrt(pow(p2.x-p1.x, 2) + pow(p2.y-p1.y, 2));
}

void PutPixel(pixel_s pixel, rgba_s cores){
	//posição dos pixels
	int pos = pixel.x*4 + pixel.y*4*IMAGE_WIDTH;

	fb_ptr[pos++] = cores.r;
	fb_ptr[pos++] = cores.g;
	fb_ptr[pos++] = cores.b;
	fb_ptr[pos] = cores.a;
}

void DrawLine(pixel_s px1, pixel_s px2, rgba_s cor1, rgba_s cor2){
	int dx = px2.x - px1.x;
	int dy = px2.y - px1.y;
	int inclin;

	float dist_Parcial;
	float dist_Total = dist(px1, px2);
	float dist_Restante;
	//Se o ponto final for menor que o ponto inicial
	if(dx < 0){
		DrawLine(px2, px1, cor2, cor1);
		return;
	}

	if(dy < 0)
		inclin = -1;
	else
		inclin = 1;
	//variavel de decisão para o teste do ponto médio
	int d; 

	pixel_s pixel = px1;
	rgba_s cor = cor1;
	PutPixel(px1, cor1);
	if(dx >= inclin*dy){ //m <= 1
		if(dy < 0){
			d = 2 * (dx+dy);
			while(pixel.x < px2.x){
				if(d < 0){
					d += 2 * (dy+dx);
					pixel.x++;
					pixel.y--;
				}
				else{
					d += 2*dy;
					pixel.x++;
				}
				dist_Parcial = dist(pixel, px2);
				dist_Restante = (dist_Parcial/dist_Total);
				cor = interp_linear(dist_Restante, cor1, cor2);
				PutPixel(pixel, cor);

			}
		}
		else{
			d = 2 * (dy-dx);
			while(pixel.x < px2.x){
				if(d < 0){
					d += 2 * dy;
					pixel.x++;
				}
				else{
					d += 2 * (dy-dx);
					pixel.x++;
					pixel.y++;
				}
				dist_Parcial = dist(pixel, px2);
				dist_Restante = (dist_Parcial/dist_Total);
				cor = interp_linear(dist_Restante, cor1, cor2);
				PutPixel(pixel, cor);
			}
		}
	}
	else{ //m > 1
		if(dy < 0){
			d = dy + 2*dx;
			while(pixel.y > px2.y){
				if(d < 0){
					d += 2 * (dy+dx);
					pixel.x++;
					pixel.y--;
				}
				dist_Parcial = dist(pixel, px2);
				dist_Restante = (dist_Parcial/dist_Total);
				cor = interp_linear(dist_Restante, cor1, cor2);
				PutPixel(pixel, cor);
			}
		}
		else{
			d = dy - 2*dx;
			while(pixel.y < px2.y){
				if(d < 0){
					d += 2 * (dy-dx);
					pixel.x++;
					pixel.y++;
				}
				else{
					d += -2*dx;
					pixel.y++;
				}
				dist_Parcial = dist(pixel, px2);
				dist_Restante = (dist_Parcial/dist_Total);
				cor = interp_linear(dist_Restante, cor1, cor2);
				PutPixel(pixel, cor);
			}
		}
	}

PutPixel(px2, cor2);


}	

void DrawTriangle(pixel_s px1, pixel_s px2, pixel_s px3, rgba_s cor1, rgba_s cor2, rgba_s cor3){
	DrawLine(px1, px2, cor1, cor2);
	DrawLine(px2, px3, cor2, cor3);
	DrawLine(px3, px1, cor3, cor1);
}

// Definição da função que chamará as funções de rasterização implementadas pelo aluno
void MyGlDraw(void) {

    //
    // >>> Chame aqui as funções que você implementou <<<
    //
    pixel_s px1 = {60, 30};
    rgba_s cor1 = {255,   0,   0, 255};		//RED
    pixel_s px2 = {256, 256};
    rgba_s cor2 = {0,   255,   0, 255};		//GREEN
    pixel_s px3 = {180, 30}; 
    rgba_s cor3 = {0,   0,   255, 255};		//BLUE
    pixel_s px4 = {500, 485};
    rgba_s cor4 = {255,   255,   255, 255};	//WHITE
    pixel_s px5 = {295, 350};
    rgba_s cor5 = {0,   128,   128, 255};	//RANDOM COLOR
    pixel_s px6 = {128, 450};
    rgba_s cor6 = {75,   45,   200, 255};	//RANDOM COLOR
    //Teste com a função PutPixel
    /*
    PutPixel(px1, cor1);
    PutPixel(px2, cor2);
    PutPixel(px3, cor3);
    PutPixel(px4, cor4);
    PutPixel(px5, cor5);
    PutPixel(px6, cor6);
	*/
    //Teste da função DrawLine
    /*
    DrawLine(px1, px2, cor1, cor2);
    DrawLine(px3, px4, cor3, cor4);
    DrawLine(px5, px6, cor5, cor6);
	*/

    //Teste da função DrawTriangle
    DrawTriangle(px1, px2, px3, cor1, cor2, cor3);
    DrawTriangle(px4, px5, px6, cor4, cor5, cor6);

    
}