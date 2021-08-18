#include <device.h>
#include <drivers/spi.h>

int spi_slave_read(const struct device *spi, struct spi_config *spi_cfg,
                   uint16_t *data) {
  struct spi_buf bufs = {.buf = data, .len = 2};
  struct spi_buf_set rx = {.buffers = &bufs};

  rx.count = 1;

  return spi_read(spi, spi_cfg, &rx);
}

int spi_slave_write(const struct device *spi, struct spi_config *spi_cfg,
                    uint16_t *data) {
  struct spi_buf bufs = {.buf = data, .len = 2};
  struct spi_buf_set tx = {.buffers = &bufs};

  tx.count = 1;

  return spi_write(spi, spi_cfg, &tx);
}

void main() {
  // Data to be exchanged
  uint16_t tx_data = 4;
  // uint16_t rx_data = 0;

  // Initialize SPI bus number 3
  const struct device *spi = device_get_binding("SPI_1");

  // SPI COnfiguration
  struct spi_config spi_cfg {
    .frequency = 3000000, .operation = SPI_WORD_SET(8) | SPI_OP_MODE_SLAVE
    // , .cs = &cs_ctrl
  };

  while (1) {
    // spi_slave_read(spi, &spi_cfg, &rx_data);
    spi_slave_write(spi, &spi_cfg, &tx_data);

    printk("Received:%d\n", (unsigned char)rx_data);
  }
}
