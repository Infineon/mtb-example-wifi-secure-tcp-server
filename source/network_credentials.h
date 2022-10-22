/******************************************************************************
* File Name: network_credentials.h
*
* Description: This file is the public interface for Wi-Fi credentials and
* TCP server certificate.
*
* Related Document: See README.md
*
*******************************************************************************
* Copyright 2019-2022, Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
*
* This software, including source code, documentation and related
* materials ("Software") is owned by Cypress Semiconductor Corporation
* or one of its affiliates ("Cypress") and is protected by and subject to
* worldwide patent protection (United States and foreign),
* United States copyright laws and international treaty provisions.
* Therefore, you may use this Software only as provided in the license
* agreement accompanying the software package from which you
* obtained this Software ("EULA").
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software
* source code solely for use in connection with Cypress's
* integrated circuit products.  Any reproduction, modification, translation,
* compilation, or representation of this Software except as specified
* above is prohibited without the express written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
* reserves the right to make changes to the Software without notice. Cypress
* does not assume any liability arising out of the application or use of the
* Software or any product or circuit described in the Software. Cypress does
* not authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death ("High Risk Product"). By
* including Cypress's product in a High Risk Product, the manufacturer
* of such system or application assumes all risk of such use and in doing
* so agrees to indemnify Cypress against all liability.
*******************************************************************************/

/*******************************************************************************
* Include guard
*******************************************************************************/
#ifndef NETWORK_CREDENTIALS_H_
#define NETWORK_CREDENTIALS_H_

#include "cy_wcm.h"

/*******************************************************************************
* Macros
********************************************************************************/
#define INITIALISER_IPV4_ADDRESS(addr_var, addr_val)   addr_var = { CY_WCM_IP_VER_V4, \
                                                       { .v4 = (uint32_t)(addr_val) } }

#define MAKE_IPV4_ADDRESS(a, b, c, d)                  ((((uint32_t) d) << 24) | \
                                                       (((uint32_t) c) << 16) | \
                                                       (((uint32_t) b) << 8) | \
                                                       ((uint32_t) a))

/* To use the Wi-Fi device in AP interface mode, set this macro as '1' */
#define USE_AP_INTERFACE                               (0)

#if(USE_AP_INTERFACE)
    #define WIFI_INTERFACE_TYPE                        CY_WCM_INTERFACE_TYPE_AP
    /* SoftAP Credentials: Modify SOFTAP_SSID and SOFTAP_PASSWORD as required */
    #define SOFTAP_SSID                                "MY_SOFT_AP"
    #define SOFTAP_PASSWORD                            "psoc1234"

    /* Security type of the SoftAP. See 'cy_wcm_security_t' structure
     * in "cy_wcm.h" for more details.
     */
    #define SOFTAP_SECURITY_TYPE                       CY_WCM_SECURITY_WPA2_AES_PSK

    #define SOFTAP_IP_ADDRESS_COUNT                    (2u)

    #define SOFTAP_IP_ADDRESS                          MAKE_IPV4_ADDRESS(192, 168, 10, 1)
    #define SOFTAP_NETMASK                             MAKE_IPV4_ADDRESS(255, 255, 255, 0)
    #define SOFTAP_GATEWAY                             MAKE_IPV4_ADDRESS(192, 168, 10, 1)
    #define SOFTAP_RADIO_CHANNEL                       (1u)
#else
    #define WIFI_INTERFACE_TYPE                        CY_WCM_INTERFACE_TYPE_STA
    /* Wi-Fi Credentials: Modify WIFI_SSID, WIFI_PASSWORD, and WIFI_SECURITY_TYPE
     * to match your Wi-Fi network credentials.
     * Note: Maximum length of the Wi-Fi SSID and password is set to
     * CY_WCM_MAX_SSID_LEN and CY_WCM_MAX_PASSPHRASE_LEN as defined in cy_wcm.h file.
     */
    #define WIFI_SSID                                  "MY_WIFI_SSID"
    #define WIFI_PASSWORD                              "MY_WIFI_PASSWORD"

    /* Security type of the Wi-Fi access point. See 'cy_wcm_security_t' structure
     * in "cy_wcm.h" for more details.
     */
    #define WIFI_SECURITY_TYPE                         CY_WCM_SECURITY_WPA2_AES_PSK

    /* Maximum number of connection retries to a Wi-Fi network. */
    #define MAX_WIFI_CONN_RETRIES                      (10u)

    /* Wi-Fi re-connection time interval in milliseconds */
    #define WIFI_CONN_RETRY_INTERVAL_MSEC              (1000u)
