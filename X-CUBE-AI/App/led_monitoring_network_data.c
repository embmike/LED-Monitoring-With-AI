#include "led_monitoring_network_data.h"

ai_handle ai_led_monitoring_network_data_weights_get(void)
{

  AI_ALIGNED(4)
  static const ai_u8 s_led_monitoring_network_weights[ 1164 ] = {
    0x7e, 0x69, 0x6c, 0xbe, 0x98, 0x5f, 0x81, 0x3e, 0x82, 0x08,
    0x0e, 0xbe, 0x9b, 0x54, 0x81, 0xbe, 0x2c, 0x47, 0x40, 0xbe,
    0x88, 0xb6, 0x7d, 0xbd, 0x22, 0x91, 0xb1, 0xbd, 0x0c, 0x69,
    0x5a, 0x3e, 0xc2, 0x0f, 0x35, 0xbe, 0x16, 0x0f, 0x84, 0xbe,
    0x92, 0x66, 0x09, 0x3d, 0xef, 0x3b, 0x0e, 0x3e, 0x68, 0xb5,
    0x98, 0xbd, 0x09, 0x61, 0xe0, 0x3e, 0x50, 0x81, 0x24, 0x3d,
    0x1e, 0xf4, 0x9e, 0xbe, 0x82, 0xfa, 0x90, 0x3e, 0x63, 0x78,
    0x8f, 0x3b, 0x90, 0xbd, 0x12, 0xbe, 0x90, 0x88, 0x50, 0xbd,
    0x03, 0x77, 0x17, 0x3e, 0x37, 0xb8, 0xc1, 0xbd, 0x10, 0x7b,
    0x4a, 0xbe, 0x82, 0x2a, 0xe4, 0xbd, 0x91, 0x48, 0x13, 0x3e,
    0xb1, 0x27, 0x32, 0xbe, 0x65, 0xd6, 0xa9, 0xbe, 0xc0, 0x2f,
    0x21, 0xbe, 0x7b, 0x7f, 0x67, 0x3e, 0x9c, 0x0c, 0xa4, 0x39,
    0x53, 0xe5, 0xef, 0x3d, 0x51, 0xfe, 0x43, 0xbe, 0xc6, 0x2f,
    0xa3, 0x3e, 0x3d, 0xa1, 0xc5, 0xbe, 0xa0, 0x93, 0x0a, 0x3e,
    0xd7, 0xc1, 0xe6, 0x3e, 0x47, 0x1b, 0xd6, 0xbd, 0x14, 0x65,
    0x88, 0x3e, 0x48, 0x8d, 0x4e, 0xbe, 0x5e, 0xa6, 0x98, 0xbe,
    0x79, 0xf0, 0xed, 0x3d, 0xa0, 0x32, 0x5e, 0xbe, 0xa8, 0x03,
    0xa8, 0x3e, 0xfa, 0x6a, 0x79, 0xbc, 0x25, 0xd9, 0x0b, 0xbe,
    0xd9, 0xe4, 0x0b, 0x3e, 0x25, 0xe6, 0xb0, 0xbe, 0xf6, 0x73,
    0xa0, 0xbe, 0x14, 0xe4, 0xbe, 0x3e, 0x58, 0x07, 0x94, 0xbe,
    0x8d, 0xff, 0x97, 0xbe, 0x8f, 0x92, 0xf4, 0x3d, 0xf8, 0x16,
    0xcb, 0x3e, 0x57, 0x65, 0x49, 0xbe, 0x54, 0x07, 0xda, 0x3e,
    0x7e, 0xb8, 0x18, 0x3e, 0xdb, 0x76, 0x98, 0xbd, 0x98, 0x8f,
    0x8b, 0x3e, 0x35, 0xcb, 0xb0, 0x3d, 0xb6, 0x37, 0x98, 0x3d,
    0xb8, 0xc9, 0x67, 0x3e, 0x81, 0x4c, 0x67, 0xbe, 0xf1, 0x75,
    0x34, 0x3e, 0x41, 0x04, 0x9f, 0xbd, 0x50, 0x8c, 0xdc, 0xbd,
    0x72, 0x35, 0x87, 0xbe, 0x6a, 0x04, 0x2d, 0x3d, 0xf2, 0x4e,
    0x13, 0xbe, 0xb4, 0xee, 0xa8, 0xbd, 0x4e, 0x0c, 0x7b, 0xbe,
    0x73, 0x48, 0x8c, 0xbe, 0xd1, 0x32, 0x06, 0xbe, 0x52, 0x24,
    0x2a, 0xbe, 0x15, 0xf1, 0x2d, 0x3e, 0x07, 0x66, 0x9e, 0x3e,
    0x2f, 0x59, 0x30, 0x3e, 0xdb, 0x05, 0x8f, 0xbe, 0xf6, 0x02,
    0x8f, 0x3e, 0xe2, 0x34, 0x16, 0x3e, 0xf4, 0xa5, 0x82, 0xbe,
    0x1e, 0x00, 0x8b, 0x3e, 0xda, 0x9b, 0x29, 0xbd, 0x69, 0x3d,
    0x76, 0x3e, 0x1d, 0x9b, 0x92, 0x3d, 0xe1, 0x6e, 0x47, 0x3e,
    0x42, 0xcc, 0x4d, 0xbe, 0x2a, 0x4b, 0x81, 0xbe, 0x90, 0xc8,
    0xb4, 0xbd, 0xf1, 0xfd, 0x08, 0x3d, 0xcb, 0xd1, 0xcc, 0x3e,
    0xa9, 0x24, 0x41, 0x3d, 0xa3, 0x87, 0xaa, 0xbe, 0x52, 0x13,
    0x31, 0xbe, 0x42, 0x22, 0x74, 0x3e, 0x6a, 0xa1, 0xa1, 0xbe,
    0x15, 0x75, 0x33, 0x3e, 0xd6, 0xcf, 0xa3, 0xbc, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc8, 0x97, 0xc7, 0x3d,
    0x00, 0x00, 0x00, 0x00, 0x7f, 0x1f, 0x85, 0xbc, 0xb3, 0xe6,
    0xc1, 0x3d, 0x42, 0xb8, 0x50, 0xbd, 0xf4, 0xd2, 0xfd, 0x3c,
    0x00, 0x00, 0x00, 0x00, 0x1f, 0x61, 0xbf, 0x3d, 0x00, 0x00,
    0x00, 0x00, 0x6d, 0xd3, 0x5b, 0xbd, 0x00, 0x00, 0x00, 0x00,
    0x6f, 0x32, 0xbd, 0x3d, 0x59, 0xd7, 0x95, 0x3d, 0x00, 0xcd,
    0x8b, 0x3d, 0xa1, 0x82, 0xa3, 0xbd, 0xc4, 0xde, 0xd5, 0x3d,
    0x00, 0x00, 0x00, 0x00, 0x14, 0xe6, 0x98, 0xbd, 0xed, 0x08,
    0x6c, 0x3c, 0x36, 0xdb, 0xc8, 0xb9, 0x00, 0x00, 0x00, 0x00,
    0xc6, 0xa4, 0xce, 0xb8, 0x14, 0x67, 0xc4, 0x3d, 0x16, 0x30,
    0xc1, 0x3d, 0x3e, 0xfc, 0xb2, 0x3d, 0xd5, 0xb1, 0x98, 0x3d,
    0x83, 0x63, 0x0a, 0x39, 0x25, 0x1c, 0x36, 0xba, 0x8a, 0x0d,
    0x1d, 0x3a, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x12, 0x79, 0xbd,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9a, 0xea,
    0x06, 0x39, 0xd6, 0x1b, 0xb3, 0x3d, 0xb6, 0xd5, 0x50, 0x38,
    0xd1, 0x64, 0xa5, 0xbd, 0x2e, 0xc9, 0x98, 0xb9, 0x62, 0x88,
    0xb7, 0x3d, 0x32, 0x26, 0xab, 0xbd, 0x00, 0x00, 0x00, 0x00,
    0xb4, 0x02, 0xe6, 0x3a, 0xd4, 0xfb, 0x80, 0xbd, 0x11, 0xf4,
    0x47, 0xbd, 0xb1, 0x55, 0x55, 0x3d, 0x82, 0x43, 0xdf, 0x3d,
    0xa2, 0xa6, 0x7c, 0x3e, 0x21, 0x67, 0x81, 0x3e, 0x5b, 0x57,
    0x5c, 0x3d, 0x46, 0x16, 0x1d, 0xbe, 0xbc, 0x67, 0x86, 0x3e,
    0xfa, 0xbf, 0x88, 0x3e, 0xb6, 0x1f, 0x6a, 0x3e, 0xf9, 0xb1,
    0x85, 0x3d, 0x8e, 0xac, 0xd7, 0xbd, 0x1e, 0x34, 0xb9, 0xbe,
    0x3a, 0x6f, 0x74, 0x3e, 0xcf, 0x39, 0x36, 0x3e, 0x34, 0xec,
    0x15, 0x3e, 0xc0, 0x3d, 0xe6, 0xbd, 0x50, 0x1e, 0xeb, 0xbd,
    0x87, 0xb2, 0x1e, 0x3d, 0xba, 0xae, 0x94, 0x3e, 0x7c, 0x72,
    0xd7, 0x3d, 0x78, 0xbf, 0xb3, 0xbd, 0xce, 0x1a, 0x2f, 0xbd,
    0x49, 0x51, 0x37, 0xbe, 0xc2, 0xea, 0x33, 0x3e, 0xc0, 0xe4,
    0x57, 0xbd, 0xfd, 0x0b, 0x83, 0xbe, 0x44, 0x98, 0xf0, 0x3e,
    0xfe, 0x21, 0xb1, 0xbe, 0x75, 0x99, 0x69, 0xbe, 0x68, 0x7a,
    0x71, 0xbc, 0xbe, 0x44, 0x28, 0x3e, 0x31, 0x35, 0x24, 0xbe,
    0x89, 0xc4, 0xfb, 0x3d, 0xe6, 0x2c, 0x62, 0x3e, 0x5e, 0xdd,
    0x97, 0xbe, 0xca, 0x73, 0x74, 0x3e, 0x50, 0xb3, 0x7e, 0xbe,
    0x93, 0x74, 0xb2, 0x3e, 0xe5, 0xa1, 0x36, 0xbe, 0x45, 0xd8,
    0xc0, 0x3e, 0x24, 0x51, 0x57, 0x3e, 0x4a, 0x90, 0x04, 0x3d,
    0xfe, 0x9c, 0xc4, 0xbe, 0xc4, 0xca, 0x21, 0x3d, 0xd0, 0x8a,
    0x80, 0x3c, 0xbb, 0x9f, 0x9a, 0x3e, 0xa8, 0xb1, 0x5e, 0x3e,
    0xec, 0xf4, 0xc0, 0x3e, 0xa1, 0xca, 0xcb, 0x3d, 0x38, 0xdd,
    0x48, 0xbd, 0xf0, 0x1b, 0xc0, 0x3c, 0x08, 0x43, 0x3f, 0x3d,
    0x54, 0x16, 0xc1, 0xbe, 0x98, 0x4d, 0x85, 0xbe, 0x49, 0x4f,
    0x24, 0xbd, 0x8c, 0x4e, 0x0a, 0xbd, 0x32, 0x45, 0x5d, 0x3d,
    0xb5, 0x56, 0xd4, 0x3e, 0x40, 0xeb, 0xf6, 0x3d, 0x3b, 0xcc,
    0x92, 0x3e, 0x5c, 0x9d, 0x4a, 0xbe, 0x61, 0x0b, 0x41, 0xbe,
    0x20, 0x06, 0x6a, 0xbd, 0x6f, 0x88, 0x95, 0x3d, 0x1f, 0xd2,
    0xb8, 0x3e, 0xd6, 0xbf, 0xcb, 0x3e, 0x99, 0x19, 0xc3, 0xbd,
    0x69, 0xda, 0x90, 0xbe, 0xb0, 0x30, 0xba, 0x3d, 0xcf, 0x23,
    0xeb, 0x3d, 0x78, 0x1a, 0xa6, 0x3e, 0xad, 0x6a, 0x0a, 0x3e,
    0x62, 0x6d, 0x7e, 0x3e, 0x28, 0x67, 0x74, 0x3e, 0x7c, 0xe8,
    0x8b, 0xbe, 0xbb, 0xe9, 0x4a, 0xbe, 0xc2, 0xa8, 0xb0, 0x3e,
    0x45, 0xa7, 0xd6, 0xbe, 0x77, 0x3e, 0xfe, 0x3d, 0x87, 0xe7,
    0x65, 0x3e, 0x7a, 0xef, 0xae, 0x3e, 0x4f, 0x3c, 0xa3, 0xbe,
    0x66, 0xa3, 0xc8, 0xbd, 0x72, 0xb2, 0x76, 0x3e, 0x90, 0x33,
    0xc6, 0x3c, 0x25, 0x5e, 0x0d, 0x3e, 0x6e, 0x23, 0x5e, 0xbe,
    0xde, 0x16, 0x87, 0xbd, 0xc9, 0x34, 0x85, 0xbc, 0x13, 0x54,
    0x53, 0x3e, 0xa1, 0x10, 0x5d, 0xbe, 0xf6, 0xb2, 0x6c, 0xbe,
    0xea, 0xdb, 0x24, 0xbe, 0xbf, 0x5d, 0xb7, 0xbe, 0x7b, 0x16,
    0xf0, 0x3d, 0xbe, 0x0c, 0x40, 0x3e, 0x02, 0x67, 0x88, 0xbe,
    0x3a, 0x8c, 0x80, 0xbe, 0xe4, 0x85, 0xc6, 0xbd, 0xcb, 0x84,
    0xae, 0x3e, 0x76, 0x64, 0x32, 0x3e, 0xf5, 0x6f, 0xa9, 0x3e,
    0x4b, 0x5b, 0xdc, 0x3d, 0x8c, 0x02, 0x92, 0x3e, 0x23, 0x6e,
    0x85, 0x3c, 0x42, 0x00, 0x7e, 0x3e, 0xb8, 0x59, 0x63, 0xbd,
    0x5a, 0xba, 0xc8, 0x3d, 0xfd, 0xef, 0x98, 0x3e, 0xc2, 0x20,
    0x9d, 0xbe, 0xc0, 0x79, 0xc7, 0xbc, 0x3c, 0x8b, 0x47, 0x3e,
    0x84, 0x98, 0x90, 0xbe, 0xbd, 0xf9, 0xc5, 0x3c, 0x56, 0x30,
    0x1b, 0x3e, 0x5e, 0x87, 0x9d, 0x3b, 0x68, 0x08, 0x88, 0xbe,
    0x0f, 0x63, 0x61, 0x3e, 0x7b, 0x37, 0x2e, 0xbd, 0x12, 0xca,
    0xaa, 0xbe, 0x4a, 0x6a, 0xa2, 0xbe, 0xfd, 0xfd, 0xaf, 0xbe,
    0x2a, 0x20, 0xbd, 0xbe, 0xe9, 0x6b, 0x83, 0xbd, 0x8f, 0x4d,
    0xd5, 0x3e, 0x2e, 0xce, 0x1c, 0x3c, 0xd2, 0xb1, 0x3d, 0x3c,
    0x35, 0xb2, 0xe3, 0xbe, 0xc6, 0x49, 0xaf, 0xbd, 0xb6, 0xed,
    0x29, 0x3e, 0x00, 0x7e, 0x59, 0x3e, 0x50, 0x53, 0xeb, 0x3c,
    0xd4, 0x4e, 0xe1, 0x3d, 0xbe, 0x5c, 0xc0, 0x3d, 0x76, 0x2f,
    0xdb, 0x3e, 0x62, 0x3f, 0xcb, 0xbe, 0x6c, 0x5a, 0xae,
    0x3d, 0xb4, 0x5c, 0x85, 0xbe, 0x9b, 0x30, 0x92, 0x3d,
    0xb5, 0x7d, 0x0b, 0xbe, 0xde, 0xf3, 0x6d, 0x3e, 0xb5,
    0xb5, 0x33, 0xbe, 0x18, 0x02, 0x82, 0x3e, 0xd1, 0xb3,
    0x49, 0xbe, 0xa5, 0x9c, 0xce, 0xbe, 0x41, 0x3c, 0xa3,
    0xbd, 0x80, 0x7d, 0xb5, 0xbd, 0x93, 0x83, 0xaa, 0x3d
  };

  return AI_HANDLE_PTR(s_led_monitoring_network_weights);

}
