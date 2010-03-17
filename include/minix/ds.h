/* Prototypes and definitions for DS interface. */

#ifndef _MINIX_DS_H
#define _MINIX_DS_H

#include <minix/types.h>

/* Flags. */
#define DSF_IN_USE		0x001	/* entry is in use */
#define DSF_PRIV_RETRIEVE	0x002	/* only owner can retrieve */
#define DSF_PRIV_OVERWRITE	0x004	/* only owner can overwrite */
#define DSF_PRIV_SNAPSHOT	0x004	/* only owner can take a snapshot */
#define DSF_PRIV_SUBSCRIBE	0x008	/* only owner can subscribe */
#define DSF_TYPE_U32		0x010	/* u32 data type */
#define DSF_TYPE_STR		0x020	/* string data type */
#define DSF_TYPE_MEM		0x040	/* memory range data type */
#define DSF_TYPE_MAP		0x080	/* mapped memory range data type */
#define DSF_TYPE_LABEL		0x100	/* label data type */

#define DSF_MASK_TYPE		0xFF0	/* mask for type flags. */
#define DSF_MASK_INTERNAL	0xFFF	/* mask for internal flags. */

#define DSF_OVERWRITE		0x01000	/* overwrite if entry exists */
#define DSF_INITIAL		0x02000	/* check subscriptions immediately */

#define DSMF_MAP_MAPPED		0x10000	/* map mapped memory range */
#define DSMF_COPY_MAPPED	0x20000	/* copy mapped memory range */
#define DSMF_COPY_SNAPSHOT	0x40000	/* copy snapshot */

/* DS constants. */
#define DS_MAX_KEYLEN 80        /* Max length of a key, including '\0'. */

/* ds.c */

/* U32 */
_PROTOTYPE( int ds_publish_u32, (const char *name, u32_t val, int flags));
_PROTOTYPE( int ds_retrieve_u32, (const char *name, u32_t *val));
_PROTOTYPE( int ds_delete_u32, (const char *ds_name));

/* STRING */
_PROTOTYPE( int ds_publish_str, (const char *name, char *val, int flags));
_PROTOTYPE( int ds_retrieve_str, (const char *name, char *val, size_t len));
_PROTOTYPE( int ds_delete_str, (const char *ds_name));

/* MEM */
_PROTOTYPE( int ds_publish_mem, (const char *ds_name, void *vaddr,
		size_t length, int flags));
_PROTOTYPE( int ds_retrieve_mem, (const char *ds_name, char *vaddr,
		size_t *length));
_PROTOTYPE( int ds_delete_mem, (const char *ds_name));

/* MAP */
_PROTOTYPE( int ds_publish_map, (const char *ds_name, void *vaddr,
		size_t length, int flags));
_PROTOTYPE( int ds_snapshot_map, (const char *ds_name, int *nr_snapshot));
_PROTOTYPE( int ds_retrieve_map, (const char *ds_name, char *vaddr,
		size_t *length, int nr_snapshot, int flags));
_PROTOTYPE( int ds_delete_map, (const char *ds_name));

/* LABEL */
_PROTOTYPE( int ds_publish_label, (const char *ds_name, u32_t value,int flags));
_PROTOTYPE( int ds_retrieve_label_name, (char *ds_name, u32_t num));
_PROTOTYPE( int ds_retrieve_label_num, (const char *ds_name, u32_t *value));
_PROTOTYPE( int ds_delete_label, (const char *ds_name));

/* Subscribe and check. */
_PROTOTYPE( int ds_subscribe, (const char *regex, int flags));
_PROTOTYPE( int ds_check, (char *ds_name, int *type));

#endif /* _MINIX_DS_H */

