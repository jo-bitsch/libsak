# Discovery in paring mode

The mobile phone running AusweisApp2 in SaK mode will regularly (about every second) announce its presence via UDP broadcast to port `24727`.

Given a phone with the name "my Android phone", that is providing the service on port 41775, the content of the UDP message is the following:
```
{
    "IFDID":"-----BEGIN CERTIFICATE-----\\nMIIC6TCCAdECCBZLrQQkNFD3MA0GCSqGSIb3DQEBCwUAMDUxFDASBgNVBAMMC0F1\\nc3dlaXNBcHAyMR0wGwYDVQQFExQxMTU4MDQ1OTY1NTI4MjEzNzEzMzAiGA8xOTcw\\nMDEwMTAwMDAwMFoYDzk5OTkxMjMxMjM1OTU5WjA1MRQwEgYDVQQDDAtBdXN3ZWlz\\nQXBwMjEdMBsGA1UEBRMUMTE1ODA0NTk2NTUyODIxMzcxMzMwggEiMA0GCSqGSIb3\\nDQEBAQUAA4IBDwAwggEKAoIBAQDm9NbQBWyADlNBVjFiMOd8PHEkcZR7Vk7ksbus\\nCbNZ2+BHNwBbou1bx2zmIILygKmR6+EvgMUBQeJa7vlYgvI5B/I80W4a+hd29h/l\\nbReygKRiE5X210KwMTiuad3xHsaW0CeDGaxrgmHFuXMXyotKE60k+EEPCnjebK0G\\ntzzkVu/kYgw394u+9PHCbhIA8NL/FYO1ZJRq+rw0pK94FbSQcqyECkCrIN5+VAp1\\nvAn1tKt+t3LMO1dBRBgx6+eCxSKkMd7Zg4ZxmIWdIAnxyac9V0/Q97DIxC/+oysO\\np5yD8gFT4Mhu3o81SxsLoWKa0lcJpV0kPiRvQ2u5GoVu4GtjAgMBAAEwDQYJKoZI\\nhvcNAQELBQADggEBADXFCRSSanUCb1BayoD3oqZF855mkucqbIMxltquQFkO+l6Z\\ndzYMHAG1vFe/CtH3hA2erNHLyI/d2sb0PIe46JE0x+svRiiWjEMJTlvj0G16dM1A\\nCIloCZ6QYgL/sszZPsmS6gAxPHVsA9yMVAFe/in263VR8lAvtGy+jra8EvBJNLHp\\n3yra+HoEJejyA4NI1RXWBd9DJr/l9QooAxEyVtUVczpCt2WzvFGqvOX+5Yaqz33j\\nBSeknAiWtJA4sLVzGydDvRsTug/+01UiJcNrHyLuLSiYxTqCiNjKkD81M5DfAecE\\nCDfZWWnyhmVDoNmJD0gc3HGMQ69EBg/eCPpsqOU=\\n-----END CERTIFICATE-----\\n",
    "IFDName":"my Android phone",
    "SupportedAPI":["IFDInterface_WebSocket_v0",     "IFDInterface_WebSocket_v2"],
    "msg":"REMOTE_IFD",
    "pairing":true,
    "port":41775
}

```
Only added newlines for readability.

## having a look at it
```
socat -v -u udp-recv:24727 open:/tmp/test,create,append
```

