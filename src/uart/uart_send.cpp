#include <device.h>
#include <drivers/uart.h>
#include <stdio.h>

// int uart_send_bytes(const struct device *uart, const uint8_t *tx_data,
//                     size_t len, int32_t timeout) {

//   return uart_tx(uart, tx_data, len, timeout);
// }

void main() {
  // Data to be exchanged
  unsigned char test_char = '8';

  // UART 2 is reserved for the serial console
  const struct device *uart = device_get_binding("UART_2");

  // Initialize UART 1 [Pin 9:Tx, Pin 10: Rx]
  //   const struct device *uart = device_get_binding("UART_1");

  uint8_t data[8];
  for (int i = 0; i < 8; i++) {
    data[i] = 'x';
  }

  while (1) {

    // uart_poll_out(uart, test_char);

    int status = uart_tx(uart, data, sizeof(data), 1000);
    printf("Sent: %d\n", status);

    k_sleep(K_TIMEOUT_ABS_MS(250));
  }
}
