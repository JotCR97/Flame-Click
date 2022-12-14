//Permitir el uso de printf() con Serial para iniciar sesión.
#include "log.h"
//Libreria MIKROE Flame Click
#include "flame.h"

    //VARIABLES
static flame_t flame;
static log_t logger;

static uint8_t flame_state = 0;
static uint8_t flame_state_old = 1;

    //FUNCIONES DE LA APLICACIÓN
void setup() {  
    log_cfg_t log_cfg;
    flame_cfg_t cfg;
    
    LOG_MAP_USB_UART( log_cfg );
    log_init( &logger, &log_cfg );
    log_info(&logger, "---- Inicialización de la aplicación ----");

    //  Haga clic en inicialización.
    flame_cfg_setup( &cfg );
    FLAME_MAP_MIKROBUS( cfg, MIKROBUS_1 );
    flame_init( &flame, &cfg );
}


    //  Implementación de tareas.
void application_task ( void )
{
    //  Estado del sensor
    
    flame_state = flame_check_status ( &flame );

    //  Si el estado devuelve 1, el sensor detecto fuego 
    if ( ( flame_state == 1 ) && ( flame_state_old == 0) )
    {
        log_printf( &logger, "  ~  C   ~ \r\n " );
       
        flame_state_old = 1;
    }
    
    //  Si el estado devuelve 0, no se esta detectando fuego
    if ( ( flame_state == 0 ) && ( flame_state_old == 1 ) )
    {
        log_printf( &logger, "   SIN LLAMA  \r\n " );
        flame_state_old = 0;
    }
}

void loop() {
      application_task(); 
    delay(1);  // Retraso entre lecturas para la estabilidad
}