dissecting the certificate results in:
```
$ echo -e "$(echo "-----BEGIN CERTIFICATE-----\\nMIIC6TCCAdECCBZLrQQkNFD3MA0GCSqGSIb3DQEBCwUAMDUxFDASBgNVBAMMC0F1\\nc3dlaXNBcHAyMR0wGwYDVQQFExQxMTU4MDQ1OTY1NTI4MjEzNzEzMzAiGA8xOTcw\\nMDEwMTAwMDAwMFoYDzk5OTkxMjMxMjM1OTU5WjA1MRQwEgYDVQQDDAtBdXN3ZWlz\\nQXBwMjEdMBsGA1UEBRMUMTE1ODA0NTk2NTUyODIxMzcxMzMwggEiMA0GCSqGSIb3\\nDQEBAQUAA4IBDwAwggEKAoIBAQDm9NbQBWyADlNBVjFiMOd8PHEkcZR7Vk7ksbus\\nCbNZ2+BHNwBbou1bx2zmIILygKmR6+EvgMUBQeJa7vlYgvI5B/I80W4a+hd29h/l\\nbReygKRiE5X210KwMTiuad3xHsaW0CeDGaxrgmHFuXMXyotKE60k+EEPCnjebK0G\\ntzzkVu/kYgw394u+9PHCbhIA8NL/FYO1ZJRq+rw0pK94FbSQcqyECkCrIN5+VAp1\\nvAn1tKt+t3LMO1dBRBgx6+eCxSKkMd7Zg4ZxmIWdIAnxyac9V0/Q97DIxC/+oysO\\np5yD8gFT4Mhu3o81SxsLoWKa0lcJpV0kPiRvQ2u5GoVu4GtjAgMBAAEwDQYJKoZI\\nhvcNAQELBQADggEBADXFCRSSanUCb1BayoD3oqZF855mkucqbIMxltquQFkO+l6Z\\ndzYMHAG1vFe/CtH3hA2erNHLyI/d2sb0PIe46JE0x+svRiiWjEMJTlvj0G16dM1A\\nCIloCZ6QYgL/sszZPsmS6gAxPHVsA9yMVAFe/in263VR8lAvtGy+jra8EvBJNLHp\\n3yra+HoEJejyA4NI1RXWBd9DJr/l9QooAxEyVtUVczpCt2WzvFGqvOX+5Yaqz33j\\nBSeknAiWtJA4sLVzGydDvRsTug/+01UiJcNrHyLuLSiYxTqCiNjKkD81M5DfAecE\\nCDfZWWnyhmVDoNmJD0gc3HGMQ69EBg/eCPpsqOU=\\n-----END CERTIFICATE-----\\n")" | openssl x509 -noout -text
Certificate:
    Data:
        Version: 1 (0x0)
        Serial Number: 1606567925386596599 (0x164bad04243450f7)
        Signature Algorithm: sha256WithRSAEncryption
        Issuer: CN = AusweisApp2, serialNumber = 11580459655282137133
        Validity
            Not Before: Jan  1 00:00:00 1970 GMT
            Not After : Dec 31 23:59:59 9999 GMT
        Subject: CN = AusweisApp2, serialNumber = 11580459655282137133
        Subject Public Key Info:
            Public Key Algorithm: rsaEncryption
                Public-Key: (2048 bit)
                Modulus:
                    00:e6:f4:d6:d0:05:6c:80:0e:53:41:56:31:62:30:
                    e7:7c:3c:71:24:71:94:7b:56:4e:e4:b1:bb:ac:09:
                    b3:59:db:e0:47:37:00:5b:a2:ed:5b:c7:6c:e6:20:
                    82:f2:80:a9:91:eb:e1:2f:80:c5:01:41:e2:5a:ee:
                    f9:58:82:f2:39:07:f2:3c:d1:6e:1a:fa:17:76:f6:
                    1f:e5:6d:17:b2:80:a4:62:13:95:f6:d7:42:b0:31:
                    38:ae:69:dd:f1:1e:c6:96:d0:27:83:19:ac:6b:82:
                    61:c5:b9:73:17:ca:8b:4a:13:ad:24:f8:41:0f:0a:
                    78:de:6c:ad:06:b7:3c:e4:56:ef:e4:62:0c:37:f7:
                    8b:be:f4:f1:c2:6e:12:00:f0:d2:ff:15:83:b5:64:
                    94:6a:fa:bc:34:a4:af:78:15:b4:90:72:ac:84:0a:
                    40:ab:20:de:7e:54:0a:75:bc:09:f5:b4:ab:7e:b7:
                    72:cc:3b:57:41:44:18:31:eb:e7:82:c5:22:a4:31:
                    de:d9:83:86:71:98:85:9d:20:09:f1:c9:a7:3d:57:
                    4f:d0:f7:b0:c8:c4:2f:fe:a3:2b:0e:a7:9c:83:f2:
                    01:53:e0:c8:6e:de:8f:35:4b:1b:0b:a1:62:9a:d2:
                    57:09:a5:5d:24:3e:24:6f:43:6b:b9:1a:85:6e:e0:
                    6b:63
                Exponent: 65537 (0x10001)
    Signature Algorithm: sha256WithRSAEncryption
    Signature Value:
        35:c5:09:14:92:6a:75:02:6f:50:5a:ca:80:f7:a2:a6:45:f3:
        9e:66:92:e7:2a:6c:83:31:96:da:ae:40:59:0e:fa:5e:99:77:
        36:0c:1c:01:b5:bc:57:bf:0a:d1:f7:84:0d:9e:ac:d1:cb:c8:
        8f:dd:da:c6:f4:3c:87:b8:e8:91:34:c7:eb:2f:46:28:96:8c:
        43:09:4e:5b:e3:d0:6d:7a:74:cd:40:08:89:68:09:9e:90:62:
        02:ff:b2:cc:d9:3e:c9:92:ea:00:31:3c:75:6c:03:dc:8c:54:
        01:5e:fe:29:f6:eb:75:51:f2:50:2f:b4:6c:be:8e:b6:bc:12:
        f0:49:34:b1:e9:df:2a:da:f8:7a:04:25:e8:f2:03:83:48:d5:
        15:d6:05:df:43:26:bf:e5:f5:0a:28:03:11:32:56:d5:15:73:
        3a:42:b7:65:b3:bc:51:aa:bc:e5:fe:e5:86:aa:cf:7d:e3:05:
        27:a4:9c:08:96:b4:90:38:b0:b5:73:1b:27:43:bd:1b:13:ba:
        0f:fe:d3:55:22:25:c3:6b:1f:22:ee:2d:28:98:c5:3a:82:88:
        d8:ca:90:3f:35:33:90:df:01:e7:04:08:37:d9:59:69:f2:86:
        65:43:a0:d9:89:0f:48:1c:dc:71:8c:43:af:44:06:0f:de:08:
        fa:6c:a8:e5
```

