#include <SPI.h>
#include <PN532_SPI.h>
#include <PN532.h>
#include <NfcAdapter.h>

PN532_SPI pn532spi(SPI, 10);
NfcAdapter nfc = NfcAdapter(pn532spi);


if (nfc.tagPresent()) {
    NfcTag tag = nfc.read();
    tag.print();
}

if (nfc.tagPresent()) {
    NdefMessage message = NdefMessage();
    message.addTextRecord("Hello, Arduino!");
    success = nfc.write(message);
}

if (nfc.tagPresent()) {
    success = nfc.format();
}

if (nfc.tagPresent()) {
    success = nfc.clean();
}
