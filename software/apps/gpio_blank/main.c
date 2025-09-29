#include "nrf.h"
#include "nrf_delay.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"
#include "nrf_pwr_mgmt.h"
#include "nrf_serial.h"

#include "buckler.h"
#include "gpio.h"

int main(void) {
  ret_code_t error_code = NRF_SUCCESS;

  // initialize RTT library
  error_code = NRF_LOG_INIT(NULL);
  APP_ERROR_CHECK(error_code);
  NRF_LOG_DEFAULT_BACKENDS_INIT();
  printf("Log initialized!\n");
  
  uint32_t* outSetPtr = (uint32_t *) 0x50000508;
  uint32_t* outClrPtr = (uint32_t *) 0x5000050C;
  uint32_t* cnfPtr = (uint32_t *) 0x50000700;
  
  //printf("%X\n%X\n%X\n", outSetPtr, outClrPtr, cnfPtr);

  uint32_t* gpio23Ptr = (uint32_t *) 0x5000075C;
  uint32_t* gpio24Ptr = (uint32_t *) 0x50000760;
  uint32_t* gpio25Ptr = (uint32_t *) 0x50000764;

  *gpio23Ptr = 1;
  *gpio24Ptr = 1;
  *gpio25Ptr = 1;

  // loop forever
  while (1) {

    *outClrPtr = 1<<25;
    
    nrf_delay_ms(500);

    // *outSetPtr = 1 << 25;
    // nrf_delay_ms(500);
    // *outSetPtr = 1 << 24; 
    //sleep(3);
    // *outClrPtr = 1 << 8;

    //*gpio23Ptr = 1<<8;
    //*gpio24Ptr = 1<<8;
    //*gpio25Ptr = 1<<8;
  }
}