We notice, this is:
* a RSA2048 key with a sha256 hash
* self signed
* the subject contains a serial number, not sure how random that is
* the validity period is basically unlimited


# Pairing

We need to establish an TLS connection to the device using a PSK cipher. The PSK is a 4 digit code, that is displayed on the smart phone screen.

The minimum supported cipher is:
[`TLS_RSA_PSK_WITH_AES_256_CBC_SHA`](https://ciphersuite.info/cs/TLS_RSA_PSK_WITH_AES_256_CBC_SHA/) With both sides using certificates. (so the linux machine uses a client certificate.)

Inside that channel, we SHOULD establish a WebSocket connection and send the following payload, as JSON:
```
{
  "msg": "IFDEstablishContext",
  "Protocol": "IFDInterface_WebSocket_v2",
  "UDName": "my linux machine"
}
```

we are expecting an answer:
```
{
"msg": "IFDEstablishContextResponse",
"ContextHandle" : <string>,
"ResultMajor": <string>,
"ResultMinor": <string>,
"IFDName": "my Android phone"
}
```

Afterwards, we close the connection, as the actual connection should not be established via a PSK cipher.

## Why this initial exchange?
This allows the phone to also have a human readable display name, for the linux machine.

# Discovery in non-pairing mode

the only difference is the `"pairing":false` key.

```
{
    "IFDID":"-----BEGIN CERTIFICATE-----\\nMIIC6TCCAdECCBZLrQQkNFD3MA0GCSqGSIb3DQEBCwUAMDUxFDASBgNVBAMMC0F1\\nc3dlaXNBcHAyMR0wGwYDVQQFExQxMTU4MDQ1OTY1NTI4MjEzNzEzMzAiGA8xOTcw\\nMDEwMTAwMDAwMFoYDzk5OTkxMjMxMjM1OTU5WjA1MRQwEgYDVQQDDAtBdXN3ZWlz\\nQXBwMjEdMBsGA1UEBRMUMTE1ODA0NTk2NTUyODIxMzcxMzMwggEiMA0GCSqGSIb3\\nDQEBAQUAA4IBDwAwggEKAoIBAQDm9NbQBWyADlNBVjFiMOd8PHEkcZR7Vk7ksbus\\nCbNZ2+BHNwBbou1bx2zmIILygKmR6+EvgMUBQeJa7vlYgvI5B/I80W4a+hd29h/l\\nbReygKRiE5X210KwMTiuad3xHsaW0CeDGaxrgmHFuXMXyotKE60k+EEPCnjebK0G\\ntzzkVu/kYgw394u+9PHCbhIA8NL/FYO1ZJRq+rw0pK94FbSQcqyECkCrIN5+VAp1\\nvAn1tKt+t3LMO1dBRBgx6+eCxSKkMd7Zg4ZxmIWdIAnxyac9V0/Q97DIxC/+oysO\\np5yD8gFT4Mhu3o81SxsLoWKa0lcJpV0kPiRvQ2u5GoVu4GtjAgMBAAEwDQYJKoZI\\nhvcNAQELBQADggEBADXFCRSSanUCb1BayoD3oqZF855mkucqbIMxltquQFkO+l6Z\\ndzYMHAG1vFe/CtH3hA2erNHLyI/d2sb0PIe46JE0x+svRiiWjEMJTlvj0G16dM1A\\nCIloCZ6QYgL/sszZPsmS6gAxPHVsA9yMVAFe/in263VR8lAvtGy+jra8EvBJNLHp\\n3yra+HoEJejyA4NI1RXWBd9DJr/l9QooAxEyVtUVczpCt2WzvFGqvOX+5Yaqz33j\\nBSeknAiWtJA4sLVzGydDvRsTug/+01UiJcNrHyLuLSiYxTqCiNjKkD81M5DfAecE\\nCDfZWWnyhmVDoNmJD0gc3HGMQ69EBg/eCPpsqOU=\\n-----END CERTIFICATE-----\\n",
    "IFDName":"my Android phone",
    "SupportedAPI":["IFDInterface_WebSocket_v0",     "IFDInterface_WebSocket_v2"],
    "msg":"REMOTE_IFD",
    "pairing":false,
    "port":41775
}

```


# Communication

