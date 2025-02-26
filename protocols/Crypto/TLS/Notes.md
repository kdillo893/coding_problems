# Transport Layer Security
https://nvlpubs.nist.gov/nistpubs/SpecialPublications/NIST.SP.800-52r2.pdf

TLS is for securing transmission of data on the transport layer of data transmission.

TLS Versions:
1.2: https://www.rfc-editor.org/info/rfc5246
1.3: https://www.rfc-editor.org/info/rfc8446

## What to make?
TLSClient
TLSServer

TLS Server is running with socket receiving requests,
TLS Client makes request over network to that server (handshake start),

Common things between each:
* Handshake Protocol (see section 4 of 1.3 standard)
* Record Protocol (see section 5 of 1.3 standard)
* Alert Protocol (see section 6 of 1.3 standard)
* Cryptographic computation functions (see section 7 of 1.3 standard)

