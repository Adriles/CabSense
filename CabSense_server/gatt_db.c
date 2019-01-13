// Copyright 2018 Silicon Laboratories, Inc.
//
//

/********************************************************************
 * Autogenerated file, do not edit.
 *******************************************************************/

#include <stdint.h>
#include "bg_gattdb_def.h"

#ifdef __GNUC__
#define GATT_HEADER(F) F __attribute__ ((section (".gatt_header"))) 
#define GATT_DATA(F) F __attribute__ ((section (".gatt_data"))) 
#else
#ifdef __ICCARM__
#define GATT_HEADER(F) _Pragma("location=\".gatt_header\"") F 
#define GATT_DATA(F) _Pragma("location=\".gatt_data\"") F 
#else
#define GATT_HEADER(F) F 
#define GATT_DATA(F) F 
#endif
#endif

GATT_DATA(const uint16_t bg_gattdb_data_uuidtable_16_map [])=
{
    0x2800,
    0x2801,
    0x2803,
    0x1800,
    0x2a00,
    0x2a01,
    0x180a,
    0x2a29,
    0x2a24,
    0x2a23,
    0x1819,
    0x2a6a,
    0x2a67,
    0x2902,
    0x2a69,
    0x2a6b,
    0x2a68,
    0x180e,
    0x2a3f,
    0x2a41,
    0x2a40,
    0x1804,
    0x2a07,
    0x1801,
    0x2a05,
};

GATT_DATA(const uint8_t bg_gattdb_data_uuidtable_128_map [])=
{
    0x0 //IAR workaround for empty array
};