#endif

/* TCP server certificate. Copy from the TCP server certificate
 * generated by OpenSSL (See Readme.md on how to generate a SSL certificate).
 */
#define keySERVER_CERTIFICATE_PEM \
"-----BEGIN CERTIFICATE-----\n"\
"MIIDZTCCAk2gAwIBAgIUPPtbVzaWQ4idal10Oqbo4Vu8vRkwDQYJKoZIhvcNAQEL\n"\
"BQAwQjELMAkGA1UEBhMCWFgxFTATBgNVBAcMDERlZmF1bHQgQ2l0eTEcMBoGA1UE\n"\
"CgwTRGVmYXVsdCBDb21wYW55IEx0ZDAeFw0yMjA5MTkwNDM5MjdaFw0yMzA5MTkw\n"\
"NDM5MjdaMEIxCzAJBgNVBAYTAlhYMRUwEwYDVQQHDAxEZWZhdWx0IENpdHkxHDAa\n"\
"BgNVBAoME0RlZmF1bHQgQ29tcGFueSBMdGQwggEiMA0GCSqGSIb3DQEBAQUAA4IB\n"\
"DwAwggEKAoIBAQDP6UHUHAZqezN4fk2cObpmpcfHjHeDJC2LeTRj9M10VuLyglft\n"\
"PMLl6JuE+NC8zDIreTFCW8sbXfXbsr2abGy4gU9Lak+KsMEHD9xWYIiG+UaHcT6K\n"\
"uayw1p23lUITNW4MGAkIfIzTUr9in9o5o5vX/YGDG1e3zZdnbjyGPmYmWCaICEEu\n"\
"PNVcjgWyJbJsLWWD1zWgGYfwRqdIGW27Dz8d+dNDrL4qWcj10TSdbLS91NEz2VN+\n"\
"qiGM04e1FiDzAshb3aru7Tc3YDgJ9C/BMJ2TEoHpxeMm6vowbp01mvrOAtCTPwFr\n"\
"LGUfkajOPl8uidSSTNABFjDo0grb0+lS9YWTAgMBAAGjUzBRMB0GA1UdDgQWBBTS\n"\
"WdG8cQyFcMIKcHv31zS6gVcgTDAfBgNVHSMEGDAWgBTSWdG8cQyFcMIKcHv31zS6\n"\
"gVcgTDAPBgNVHRMBAf8EBTADAQH/MA0GCSqGSIb3DQEBCwUAA4IBAQAfjgz09KG+\n"\
"9bZSzDgu3JotZDP5hqZfvUBPPjYgCEsX7OwilxMpFbybc3KAd2bLnNPMiJjBMgu/\n"\
"kN2QlPoUuGY6hM2dlEoWYr9BCZuEmELIublg5GXZVq1/R5ukeo7q3Zy64rihrYtv\n"\
"FKV3sx5ciEnEvlZWOdXwdxDpLDLAiW6t6ckUO8L+OFHq7BBHOu/XP3Xu4XX1w249\n"\
"W5vYFT7+qu0bMXnGEkCGgNghlrnxj0+jxd8fWU6OfAE0BJ7J6xglqAKHf2G3B81c\n"\
"ChsZMFBJ7wMKI2n/kFmc+HFAlkNR84d5fcU6w8nrCytq4RbiVd/zJGTFCW8K/KfZ\n"\
"Tp7CXJ/yJUQG\n"\
"-----END CERTIFICATE-----\n"

