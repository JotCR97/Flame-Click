#line 2 "flame.ino"
#ifdef UNIT_TEST
 
test(toggleLed)
{
  if ( ( flame_state == 1 ) && ( flame_state_old == 0) )
  ledStatus = LOW;
  toggleLed();
  assertEqual(ledStatus, LOW); /*ERROR ¿Qué estás haciendo?*/

  if ( ( flame_state == 0 ) && ( flame_state_old == 1) ) 
  ledStatus = HIGH;
  toggleLed();
  assertEqual(ledStatus, LOW);
}
 
#endif