uint8_t bg_gattdb_data_attribute_field_41_data[1]={0x00,};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_41 ) = {
	.properties=0x02,
	.index=10,
	.max_len=1,
	.data=bg_gattdb_data_attribute_field_41_data,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_40 ) = {
	.len=5,
	.data={0x02,0x2a,0x00,0x07,0x2a,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_39 ) = {
	.len=2,
	.data={0x04,0x18,}
};
uint8_t bg_gattdb_data_attribute_field_38_data[1]={0x00,};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_38 ) = {
	.properties=0x04,
	.index=9,
	.max_len=1,
	.data=bg_gattdb_data_attribute_field_38_data,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_37 ) = {
	.len=5,
	.data={0x04,0x27,0x00,0x40,0x2a,}
};
uint8_t bg_gattdb_data_attribute_field_35_data[1]={0x00,};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_35 ) = {
	.properties=0x12,
	.index=8,
	.max_len=1,
	.data=bg_gattdb_data_attribute_field_35_data,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_34 ) = {
	.len=5,
	.data={0x12,0x24,0x00,0x41,0x2a,}
};
uint8_t bg_gattdb_data_attribute_field_32_data[1]={0x00,};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_32 ) = {
	.properties=0x12,
	.index=7,
	.max_len=1,
	.data=bg_gattdb_data_attribute_field_32_data,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_31 ) = {
	.len=5,
	.data={0x12,0x21,0x00,0x3f,0x2a,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_30 ) = {
	.len=2,
	.data={0x0e,0x18,}
};
uint8_t bg_gattdb_data_attribute_field_28_data[19]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_28 ) = {
	.properties=0x10,
	.index=6,
	.max_len=19,
	.data=bg_gattdb_data_attribute_field_28_data,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_27 ) = {
	.len=5,
	.data={0x10,0x1d,0x00,0x68,0x2a,}
};
struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_25_data = {
	.len=0,
	.data={0x00,0x00,0x00,}
};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_25 ) = {
	.properties=0x28,
	.index=5,
	.max_len=3,
	.data_varlen=&bg_gattdb_data_attribute_field_25_data,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_24 ) = {
	.len=5,
	.data={0x28,0x1a,0x00,0x6b,0x2a,}
};
uint8_t bg_gattdb_data_attribute_field_23_data[16]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_23 ) = {
	.properties=0x02,
	.index=4,
	.max_len=16,
	.data=bg_gattdb_data_attribute_field_23_data,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_22 ) = {
	.len=5,
	.data={0x02,0x18,0x00,0x69,0x2a,}
};
uint8_t bg_gattdb_data_attribute_field_20_data[28]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_20 ) = {
	.properties=0x10,
	.index=3,
	.max_len=28,
	.data=bg_gattdb_data_attribute_field_20_data,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_19 ) = {
	.len=5,
	.data={0x10,0x15,0x00,0x67,0x2a,}
};
uint8_t bg_gattdb_data_attribute_field_18_data[4]={0x00,0x00,0x00,0x00,};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_18 ) = {
	.properties=0x02,
	.index=2,
	.max_len=4,
	.data=bg_gattdb_data_attribute_field_18_data,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_17 ) = {
	.len=5,
	.data={0x02,0x13,0x00,0x6a,0x2a,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_16 ) = {
	.len=2,
	.data={0x19,0x18,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_15 ) = {
	.len=6,
	.data={0x00,0x01,0x02,0x03,0x04,0x05,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_14 ) = {
	.len=5,
	.data={0x02,0x10,0x00,0x23,0x2a,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_13 ) = {
	.len=10,
	.data={0x42,0x6c,0x75,0x65,0x20,0x47,0x65,0x63,0x6b,0x6f,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_12 ) = {
	.len=5,
	.data={0x02,0x0e,0x00,0x24,0x2a,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_11 ) = {
	.len=12,
	.data={0x53,0x69,0x6c,0x69,0x63,0x6f,0x6e,0x20,0x4c,0x61,0x62,0x73,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_10 ) = {
	.len=5,
	.data={0x02,0x0c,0x00,0x29,0x2a,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_9 ) = {
	.len=2,
	.data={0x0a,0x18,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_8 ) = {
	.len=2,
	.data={0x00,0x00,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_7 ) = {
	.len=5,
	.data={0x02,0x09,0x00,0x01,0x2a,}
};
uint8_t bg_gattdb_data_attribute_field_6_data[15]={0x43,0x61,0x62,0x53,0x65,0x6e,0x73,0x65,0x5f,0x73,0x65,0x72,0x76,0x65,0x72,};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_6 ) = {
	.properties=0x0a,
	.index=1,
	.max_len=15,
	.data=bg_gattdb_data_attribute_field_6_data,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_5 ) = {
	.len=5,
	.data={0x0a,0x07,0x00,0x00,0x2a,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_4 ) = {
	.len=2,
	.data={0x00,0x18,}
};
uint8_t bg_gattdb_data_attribute_field_2_data[4]={0x00,0x00,0x00,0x00,};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_2 ) = {
	.properties=0x20,
	.index=0,
	.max_len=4,
	.data=bg_gattdb_data_attribute_field_2_data,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_1 ) = {
	.len=5,
	.data={0x20,0x03,0x00,0x05,0x2a,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_0 ) = {
	.len=2,
	.data={0x01,0x18,}
};
GATT_DATA(const struct bg_gattdb_attribute bg_gattdb_data_attributes_map[])={
    {.uuid=0x0000,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_0},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_1},
    {.uuid=0x0018,.permissions=0x800,.caps=0xffff,.datatype=0x01,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_2},
    {.uuid=0x000d,.permissions=0x807,.caps=0xffff,.datatype=0x03,.min_key_size=0x00,.configdata={.flags=0x02,.index=0x00,.clientconfig_index=0x00}},
    {.uuid=0x0000,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_4},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_5},
    {.uuid=0x0004,.permissions=0x803,.caps=0xffff,.datatype=0x01,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_6},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_7},
    {.uuid=0x0005,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_8},
    {.uuid=0x0000,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_9},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_10},
    {.uuid=0x0007,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_11},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_12},
    {.uuid=0x0008,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_13},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_14},
    {.uuid=0x0009,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_15},
    {.uuid=0x0000,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_16},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_17},
    {.uuid=0x000b,.permissions=0x801,.caps=0xffff,.datatype=0x01,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_18},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_19},
    {.uuid=0x000c,.permissions=0x800,.caps=0xffff,.datatype=0x01,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_20},
    {.uuid=0x000d,.permissions=0x807,.caps=0xffff,.datatype=0x03,.min_key_size=0x00,.configdata={.flags=0x01,.index=0x03,.clientconfig_index=0x01}},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_22},
    {.uuid=0x000e,.permissions=0x801,.caps=0xffff,.datatype=0x01,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_23},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_24},
    {.uuid=0x000f,.permissions=0x802,.caps=0xffff,.datatype=0x02,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_25},
    {.uuid=0x000d,.permissions=0x807,.caps=0xffff,.datatype=0x03,.min_key_size=0x00,.configdata={.flags=0x02,.index=0x05,.clientconfig_index=0x02}},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_27},
    {.uuid=0x0010,.permissions=0x800,.caps=0xffff,.datatype=0x01,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_28},
    {.uuid=0x000d,.permissions=0x807,.caps=0xffff,.datatype=0x03,.min_key_size=0x00,.configdata={.flags=0x01,.index=0x06,.clientconfig_index=0x03}},
    {.uuid=0x0000,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_30},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_31},
    {.uuid=0x0012,.permissions=0x801,.caps=0xffff,.datatype=0x01,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_32},
    {.uuid=0x000d,.permissions=0x807,.caps=0xffff,.datatype=0x03,.min_key_size=0x00,.configdata={.flags=0x01,.index=0x07,.clientconfig_index=0x04}},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_34},
    {.uuid=0x0013,.permissions=0x801,.caps=0xffff,.datatype=0x01,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_35},
    {.uuid=0x000d,.permissions=0x807,.caps=0xffff,.datatype=0x03,.min_key_size=0x00,.configdata={.flags=0x01,.index=0x08,.clientconfig_index=0x05}},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_37},
    {.uuid=0x0014,.permissions=0x804,.caps=0xffff,.datatype=0x01,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_38},
    {.uuid=0x0000,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_39},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_40},
    {.uuid=0x0016,.permissions=0x801,.caps=0xffff,.datatype=0x01,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_41},
};

GATT_DATA(const uint16_t bg_gattdb_data_attributes_dynamic_mapping_map[])={
	0x0003,
	0x0007,
	0x0013,
	0x0015,
	0x0018,
	0x001a,
	0x001d,
	0x0021,
	0x0024,
	0x0027,
	0x002a,
};

GATT_DATA(const uint8_t bg_gattdb_data_adv_uuid16_map[])={0x0};
GATT_DATA(const uint8_t bg_gattdb_data_adv_uuid128_map[])={0x0};
GATT_HEADER(const struct bg_gattdb_def bg_gattdb_data)={
    .attributes=bg_gattdb_data_attributes_map,
    .attributes_max=42,
    .uuidtable_16_size=25,
    .uuidtable_16=bg_gattdb_data_uuidtable_16_map,
    .uuidtable_128_size=0,
    .uuidtable_128=bg_gattdb_data_uuidtable_128_map,
    .attributes_dynamic_max=11,
    .attributes_dynamic_mapping=bg_gattdb_data_attributes_dynamic_mapping_map,
    .adv_uuid16=bg_gattdb_data_adv_uuid16_map,
    .adv_uuid16_num=0,
    .adv_uuid128=bg_gattdb_data_adv_uuid128_map,
    .adv_uuid128_num=0,
    .caps_mask=0xffff,
    .enabled_caps=0xffff,
};

const struct bg_gattdb_def *bg_gattdb=&bg_gattdb_data;