/* Private key of the TCP Server. Copy from the TCP server key 
 * generated by OpenSSL (See Readme.md on how to create a private key).
 */
#define keySERVER_PRIVATE_KEY_PEM \
"-----BEGIN PRIVATE KEY-----\n"\
"MIIEvgIBADANBgkqhkiG9w0BAQEFAASCBKgwggSkAgEAAoIBAQDP6UHUHAZqezN4\n"\
"fk2cObpmpcfHjHeDJC2LeTRj9M10VuLyglftPMLl6JuE+NC8zDIreTFCW8sbXfXb\n"\
"sr2abGy4gU9Lak+KsMEHD9xWYIiG+UaHcT6Kuayw1p23lUITNW4MGAkIfIzTUr9i\n"\
"n9o5o5vX/YGDG1e3zZdnbjyGPmYmWCaICEEuPNVcjgWyJbJsLWWD1zWgGYfwRqdI\n"\
"GW27Dz8d+dNDrL4qWcj10TSdbLS91NEz2VN+qiGM04e1FiDzAshb3aru7Tc3YDgJ\n"\
"9C/BMJ2TEoHpxeMm6vowbp01mvrOAtCTPwFrLGUfkajOPl8uidSSTNABFjDo0grb\n"\
"0+lS9YWTAgMBAAECggEBAM+2F6ATB43l27wrYtoLCmB2iyqe+N85i47l3iNmdMQf\n"\
"8ceZ1MIcjBIo2wZzlgaocg7gmwfSsQ18R53f6nCWld+WwGN1qFXE1HN7swNQmdVO\n"\
"wNmbl4H8kbxyDUtVgJe0L2dBs/SYihCtgKrFTL186LtWdsdGz9G/Qd2BUlJDkMYI\n"\
"ST94YUUVUikwzyqE62RvtttHTXR83WheNTtYNy82k8v4RnP6u2Uc9aw7vv8oH3ed\n"\
"V5jrCCgZOs6uL3wlNQmi4tIKpkChqfwt2H5XAhWriULB3a6k0BM5mSeG5EVbjaFJ\n"\
"hZkSRcDXd+P0Z/NVDOTz2B3TpsARHeSjDDzQErxOq7ECgYEA9c4rqY3OdbaaGLFP\n"\
"t0qf7XF/bv04RQk3AclgTwz4akazB/NeYKz2VT8cfHDM7B1+qos9+NBoM1Zl4arn\n"\
"u5Q0MgmrIvrl3etefIyDVkyrGJgl+WYxBTcW03L4iuMmC0D0w6m0vVxjLLb8yfwX\n"\
"uje5PpTlTRrX/qaGvI5MIfw+rbcCgYEA2Ii/EbyKlzzng6P9aMS/4v0+gchqCCGY\n"\
"NPfrBjy9njmAgt6BnodLfyBG3lb26xrzCXFFUsU2GnE65ZU9YdEaWDY6SYmhqg24\n"\
"0SiAxuNYvTQ/Sh31wq8w0s4CCGvPQG/N0HhO+N92iabVpprMPNeYSUkoFvZiPQcm\n"\
"Cmc5sODk5wUCgYEA71MCff58022r0XjqFZsJ5YTJP4Y6gDT9orawF6eYQtl9PLN+\n"\
"43/kA5IEKUEmtInvJxuVhilcGwf3AGaHY8Jjo4h4YQGKR6z//SJOSfsx5ytUZeRS\n"\
"vDIr/kqFpayOAQ0Ig207ddd7FDFCJWNWss/IhB8ytwT44o6+xt2BUOGpITcCgYBQ\n"\
"EoltmqY5dSk70enE03UOEI4L2jvzk9DATamYnd+U4ji2rGeMYwW1Fg9+6vPWTxnu\n"\
"tPdou0rdjl+0RHL1eCjg0/TL+txQkVB18B9m7O2E0gxRcTDPdI9+dPXlfVCfyHh4\n"\
"jfTOLXydPJenS3kZSrSi7S2pCCWd4cXcdP2tfgzHrQKBgEUMrOA14sh2empTpu6C\n"\
"ieHk3cpzhWqd45rwMlE27ZO1OehORYYz99ZWCyUEAssehjmvKKB0SidQb+gGDMS+\n"\
"Ep/YsWd6fUn0N5hiJ4jEK5HVs8jYRafMiOCx+O5t43LcEsdWva2G6tJgh5vjohBo\n"\
"9ljEt3iQSE1wtQ7v+GPMVedo\n"\
"-----END PRIVATE KEY-----\n"

