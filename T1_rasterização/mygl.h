#ifndef MYGL_H
#define MYGL_H

#include "core.h"
#include <math.h>
#include "frame_buffer.h"

//Estruturas para configuração das cores RGBA e dos pixels
typedef struct cores_RGBA
{
	unsigned char r; //RED
	unsigned char g; //GREEN
	unsigned char b; //BLUE
	unsigned char a; //ALPHA
} rgba_s;

typedef struct pixel
{
	int x;
	int y;
} pixel_s;

// Declaração da função que chamará as funções de rasterização implementadas pelo aluno
void MyGlDraw(void);

rgba_s interp_linear(float, rgba_s, rgba_s);
float dist(pixel_s p1, pixel_s p2);

void PutPixel(pixel_s, rgba_s);
void DrawLine(pixel_s, pixel_s, rgba_s, rgba_s);
void DrawTriangle(pixel_s, pixel_s, pixel_s, rgba_s, rgba_s, rgba_s);

//
// >>> Declare aqui as funções que você implementar <<<
//


#endif  // MYGL_H
