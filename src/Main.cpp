#include "NoEntiendo.hpp"

void main()
{
	NOE_Inicia();
	
	while(!NOE_ObtenTeclaPulsada(NOE_TECLA_ESCAPE))
	{
	
		NOE_Actualiza();
		
		
		NOE_LimpiaPantalla(0, 0, 0);
		
		
		NOE_MuestraPantalla();
	}
	
	NOE_Finaliza();
}