/* TCP client certificate. In this example this is the RootCA
 * certificate so as to verify the TCP client's identity. */
#define keyCLIENT_ROOTCA_PEM \
"-----BEGIN CERTIFICATE-----\n"\
"MIIDZTCCAk2gAwIBAgIUCB3odAFJqqSzvarpsDycsXVAOlMwDQYJKoZIhvcNAQEL\n"\
"BQAwQjELMAkGA1UEBhMCWFgxFTATBgNVBAcMDERlZmF1bHQgQ2l0eTEcMBoGA1UE\n"\
"CgwTRGVmYXVsdCBDb21wYW55IEx0ZDAeFw0yMjA5MTkwNTA1MTBaFw0yMzA5MTkw\n"\
"NTA1MTBaMEIxCzAJBgNVBAYTAlhYMRUwEwYDVQQHDAxEZWZhdWx0IENpdHkxHDAa\n"\
"BgNVBAoME0RlZmF1bHQgQ29tcGFueSBMdGQwggEiMA0GCSqGSIb3DQEBAQUAA4IB\n"\
"DwAwggEKAoIBAQDUSCHIcQ/EmVPVVasxANetNVIyCmYruz2pP0dGHcMA8cp9YLV8\n"\
"FRg9SvPrGSvxMQBMfJc6dJJFm1SWARpkthPKCk9c0TZJHYiPysEI00TT1cHJZVwQ\n"\
"wv4+YwIoCHxGcBnskSuqF03S2d8F50GkORKBewe3PfeNSK0hG/nV0ysylZQFQc9w\n"\
"05E5v6mlXU5sDeCcXwgOeffiLMkcH5gIlqIy9ZUh+wie4LsQ74F8PML+nkW1a6Ce\n"\
"FvFbtJgxoqIVVswbNctfEs5cjU59T14V4VD4kpRZfYfatKMGr9q0the8virVohWb\n"\
"1d6Qf9rscmhwww5g1vyxCYjUb329OJw+neCHAgMBAAGjUzBRMB0GA1UdDgQWBBSd\n"\
"/own2dVyCfTtq8RLmC09d910gTAfBgNVHSMEGDAWgBSd/own2dVyCfTtq8RLmC09\n"\
"d910gTAPBgNVHRMBAf8EBTADAQH/MA0GCSqGSIb3DQEBCwUAA4IBAQBSN9hqUtgj\n"\
"6N6GAx5Ru7lLPlxmWw6nGHL6GtYrj878OPuxq9Sp81vpgoCFGQJB+XzbVZtiXIHq\n"\
"bu0ML2KbLFZi2xY6puCTFyz5dPz5JYkvHBkCM/nPb5miOui+ez+DLeRA9fiwoNZ9\n"\
"AYFXMR9EzYCvHmcBNqiVooUZkuORFg++mowZlgDjAJUhCYiK5VKHHdsAonADijUj\n"\
"cVra5iMNNVyGMMd3+j/0wS7MwSpEt9ckKRS+wxaGp+yvGbU/FL3+cy72tp1BuPt9\n"\
"ZixeFmgjizO5V7yNZbBL5+B3DdCAtMuYzMlyOBI4NRDr7YbZFsve1mXGkxjVpW4e\n"\
"7v9U5o9yVYgf\n"\
"-----END CERTIFICATE-----\n"


#endif /* NETWORK_CREDENTIALS_H_ */
